#include<string.h>
#include<stdio.h>
#include <stdlib.h>

#define n 100
#define m 199

int j;
struct ChCount
{
    char ch;
    int coun;
} CharCount[128];
typedef struct
{
    char ch;
    char bits[n+1];
} Codenode;
typedef Codenode HuffmanCode;
HuffmanCode H[n];
char temp[n];
typedef struct
{
    double weight;
    int parent;
    int lchild;
    int rchild;
} HTNODE;

HTNODE  T[199];
void InitHT(HTNODE * T);
void Input(HTNODE * T);
void CreatHT(HTNODE *  T);
void SelectMin(HTNODE *  T,int s,int & p1,int & p2);
void CharSetHuffmanEncoding(HTNODE *T, HuffmanCode *H);
void prin();

int main()
{
   CreatHT(T);
   CharSetHuffmanEncoding(T, H);
   prin();
   return 0;
}

void InitHT(HTNODE * T)
{
    int i;
    for(i=0; i<2*n-1; i++)
    {
        T[i].lchild=-1;
        T[i].parent=-1;
        T[i].rchild=-1;
        T[i].weight=0;
    }
}
void Input(HTNODE * T)
{
    int k;

    FILE *fp;
     j=0;
    int i;
    int high=0;
    char c;
    for( i=0; i <128; i++)
    {
        CharCount[i].coun=0;
    }
    if((fp=fopen("input.txt","a+"))==NULL)
    {
        printf("can't open file data.txt\n");
        exit(0);
    }
    c=fgetc(fp);

    CharCount[0].ch=c;
    CharCount[0].coun=1;
    j++;
    while((c=fgetc(fp))!=EOF)
    {

        for( i=0; i <j; i++)
        {
            if(c==CharCount[i].ch)
            {
                CharCount[i].coun++;
                high=1;
                break;
            }
            else
                high=0;
        }

        if(!high)
        {
            CharCount[j].ch=c;
            CharCount[j].coun++;
            j++;
        }


    }
    fclose(fp);
    for(k=0; k<j; k++)
    {
        i=0;
        T[k].weight= CharCount[i].coun;
        i++;

    }


}

void CreatHT(HTNODE *  T)
{
    int i,p1,p2;
    InitHT(T);
    Input(T);
    for(i=j; i<2*j-1; i++)
    {
        SelectMin(T,i-1,p1,p2);

        T[p1].parent=T[p2].parent=i;
        T[i].lchild=p1;
        T[i].rchild=p2;
        T[i].weight=T[p1].weight+T[p2].weight;
    }
}

void SelectMin(HTNODE *  T, int s, int &p1, int &p2)
{
    int i,k;
    for(i=0; i<=s; i++)
        if(T[i].parent == -1)
        {
            p1 = i;
            break;
        }
    for(k=i+1; k <= j; k++)
        if(T[k].parent == -1)
        {
            p2 = j;
            break;
        }
    for(i =0; i <= j; i++)
        if((T[p1].weight > T[i].weight) && (T[i].parent == -1)&& (p2 != i))
            p1=i;
    for(k= 0; k<=j; k++)
        if((T[p2].weight > T[k].weight) && (T[k].parent == -1)&& (p1 != j))
            p2=j;
}

void CharSetHuffmanEncoding(HTNODE *T, HuffmanCode *H)
{
    int c, p, i;
    char cd[j+1];
    int start;
    cd[j]='\0';
    for( i =0; i <j; i++)
    {
        H[i].ch=CharCount[i].ch;
        start=j;
        c =i;
        while( (p=T[c].parent)>=0)
        {
            cd[--start]=(T[p].lchild==c)? '0' : '1';
            c=p;
        }
        strcpy(H[i].bits,&cd[start]);
    }
}
void prin()
{
    int i;
    char cha;
    char coun[n+1];
    FILE *fp;
    for( i=0; i <j; i++)
    {



        if((fp=fopen("output.txt","a"))==NULL)
        {
            printf("can't open file data.txt\n");
            exit(0);
        }
        cha= CharCount[i].ch;
        strcpy(coun,H[i].bits);
        if(cha!='\n')
        {
            fputc(cha,fp);
            fputc(':',fp);
            fputc(*coun,fp);
            fputc(' ',fp);

        }
        fclose(fp);
    }
    char CH;

    if((fp=fopen("output.txt","r"))==NULL)
    {
        printf("can't open file data1.txt\n");
        exit(0);
    }

    while((CH=fgetc(fp))!=EOF)
    {
        putchar(CH);
    }
    fclose(fp);
}
