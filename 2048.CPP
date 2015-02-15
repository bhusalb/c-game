//created by bishnu bhusal
//use w,s,a and d for up,down,left and right respectively,and r to restart
//there are some error with controller
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>



#define ESC 27
#define UP 119
#define LEFT 97
#define DOWN 115
#define RIGHT 100
#define RESTART 114



long int score=0;
int w=0;
int a[4][4];     //for display unit
int b[4][4];    //for checking unit
void layout();
int xrand(int x)      // random number
	{
	int temp;
	temp= rand()%x;
	return temp;
	}
void generate(int value=2)    //to    generate random number
	{
	int k=0,l=0,i,j;
	//for i random value
	for(i=0;i<4;i++)
		{
		for(j=0;j<4;j++)
			{
			if(a[i][j]==0);
				{
				k=1;
				break;
				}
			}
		}
	if(k==1)
		{
		for(int temp=0;temp<1000;temp++)
			{
			i=xrand(4);
			j=xrand(4);
			if(a[i][j]==0)
				{
				a[i][j]=value;
				l=1;
				break;
				}
			}
		/*if( (temp>80)&&(l==0))
			{
			for(i=0;i<4;i++)
				{
				for(j=0;j<4;j++)
					{
					if(a[i][j]==0);
						{
						a[i][j]=value;
						break;
						}
					}
				}
			}*/
		}
	}

void intialize()      //to intialize the array value
	{
	score=0;
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			{
			a[i][j]=0;
			}
		}
	generate();
	generate();
	}

int rev(int x)            //to   reverse number
	{
	int s=0;
	while(x!=0)
		{
		s=s*10+x%10;
		x/=10;
		}
	return s;
	}

void int2str(int x,char s[20])   //to convert integer to string
	{
	int temp=0;
	if(x%10==0)
		{
		temp=1;
		}
	if(x%100==0)
		{
		temp=2;
		}
	if(x%1000==0)
		{
		temp=3;
		}
	x=rev(x);
	int r=0;
	strcpy(s,"");
	while(x!=0)
		{
		r=x%10;
		switch (r)
			{
			case 0:
			strcat(s,"0");
			break;

			case 1:
			strcat(s,"1");
			break;

			case 2:
			strcat(s,"2");
			break;

			case 3:
			strcat(s,"3");
			break;

			case 4:
			strcat(s,"4");
			break;

			case 5:
			strcat(s,"5");
			break;

			case 6:
			strcat(s,"6");
			break;

			case 7:
			strcat(s,"7");
			break ;

			case 8:
			strcat(s,"8");
			break;

			case 9:
			strcat(s,"9");
			break;
			}
		x/=10;
		}
	if(temp==1)
		{
		strcat(s,"0");
		}
	if(temp==2)
		{
		strcat(s,"00") ;
		}
	if(temp==3)
		{
		strcat(s,"000");
		}
	}

void display()
	{
	int x,y,c,b;
	char s[20];
	x=getmaxx()/2;
	y=getmaxy()/2;
	c=x-75;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(2, HORIZ_DIR, 7);
	layout();
	for(int i=0;i<4;i++)
		{
		b=y-75;
		for(int j=0;j<4;j++)
			{
			setcolor(j+3);
			int2str(a[i][j],s);
			if(a[i][j]!=0)
				{
				outtextxy(c,b,s);
				}
			b+=50;
			}
		c+=50;
		}
	int2str(score,s);
	x=x+150;
	y=y+200;
	settextstyle(4, HORIZ_DIR, 5);
	//setcolor(15);
	outtextxy(x,y,s);
	settextstyle(3, HORIZ_DIR, 5);
	setcolor(9);
	outtextxy(x-150,y,"Score:");
	setcolor(15);
	}


void layout()
	{
	int x,y;
	x=getmaxx()/2;
	y=getmaxy()/2;
	rectangle(x-100,y-100,x+100,y+100);
	for(int i=50;i<=150;i=i+50)
		{
		line(x-100,y-100+i,x+100,y-100+i);
		line(x-100+i,y-100,x-100+i,y+100);
		}
	}



void last_page()
	{
	cleardevice();
	setbkcolor(11);
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
	setcolor(2);
	settextstyle(1, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
       //	outtextxy(x_max / 2, 50,"Specials thanks");
       //	outtextxy( x_max / 2 , 75, "Yubaraj Poudel");
       //	outtextxy(x_max / 2 , 100,"Bishwas Wagle" );
	outtextxy(x_max / 2 , 200, "Developed By");
	outtextxy(x_max / 2 , 225, "Bishnu Bhusal");
	delay(2000);
	cleardevice();
	exit(1);
	}
void left()
	{
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			{
			for(int k=i+1;k<4;k++)
				{
				if(a[i][j]==0&&a[k][j]!=0)
					{
					a[i][j]=a[k][j];
					a[k][j]=0;
					}
				}
			if((a[i][j]==a[i+1][j])&& a[i][j]!=0)
				{
				a[i][j]*=2;
				score=score+a[i][j];
				a[i+1][j]=0;
				}
			}
		}
	}

