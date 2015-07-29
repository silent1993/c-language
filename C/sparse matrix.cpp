#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
typedef struct
{
    int r,c;
    int v;

}Triple;
typedef struct{
    Triple data[MAXSIZE+1];
    int rows,cols ;
    int terms;
}TSMatrix;


void TSM_input(TSMatrix & s);
void TSM_output(TSMatrix s);

TSMatrix TSM_trans(TSMatrix s);

int main()
{
    TSMatrix S,D;
    TSM_input(S);
    TSM_output(S);
    printf("after trans");
    D=TSM_trans(S);
    TSM_trans(D);
}
void TSM_input(TSMatrix & s)
{

    int i;
    printf("�����������\n");
    scanf("%d",&s.rows);
    printf("��������\n");
    scanf("%d",&s.cols);
    printf("�������Ԫ�ظ���\n");
    scanf("%d",&s.terms);
    for(i=0;i<s.terms;i++)
    {
        printf("�������Ԫ����Ϣ\n");
        scanf("%d",&s.data[i].c);
        scanf("%d",&s.data[i].r);
        scanf("%d",&s.data[i].v);
    }

}

void TSM_output(TSMatrix s)
{
    int i;
    printf("ϡ���������\t%d������\t%d\n",s.rows,s.cols);
    printf("ϡ��������Ԫ��Ϊ��");
    for(i=0;i<s.terms;i++)
    {
        printf("��%d����Ԫ��Ϊ��",i+1);
        printf("%d",s.data[i].v);
    }


}

TSMatrix TSM_trans(TSMatrix s)
{
    TSMatrix d;
    int i,k;
    d.terms=s.terms;
    d.cols=s.rows;
    d.rows=s.cols;
    for(i=0,k=0;i<s.terms;i++,k++)
    {
         d.data[k].c=s.data[k].r;
         d.data[k].r=s.data[k].c;
         d.data[k].v=s.data[k].v;

    }
    return d;
}
