#include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>

  struct ChCount
 {
char ch;
 int coun;
 } CharCount[128];
typedef ChCount * chcount;
//void write(chcount ChCoun);
//void prin();
 int  main()
 {
 FILE *fp;
         int j=0;
 int i;
int high=0;
 char c;
 for( i=0;i <128;i++)
 {
 CharCount[i].coun=0;
 }
 if((fp=fopen("C:\\data.txt","a+"))==NULL)
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

 for( i=0;i <j;i++)
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

 char cha;
    char coun;
 for( i=0;i <j;i++)
 {



     if((fp=fopen("D:\\data1.txt","a"))==NULL)
 {
 printf("can't open file data.txt\n");
 exit(0);
 }
  cha= CharCount[i].ch;
  coun=CharCount[i].coun+'0';
  if(cha!='\n')
  {
      fputc(cha,fp);
       fputc(':',fp);
      fputc(coun,fp);
       fputc(' ',fp);

  }
  fclose(fp);
 }
     char CH;

     if((fp=fopen("D:\\data1.txt","r"))==NULL)
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

/* void write(chcount ChCount)
 {
     FILE *fp;
     char cha;
     int coun;
     if((fp=fopen("D:\\data1.txt","a"))==NULL)
 {
 printf("can't open file data.txt\n");
 exit(0);
 }
  cha=ChCoun->ch;
  coun=ChCoun->coun;
  if(cha!='\n')
  {
      fputc(cha,fp);
      fputc(coun,fp);

  }
  fclose(fp);
 }
 void prin()
 {
     char c;
     FILE *fp;
     if((fp=fopen("D:\\data1.txt","r"))==NULL)
 {
 printf("can't open file data1.txt\n");
 exit(0);
 }

 while((c=fgetc(fp))!=EOF)
 {
    putchar(c);
 }
 fclose(fp);
 }
*/
