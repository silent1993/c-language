#include <stdio.h>
#include <stdlib.h>

struct polynode
{
    double coef;
    int exf;
    polynode *link;

};
typedef polynode *polypointer;


polypointer Insert (double c,int e,polypointer d)
{
    polypointer x;
    x=new polynode;
    x->coef=c;
    x->exf=e;
    x->link=NULL;
    d->link=x;
    return x;
}

polypointer PolyAdd(polypointer a,polypointer b)
{
    polypointer p,q,d,c;
    p=a;
    q=b;
    c=new polynode;
    d=c;
    int co;
    co=(p->exf)-(q->exf);
    while((p!=NULL)&&(q!=NULL))
        switch(co)
        {
        case'0':
            x=p->coef+q->coef;
            if(x!=0)
                d=Insert(x,p->exp,d);

            p=p->link;
            q=q->link;
            break;
        case '>0':
            d=Insert(p->coef,q->exf,d);
            p=p->link;
            break;
        case '<0':
            d=Insert(q->coef,q->exf,d);
            q=q->link;
            break;


        }
        while(p!=NULL)
        {
            d=Insert(p->coef,p->exf,d);
            p=p->link;
        }
        while(q!=NULL)
        {
            d=Insert(q->coef,q->exf,d);
            q=q->link;
        }
        p=c;
        c=c->link;
        delete p;
        return c;
}
int main()
{
    return 0;
}
