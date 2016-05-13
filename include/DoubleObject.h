#ifndef DOUBLEOBJECT_H
#define DOUBLEOBJECT_H

#include "IObject.h"
class DoubleObject: public IObject
{
public:
    DoubleObject():IObject() {};
    DoubleObject(double value):IObject(),value(value) {};
    ~DoubleObject() {};

    bool Equal(IObject *other) const;
    IObject* Clone() const;
    void ShowMe() const;

private:
    double value;
};

#endif // DOUBLEOBJECT_H
