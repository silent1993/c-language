#include <stdio.h>
#include <stdlib.h>
struct mylist {
    int n;
    struct mylist *next;
};

typedef struct mylist LIST;

typedef struct mylist *List;

void Insert(int x,List &r)
 { num++;
    LIST *p ;
    p=(LIST*)malloc(sizeof(LIST));
    p->n=x;struct mylist {
    int n;
    struct mylist *next;
};

typedef struct mylist LIST;

typedef struct mylist *List;
    if(r->next== NULL) {
        p->next=p;
        r=p;

    } else {
        p->next=r->next;
        r->next=p;
    }
    r=r->next;
    return;
}

void out(List r) {
    LIST *p ;
    if(r==NULL) {
        printf("empty");

    } else {
        //printf("%d",r->next->n);void Insert(int x,List &r)
 {
    LIST *p ;
    p=(LIST*)malloc(sizeof(LIST));
    p->n=x;
    if(r->next== NULL) {
        p->next=p;
        r=p;

    } else {
        p->next=r->next;
        r->next=p;
    }
    r=r->next;
    return;
}

void out(List r) {
    LIST *p ;
    if(r==NULL) {
        printf("empty");

    } else {
        //printf("%d",r->next->n);
        LIST* q;
        q = r->next; num++;
        p=r;
        p->next=q->next;
		free(q);
    }
}
        LIST* q;
        q = r->next;
        p=r;
        p->next=q->next;
		free(q);
    }
}

void PrintList(List r) {
    LIST* p = r->next;
    while(p != r) {
        printf("%d\n", p->n);
        p = p->next;
    }
    printf("%d\n",r->n);
    return;
}

int main() {
    int k,b;
    LIST *r;
    r= (LIST*)malloc(sizeof(LIST));
    r->next=NULL;
    r->n=0;
    int i;
    LIST *p, *q;
    p = r;
    for( i = 1; i <= 10; i++) {
        q = (LIST *)malloc(sizeof(LIST));
        q->n = i;
        q->next = NULL;
        p->next = q;
        p = q;
    }
    //q = p;
    p->next=r->next;
    r=p;
    printf("r = %d\n",(r->n));
    PrintList( r);
    printf("if you want to in 1,if 2\n");
    scanf("%d",&k);
    if(k==1) {
        out(r);
        printf("\n\n");
        PrintList( r);
    }
    if(k==2) {
        scanf("%d",&b);
        Insert(b,r);
        PrintList( r);
    }

    return 0;
}
