#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#define propo 2
#define slot 2
FILE *fp,*fp1;
void show_mouse();
void getmousepos(int *x,int *y,int *button);
struct package
{
	unsigned sec,name;
};
struct detail
{
	unsigned sec,milli;
	int re;
	char arri[15],dep[15],col[15];
};
struct detail1
{
	unsigned sec,milli;
	char arri[15],dep[15],rej[15];
};
struct detail1 de1;
struct detail de;
union REGS in,ou;
int pu,s,cur;
struct package p[10000];
void  hide_mouse();
unsigned int simsec,counter,obp,obs,lamda;
void draw_graph();
void slot_simulate();
void display();
void f4temp();
void draw_graph();
void distribute();
int fact(int n);
void poison_distribute(int t,int pos);
unsigned int generate_random(unsigned int m);
void simulate();
void f1();
void f2();
void f3();
void click(int condition,int x1,int y1,int x2,int y2);
void re_paint();
void f4();
void repor_back();
void f5();
void repor_back1();
void f6();
void f9();
void f7();
void f8();
void f10()
{
	 int x,y,button;
	hide_mouse();
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	setcolor(YELLOW);
	 setfillstyle(1,BLUE);
	 bar(5,165,630,225);
	 outtextxy(280,8,"ERROR");
	 setcolor(7);
	 outtextxy(222,195,"Sorry No data to Display ");
	 setfillstyle(SOLID_FILL,7);
	 bar(480,380,530,400);
	 click(0,480,380,530,400);
	 setcolor(4);
	 outtextxy(495,385,"OK");
	 show_mouse();
	 while(1)
	 {
		getmousepos(&x,&y,&button);
		if((x>480)&&(y>380)&&(x<530)&&(y<400)&&(button==1))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			break;
		}
	 }

}

void f8()
{
	 int x,y,button;
	 hide_mouse();
	 setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	//bar(150,180,550,250);
	setcolor(YELLOW);
	 setfillstyle(1,BLUE);
	 //bar(5,35,630,125);
	 bar(5,165,630,215);
	 outtextxy(275,8,"ABOUT");
	 outtextxy(242,175,"Developed By");
	 outtextxy(222,195,"Enoch Arulprakash");
	 setfillstyle(SOLID_FILL,7);
	 bar(480,380,530,400);
	 click(0,480,380,530,400);
	 setcolor(4);
	 outtextxy(495,385,"OK");
	 show_mouse();
	 while(1)
	 {
		getmousepos(&x,&y,&button);
		if((x>480)&&(y>380)&&(x<530)&&(y<400)&&(button==1))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			break;
		}
	 }

}

