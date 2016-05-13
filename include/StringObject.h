#ifndef STRINGOBJECT_H
#define STRINGOBJECT_H
#include <string>

#include "IObject.h"
class StringObject: public IObject
{
public:
    StringObject():IObject() { };
    StringObject(std::string val):IObject(),value(val) {};
    ~StringObject() {};

    bool Equal(IObject *other) const;
    IObject* Clone() const;
    void ShowMe() const;

private:
    std::string value;
};

#endif // STRINGOBJECT_H
