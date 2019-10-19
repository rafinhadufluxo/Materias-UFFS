#include <Render.h>
#include <QPaintDevice>
#include <QFileDialog>
#include <PlyParser.h>
#include <QRgb>
#include <fstream>
using namespace std;

QVector <QVector<QPointF> > facesTotais;

Render::Render(int w, int h, CommandQueue *c) {


    screenW = w;
    screenH = h;
    cmdq = c;
    sel = NULL;
    buffer = NULL;
    backBuffer = NULL;
    frontBuffer = NULL;
    screen = NULL;
    vsel = NULL;
    hsel = NULL;
    fsel = NULL;
    facePonto = NULL;
    
    zoom = 1.0;
    screen = new QImage(w, h, QImage::Format_ARGB32_Premultiplied);
    ponto = new QPoint(0,0);

    corArestaGrossa = qRgb(255,255,0);
    corVerticeGrosso = qRgb(0,255,0);
    corFace = qRgb(255,255,255);
    corFaceExt = qRgb(0,0,0);

    arestaScreen.setColor(QColor(0,0,0,255));
    selecionadoScreen.setColor(QColor(0,128,128,128));
    selecionadoScreen.setColor(QColor(255,0,0,128));
    selecionadoScreen.setWidth(10);
    vizinhoScreen.setColor(QColor(0,255,0,128));
    vizinhoScreen.setWidth(10);
    faceExternaBack.setColor(corFaceExt);
    arestaGrossaBack.setColor(corArestaGrossa);
    verticeGrossoBack.setColor(corVerticeGrosso);
    arestaGrossaBack.setWidth(10);
    verticeGrossoBack.setWidth(10);

    mostraAresta = false;
    mostraFace = false;
    mostraPonto = false;

    faceSelected = true;

}

void Render::run(void) {
    ExCom ex;
    
    do {
        ex = cmdq->consome();
        if(buffer == NULL)
        {
             msleep(100);
             continue;
        }
        switch(ex.cmd)
        {
        case NENHUM:
            msleep(100);
            continue;
        case INCZOOM:
            incZoom();
            break;
        case DECZOOM:
            decZoom();
            break;
        case INCX:
            incX();
            break;
        case DECX:
            decX();
            break;
        case INCY:
            incY();
            break;
        case DECY:
            decY();
            break;
        case PONTOS:
            mostraPonto = !mostraPonto;
            renderizaFront();
            break;
        case ARESTAS:
            mostraAresta = !mostraAresta;
            renderizaFront();
            break;
        case FACES:
            mostraFace = !mostraFace;
            renderizaFront();
            break;
        case SELECT:
            if(sel == NULL)
            sel = new QPoint();
            sel->setX(ex.x);
            sel->setY(ex.y);
            click();
            break;
        case DELETA:
            deleta();
            break;
        case VDV:
            vdv();
            break;
        case SWITCHCLICK:
            switchClick();
            break;
        case SALVAR:
            salvar("tmp.ply");
            break;
        }
        atualizaScreen();
    } while (true);

}

void Render::updateScreen(int w, int h)
{
    screenW = w;
    screenH = h;

    if(buffer->width() < w || buffer->height() < h)
    {
        reiniciaBuffers(screenW * zoom, screenH * zoom);

    }

    if(ponto->x() + w > buffer->width())
        ponto->setX(buffer->width() - w);
    if(ponto->y() + h > buffer->height())
        ponto->setY(buffer->height() - h);

    atualizaScreen();
}

void Render::recebeArquivo(const QString &filename)
{
    QVector<QPointF> tmp;
    if(sel != NULL)
    {
        delete sel;
        sel = NULL;
    }

    mostraAresta = false;
    mostraFace = false;
    mostraPonto = false;
    vsel = NULL;
    hsel = NULL;
    fsel = NULL;

    zoom = 1.0;
    if(ponto == NULL)
        ponto = new QPoint();

    ponto->setX(0);
    ponto->setY(0);

    PlyParser ply(filename);
    
    tmp = ply.proximo();
    interface.clear();

    int i_faces = 0;
    while (i_faces < ply.getNFaces())
    {
        interface.addFace(tmp);
        facesTotais << tmp;
        tmp = ply.proximo();

        i_faces++;
    }
    interface.faceExterna = NULL;
    interface.addExtEdges();

    reiniciaBuffers(screenW * zoom, screenH * zoom);

    atualizaScreen();
 }
 
