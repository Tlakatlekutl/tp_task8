#include "DoubleObject.h"
#include <iostream>

bool DoubleObject::Equal(IObject * other) const
{
    DoubleObject *pint = dynamic_cast<DoubleObject*>(other);
    if (this->value == pint->value)
        return true;
    return false;
}
IObject* DoubleObject::Clone() const
{
    IObject* temp = new DoubleObject(this->value);
    return temp;
}
void DoubleObject::ShowMe() const
{
    std::cout<<"I`m DOUBLE and my value is " << value << std::endl;
}