void f7()
{
	int x,y,button;
	 hide_mouse();
	 setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	//bar(150,180,550,250);
	setcolor(YELLOW);

	 setfillstyle(1,BLUE);
	 bar(5,95,630,185);
	 bar(5,225,630,285);
	 outtextxy(250,8,"TECHNICAL HELP");
	 setcolor(7);
	 outtextxy(32,105,"          PURE ALOHA: Packet can arrive at any instance of time ");
	 outtextxy(32,115,",suppose if two or more packets arrive at the same period of time");
	 outtextxy(32,125,"then collision take place ,collision is detected and it is re-transmit");
	 outtextxy(32,135,"-ed by the aloha protocol at a random period of time.suppose a packet");
	 outtextxy(32,145,"is arrived while the other packet still in the communication channel ");
	 outtextxy(32,155,"then they result in collision and the packets are re-transmitted at a");
	 outtextxy(32,165,"random period of time.we are simulating this protocol to find the");
	 outtextxy(32,175,"throughput or efficiency of this protocol.");
	 outtextxy(32,235,"         SLOTTED ALOHA:In this protocol time slot is alloted for the");
	 outtextxy(32,245,"packet ,the packet that arrive in the initial time slot are accepted ");
	 outtextxy(32,255,"and delivered packet that comes other than alloted initial time slot ");
	 outtextxy(32,265,"those packets are rejected ,suppose two or more packets arrive at a ");
	 outtextxy(32,275,"same time slot then those packets are rejected.");

	 setfillstyle(SOLID_FILL,7);
	 bar(480,380,530,400);
	 click(0,480,380,530,400);
	 setcolor(4);
	 outtextxy(500,387,"OK");
	 show_mouse();
	 while(1)
	 {
		getmousepos(&x,&y,&button);
		if((x>480)&&(y>380)&&(x<530)&&(y<400)&&(button==1))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			break;
		}
	 }

}
void f9temp()
{
	hide_mouse();
	cleardevice();

	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	//bar(150,180,550,250);
	setcolor(YELLOW);
	outtextxy(270,7,"HELP");
	setfillstyle(1,7);
	bar(250,150,365,170);
	bar(250,190,365,210);
	click(0,250,150,365,170);
	click(0,250,190,365,210);
	setcolor(4);
	outtextxy(259,155,"TECHNICAL");
	outtextxy(259,195,"ABOUT");
	setfillstyle(SOLID_FILL,7);
	 bar(480,380,530,400);
	 click(0,480,380,530,400);
	 setcolor(4);
	 outtextxy(495,385,"OK");
	show_mouse();
}
void f9()
{
	int x,y,button;
	f9temp();
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>250)&&(x<365)&&(y>150)&&(y<170)&&(button==1))
		{
				click(1,250,150,365,170);
				delay(100);
				click(0,250,150,365,170);
				f7();
				f9temp();

		}
		else if((x>250)&&(x<365)&&(y>190)&&(y<210)&&(button==1))
		{
			click(0,250,190,365,210);
			delay(100);
			click(1,250,190,365,210);
			f8();
			f9temp();
		}
		else if((x>480)&&(x<530)&&(y>380)&&(y<400)&&(button==1))
		{
			click(0,480,380,530,400);
			delay(100);
			click(1,480,380,530,400);
			break;
		}
	}

}
void f6()
{
	int x,y,n,x1,y1,button,left=0,top=0,right=getmaxx(),bottom=getmaxy();
	char con[10];
	cleardevice();
	hide_mouse();
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,40);
	setcolor(YELLOW);
	outtextxy(200,10,"SLOTTED ALOHA REPORT");
	setfillstyle(SOLID_FILL,7);
	setcolor(7);
	outtextxy(50,30,"Number of Packet");
	itoa(counter,con,10);
	outtextxy(200,30,con);
	outtextxy(350,30,"Number of Packet Deleiverd");
	itoa(obs,con,10);
	outtextxy(600,30,con);
	bar(520,360,570,380);
	click(0,520,360,570,380);
	 bar(520,400,570,420);
	 click(0,520,400,570,420);
	 setlinestyle(0,1,1);
	 setcolor(4);
	 outtextxy(535,405,"OK");
	 outtextxy(530,365,"NEXT");
	repor_back1();
	x1=60;y1=64;
	n=1;
	rewind(fp1);
	show_mouse();
	while((fread(&de1,sizeof(de1),1,fp1)==1))
	{
		itoa(de1.sec,con,10);
		outtextxy(x1,y1,con);
		itoa(de1.milli,con,10);
		x1+=75;
		outtextxy(x1,y1,con);
		x1+=75;
		outtextxy(x1,y1,de1.arri);
		x1+=75;
		outtextxy(x1,y1,de1.dep);
		x1+=75;
		outtextxy(x1,y1,de1.rej);
		y1+=12;
		x1=60;
		n++;
		if(n%28==0)
		{
			while(1)
			{
				getmousepos(&x,&y,&button);
				if((x>520)&&(x<570)&&(y>360)&&(y<380)&&(button==1))
				{
					click(1,520,360,570,380);
					delay(100);
					click(0,520,360,570,380);
					y1=64;
					hide_mouse();
					repor_back1();
					show_mouse();
					break;
				}
				else if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
				{
					click(1,520,400,570,420);
					delay(100);
					click(0,520,400,570,420);
					return;
				}
			}
		}
	}
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
		{
			click(1,520,400,570,420);
			delay(100);
			click(0,520,400,570,420);
			break;
		}
	}
}