void Render::atualizaScreen(void)
{
    QPainter p;

    if(screen != NULL)
        delete screen;

    screen = new QImage(screenW, screenH, QImage::Format_ARGB32_Premultiplied);
    p.begin(screen);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawImage(0,0, buffer->copy(ponto->x(),ponto->y(),screenW, screenH));
    p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    p.drawImage(0,0, frontBuffer->copy(ponto->x(),ponto->y(),screenW, screenH));
    p.end();
    emit renderizado(*screen);
}

void Render::incX()
{
    if(ponto->x() + INCPOS + screenW/2 < buffer->width())
        ponto->setX(ponto->x() + INCPOS);
}
void Render::decX()
{
    if(ponto->x() - INCPOS >= 0)
        ponto->setX(ponto->x() - INCPOS);
    else
        ponto->setX(0);

}
void Render::incY()
{
    if(ponto->y() + INCPOS + screenH/2 < buffer->height())
        ponto->setY(ponto->y() + INCPOS);
}
void Render::decY()
{
    if(ponto->y() - INCPOS >= 0)
        ponto->setY(ponto->y() - INCPOS);
    else
        ponto->setY(0);
}
void Render::incZoom()
{
    if(zoom == ZOOMLIMIT)
        return;

    if(zoom + INCZ < ZOOMLIMIT)
        zoom += INCZ;
    else
        zoom = ZOOMLIMIT;

    reiniciaBuffers(screenW * zoom, screenH * zoom);
}
void Render::decZoom()
{
    if(zoom == 1.0)
        return;

    if(zoom - INCZ > 1.0)
        zoom -= INCZ;
    else
        zoom = 1.0;

    if(ponto->x() + screenW > screenW*zoom)
        ponto->setX(screenW*zoom - screenW);
    if(ponto->y() + screenH > screenH*zoom)
        ponto->setY(screenH*zoom - screenH);

    reiniciaBuffers(screenW * zoom, screenH * zoom);
}

QPoint Render::transforma(const QPointF &in)
{
    double xwmax, xwmin, ywmax, ywmin;
    double xmax, xmin, ymax, ymin;
    double sx,sy;

    xmin = buffer->width() * MARGEM;
    ymin = buffer->height() * MARGEM;
    xmax = buffer->width() - xmin;
    ymax = buffer->height() - ymin;

    xwmin = interface.getMinX();
    xwmax = interface.getMaxX();
    ywmin = interface.getMinY();
    ywmax = interface.getMaxY();

    sx = (xmax - xmin )/(xwmax - xwmin );
    sy = (ymax - ymin )/(ywmax - ywmin );

    if(sx < sy)
        sy = sx;
    else
        sx = sy;

    double x = sx*in.x() - sx*xwmin + xmin;
    double y = sy*in.y() - sy*ywmin + ymin;

    QPoint p(qRound(x), qRound(y));
    return p;
}

QPointF Render::destransforma(const QPoint &in)
{
    double xwmax, xwmin, ywmax, ywmin;
    double xmax, xmin, ymax, ymin;
    double sx,sy;

    xwmin = buffer->width() * MARGEM;
    ywmin = buffer->height() * MARGEM;
    xwmax = buffer->width() - xwmin;
    ywmax = buffer->height() - ywmin;

    xmin = interface.getMinX();
    xmax = interface.getMaxX();
    ymin = interface.getMinY();
    ymax = interface.getMaxY();

    sx = (xmax - xmin )/(xwmax - xwmin );
    sy = (ymax - ymin )/(ywmax - ywmin );

    if(sx > sy)
        sy = sx;
    else
        sx = sy;

    double x = sx*in.x() - sx*xwmin + xmin;
    double y = sy*in.y() - sy*ywmin + ymin;

    QPointF p(x, y);
    return p;
}

