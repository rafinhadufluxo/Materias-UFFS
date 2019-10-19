#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMap>
#include <QPair>
#include "Vertex.h"
#include "HalfEdge.h"
#include "Face.h"
#include "KDTree.h"

#define EXTERNA NULL
#define INF 0x3F3F3F3F
#define MIN(a,b) ((a < b)?(a):(b))
#define MAX(a,b) ((a > b)?(a):(b))

class Interface : public QObject
{
    Q_OBJECT
public:
    Interface();

HalfEdge* findTwin(QPointF u,QPointF v);
void addFace(QVector<QPointF> in);
void addExtEdges(void);
double getMaxX(void){ return maxX; }
double getMaxY(void){ return maxY; }
double getMinX(void){ return minX; }
double getMinY(void){ return minY; }
QList<QPair<QPointF, QPointF> > getTodasArestas();
HalfEdge* getArestaNear(QPointF p);
Face* getFaceNear(QPointF p);
Vertex* getVerticeNear(QPointF p);
bool isExterna(Face* f);
QVector<HalfEdge* > componentesFaceExterna;
void clear(void);

QMap<QPair<QPointF,QPointF>, HalfEdge *>& getMap();
QVector<Face*>& getFaces();


void removeFaceFromCollection(Face*);
void removeEdgeFromCollection(HalfEdge*);


public:
    KDTree *kdt;
    QVector<Face*> faces;
    QMap<QPair<QPointF,QPointF>, HalfEdge *> map;
    QMap<QPointF, Vertex*> vertices;
    double minX, minY, maxX, maxY;
    Face *faceExterna;


    Vertex* addVertex(QPointF p);
    void adicionaface(HalfEdge* e, Face* f);
    bool dentroFace(HalfEdge* h, QPointF p);
    double vProd(QPointF p1, QPointF p2);
    double eProd(QPointF p1, QPointF p2);
    double modulo2(QPointF p1, QPointF p2);

};

#endif // INTERFACE_H
