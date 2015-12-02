#include "tabobserver.h"

TabObserver::TabObserver(TabSubject *s)
{
    subject = s;
    this->subject->attach(this);
}

