#ifndef KDTREE_H
#define KDTREE_H

#include <QObject>
#include <QPointF>
#include "HalfEdge.h"
#include <QRect>
#include <QLineF>
#include <QDebug>
#include <cmath>

#define NAO(a) (((fabs(a)) < 0.0000000001)?(1):(0))

typedef struct _NO
{
    double chave;
    _NO *esq;
    _NO *dir;
    QList<HalfEdge*> *lista;
}NO;

typedef struct _SORTEADOR
{
    double val;
    int ind;
}SORTEADOR;

class KDTree : QObject
{
    Q_OBJECT

private:
    NO *raiz;

    NO* divide(QList<HalfEdge *> *list, QRectF limite, bool primeiro);
    double pivoteia(QList<HalfEdge *> *list, QRectF limite, bool primeiro, QList<HalfEdge *> *men, QList<HalfEdge *> *mai);
    bool cruza(const QLineF &v, const QLineF &u);
    QList<HalfEdge *>* busca(const QPointF &p, NO* no,bool primeiro);
    void limpa(NO*);

    double vProd(QPointF p1, QPointF p2);
    double eProd(QPointF p1, QPointF p2);

public:
    KDTree(const QList<HalfEdge *> &list, QRectF limite);
    virtual ~KDTree();
    QList<HalfEdge *> *find(const QPointF &p);
};

bool operator<(const SORTEADOR& s1, const SORTEADOR& s2);

#endif // KDTREE_H
