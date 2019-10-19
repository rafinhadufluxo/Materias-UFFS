#ifndef HALFEDGE_H
#define HALFEDGE_H

#include <QPoint>
#include <QObject>
#include "Vertex.h"

class Face;

class HalfEdge : public QObject
{
    Q_OBJECT
public:
    HalfEdge();
    virtual ~HalfEdge();

void setOrigem(Vertex *v);
void setOrigem(QPoint *p);
void setFace(Face *f);
void setTwin(HalfEdge *twin);
void setProx(HalfEdge *prox);
void setAnt(HalfEdge *ant);
Vertex*   getOrigem(void);
Vertex*   getDestino(void);
Face*     getFace(void);
HalfEdge* getTwin(void);
HalfEdge* getProx(void);
HalfEdge* getAnt(void);
bool operator==(HalfEdge& );
bool operator!=(HalfEdge& );
//HalfEdge* self(void);


    class Iterator
    {
    private:


    public:
        enum Modo{Vertice,Face};
        Iterator();
        Iterator(const Iterator& i);
        Iterator(HalfEdge *atual, Modo modo);
        Iterator& operator++(int i);
        Iterator& operator++();
        HalfEdge* operator->();
        Iterator& operator=(const Iterator& i);
        bool operator==(const Iterator& i)const;
        bool operator!=(const Iterator& i)const;
        HalfEdge& operator*()const;
        HalfEdge* operator&();


        HalfEdge* atual;
        Modo modo;

    };

    typedef HalfEdge::Iterator iterator;
    iterator v_begin();
    iterator v_end();
    iterator f_begin();
    iterator f_end();

private:
    Vertex *origem;
    Face *f;
    HalfEdge *twin, *prox, *ant;

};

#endif // HALFEDGE_H
