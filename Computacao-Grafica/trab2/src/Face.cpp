#include "Face.h"

Face::Face()
{

}

Face::~Face()
{
}

void Face::setOuterComp(HalfEdge *e)
{
    this->outerComp = e;
}

HalfEdge* Face::getOuterComp(void)
{
    return this->outerComp;
}
