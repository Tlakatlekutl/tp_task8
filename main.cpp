#include <iostream>
#include "TpSet.h"
#include "IObject.h"
#include "IntObject.h"
#include "DoubleObject.h"
#include "StringObject.h"

using namespace std;

int main()
{
    try
    {

        /*
            IObject* a = new Object(1);
            IObject* b = new IntObject(2);
            IObject* c = new IntObject(3);
            IObject* d = new IntObject(4);
            IObject* e = new IntObject(5);*/

        /*
         IObject* a = new DoubleObject(1.1);
         IObject* b = new DoubleObject(2.2);
         IObject* c = new DoubleObject(3.3);
         IObject* d = new DoubleObject(4.4);
         IObject* e = new DoubleObject(5.4);*/


        IObject* a = new StringObject("aaa");
        IObject* b = new StringObject("bbb");
        IObject* c = new StringObject("ccc");
        IObject* d = new StringObject("ddd");
        IObject* e = new StringObject("fff");

        TpSet ts;
        ts.PushBack(a);
        ts.PushBack(b);
        ts.PushBack(c);
        ts.Pop(nullptr);
        ts.ShowSet();

        TpSet ots;

        ots.PushBack(c);
        ots.PushBack(d);
        ots.PushBack(e);
        ots.ShowSet();
        cout<<"------"<<endl;
        TpSet result = ots-ts;
        result.ShowSet();
        cout<<"------"<<endl;
        TpSet result2 = ts*ots;
        result2.ShowSet();

        cout<<"------"<<endl;
        TpSet result3 = ts-ots;
        result3.ShowSet();


        cout<<"------"<<endl;
        TpSet result4 = ts^ots;
        result4.ShowSet();

        delete a;
        delete b;
        delete c;
        delete d;
        delete e;

        return 0;
    }
    catch(...)
    {
        cout<<"что-то пошло не так" <<endl;
    }
}
