#include "TpSet.h"
#include "IObject.h"
#include "IntObject.h"

TpSet::TpSet():currentSize(0),maxSize(BUF_LENGTH)
{
    try
    {
        buf = new IObject*[maxSize];
        for (int i = 0; i < maxSize; i++)
            buf[i] = nullptr;
    }
    catch(std::bad_alloc)
    {
        std::cout << "Ошибка выделения памяти"<<std::endl;
        throw;
    }
}
TpSet::TpSet(const TpSet& other)
{
    try
    {
        this->maxSize = other.maxSize;
        this->currentSize = other.currentSize;
        this->buf = new IObject*[this->maxSize];
        for (int i = 0; i < this->currentSize; i++)
            this->buf[i] = other.buf[i]->Clone();
    }
    catch(...)
    {
        std::cout << "Ошибка копирования"<<std::endl;
        throw;
    }

}

TpSet::~TpSet()
{
    for (int i = 0; i < currentSize; i++)
        delete buf[i];
    delete [] buf;
}

bool TpSet::InSet(IObject* value) const
{
    for (int i = 0; i < currentSize; i++)
    {
        bool check = buf[i]->Equal(value);
        if (check)
            return true;
    }
    return false;
}
void TpSet::PushBack(IObject* value)
{
    if (!InSet(value))
    {
        currentSize++;
        if (currentSize > maxSize)
            AddSize();

        this->buf[currentSize-1] = value->Clone();
    }
    /* else
     {
         std::cout<< "Такой элемент уже существует"<<std::endl;
     }*/

}
void TpSet::Pop(IObject* value)
{
    if (!InSet(value))
    {
        //std::cout<<"not in set"<< std::endl; //throw notInSet;
        return;
    }

    int offset = 0;
    for (int i = 0; i < this->currentSize; i++)
    {
        if (this->buf[i]->Equal(value))
        {
            offset++;
            delete buf[i];
            continue;
        }
        buf[i - offset] = this->buf[i];
    }

    this->currentSize--;


}
void TpSet::ShowSet() const
{
    if (!currentSize)
    {
        std::cout<<"Пустое множество"<< std::endl;
        return;
    }
    for (int i = 0; i < currentSize; i++)
        buf[i]->ShowMe();
}

TpSet& TpSet::operator = (const TpSet& set1)
{
    for (int i = 0; i < this->currentSize; i++)
        delete buf[i];
    delete [] buf;
    this->currentSize = set1.currentSize;
    this->maxSize = set1.maxSize;
    this->buf = new IObject*[this->maxSize];
    for (int i = 0; i < currentSize; i++)
    {
        this->buf[i] = set1.buf[i];
    }

    return *this;
}
void TpSet::AddSize()
{
    try
    {
        //throw std::bad_alloc();
        IObject **temp = new IObject*[this->maxSize+bufLength];
        for (int i = 0; i < this->maxSize; i++)
        {
            temp[i] = this->buf[i]->Clone();
            delete this->buf[i];
        }
        delete [] this->buf;
        this->buf = temp;


        this->maxSize+=bufLength;
    }

    catch (std::bad_alloc)
    {
        std::cout << "Ошибка выделения памяти"<<std::endl; //exit(1)
        throw;
    }
    catch (...)
    {
        std::cout << "Что-то пошло не так"<<std::endl;
        throw;
    }
    //std::bad_alloc &
    //TODO catch
}
TpSet TpSet::operator + (const TpSet& set1) const
{
    TpSet temp(*this);
    for (int i = 0; i < set1.currentSize; i++)
    {
        if (!InSet(set1.buf[i])) {}
        temp.PushBack(set1.buf[i]);
    }
    return temp;
}
TpSet TpSet::operator * (const TpSet &set1) const
{

    TpSet temp(*this);
    for (int i = 0; i < currentSize; i++)
    {
        if (!set1.InSet(buf[i]))
            temp.Pop(buf[i]);
    }
    return temp;
}
TpSet TpSet::operator - (const TpSet& set1) const
{
    TpSet result (*this);

    TpSet a = *this * set1;
    for (int i = 0; i < a.currentSize; i++)
        result.Pop (a.buf[i]);

    return result;
}
TpSet TpSet::operator ^ (const TpSet& set1) const
{
    TpSet result;
    TpSet a = *this + set1;
    TpSet b = *this * set1;
    //result = (a - b);//.ShowSet();
    //result.ShowSet();
    return (a-b);
}






















