#ifndef TPSET_H
#define TPSET_H

#include <iostream>
#include "IObject.h"
#define BUF_LENGTH 5

class TpSet
{
public:
    TpSet();//:currentSize(0),maxSize(BUF_LENGTH){};
    TpSet(const TpSet& other);
    virtual ~TpSet();

    bool InSet(IObject* value) const;
    void PushBack(IObject* value);
    void Pop(IObject* value);
    void ShowSet() const;

    TpSet& operator = (const TpSet& set1);
    TpSet operator + (const TpSet& set1) const;
    TpSet operator * (const TpSet& set1) const;
    TpSet operator - (const TpSet& set1) const;
    TpSet operator ^ (const TpSet& set1) const;

    class notInSet;

private:
    IObject **buf;
    int maxSize;
    int currentSize;
    const int bufLength = BUF_LENGTH; //??????
    void AddSize();
};

#endif // TPSET_H
