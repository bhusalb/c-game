#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream.h>
#include <string.h>
#include <iomanip.h>
#include <time.h>

#define ESC 27
#define UP 119
#define LEFT 97
#define DOWN 115
#define RIGHT 100
#define FIRE 120
const int M=20;//for number of bullet
int diff;// difficulty level
char name[50];
/*void collide(int x,int y)
	{
	int ch;
       //	clrscr();
	clearviewport();
	setviewport(0,0,x,y,1);
	x=x/2;
	y=y/2;
	settextstyle(GOTHIC_FONT,HORIZ_DIR,8);
	outtextxy(50,y-50,"GAME OVER");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(0,y+50,"Press R to replay OR Press ESC to exit");
	while(1)
		{
		if (kbhit())
			{
			ch=tolower(getch());
			if (ch==ESC)
				{
				first.last_page();
				exit(1);
				}
			if (ch==114)
				goto baa ;
			}
		}
	}      */
int xabs(int x)
{
	if (x < 0)
		x = x * (-1);
	return x;
}
int xrand(int x)
{
	x = rand() % x;
	return x;
}
class car
{
	int x1, y1;
public:
	car(int a, int b)
	{
		x1 = a;
		y1 = b;
	}
	void main_car()
	{
		rectangle(15 + x1, y1, 25 + x1, 10 + y1);
		rectangle(x1, 15 + y1, 10 + x1, 25 + y1);
		rectangle(15 + x1, 15 + y1, 25 + x1, 25 + y1);
		rectangle(30 + x1, 15 + y1, 40 + x1, 25 + y1);
		rectangle(x1, 30 + y1, 10 + x1, 40 + y1);
		rectangle(30 + x1, 30 + y1, 40 + x1, 40 + y1);
	}
	void side_car()
	{
		rectangle(x1, y1, 10 + x1, 10 + y1);
		rectangle(30 + x1, y1, 40 + x1, 10 + y1);
		rectangle(x1, 15 + y1, 10 + x1, 25 + y1);
		rectangle(15 + x1, 15 + y1, 25 + x1, 25 + y1);
		rectangle(30 + x1, 15 + y1, 40 + x1, 25 + y1);
		rectangle(15 + x1, y1 + 30, 25 + x1, 40 + y1);
	}
};
class page
{
	//char name[50];
public:
	void page_1(int x, int y, int x1, int y1)
	{
		setbkcolor(15);
		int temp_loc;
		temp_loc=getmaxx()/2;
		settextstyle(4, HORIZ_DIR, 20);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(temp_loc, 100, "88");
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 8);
		outtextxy(temp_loc, 200, "RACING MOTO");
		settextjustify(0,0);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
		outtextxy(x1, y1 + 50, "Select Difficulty level");
		outtextxy(x1, y1 + 65, "1.Hard");
		outtextxy(x1, y1 + 80, "2.Middle");
		outtextxy(x1, y1 + 95, "3.Easy");
		diff = getch();
		if (diff == 49)
			diff = 20;
		else if (diff == 50)
			diff = 30;
		else if (diff == 51)
			diff = 40;
		else
			diff = 40;
		//printf("%d",diff);
		//getch();
		cleardevice();
	}
	void last_page()
	{
	cleardevice();
	setviewport(0,0,getmaxx(),getmaxy(),0);
	setbkcolor(15);
	/*
	cout<<setw(40)<<"Specials thanks"<<endl;
	cout<<setw(45)<<"Bishwas Wagle"<<endl;
	cout<<setw(45)<<"Yubaraj Poudel"<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"Developed By"<<endl;
	cout<<setw(50)<<"Bishnu Bhusal"<<endl;
	 */
	int x_max;
	//y_max=getmaxy();
	x_max=getmaxx();
	cleardevice();
	setcolor(8);
	settextstyle(1, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x_max / 2, 50,"Specials thanks");
	outtextxy( x_max / 2 , 75,"Deepak Rawal(DR sir)");
	outtextxy(x_max / 2 , 100,"Roshan Porkharal(RP sir)" );
	outtextxy(x_max / 2 , 125,"Yubaraj Poudel(guide line provider)" );
	outtextxy(x_max / 2 , 200, "Developed By");
	outtextxy(x_max / 2 , 225, "Bishnu");
	outtextxy(x_max / 2 , 250, "Suman");
	outtextxy(x_max / 2 , 275, "Tek raj");
	outtextxy(x_max / 2 , 300, "Prashant");
	delay(3000);
	cleardevice();

	}
};
void bullet(int x, int y)
	{
	setcolor(15);
	for(int i=0;i<10;i++)
		{
		rectangle(x + 5, y - 10+i, x, y);
		}
	setcolor(4);
	}
int main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int x_max, y_max, x = 60, y, ch, j = 0, temp[2], x1, y1, x2, y2, yy, yyy = 0;
	int abull[M], bbull[M], jud[M], no = 0,fire[M];//for bullet
	int looper;
	for(looper=0;looper<M;looper++)
		{
		abull[looper]=0;
		bbull[looper]=0;
		jud[looper]=0;
		fire[looper]=0;
		}
	clrscr();
	initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
	setcolor(4);
	page first;
	x_max = getmaxx();
	y_max = getmaxy();
	//collide(x_max,y_max);
	first.page_1(150, 150, x_max / 2 - 200, y_max / 2);
	setbkcolor(2);
