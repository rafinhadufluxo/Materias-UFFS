#include "Vertex.h"

inline bool operator< (const QPointF& p1, const QPointF& p2)
{
 if (p1.x() == p2.x())
        return (p1.y() < p2.y());

    return (p1.x() < p2.x());

}

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

Vertex::Vertex(QPointF p)
{
    this->p = p;
}

bool Vertex::operator== ( const Vertex &v2)const
{
    return (this->getPoint() == v2.getPoint());
}

bool Vertex::operator <(Vertex *v)const
{
    return this->p < v->getPoint();
}

void Vertex::setPoint(QPointF p)
{
    this->p = p;
}

void Vertex::setEdge(HalfEdge *hEdge)
{
    this->hEdge = hEdge;
}

QPointF Vertex::getPoint(void) const
{
    return p;
}

HalfEdge* Vertex::getEdge(void)
{
    return hEdge;
}

double Vertex::vProd(QPointF p1, QPointF p2)
{
    return (p1.x() * p2.y() - p1.y() * p2.x());
}

double Vertex::eProd(QPointF p1, QPointF p2)
{
    return (p1.x() * p2.x() + p1.y() * p2.y());
}