void repor_back1()
{
	char temp[7][10]={"Sec", "Milli", "Arri", "Dept", "Rej","\0"};
	int i,x1=50,x2=50,k,left,top,right,bottom;
	left=50,top=50,right=425,bottom=400;

	setfillstyle(1,BLUE);
	rectangle(left,top,right,bottom);
	setcolor(7);
	bar(left,top,right,bottom);
	setlinestyle(0,1,1);
	for(i=0;i<5;i++)
	{
		x1+=75;
		x2+=75;
		line(x1,50,x2,400);
	}
	line(50,62,425,62);
	setlinestyle(0,1,1);
	for(i=74;i<=387;i+=12)
	{
		setcolor(7);
		line(50,i,425,i);

	}
	k=0;
	for(i=75;i<=450;i+=75)
	{
		//setfillstyle(1,BLUE);
		outtextxy(i,53,temp[k]);
		k++;
	}
}
void f5()
{
	int x,y,n,x1,y1,button,left=0,top=0,right=getmaxx(),bottom=getmaxy();
	char con[10];
	cleardevice();
	hide_mouse();
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,40);
	setcolor(YELLOW);
	outtextxy(250,10,"PURE ALOHA REPORT");
	setcolor(7);
	outtextxy(50,30,"Number of Packet");
	itoa(counter,con,10);
	outtextxy(200,30,con);
	outtextxy(350,30,"Number of Packet Deleiverd");
	itoa(obp,con,10);
	outtextxy(600,30,con);
	setfillstyle(SOLID_FILL,7);
	bar(520,360,570,380);
	click(0,520,360,570,380);
	 bar(520,400,570,420);
	 click(0,520,400,570,420);
	 setcolor(4);
	 outtextxy(535,405,"OK");
	 outtextxy(530,365,"NEXT");
	repor_back();
	x1=60;y1=64;
	n=1;
	show_mouse();
	rewind(fp);
	while((fread(&de,sizeof(de),1,fp)==1))
	{
		itoa(de.sec,con,10);
		outtextxy(x1,y1,con);
		itoa(de.milli,con,10);
		x1+=75;
		outtextxy(x1,y1,con);
		x1+=75;
		outtextxy(x1,y1,de.arri);
		x1+=75;
		outtextxy(x1,y1,de.dep);
		x1+=75;
		if((strcmp(de.col,'\0')!=0))
		{

			outtextxy(x1,y1,de.col);
			x1+=75;
			itoa(de.re,con,10);
			outtextxy(x1,y1,con);
		}
		y1+=12;
		x1=60;
		n++;
		if(n%28==0)
		{
			while(1)
			{
				getmousepos(&x,&y,&button);
				if((x>520)&&(x<570)&&(y>360)&&(y<380)&&(button==1))
				{
					click(1,520,360,570,380);
					delay(100);
					click(0,520,360,570,380);
					y1=64;
					hide_mouse();
					repor_back();
					show_mouse();
					break;
				}
				else if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
				{
					click(1,520,400,570,420);
					delay(100);
					click(0,520,400,570,420);
					return;
				}
			}
		}
	}
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
		{
			click(1,520,400,570,420);
			delay(100);
			click(0,520,400,570,420);
			break;
		}
	}
}
void repor_back()
{
	char temp[7][10]={"Sec", "Milli", "Arri", "Dept", "Coll" ,"Re-Tr","\0"};
	int i,x1=50,x2=50,k,left,top,right,bottom;
	left=50,top=50,right=500,bottom=400;
	setcolor(BLUE);
	hide_mouse();
	rectangle(left,top,right,bottom);
	setfillstyle(1,1);
	bar(left,top,right,bottom);
	setlinestyle(0,1,1);
	for(i=0;i<5;i++)
	{
		x1+=75;
		x2+=75;
		setcolor(7);
		line(x1,50,x2,400);
	}
	line(50,62,500,62);
	for(i=74;i<=400;i+=12)
	{
		setcolor(7);
		line(50,i,500,i);

	}
	k=0;
	for(i=75;i<=450;i+=75)
	{
		//setcolor(YELLOW);
		outtextxy(i,53,temp[k]);
		k++;
	}
	show_mouse();
}
void f4temp()
{
	hide_mouse();
	cleardevice();

	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	setcolor(YELLOW);
	//setcolor(YELLOW);
	outtextxy(270,9,"REPORT");
	setfillstyle(1,7);
	bar(250,150,365,170);
	bar(250,190,365,210);
	click(0,250,150,365,170);
	click(0,250,190,365,210);
	setcolor(4);
	outtextxy(259,155,"PURE ALOHA");
	outtextxy(259,195,"SLOTTED ALOHA");
	setfillstyle(SOLID_FILL,7);
	bar(480,380,530,400);
	click(0,480,380,530,400);
	setcolor(4);
	outtextxy(495,385,"OK");
	show_mouse();
}
void f4()
{
	int x,y,button;
	f4temp();
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>250)&&(x<365)&&(y>150)&&(y<170)&&(button==1))
		{
				click(1,250,150,365,170);
				delay(100);
				click(0,250,150,365,170);
				if(pu==1)
					f5();
				else
					f10();
				f4temp();
		}
		else if((x>250)&&(x<365)&&(y>190)&&(y<210)&&(button==1))
		{
			click(0,250,190,365,210);
			delay(100);
			click(1,250,190,365,210);
			if(s==1)
				f6();
			else
				f10();
			f4temp();

		}
		else if((x>480)&&(x<530)&&(y>380)&&(y<400)&&(button==1))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			break;
		}

	}

}
void re_paint()
{
	int i,y1,left=0,top=0,right,bottom;
	   char temp[10];
	   hide_mouse();
	setcolor(YELLOW);
	setfillstyle(1,BLUE);
	left=200,top=70,right=400,bottom=420;
	rectangle(left,top,right,bottom);
	bar(left,top,right,bottom);
	line(200,83,400,83);
	setlinestyle(0,1,1);
	setcolor(7);
	outtextxy(250,73,"Distribution");
	for(i=95;i<=424;i+=12)
	{
		setfillstyle(1,1);
		bar(202,i-10,398,i-3);
		setcolor(7);
		line(200,i,400,i);
	}
	show_mouse();

}
void f3()
{
	int i,arr[1000],y1,x,y,k=1,button;char temp[20];
	int left=0,top=0,right=getmaxx(),bottom=getmaxy();
	hide_mouse();
	cleardevice();
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	//bar(150,180,550,250);
	setcolor(YELLOW);
	outtextxy(260,10,"POISSION DISTRIBUTION");

	    setfillstyle(1,BLUE);
	bar(350,70,630,82);

	setcolor(7);
	rectangle(left,top,640,480);
	itoa(counter,temp,10);
	outtextxy(404,72,"No of Packet Generated");
	outtextxy(600,72,temp);
	//outtextxy(230,15,"POISSON DISTRIBUTION");
	setfillstyle(SOLID_FILL,7);
	bar(520,360,570,380);
	click(0,520,360,570,380);
	 bar(520,400,570,420);
	 click(0,520,400,570,420);
	 setcolor(4);
	 outtextxy(535,405,"OK");
	 outtextxy(530,365,"NEXT");
	re_paint();
	show_mouse();
	y1=85;
	for(i=0;i<counter;i++)
	{
		itoa(p[i].sec,temp,10);
		outtextxy(280,y1,temp);
		y1+=12;
		if(k%28==0)
		{
			while(1)
			{
				getmousepos(&x,&y,&button);
				if((x>520)&&(x<570)&&(y>360)&&(y<380)&&(button==1))
				{
					click(1,520,360,570,380);
					delay(100);
					click(0,520,360,570,380);
					y1=85;
					re_paint();
					break;
				}
				else if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
				{
					click(1,520,400,570,420);
					delay(100);
					click(0,520,400,570,420);
					return;
				}
			}
		}
		k++;
	}
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>520)&&(x<570)&&(y>400)&&(y<420)&&(button==1))
		{
			click(1,520,400,570,420);
			delay(100);
			click(0,520,400,570,420);
			break;
		}
	}

}
void click(int condition,int x1,int y1,int x2,int y2)
{
	int first,next;
	if(condition==0)
	{
		first=15;
		next=0;
	}
	else
	{
		first=0;
		next=15;
	}
	setcolor(first);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(next);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
}


