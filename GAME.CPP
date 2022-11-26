#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<C:\TC\BIN\win.h> //header fill of graph() function
#include<C:\TC\BIN\gstart.h>//main page
main()
{
openg();
re:
int gd=DETECT,gm,error;//graph variable
int i,j;  //loop variable
int r,t;  //for gotoxy (string mover)
int m=3,n=3,o=3,p=3;  //move by keys variable
int ab[4][4],aci[4][4],com,no;//compare variable
initgraph(&gd,&gm,"C:\\TC\\BGI");//graph initialization
error=graphresult();
if(error!=grOk)
{
printf("%s",grapherrormsg(error));
}
int max=16,min=1,result,diff;//rand variable
int a[15];             //rand array
char as[4][4][3],key,tem[3];//convert string array&& key(key && temp)
int de=0;     //convert in string variable as default for use whole program
//rand
srand(time(0));
diff=max-min;
for(i=0;i<15;i++)
{
a:
result=rand()%diff;
a[i]=result+min;
for(j=0;j<i;j++)
{
if(a[i]==a[j])
{
j--;
goto a;
}
}
}
//2d STRING
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(i==3&&j==3)
{
strcpy(as[i][j]," ");
}
else
{
sprintf(as[i][j],"%d",a[de]);
de++;
}
}
}
c:	    //key lable
setcolor(BLACK);
setfillstyle(1,GREEN);
rectangle(0,0,638,478);
floodfill(10,10,GREEN);
setcolor(WHITE);
rectangle(3,3,635,475);
rectangle(8,8,630,470);
//header
line(8,90,630,90);
settextstyle(7,0,5);
setcolor(RED);
outtextxy(130,10,"SERIAL-NUMBER");
//user score
setcolor(RED);
setfillstyle(1,MAGENTA+BROWN+YELLOW);
rectangle(430,100,625,465);
floodfill(500,300,RED);
//main
setcolor(RED);
setfillstyle(1,RED);
rectangle(100,100,300,350);
floodfill(103,150,RED);
setcolor(WHITE);
rectangle(105,105,295,345);
//smallbox
//row1
rectangle(108,110,148,160);
rectangle(156,110,196,160);
rectangle(204,110,244,160);
rectangle(252,110,292,160);
//row2
rectangle(108,170,148,220);
rectangle(156,170,196,220);
rectangle(204,170,244,220);
rectangle(252,170,292,220);
//row3
rectangle(108,230,148,280);
rectangle(156,230,196,280);
rectangle(204,230,244,280);
rectangle(252,230,292,280);
//row4
rectangle(108,290,148,340);
rectangle(156,290,196,340);
rectangle(204,290,244,340);
rectangle(252,290,292,340);
 //MOVER by key&&gotoxy
t=9;
for(i=0;i<4;i++)
{
r=15;
for(j=0;j<4;j++)
{
gotoxy(r,t);
printf("%s",as[i][j]);
r++;
r++;
r++;
r++;
r++;
r++;
}
t++;
t++;
t++;
t++;
printf("\n");
}
no=1;
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(i==3&&j==3)
break;
aci[i][j]=atoi(as[i][j]);
ab[i][j]=no;
no++;
//printf("%d %d %d %d\n",aci[i][j],ab[i][j],i,j);
}
}
com=1;
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(i==3&&j==3)
continue;
if(ab[i][j]!=aci[i][j])
{
com=0;
break;
}
}
}
//printf("%d",com);
if(com==1)
{
clrscr();
graph();//function call from other header file
exit(0);
}
//key statement
while(1)
{
settextstyle(8,0,1);
setcolor(RED);
outtextxy(500,140,"HELP");
line(480,165,560,165);
setcolor(WHITE);
outtextxy(432,160,"LEFT:-LEFT KEY");
outtextxy(432,180,"RIGHT:-RIGHT KEY");
outtextxy(432,200,"TOP:-TOP KEY");
outtextxy(432,220,"BOTTOM:-BOTTOM");
outtextxy(500,240,"KEY");
outtextxy(432,260,"RESTART:-TAB KEY");
outtextxy(432,280,"QUIT:-ESC KEY");
key=getch();
sound(123);
delay(100);
nosound();
switch(key)
{
case 72:if(m==0)
goto b;
strcpy(tem,as[m][n]);
o--;
strcpy(as[m][n],as[o][p]);
strcpy(as[o][p],tem);
m=o;
clrscr();
goto c;
b:
break;
case 80:
if(m==3)
goto b;
strcpy(tem,as[m][n]);
o++;
strcpy(as[m][n],as[o][p]);
strcpy(as[o][p],tem);
m=o;
clrscr();
goto c;
break;
case 75:
if(n==0)
goto b;
strcpy(tem,as[m][n]);
p--;
strcpy(as[m][n],as[o][p]);
strcpy(as[o][p],tem);
n=p;
clrscr();
goto c;
break;
case 77:
if(n==3)
goto b;
strcpy(tem,as[m][n]);
p++;
strcpy(as[m][n],as[o][p]);
strcpy(as[o][p],tem);
n=p;
clrscr();
goto c;
break;
case 27://esc
exit(0);
break;
case 9: //tab for restart
goto re;
}
}
getch();
closegraph();
return 0;
}