void Render::renderiza(void)
{
    QPoint p1, p2, t;
    QList<QPair<QPointF,QPointF> > lista = interface.getTodasArestas();
    QPainter buff(buffer);
    QPainter back(backBuffer);

    buff.fillRect(buffer->rect(), Qt::white);
    buff.fillRect(buffer->rect(),Qt::transparent);
    back.fillRect(backBuffer->rect(), Qt::white);
    back.fillRect(backBuffer->rect(), Qt::transparent);

    buff.setPen(arestaScreen);

    for(int i = 0; i < lista.size() ; ++i)
    {
        p1 = transforma(lista[i].first);
        p2 = transforma(lista[i].second);

        buff.drawLine(p1,p2);

        back.setPen(arestaGrossaBack);
        back.drawLine(p1,p2);
        back.setPen(verticeGrossoBack);
        back.drawEllipse(p1,5,5);
        back.drawEllipse(p2,5,5);
    }
}

void Render::click(void)
{
    Vertex* v = NULL;
    HalfEdge* h = NULL;
    Face *f = NULL;
    HalfEdge* t = NULL;
    QPointF p1;
    QPoint p2;

    p2.setX(sel->x() + ponto->x());
    p2.setY(sel->y() + ponto->y());

    QRgb rgb = backBuffer->pixel(p2);
    p1 = destransforma(p2);

    if(rgb == corVerticeGrosso)
    {
        v = interface.getVerticeNear(p1);
    }else if(rgb == corArestaGrossa)
    {
        h = interface.getArestaNear(p1);
    }else if(rgb == corFace)
    {
        /* if i switched the click i should add a full vertex */
        if(!faceSelected){
            facePonto = interface.getFaceNear(p1);
            addFullVertex();
        }
        else{
            f = interface.getFaceNear(p1);
        }
    }

    if(hsel != NULL)
        t = hsel->getTwin();

    if(v == vsel && (h == hsel || h == t) && f == fsel)
    {
        vsel = NULL;
        hsel = NULL;
        fsel = NULL;
    }else
    {
        vsel = v;
        hsel = h;
        fsel = f;
    }

    renderizaFront();
}

void Render::renderizaFront(void)
{
    QPainter p(frontBuffer);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.fillRect(frontBuffer->rect(), Qt::transparent);
    p.end();

    if(mostraFace)
        renderizaFaces();
    if(mostraAresta)
        renderizaArestas();
    if(mostraPonto)
        renderizaVertices();

    verticeSelecionado();
    arestaSelecionada();
    faceSelecionada();

    atualizaScreen();
}

void Render::renderizaFaces()
{
    HalfEdge *partida;
    HalfEdge::iterator it;
    bool renderizaExterna = false;

    if(vsel != NULL)
        partida = vsel->getEdge();
    if(hsel != NULL)
        partida = hsel;
    if(fsel != NULL)
        partida = fsel->getOuterComp();

    if(vsel != NULL)
    {
        if(interface.isExterna(partida->getFace()))
            renderizaExterna = true;
        else
            renderizaFace(partida, frontBuffer,vizinhoScreen);
        for(it = partida->v_begin(); it != partida->v_end(); ++it)
        {
            if(interface.isExterna(it->getFace()))
                renderizaExterna = true;
            else
                renderizaFace(&it, frontBuffer,vizinhoScreen);
        }
    }

    if(hsel != NULL)
    {
        if(interface.isExterna(partida->getFace()))
            renderizaExterna = true;
        else
            renderizaFace(partida, frontBuffer,vizinhoScreen);

        if(interface.isExterna(partida->getTwin()->getFace()))
            renderizaExterna = true;
        else
            renderizaFace(partida->getTwin(), frontBuffer,vizinhoScreen);
    }

    QVector<HalfEdge *> *v;
    QSet<Face*> f;
    if(fsel != NULL)
    {
        if(interface.isExterna(fsel))
            v = &(interface.componentesFaceExterna);
        else
        {
            v = new QVector<HalfEdge *>();
            v->push_back(partida->getTwin());
        }
        for(int i = 0; i < v->size(); ++i)
        {
            partida = v->at(i)->getTwin();

            if(interface.isExterna(partida->getTwin()->getFace()))
                renderizaExterna = true;
            else
                renderizaFace(partida->getTwin(), frontBuffer,vizinhoScreen);
            for(it = partida->f_begin(); it != partida->f_end(); ++it)
            {
                if(interface.isExterna(it->getTwin()->getFace()))
                    renderizaExterna = true;
                else
                    f.insert(it->getTwin()->getFace());
            }
        }
        if(!interface.isExterna(fsel))
            delete v;
        QSet<Face*>::iterator jt;
        for(jt = f.begin(); jt != f.end(); ++jt)
            renderizaFace((*jt)->getOuterComp(), frontBuffer,vizinhoScreen);
    }


    if(renderizaExterna)
        renderizaFaceExterna(&vizinhoScreen);
}