void f2()
{
	int x,y,button,i,j;    char ch,gname[10];    pu=0;s=0;
	cleardevice();
	hide_mouse();
	//setbkcolor(3);

	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(4);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	bar(150,180,550,250);
	setcolor(YELLOW);
	outtextxy(260,10,"GET DATA");
	setcolor(7);
	outtextxy(170,200,"Enter The Arrival rate of the Packet:");
	outtextxy(170,230,"Enter The Time to Simulate:");
	setfillstyle(1,WHITE);
	bar(460,190,520,210);
	bar(460,220,520,240);
	gotoxy(60,13);
	setfillstyle(1,1);
	bar(150,350,300,400);
	outtextxy(160,360,"Pure-Aloa");
	outtextxy(160,380,"Slotted-Aloha");
	setfillstyle(1,15);
	bar(280,355,290,365);
	click(1,280,355,290,365);
	bar(280,375,290,385);
	click(1,280,375,290,385);
	setfillstyle(SOLID_FILL,7);
	 bar(480,380,530,400);
	 click(0,480,380,530,400);
	 setcolor(4);
	 outtextxy(495,385,"OK");
	i=-1;
	while(1)
	{
		ch=getchar();
		i++;
		gname[i]=ch;
		if(ch=='\n')
		{
			gname[i]='\0';
			lamda=0;
			for(j=0;gname[j]!='\0';j++)
			{
				lamda=(lamda*10)+(gname[j]-48);

			}
			if(lamda>0)
			break;
			else
			{
				setfillstyle(1,3);
				bar(450,190,520,210);
				gotoxy(58,13);
				i=-1;
			}
		}
	}
	gotoxy(60,15);
	i=-1;
	while(1)
	{
		ch=getchar();
		i++;
		gname[i]=ch;
		if(ch=='\n')
		{
			gname[i]='\0';
			simsec=0;
			for(j=0;gname[j]!='\0';j++)
			{
				simsec=(simsec*10)+(gname[j]-48);
			}
			if(simsec>0)
			break;
			else
			{
				setfillstyle(1,3);
				bar(450,220,520,240);
				gotoxy(58,15);
				i=-1;
			}
		}
	}
	show_mouse();
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>280)&&(x<290)&&(y>355)&&(y<365)&&(button==1))
		{
			if(pu==0)
			{
				hide_mouse();
				setcolor(4);
				setlinestyle(0, 1, 3);
				line(282,357,284,361);
				line(288,357,284,361);
				pu=1;
				delay(200);
				show_mouse();
			}
			else
			{
				pu=0;
				hide_mouse();
				setcolor(15);
				setlinestyle(0, 1, 3);
				line(282,357,284,361);
				line(288,357,284,361);
				delay(200);
				show_mouse();

			}
		}

		else if((x>280)&&(x<290)&&(y>375)&&(y<385)&&(button==1))
		{
			if(s==0)
			{
				hide_mouse();
				setcolor(4);
				setlinestyle(0, 1, 3);
				line(282,377,284,381);
				line(288,377,284,381);
				s=1;
				delay(200);
				show_mouse();
			}
			else
			{

				s=0;
				hide_mouse();
				setcolor(15);
				setlinestyle(0, 1, 3);
				line(282,377,284,381);
				line(288,377,284,381);
				delay(200);
				show_mouse();
			}
		}
		else if((x>480)&&(x<530)&&(y>380)&&(y<400)&&(button==1)&&((s==1)||(pu==1)))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			show_mouse();
			break;
		}
	}
}
void main_screen()
{
	hide_mouse();
	cleardevice();
	setfillstyle(SOLID_FILL,9);
	bar(0,0,640,480);
	setpalette(GREEN,15);
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(YELLOW);
	rectangle(0,0,640,480);
	setlinestyle(0,0,1);
	setfillstyle(1,GREEN);
	bar(0,0,640,480);
	setfillstyle(1,BLUE);
	bar(5,5,630,25);
	outtextxy(225,10,"ALOHA PROTOCOL SIMULATION");
	setfillstyle(SOLID_FILL,7);
	bar(25,100,115,120);
	click(0,25,100,115,120);
	setcolor(4);
	outtextxy(40,105,"SIMULATE");
	bar(120,150,210,170);
	click(0,120,150,210,170);
	setcolor(4);
	outtextxy(127,155,"  REPORT");
	bar(215,200,305,220);
	click(0,215,200,305,220);
	setcolor(4);
	outtextxy(240,205,"HELP");
	bar(310,250,400,270);
	click(0,310,250,400,270);
	setcolor(4);
	outtextxy(335,255,"GRAPH");
	bar(405,300,495,320);
	click(0,405,300,495,320);
	setcolor(4);
	outtextxy(435,305,"EXIT");

}
void f1()
{
	int x,y,button;
	main_screen();
	show_mouse();
	while(1)
	{
		getmousepos(&x,&y,&button);
		if((x>25)&&(y>100)&&(x<115)&&(y<120)&&(button==1))
		{
			click(1,25,100,115,120);
			delay(100);
			click(0,25,100,115,120);
			f2();
			distribute();
			poison_distribute(1,0);
			f3();
			if(s==1)
			slot_simulate();
			if(pu==1)
			simulate();
			cleardevice();
			main_screen();
			show_mouse();
		}
		else if((x>120)&&(y>150)&&(x<210)&&(y<170)&&(button==1))
		{
			click(1,120,150,210,170);
			delay(100);
			click(0,120,150,210,170);
			f4();
			cleardevice();
			main_screen();
			show_mouse();
		}
		else if((x>215)&&(y>200)&&(x<305)&&(y<220)&&(button==1))
		{
			click(1,215,200,304,220);
			delay(100);
			click(0,215,200,304,220);
			f9();
			cleardevice();
			main_screen();
			show_mouse();
		}
		else if((x>310)&&(y>250)&&(x<400)&&(y<270)&&(button==1))
		{
			click(1,310,250,400,270);
			delay(100);
			click(0,310,250,400,270);
			if((pu==1)||(s==1))
			draw_graph();
			else
			f10();
			cleardevice();
			main_screen();
			show_mouse();
		}
		else if((x>405)&&(y>300)&&(x<495)&&(y<320)&&(button==1))
		{
			click(1,405,300,495,320);
			delay(100);
			click(0,405,300,495,320);
			exit(0);
		}

	}


}

