#ifndef VERTEX_H
#define VERTEX_H

#include <QPoint>
#include <QObject>

class HalfEdge;

class Vertex : public QObject
{
    Q_OBJECT
public:
    Vertex();
    virtual ~Vertex();
    Vertex(QPointF p);

    bool operator==( const Vertex &v2)const;
    bool operator< (Vertex *v)const;
    void setEdge(HalfEdge *hEdge);
    void setPoint(QPointF p);
    QPointF getPoint(void) const;
    HalfEdge* getEdge(void);

    double vProd(QPointF p1, QPointF p2);
    double eProd(QPointF p1, QPointF p2);

   private:
    QPointF p;
    HalfEdge *hEdge;

};

inline bool operator< (const QPointF& p1, const QPointF& p2);

#endif // VERTEX_H
