/* 
 * File:   PlyParser.h
 * Author: thiago
 *
 * Created on 25 de Setembro de 2010, 14:36
 */

#ifndef _PLYPARSER_H
#define	_PLYPARSER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QPointF>


class PlyParser : public QObject
{
    Q_OBJECT
public:
    PlyParser(const QString&);
    virtual ~PlyParser();
    
    QVector<QPointF> proximo();
    int getNFaces(void);
    
private:
    bool semPalavras(QString s);
    int nVertices;
    int nFaces;
    QVector<QPointF> pontos;
    QVector<QVector<int> > faces;
    int indice;
        
};

#endif	/* _COMMANDQUEUE_H */