baa :
	j = 0;
	yyy = 0;
	y = y_max - 89;
	setcolor(BLUE);
	settextjustify(0, 0);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(2, 2, "press ESC to exit and W,S for up and down And A,D for left and right moves");
	settextstyle(2, HORIZ_DIR, 7);
	outtextxy(200,50,"This Demo Version");
	outtextxy(200,85,"Press W -> Up");
	outtextxy(200,120,"Press S ->Down");
	outtextxy(200,155,"Press A ->Left ");
	outtextxy(200,190,"Press D ->Right");
	outtextxy(200,225,"Press X ->Fire");
	outtextxy(200,260,"sorry we are under developing");
	outtextxy(200,295,"process so fire isn't working");
	//cout<<"press ESC to exit and W,S for up and down And A,D for left and right moves";
	line(190, 25, 190, y_max - 10);  //vertical line
	line(10, 25, 10, y_max - 10);   //vertical line
	line(10, 25, 190, 25); //hortionzal line
	line(10, y_max - 10, 190, y_max - 10);  //hortionzal line
	setcolor(4);
	setviewport(20, 28, 170, y_max - 20, 10);
	while (1)
	{
		temp[0] = xrand(3);
		x1 = 10 + temp[0] * 50;
		for (int i = 0;i < y_max - 40;i += 10)  //for controller key and collosion
		{
			if (kbhit())
			{
				ch = tolower(getch());
				if (ch == UP)
					if ((y - 50) > 20)
						y -= 50;
					else
					{
						sound(1200);
						delay(100);
						nosound();
					}
				if (ch == DOWN)
					if ((y + 50) < (y_max - 75))
						y += 50;
					else
					{
						sound(1200);
						delay(100);
						nosound();
					}
				if (ch == LEFT)
					if ((x - 50) > 0)
						x -= 50;
					else
					{
						sound(1200);
						delay(100);
						nosound();
					}
				if (ch == RIGHT)
					if ((x + 50) <= 110)
						x += 50;
					else
					{
						sound(1200);
						delay(100);
						nosound();
					}
				if (ch == ESC)
				{
					first.last_page();
					exit(1);
				}
				if (ch == FIRE)
				{
					fire[no] = 1;
					no++;
					if (no == M)
						no = 0;
				}
			}          //end of controller and collosion part
			//start of randomize
			y1 = 20 + i;
			y2 = 20 + j;
			car a(x, y), b(x1, y1), c(x2, y2), d(110, 20 + i);
			a.main_car();
			//if (x)
			yy = (y_max) / 2;
			yy = yy % 10;
			yy = (y_max) / 2 - yy;
			if (yy == i)
			{
				temp[1] = xrand(2);
				j = 0;
				yyy = 3;
			}
			if (j <= (y_max - 40) && (yyy != 0))
			{
				if (temp[0] == 0)
				{
					if (temp[1] == 0)
						x2 = 60;
					else
						x2 = 110;
				}
				if (temp[0] == 1)
				{
					if (temp[1] == 0)
						x2 = 10;
					else
						x2 = 110;
				}
				if (temp[0] == 2)
				{
					if (temp[1] == 0)
						x2 = 10  ;
					else
						x2 = 60;
				}
				c.side_car();
				j = j + 10;
			}
			b.side_car();
			//	c.side_car();      abs
			for (int loop = 0;loop <= no;loop++)
			{
				if (fire[loop] == 1)
				{
					if (jud[loop] == 0)
					{
						bbull[loop] = y;
						abull[loop] = x+17;
						jud[loop] = 1;
					}
					bullet(abull[loop], bbull[loop]);
					bbull[loop] -= 10;
					if (bbull[loop] <= 30)
					{
						fire[loop] = 0;
						jud[loop] = 0;
					}
				}
			}
			//d.side_car()
			if ( ( (x == x1) && (  xabs(y - y1) < 40 ) ) || ((x == x2) && (xabs(y - y2) < 40 )    ) )
			{
				sound(1200);
				delay(100);
				nosound();
				//clrscr();
				cleardevice();
				setviewport(0, 0, x_max, y_max, 1);
				settextstyle(GOTHIC_FONT, HORIZ_DIR, 8);
				outtextxy(50, y_max / 2 - 50, "GAME OVER");
				settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
				outtextxy(0, y_max / 2 + 50, "Press R to replay OR Press ESC to exit");
				while (1)
				{
					if (kbhit())
					{
						ch = tolower(getch());
						if (ch == ESC)
						{
							first.last_page();
							exit(1);
						}
						if (ch == 114)
						{
							clearviewport();
							cleardevice();
							goto baa ;
						}
					}
				}
			}
			delay(diff);
			clearviewport();
		}
	}
	/* clean up */
	cleardevice();
	closegraph();
	return 0;
}