void Render::renderizaArestas()
{
    QPainter buff(frontBuffer);
    QPoint p;
    HalfEdge *partida;
    HalfEdge::iterator it;

    buff.setPen(vizinhoScreen);

    if(vsel != NULL)
        partida = vsel->getEdge();
    if(hsel != NULL)
        partida = hsel;
    if(fsel != NULL)
        partida = fsel->getOuterComp();

    if(vsel != NULL || hsel != NULL)
    {
        for(it = partida->v_begin(); it != partida->v_end(); ++it)
        {
            buff.drawLine(transforma(it->getOrigem()->getPoint()), transforma(it->getDestino()->getPoint()));
        }
        if(hsel != NULL)
        {
            partida = partida->getTwin();
            for(it = partida->v_begin(); it != partida->v_end(); ++it)
            {
                buff.drawLine(transforma(it->getOrigem()->getPoint()), transforma(it->getDestino()->getPoint()));
            }
        }else
            buff.drawLine(transforma(partida->getOrigem()->getPoint()), transforma(partida->getDestino()->getPoint()));
    }
    QVector<HalfEdge *> *v;
    if(fsel != NULL)
    {
        if(interface.isExterna(fsel))
            v = &(interface.componentesFaceExterna);
        else
        {
            v = new QVector<HalfEdge *>();
            v->push_back(partida->getTwin());
        }
        for(int i = 0; i < v->size(); ++i)
        {
            partida = v->at(i)->getTwin();

            for(it = partida->f_begin(); it != partida->f_end(); ++it)
            {
                buff.drawLine(transforma(it->getOrigem()->getPoint()), transforma(it->getDestino()->getPoint()));
            }
            buff.drawLine(transforma(partida->getOrigem()->getPoint()), transforma(partida->getDestino()->getPoint()));
        }
        if(!interface.isExterna(fsel))
            delete v;
    }

}
void Render::renderizaVertices()
{
    QPainter buff(frontBuffer);
    QPoint p;
    HalfEdge *partida;
    HalfEdge::iterator it;

    buff.setPen(vizinhoScreen);

    if(vsel != NULL)
        partida = vsel->getEdge();
    if(hsel != NULL)
        partida = hsel;
    if(fsel != NULL)
        partida = fsel->getOuterComp();

    if(vsel != NULL || hsel != NULL)
    {
        for(it = partida->v_begin(); it != partida->v_end(); ++it)
        {
            buff.drawEllipse(transforma(it->getDestino()->getPoint()), 5,5);
        }
        if(hsel != NULL)
        {
            partida = partida->getTwin();
            for(it = partida->v_begin(); it != partida->v_end(); ++it)
            {
                buff.drawEllipse(transforma(it->getDestino()->getPoint()), 5,5);
            }
        }else
            buff.drawEllipse(transforma(partida->getDestino()->getPoint()), 5,5);
    }
    QVector<HalfEdge *> *v;
    if(fsel != NULL)
    {
        if(interface.isExterna(fsel))
            v = &(interface.componentesFaceExterna);
        else
        {
            v = new QVector<HalfEdge *>();
            v->push_back(partida->getTwin());
        }
        for(int i = 0; i < v->size(); ++i)
        {
            partida = v->at(i)->getTwin();
            for(it = partida->f_begin(); it != partida->f_end(); ++it)
            {
                buff.drawEllipse(transforma(it->getOrigem()->getPoint()), 5,5);
            }
            buff.drawEllipse(transforma(partida->getOrigem()->getPoint()), 5,5);
        }
        if(!interface.isExterna(fsel))
            delete v;
    }
}

