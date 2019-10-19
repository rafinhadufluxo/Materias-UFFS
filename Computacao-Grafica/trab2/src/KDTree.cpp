#include "KDTree.h"
#include <QtAlgorithms>

KDTree::KDTree(const QList<HalfEdge *> &list, QRectF limite)
{
return;
    if(list.size() > 0)
    {
        raiz = divide(new QList<HalfEdge *>(list), limite, true);
    }else
        raiz = NULL;
    qsrand(0);
}

KDTree::~KDTree(){}

NO* KDTree::divide(QList<HalfEdge *> *list, QRectF limite, bool primeiro)
{
    NO *no;
    double v;
    QRectF retE(limite);
    QRectF retD(limite);
    QList<HalfEdge *> *esq = new QList<HalfEdge *>();
    QList<HalfEdge *> *dir = new QList<HalfEdge *>();
    if(primeiro)
        qDebug() << "Dividir em x";
    else
        qDebug() << "Dividir em y";

    v = pivoteia(list, limite, primeiro, esq, dir);

    qDebug() << "P1";

    if(esq->size() == 0 || dir->size() == 0 || (esq->size() == list->size() && dir->size() == list->size()))
    {
        delete esq;
        delete dir;
        return NULL;
    }

    qDebug() << "P2";

    no = new NO();
    no->chave = v;

    if(primeiro)
    {
        retE.setRight(v);
        retD.setLeft(v);
    }else
    {
        retE.setTop(v);
        retD.setBottom(v);
    }

    qDebug() << "P3";

    no->esq = divide(esq, retE, !primeiro);
    qDebug() << "P4";
    no->dir = divide(dir, retD, !primeiro);
    qDebug() << "P5";

    if(no->esq == NULL && no->dir == NULL)
    {
        delete esq;
        delete dir;
        no->lista = list;
    }else if(no->esq == NULL)
    {
        delete list;
        no->lista = esq;
    }else if(no->dir == NULL)
    {
        delete list;
        no->lista = dir;
    }else
    {
        delete list;
    }
    qDebug() << "P6";

    return no;

}

double KDTree::pivoteia(QList<HalfEdge *> *list, QRectF limite, bool primeiro, QList<HalfEdge *> *men, QList<HalfEdge *> *mai)
{
    int it;
    double corte;
    QPoint p1, p2;
    HalfEdge *i;

    qDebug() << "U1";

    if(primeiro)
    {
        corte = (double)qrand()/(double)RAND_MAX;
        corte = corte * (limite.right() - limite.left()) + limite.left();
    }else
    {
        corte = (double)qrand()/(double)RAND_MAX;
        corte = corte * (limite.bottom() - limite.top()) + limite.top();
    }

    qDebug() << "reg" << limite << " corte " << corte;

    qDebug() << "U2";

    if(primeiro)
    {
        p1.setX(corte);
        p2.setX(corte);
        p1.setY(limite.top());
        p2.setY(limite.bottom());
    }else
    {
        p1.setY(corte);
        p2.setY(corte);
        p1.setX(limite.left());
        p2.setX(limite.right());
    }

    qDebug() << "U3";

    for(it = 0; it < list->size(); ++it)
    {
        i = list->at(it);
        if(cruza(QLineF(p1,p2), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint())))
        {
            men->push_back(i);
            mai->push_back(i);
        }else if(primeiro)
        {
            if((cruza(QLineF(limite.bottomLeft(),limite.topLeft()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint()))
            ||  cruza(QLineF(p1,limite.topLeft()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint()))
            ||  cruza(QLineF(p2,limite.bottomLeft()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint()))) ||
               (i->getOrigem()->getPoint().x() >= limite.left() && i->getOrigem()->getPoint().x() <= corte &&
                i->getOrigem()->getPoint().y() <= limite.top() && i->getOrigem()->getPoint().y() >= limite.bottom()))
                men->push_back(i);
            else
                mai->push_back(i);
        }else
        {
            if((cruza(QLineF(limite.bottomLeft(),limite.bottomRight()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint()))
            ||  cruza(QLineF(p1,limite.bottomLeft()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint()))
            ||  cruza(QLineF(p2,limite.bottomRight()), QLineF(i->getOrigem()->getPoint() , i->getDestino()->getPoint())) ) ||
                (i->getOrigem()->getPoint().x() >= limite.left() && i->getOrigem()->getPoint().x() <= limite.right() &&
                i->getOrigem()->getPoint().y() <= corte && i->getOrigem()->getPoint().y() >= limite.bottom()))
                men->push_back(i);
            else
                mai->push_back(i);
        }
        qDebug() << "U4";
    }

    qDebug() << "U5";

    return corte;

}

bool KDTree::cruza(const QLineF &v, const QLineF &u)
{
    QPointF p = v.p1();
    QPointF q = v.p2();

    QPointF r = u.p1();
    QPointF s = u.p2();

   double a = vProd(p-r, q-r);
   double b = vProd(p-s, q-s);
   double c = vProd(r-p, s-p);
   double d = vProd(r-q, s-q);

   if (a*b < 0 && c*d < 0) return true;

   if (NAO(a) && eProd(p-r, q-r)<= 0) return true;
   if (NAO(b) && eProd(p-s, q-s)<= 0) return true;
   if (NAO(c) && eProd(r-p, s-p)<= 0) return true;
   if (NAO(d) && eProd(r-q, s-q)<= 0) return true;

    return false;
}

QList<HalfEdge *>* KDTree::find(const QPointF &p)
{
    return busca(p, raiz,true);
}

QList<HalfEdge *>* KDTree::busca(const QPointF &p, NO* no,bool primeiro)
{

    if(primeiro)
    {
        if(p.x() < no->chave)
        {
            if(no->esq == NULL)
                return no->lista;
            else
                return busca(p,no->esq,!primeiro);
        }else
        {
            if(no->dir == NULL)
                return no->lista;
            else
                return busca(p,no->dir,!primeiro);
        }
    }else
    {
        if(p.y() > no->chave)
        {
            if(no->esq == NULL)
                return no->lista;
            else
                return busca(p,no->esq,!primeiro);
        }else
        {
            if(no->dir == NULL)
                return no->lista;
            else
                return busca(p,no->dir,!primeiro);
        }
    }
}

void KDTree::limpa(NO* no)
{
    if(no->esq != NULL)
        limpa(no->esq);
    if(no->dir != NULL)
        limpa(no->dir);

    if(no->lista != NULL)
    {
        delete no->lista;
    }

    delete no;
}

bool operator<(const SORTEADOR& s1, const SORTEADOR& s2){ return s1.val < s2.val; }

double KDTree::vProd(QPointF p1, QPointF p2)
{
    return (p1.x() * p2.y() - p1.y() * p2.x());
}

double KDTree::eProd(QPointF p1, QPointF p2)
{
    return (p1.x() * p2.x() + p1.y() * p2.y());
}

