#include <HalfEdge.h>

HalfEdge::HalfEdge()
{
    this->prox = NULL;
    this->twin = NULL;
    this->ant = NULL;
    this->f = NULL;
    this->origem = NULL;
}

HalfEdge::~HalfEdge()
{
}

void HalfEdge::setOrigem(Vertex *v)
{
    this->origem = v;
}

void HalfEdge::setFace(Face *f)
{
    this->f = f;
}

void HalfEdge::setTwin(HalfEdge *twin)
{
    this->twin = twin;
}

void HalfEdge::setProx(HalfEdge *prox)
{
    this->prox = prox;
}

void HalfEdge::setAnt(HalfEdge *ant)
{
    this->ant = ant;
}

Vertex* HalfEdge::getOrigem(void)
{
    return this->origem;
}

Vertex* HalfEdge::getDestino(void)
{
    return this->getProx()->getOrigem();
}

Face* HalfEdge::getFace(void)
{
    return this->f;
}

HalfEdge* HalfEdge::getAnt(void)
{
    return this->ant;
}

HalfEdge* HalfEdge::getProx(void)
{
    return this->prox;
}

HalfEdge* HalfEdge::getTwin(void)
{
    return this->twin;
}

bool HalfEdge::operator==(HalfEdge& e)
{
    if(this->origem == e.getOrigem() && this->ant == e.ant && this->prox == e.prox &&
       this->twin == e.getTwin() && this->f == e.getFace())
        return true;


    if(this->origem == NULL || this->prox == NULL || e.getProx() == NULL || e.getOrigem() == NULL)
        return false;

    if(this->prox->getOrigem() == NULL || e.getProx()->getOrigem())
        return false;

    HalfEdge* t = this->getProx();
    HalfEdge* p = e.getProx();
    Vertex *v1 = this->getOrigem();
    Vertex *v2 = e.getOrigem();
    Vertex *u1 = t->getOrigem();
    Vertex *u2 = p->getOrigem();

    return ((*v1 == *v2) && (*u1 == *u2));
}

bool HalfEdge::operator!=(HalfEdge& e)
{
    return !(this->operator ==(e));
}

HalfEdge::iterator HalfEdge::v_begin()
{
    return Iterator(this->getTwin()->getProx(), Iterator::Vertice);
}
HalfEdge::iterator HalfEdge::v_end()
{
    return Iterator(this, Iterator::Vertice);
}
HalfEdge::iterator HalfEdge::f_begin()
{
    return Iterator(this->getProx(), Iterator::Face);
}
HalfEdge::iterator HalfEdge::f_end()
{
    return Iterator(this, Iterator::Face);
}


// Iterator
HalfEdge::Iterator::Iterator(const HalfEdge::Iterator &i)
{
    this->atual = i.atual;
    this->modo =  i.modo;
}
HalfEdge::Iterator::Iterator()
{
    this->atual = NULL;
}
HalfEdge::Iterator::Iterator(HalfEdge *atual, HalfEdge::Iterator::Modo modo)
{
    this->atual = atual;
    this->modo =  modo;
}
HalfEdge::Iterator& HalfEdge::Iterator::operator++(int i)
{
    HalfEdge::Iterator it(*this);
    ++(*this);
    return it;
}

HalfEdge::Iterator& HalfEdge::Iterator::operator++()
{

    if(modo == HalfEdge::Iterator::Face)
        atual = atual->getProx();

    if(modo == HalfEdge::Iterator::Vertice){
        atual =atual->getTwin()->getProx();

    }

    return *this;
}
HalfEdge* HalfEdge::Iterator::operator&()
{
    return this->atual;
}
HalfEdge* HalfEdge::Iterator::operator->()
{
    return this->atual;
}
HalfEdge::Iterator& HalfEdge::Iterator::operator=(const HalfEdge::Iterator& i)
{
    this->atual = i.atual;
    this->modo = i.modo;

    return *this;
}
bool HalfEdge::Iterator::operator==(const HalfEdge::Iterator& i)const
{
    if(modo != i.modo)
        return false;

    if(atual == i.atual)
        return true;

    if(atual == NULL || i.atual == NULL)
        return false;

    return (*atual == *(i.atual));
}
bool HalfEdge::Iterator::operator!=(const HalfEdge::Iterator& i)const
{
    if(modo != i.modo)
        return true;

    if(atual == i.atual)
        return false;

    return (*atual != *(i.atual));
}
HalfEdge& HalfEdge::Iterator::operator*()const
{
    HalfEdge e;
    if(atual == NULL)
           return e;

    return *atual;
}

