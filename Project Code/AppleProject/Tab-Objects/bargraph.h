#ifndef BARGRAPH_H
#define BARGRAPH_H

#include "Tab-Objects/tabobserver.h"

class TabSubject;

class BarGraph:public TabObserver
{
public:
    BarGraph(TabSubject *s);
};

#endif // BARGRAPH_H
