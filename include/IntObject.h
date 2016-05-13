#ifndef INTOBJECT_H
#define INTOBJECT_H
#include "IObject.h"

class IntObject: public IObject
{
public:
    IntObject():IObject() {}; // value = std::rand() % 10; };//??????
    IntObject(int value):IObject(), value(value) {};
    ~IntObject() {};

    bool Equal(IObject *other) const;
    IObject* Clone() const;
    void ShowMe() const;

private:
    int value;
};

#endif // INTOBJECT_H