int init_mouse()
{
	in.x.ax=0;
	int86(0x33,&in,&ou);
	return (ou.x.ax);
}
void  hide_mouse()
{
	in.x.ax=2;
	int86(0x33,&in,&ou);
}
void show_mouse()
{
	in.x.ax=1;
	int86(0x33,&in,&ou);
}
void getmousepos(int *x,int *y,int *button)
{
	in.x.ax=3;
	int86(0x33,&in,&ou);
	*button=ou.x.bx;
	*x=ou.x.cx;
	*y=ou.x.dx;
}
void distribute()
{
	unsigned int i,j,no,k,temp,pos;
	counter=0,no=0,pos=0;
	for(i=0;i<simsec;i++)
	{
		 while(1)
		 {
			temp=random(lamda+6);
			if(lamda>5)
			{
				if((temp>=lamda-5)&&(temp<=lamda+5))
				{
					counter+=temp;
					for(j=1;j<=temp;j++)
					{
						p[pos].sec=no+random(100);
						pos++;
					}
					break;
				}
			}
			else
			{
				if(temp>=lamda)
				{
					counter+=temp;
					for(j=1;j<=temp;j++)
					{
						p[pos].sec=no+random(100);
						pos++;
					}
					break;
				}
			}
		 }
		 no+=100;
	}

}
void poison_distribute(int t,int pos)
{
	FILE *fp;
	char res[7];
	unsigned temp,i,j,tname;
	for(i=pos+1;i<counter;i++)
	{
		for(j=i;j>=pos+1;j--)
		{
			if(p[j].sec<p[j-1].sec)
			{
				temp=p[j].sec;
				p[j].sec=p[j-1].sec;
				p[j-1].sec=temp;
				tname=p[j].name;
				p[j].name=p[j-1].name;
				p[j-1].name=tname;
			}
			else
			break;
		}
	}
	if(t==1)
	{
		fp=fopen("check.txt","w");
		for(i=0;i<counter;i++)
		{
			p[i].name=i;
			fprintf(fp,"%d %c %d",p[i].name,' ',p[i].sec);
			fprintf(fp,"%c",'\n');
		}
		fclose(fp);
	}
}
unsigned int generate_random(unsigned int m)
{
	unsigned int temp;
	while(1)
	{
		temp=random(20);
		if(temp>1)
		return (temp+m);
	}
}
void simulate()
{
	FILE *a,*d,*c;
	char na[3]={"PA"},temp1[17],res[15],ta[16];
	unsigned milli=0,sec=0,pointer=0,no,j,temp,go=0,store;
	int prev=-1;
	obp=0;
	a=fopen("arrival.txt","w");
	d=fopen("dep.txt","w");
	c=fopen("col.txt","w");
	fclose(fp);
	fp=fopen("detail.txt","wb+");
	do
	{
		if(prev>-1)
		{
			if(milli==p[pointer].sec)
			{
				store=p[pointer].sec;
				j=pointer;no=0;
				while(p[j].sec==p[j+1].sec)
				{

					j++;
					no++;
				}
				if(no<=0)
				{
					strcpy(res,na);
					itoa(p[pointer].name,temp1,10);
					strcat(res,temp1);
					de.milli=milli;de.sec=sec;strcpy(de.arri,res);strcpy(de.col,'\0');strcpy(de.dep,'\0');
					fwrite(&de,sizeof(de),1,fp);
					fprintf(a,"%d %c %d %c %s",milli,' ',sec,' ',res);
					fprintf(a,"%c",'\n');
				}
				if(no>0)
				{
					for(j=pointer;j<(pointer+no+1);j++)
					{

						p[j].sec=generate_random(p[j].sec);
						strcpy(res,na);
						itoa(p[j].name,temp1,10);
						strcat(res,temp1);
						de.milli=milli;de.sec=sec;strcpy(de.arri,res);strcpy(de.col,'\0');strcpy(de.dep,'\0');
						fwrite(&de,sizeof(de),1,fp);
						fprintf(a,"%d %c %d %c %s",milli,' ',sec,' ',res);
						fprintf(a,"%c",'\n');
						itoa(p[j].sec,ta,10);
						de.milli=milli;de.sec=sec;strcpy(de.col,res);strcpy(de.arri,'\0');strcpy(de.dep,'\0');
						de.re=p[j].sec;
						fwrite(&de,sizeof(de),1,fp);
						fprintf(c,"%d %c %d %c %s %c %s",milli,' ',sec,' ',res,' ',ta);
						fprintf(c,"%c",'\n');
					}
					poison_distribute(0,pointer);
				}
				temp=store-prev;
				if(temp>=propo)
				{
					if(go==0)
					{
						strcpy(res,na);
						itoa(p[pointer-1].name,temp1,10);
						strcat(res,temp1);
						de.milli=milli;de.sec=sec;strcpy(de.dep,res);strcpy(de.col,'\0');strcpy(de.arri,'\0');
						fwrite(&de,sizeof(de),1,fp);
						fprintf(d,"%d %c %d %c %s",milli,' ',sec,' ',res);
						fprintf(d,"%c",'\n');
						obp+=1;
					}
					if(no<=0)
					{
						go=0;
						pointer++;
						prev=store;
					}
				}
				else
				{
					if(no<=0)
					{
						p[pointer-1].sec=generate_random(p[pointer-1].sec);
						p[pointer].sec=generate_random(p[pointer].sec);
						strcpy(res,na);
						itoa(p[pointer-1].name,temp1,10);
						strcat(res,temp1);
						itoa(p[pointer-1].sec,ta,10);
						de.milli=milli;de.sec=sec;strcpy(de.col,res);strcpy(de.arri,'\0');strcpy(de.dep,'\0');
						de.re=p[pointer-1].sec;
						fwrite(&de,sizeof(de),1,fp);
						fprintf(c,"%d %c %d %c %s %c %s",milli,' ',sec,' ',res,' ',ta);
						fprintf(c,"%c",'\n');
						strcpy(res,na);
						itoa(p[pointer].name,temp1,10);
						strcat(res,temp1);
						itoa(p[pointer].sec,ta,10);
						de.milli=milli;de.sec=sec;strcpy(de.col,res);strcpy(de.arri,'\0');strcpy(de.dep,'\0');
						de.re=p[pointer].sec;
						fwrite(&de,sizeof(de),1,fp);
						fprintf(c,"%d %c %d %c %s %c %s",milli,' ',sec,' ',res,' ',ta);
						fprintf(c,"%c",'\n');
					}
					else
					{
						p[pointer-1].sec=generate_random(p[pointer-1].sec);
						strcpy(res,na);
						itoa(p[pointer-1].name,temp1,10);
						strcat(res,temp1);
						itoa(p[pointer-1].sec,ta,10);
						de.milli=milli;de.sec=sec;strcpy(de.col,res);strcpy(de.arri,'\0');strcpy(de.dep,'\0');
						de.re=p[pointer-1].sec;
						fwrite(&de,sizeof(de),1,fp);
						fprintf(c,"%d %c %d %c %s %c %s",milli,' ',sec,' ',res,' ',ta);
						fprintf(c,"%c",'\n');
					}
					pointer--;
					prev=-1;
					poison_distribute(0,pointer);
				}
				if((no>0)||(temp<propo))
				prev=-1;

			}
			else if(prev+propo==milli)
			{
				strcpy(res,na);
				itoa(p[pointer-1].name,temp1,10);
				strcat(res,temp1);
				obp+=1;
				de.milli=milli;de.sec=sec;strcpy(de.dep,res);strcpy(de.col,'\0');strcpy(de.arri,'\0');
				fwrite(&de,sizeof(de),1,fp);
				fprintf(d,"%d %c %d %c %s",milli,' ',sec,' ',res);
				fprintf(d,"%c",'\n');
				go=1;

			}
		}
		else
		{
			if(milli==p[pointer].sec)
			{
				j=pointer;no=0;
				while(p[j].sec==p[j+1].sec)
				{
					j++;
					no++;
				}
				if(no<=0)
				{
					strcpy(res,na);
					itoa(p[pointer].name,temp1,10);
					strcat(res,temp1);
					de.milli=milli;de.sec=sec;strcpy(de.arri,res);strcpy(de.col,'\0');strcpy(de.dep,'\0');
					fwrite(&de,sizeof(de),1,fp);
					fprintf(a,"%d %c %d %c %s",milli,' ',sec,' ',res);
					fprintf(a,"%c",'\n');
				}
				if(no>0)
				{
					for(j=pointer;j<(pointer+no+1);j++)
					{
						p[j].sec=generate_random(p[j].sec);
						strcpy(res,na);
						itoa(p[j].name,temp1,10);
						strcat(res,temp1);
						de.milli=milli;de.sec=sec;strcpy(de.arri,res);strcpy(de.col,'\0');strcpy(de.dep,'\0');
						fwrite(&de,sizeof(de),1,fp);
						fprintf(a,"%d %c %d %c %s",milli,' ',sec,' ',res);
						fprintf(a,"%c",'\n');
						itoa(p[j].sec,ta,10);
						de.milli=milli;de.sec=sec;strcpy(de.col,res);strcpy(de.arri,'\0');strcpy(de.dep,'\0');
						de.re=p[j].sec;
						fwrite(&de,sizeof(de),1,fp);
						fprintf(c,"%d %c %d %c %s %c %s",milli,' ',sec,' ',res,' ',ta);
						fprintf(c,"%c",'\n');
					}
					poison_distribute(0,pointer);
				}
				else
				{
					prev=p[pointer].sec;
					pointer++;
				}
			}
		}
		milli+=1;
		if(milli%99==0)
		sec+=1;
	}while(sec<simsec);
}
void slot_simulate()
{
	FILE *ar,*re,*dep;
	char pa[3]={"pa"},temp1[15],res[15];
	unsigned int milli=0,sec=0,pointer=0,j,no;
	int prev=-1;
	obs=0;
	ar=fopen("arr","w");
	re=fopen("reject","w");    dep=fopen("went","w");
	fclose(fp1);
	fp1=fopen("detail1.txt","wb+");
	do
	{
		if(prev>=0)
		{
			if(milli==p[prev].sec+slot)
			{
				strcpy(res,pa);
				itoa(p[prev].name,temp1,10);
				strcat(res,temp1);
				de1.milli=milli;de1.sec=sec;strcpy(de1.dep,res);strcpy(de1.rej,'\0');strcpy(de1.arri,'\0');
				fwrite(&de1,sizeof(de1),1,fp1);
				fprintf(dep,"%d %c %s",milli,' ',res);
				fprintf(dep,"%c",'\n');
				obs+=1;
			}
		}
		if(milli==p[pointer].sec)
		{
			j=pointer,no=0;
			while(p[j].sec==p[j+1].sec)
			{
				no++;
				j++;
			}
			if(no>0)
			{
				for(j=pointer;j<=(pointer+no);j++)
				{
					strcpy(res,pa);
					itoa(p[j].name,temp1,10);
					strcat(res,temp1);
					de1.milli=milli;de1.sec=sec;strcpy(de1.arri,res);strcpy(de1.rej,'\0');strcpy(de1.dep,'\0');
					fwrite(&de1,sizeof(de1),1,fp1);
					fprintf(ar,"%d %c %s",milli,' ',res);
					fprintf(ar,"%c",'\n');
					de1.milli=milli;de1.sec=sec;strcpy(de1.arri,'\0');strcpy(de1.rej,res);strcpy(de1.dep,'\0');
					fwrite(&de1,sizeof(de1),1,fp1);
					fprintf(re,"%d %c %s",milli,' ',res);
					fprintf(re,"%c",'\n');
				}
				pointer+=no+1;
			}
			else
			if(no<=0)
			{
				strcpy(res,pa);
				itoa(p[pointer].name,temp1,10);
				strcat(res,temp1);
				de1.milli=milli;de1.sec=sec;strcpy(de1.arri,res);strcpy(de1.rej,'\0');strcpy(de1.dep,'\0');
				fwrite(&de1,sizeof(de1),1,fp1);
				fprintf(ar,"%d %c %s",milli,' ',res);
				fprintf(ar,"%c",'\n');
				if(p[pointer].sec%slot!=0)
				{
					strcpy(res,pa);
					itoa(p[pointer].name,temp1,10);
					strcat(res,temp1);
					de1.milli=milli;de1.sec=sec;strcpy(de1.arri,'\0');strcpy(de1.rej,res);strcpy(de1.dep,'\0');
					fwrite(&de1,sizeof(de1),1,fp1);
					fprintf(re,"%d %c %s",milli,' ',res);
					fprintf(re,"%c",'\n');
				}
				else
				prev=pointer;
				pointer+=1;
			}
		}
		milli+=1;
		if(milli%99==0)
		sec+=1;
	}while(sec<simsec);
}
void draw_graph()
{
	float sang=0,eang;   int x,y,button;
	char temp[10];
	float valp=0,vals=0;
	hide_mouse();
	cleardevice();
	setbkcolor(1);
	vals=(float)((float)obs/(float)counter)*100;
	valp=(float)((float)obp/(float)counter)*100;
	setcolor(14);
	outtextxy(250,10,"GRAPHICAL REPRESENTATION");
	outtextxy(50,50,"Name of The Protocol");
	outtextxy(300,50,"Graph");
	outtextxy(450,50,"Throughput");
	if(pu==1)
	{

		outtextxy(90,100,"Pure Aloha");
		eang=(360*valp)/100;
		setfillstyle(SOLID_FILL,2);
		pieslice(320,100,sang,eang,30);
		setfillstyle(SOLID_FILL,0);
		if(eang!=360)
		pieslice(320,100,eang,360,30);
		itoa(valp,temp,10);
		strcat(temp,"%");
		outtextxy(460,100,temp);
	}
	if(s==1)
	{
		outtextxy(90,200,"Slotted Aloha");
		eang=(360*vals)/100;
		setfillstyle(SOLID_FILL,2);
		pieslice(320,200,sang,eang,30);
		setfillstyle(SOLID_FILL,0);
		if(eang!=360)
		pieslice(320,200,eang,360,30);
		itoa(vals,temp,10);
		strcat(temp,"%");
		outtextxy(460,200,temp);
	}
	setfillstyle(SOLID_FILL,7);
	bar(480,380,530,400);
	click(0,480,380,530,400);
	setcolor(4);
	outtextxy(495,385,"OK");
	show_mouse();
	 while(1)
	 {
		getmousepos(&x,&y,&button);
		if((x>480)&&(y>380)&&(x<530)&&(y<400)&&(button==1))
		{
			click(1,480,380,530,400);
			delay(100);
			click(0,480,380,530,400);
			break;
		}
	 }
}

void main()
{
	int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"..\\bgi");
	randomize();
	init_mouse();
	show_mouse();
	f1();
}