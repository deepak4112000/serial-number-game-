#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
void graph(void);
void graph(void)
{
int gd=DETECT,gm,er;
int r=3;
gotoxy(151,151);
printf("%d",r);
initgraph(&gd,&gm,"C:\\TC\\BGI");
er=graphresult();
if(er!=grOk)
{
printf("error:%s",grapherrormsg(er));
exit(0);
}
setcolor(GREEN);
setfillstyle(1,YELLOW);
rectangle(3,3,635,470);
floodfill(5,5,GREEN);
settextstyle(1,0,5);
setcolor(RED);
outtextxy(225,180,"YOU WIN");
ellipse(310,230,0,180,110,100);
sound(123);
delay(300);
sound(400);
delay(400);
sound(500);
delay(220);
sound(520);
delay(300);
sound(50);
delay(200);
sound(25);
delay(100);
sound(10);
delay(100);
sound(5);
delay(100);
sound(1);
nosound();
getch();
closegraph();
}