void right()
	{
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			{
			for(int k=i+1;k<4;k++)
				{
				if(a[k][j]==0&&a[i][j]!=0)
					{
					a[k][j]=a[i][j];
					a[i][j]=0;
					}
				}
			if((a[i][j]==a[i+1][j])&&a[i][j]!=0)
				{
				a[i+1][j]*=2;
				score=score+a[i+1][j];
				a[i][j]=0;
				}
			}
		}
	}


void down()
	{
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			{
			for(int k=j+1;k<4;k++)
				{
				if(a[i][k]==0&&a[i][j]!=0)
					{
					a[i][k]=a[i][j];
					a[i][j]=0;
					}
				}
			if((a[i][j]==a[i][j+1])&&a[i][j]!=0)
				{
				a[i][j+1]*=2;
				score=score+a[i][j+1];
				a[i][j]=0;
				}
			}
		}
	}


void up()
	{
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			{
			for(int k=j+1;k<4;k++)
				{
				if(a[i][j]==0&&a[i][k]!=0)
					{
					a[i][j]=a[i][k];
					a[i][k]=0;
					}
				}
			if((a[i][j]==a[i][j+1])&&a[i][j]!=0)
				{
				a[i][j]*=2;
				score=score+a[i][j];
				a[i][j+1]=0;
				}
			}
		}
	}
void win_page()
	{
	char ch;
	int y_mid,x,y;
	y_mid=getmaxy()/2;
	cleardevice();
	x=getmaxx()/2;
	y=y_mid-50;
	settextstyle(0, HORIZ_DIR, 8);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x, y, "You Won");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	y+=100;
	outtextxy(x, y, "go on");
	ch=tolower(getch());
	if(ch==ESC)
		{
		last_page();
		}

	}
void win()
	{
	int i,j;
	if(w==0)
		{
		for(i=0;i<4;i++)
			{
			for(j=0;j<4;j++)
				{
				if(a[i][j]==2048)
					{
					w=1;
					win_page();
					break;
					}
				}
			}
		}

	}

void gameovers() //game over screen layout
	{
	char ch;
	int y_mid,x,y;
	y_mid=getmaxy()/2;
	cleardevice();
	x=getmaxx()/2;
	y=y_mid-50;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 8);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x, y, "GAME OVER");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	y+=100;
	outtextxy(x, y, "Press R to replay OR Press ESC to exit");
	ch=tolower(getch());
	if(ch==ESC)
		{
		last_page();
		}
	else
		{
		intialize();
		}
	}

int gameover()    //to
	{
	int i,j,k=0,x=1,temp;
	temp=score;
	int c[4][4];
	for(i=0;i<4;i++)
		{
		for(j=0;j<4;j++)
			{
			if(a[i][j]==0)
				{
				k=1;
				break;
				}
			}
		}
	if(k==0)
		{
		for(i=0;i<4;i++)
			{
			for(j=0;j<4;j++)
				{
				c[i][j]=a[i][j];
				}
			}
		up();
		down();
		left();
		right();
		for(i=0;i<4;i++)
			{
			for(j=0;j<4;j++)
				{
				if(c[i][j] != a[i][j])
					{
					x=0;
					break;
					}
				}
			}
		if(x==0)
			{
			for(i=0;i<4;i++)
				{
				for(j=0;j<4;j++)
					{
					a[i][j]=c[i][j];
					}
				}
			}
		score=temp;
		return x;
		}
	else
		{
		return 0;
		}
	}



void check()
	{
	//gotoxy(0,0);
	clrscr();
	cout<<"testing purpose only"<<endl;
	for(int i=0;i<4;i++)
		{
		for(int j=0;j<4;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
		}
	}


void controller()
	{
	int ch;
	if (kbhit())
		{
		ch = toascii(tolower(getch()));
			if (ch==UP)
				{
				up();
				generate();
				}
			if (ch==DOWN)
				{
				down();
				generate();
				}
			if (ch==LEFT)
				{
				left();
				generate();
				}
			if (ch==RIGHT)
				{
				right();
				generate();
				}
			if (ch == ESC)
				{
				last_page();
				}
			if(ch==RESTART)
				{
				intialize();
				}
			cleardevice();
			display();
			if(gameover()==1)
				{
				gameovers();
				}
			if(w==0)
				win();
			}
	}

void first_page()
	{
	int y_mid,x,y;
	y_mid=getmaxy()/2;
	x=getmaxx()/2;
	cleardevice();
	y=y_mid-100;
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 12);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(x, y, "2048");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	y+=150;
	outtextxy(x, y, "welcome to 2048 Puzzle game");
	delay(2000);
	cleardevice();
	}

int main()
	{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	clrscr();
	initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
	intialize();
	first_page();
	setbkcolor(10);
	layout();
	display();
	//check();
	while(1)
		{
		controller();
		}
	getch();
	return 0;
	}
