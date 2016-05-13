#ifndef IOBJECT_H
#define IOBJECT_H


class IObject
{
public:
    IObject();
    virtual ~IObject(); //=0 ????
    virtual bool Equal(IObject*) const = 0;
    virtual IObject* Clone() const = 0;
    virtual void ShowMe() const = 0;

protected:

private:
};

#endif // IOBJECT_H
