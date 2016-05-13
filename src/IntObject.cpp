#include "IntObject.h"
#include <iostream>

bool IntObject::Equal(IObject * other) const
{
    IntObject *pint = dynamic_cast<IntObject*>(other);
    if (this->value == pint->value)
        return true;
    return false;
}
IObject* IntObject::Clone() const
{
    IObject* temp = new IntObject(this->value);
    return temp;
}
void IntObject::ShowMe() const
{
    std::cout<<"I`m INT and my value is " << value << std::endl;
}