void Render::reiniciaBuffers(int w, int h)
{
    if(buffer != NULL)
        delete buffer;
    if(backBuffer != NULL)
        delete backBuffer;
    if(frontBuffer != NULL)
        delete frontBuffer;

    buffer = new QImage(w, h, QImage::Format_ARGB32_Premultiplied);
    backBuffer = new QImage(w, h, QImage::Format_ARGB32_Premultiplied);
    frontBuffer = new QImage(w, h, QImage::Format_ARGB32_Premultiplied);


    QPainter p;
    p.begin(buffer);
    p.fillRect(buffer->rect(), Qt::white);
    p.end();
    p.begin(backBuffer);
    p.fillRect(backBuffer->rect(),Qt::white);
    p.end();
    p.begin(frontBuffer);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.fillRect(frontBuffer->rect(), Qt::transparent);
    p.end();

    renderiza();
    renderizaFront();
}

void Render::renderizaFace(HalfEdge *h,QImage* b,QPen pen)
{
    QPainter buff(b);
    QPainterPath *path;
    QPoint p;
    HalfEdge::iterator it;

    buff.setPen(pen);

    path = new QPainterPath();
    p = transforma(h->getOrigem()->getPoint());
    path->moveTo(p.x(),p.y());
    for(it = h->f_begin(); it !=  h->f_end(); ++it)
    {
        p = transforma(it->getOrigem()->getPoint());
        path->lineTo(p.x(),p.y());
    }
    p = transforma(h->getOrigem()->getPoint());
    path->lineTo(p.x(),p.y());

    buff.fillPath(*path,pen.brush());
    delete path;
}

void Render::verticeSelecionado()
{
    QPainter p(frontBuffer);

    if(vsel == NULL)
        return;

    p.setPen(selecionadoScreen);
    p.drawEllipse(transforma(vsel->getPoint()),5,5);

}
void Render::arestaSelecionada()
{
     QPainter p(frontBuffer);

    if(hsel == NULL)
        return;

    p.setPen(selecionadoScreen);
    p.drawLine(transforma(hsel->getOrigem()->getPoint()), transforma(hsel->getDestino()->getPoint()));

}
void Render::faceSelecionada()
{
    if(fsel == NULL)
        return;

    if(interface.isExterna(fsel))
        renderizaFaceExterna(&selecionadoScreen);
    else
        renderizaFace(fsel->getOuterComp(), frontBuffer,selecionadoScreen);
}

