#include "StringObject.h"
#include <iostream>

bool StringObject::Equal(IObject * other) const
{
    StringObject *pint = dynamic_cast<StringObject*>(other);
    if (this->value == pint->value)
        return true;
    return false;
}
IObject* StringObject::Clone() const
{
    IObject* temp = new StringObject(this->value);
    return temp;
}
void StringObject::ShowMe() const
{
    std::cout<<"I`m STRING and my value is \"" << value <<"\""<< std::endl;
}