void Render::renderizaFaceExterna(QPen *pen)
{
    bool passa;
    QVector<HalfEdge*> *list = &(interface.componentesFaceExterna);
    QVector<HalfEdge*> temp;
    HalfEdge *val;
    HalfEdge::iterator it, jt;
    QImage buffExt(buffer->width(), buffer->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter p;
    p.begin(&buffExt);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.fillRect(buffExt.rect(), pen->color());
    p.end();

    for(int i = 0; i < list->size(); ++i)
    {
        val = list->at(i);
        passa = false;

          for(it = val->v_begin(); it != val->v_end() ; ++it)
            {
               if(dentroFace(val->getTwin(),it->getDestino()->getPoint()))
                {
                    passa = true;
                    break;
                }
            }

        if( passa || componenteFaceUnica(&it))
            renderizaComponente(val->getTwin(),&buffExt,QPen(Qt::transparent));
        else
            temp.push_back(val->getTwin());
    }
    for(int i = 0; i < temp.size(); ++i)
        renderizaFace(temp[i],&buffExt,*pen);

    p.begin(frontBuffer);
    p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    p.drawImage(0,0, buffExt);
    p.end();
}

bool Render::dentroFace(HalfEdge* h, QPointF p)
{
    HalfEdge::iterator it;
    QVector<QPointF> list;

    list.push_back(h->getOrigem()->getPoint());
    for(it = h->f_begin(); it != h->f_end(); ++it)
    {
        list.push_back(it->getOrigem()->getPoint());
    }

    QPolygonF po(list);

    return po.containsPoint(p, Qt::OddEvenFill);
}

void Render::renderizaComponente(HalfEdge *h,QImage* b,QPen pen)
{
    QPainter buff(b);
    QPainterPath *path;
    QPoint p;
    HalfEdge::iterator it;

    buff.setPen(pen);

    path = new QPainterPath();
    p = transforma(h->getOrigem()->getPoint());
    path->moveTo(p.x(),p.y());
    for(it = h->f_begin(); it !=  h->f_end(); ++it)
    {
        p = transforma(it->getOrigem()->getPoint());
        path->lineTo(p.x(),p.y());
    }
    p = transforma(h->getOrigem()->getPoint());
    path->lineTo(p.x(),p.y());

    buff.setCompositionMode(QPainter::CompositionMode_Source);
    buff.fillPath(*path,pen.brush());
    delete path;
}

bool Render::componenteFaceUnica(HalfEdge *h)
{
    QSet<QPointF> a;
    QSet<QPointF> b;
    QSet<QPointF> c;
    HalfEdge::iterator it;

    a.insert(h->getOrigem()->getPoint());
    for(it = h->f_begin(); it != h->f_end(); ++it)
    {
        a.insert(it->getOrigem()->getPoint());
    }

    b.insert(h->getTwin()->getDestino()->getPoint());
    for(it = h->getTwin()->f_begin(); it != h->getTwin()->f_end(); ++it)
    {
        b.insert(it->getDestino()->getPoint());
    }

    return ((a - b).isEmpty() || (b-a).isEmpty());
}

uint qHash(const QPointF& p)
{
    return (uint)qRound(p.x()*p.y());
}

void Render::deleta()
{
    //se hsel eh diferente de nulo, essa ARESTA esta selecionada
    //se fsel eh diferente de nulo, essa FACE esta selecionada
    //se vsel eh diferente de nulo, esse VERTICE esta selecionado

    //para verificar se a face f eh externa, use: interface.isExterna(f);


    if(hsel != NULL)
    {

        if(interface.isExterna(hsel->getFace()) || interface.isExterna(hsel->getTwin()->getFace())){
            HalfEdge *externa = hsel->getTwin(), *interna = hsel;

            if (interface.isExterna(hsel->getFace()))
            {
                externa = hsel;
                interna = hsel->getTwin();
            }

            Vertex *origem  = hsel->getOrigem();
            Vertex *destino = hsel->getDestino();

            QPair<QPointF,QPointF> par1  =
                    QPair<QPointF,QPointF>(origem->getPoint(),destino->getPoint());

            QPair<QPointF,QPointF> par2  =
                    QPair<QPointF,QPointF>(destino->getPoint(),origem->getPoint());

            interface.getMap().remove(par1);
            interface.getMap().remove(par2);

            Face * nExter = hsel->getFace();

            if(interface.isExterna(hsel->getFace()))
            {
                nExter = hsel->getTwin()->getFace();
            }

            QVector<Face *> faces = interface.getFaces();

            for(int i = 0; i < faces.size(); i++)
            {
                Face *atual = faces[i];

                if (atual == nExter)
                {
                    faces.remove(i);
                    interface.faces.remove(i);
                    break;
                }
            }


            //Atualizar a face das dentro do poligono
            HalfEdge *it = interna->getProx();

            while(it!= interna){
                it->setFace(externa->getFace());
                it = it->getProx();
            }
            //Atualizar a anterior e a proxima
            externa->getAnt()->setProx(interna->getProx());
            externa->getProx()->setAnt(interna->getAnt());

            interna->getProx()->setAnt(externa->getAnt());
            interna->getAnt()->setProx(externa->getProx());

            hsel = NULL;
            renderiza();
            renderizaFront();
        }
    }
}

void Render::vdv()
{
    QPainter buff(frontBuffer);
    QPoint p;
    HalfEdge *partida, *partida2;
    HalfEdge *prox;
    Vertex *aux;

    buff.setPen(vizinhoScreen);

    if(vsel != NULL)
        partida = vsel->getEdge();
    else
        return;

    partida2 = partida->getProx();

    prox = partida2;
    do {
        aux = prox->getDestino();
        buff.drawEllipse(transforma(aux->getPoint()),5,5);

        prox = prox->getTwin()->getProx();
    } while (prox != partida2);

    partida2 = partida->getTwin()->getProx()->getProx();

    prox = partida2;
    do {
        aux = prox->getDestino();
        buff.drawEllipse(transforma(aux->getPoint()),5,5);

        prox = prox->getTwin()->getProx();
    } while (prox != partida2);

}


void Render::switchClick(void)
{
    faceSelected = !faceSelected;
    if(!faceSelected){
        salvar("tmp.ply");
        recebeArquivo("tmp.ply");
    }
}

void Render::addFullVertex(void)
{

    QPointF point;
    QPoint click;
    QPointF start;
    QPointF end;
    QPointF first;
    HalfEdge *edge;
    QVector<QPointF> list;
    QVector<QPointF> listAntiga;

    /* get click and transforms to point */
    click.setX(sel->x());
    click.setY(sel->y());
    point = destransforma(click);

    /* get the nearest edge and his start and end */
    edge = interface.getArestaNear(point);

    /* if the current face is different from face
       form the half-edge his twin is the right one
    */
    if(edge->getFace() != interface.getFaceNear(point)){
        edge = edge->getTwin();
    }

    interface.removeFaceFromCollection(facePonto);
    /* gets the first start, the current start and the current end */
    end = edge->getDestino()->getPoint();
    first = edge->getOrigem()->getPoint();
    start = edge->getOrigem()->getPoint();

    listAntiga << end;
    listAntiga << start;

    /* adds to points to a list */
    list << start;
    list << end;
    list << point;

    facesTotais << list;
    list.clear();

    /* while doesn't arrives into the start point, keep running to the next edge */
    while(end != first)
    {
        /* get next edge */
        edge = edge->getProx();

        /* get edge data */
        start = edge->getOrigem()->getPoint();
        end = edge->getDestino()->getPoint();

        if(!listAntiga.contains(end)){
              listAntiga << end;
        }
        if(!listAntiga.contains(start)){
              listAntiga << start;
        }

        /* adds to points to a list */
        list << start;
        list << end;
        list << point;
        facesTotais << list;

        /* empty the list for a next round */
        list.clear();

    }

    for(int i=0; i<facesTotais.size(); i++){
        QVector<QPointF> tmp = facesTotais[i];
        for(int j=0; j<facesTotais[i].size(); j++){
            if(listAntiga.contains(tmp[0])){
                tmp.remove(0);

            }
        }
        if(tmp.size()==0){
            facesTotais.remove(i);
            break;
        }
    }
    interface.clear();

    for(int i=0; i<facesTotais.size(); i++){
        interface.addFace(facesTotais[i]);
    }

    salvar("tmp.ply");
    renderiza();
}

void Render::salvar(const QString &filename)
{
    ofstream arquivo;
    arquivo.open(filename.toStdString().c_str());
    arquivo << "ply\nformat ascii 1.0\ncomment triangulos apenas\nobj_info malha 2D";
    arquivo << "\nelement vertex " << interface.vertices.size();
    arquivo << "\nproperty float x\nproperty float y\nproperty float z";
    arquivo << "\nelement face " << interface.faces.size();
    arquivo << "\nproperty list uchar int vertex_indices\nend_header\n";

    QMap<QPointF, int> mapaVertices;
    for(int i=0; i<interface.vertices.size();i++){
        mapaVertices.insert(interface.vertices.keys()[i],i);
        arquivo << interface.vertices.keys()[i].x() << " ";
        arquivo << interface.vertices.keys()[i].y() << "\n";
    }

    for(int i=0; i<facesTotais.size();i++){
        arquivo<< facesTotais[i].size() << " ";
        for(int j=0; j<facesTotais[i].size();j++){
            arquivo << mapaVertices.value(facesTotais[i][j]) << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();

}
