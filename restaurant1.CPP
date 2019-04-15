

//////////////////////////////////////////////////////////////////////////////
		       /* COMPUTER SCIENCE*/
//////////////////////////////////////////////////////////////////////////////
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>


class restaurant
{
public:
	int orderid;
	float price;
	int choice[4];
	int j;
	restaurant()
	{
	choice[0]=0;
	choice[1]=0;
	choice[2]=0;
	choice[3]=0;
	}
void getdata()
{       cout<<"Enter the Order id  ";
	cin>>orderid;
	char ch='y';
	do
	{clrscr();
	closegraph();
	cout<<"*********************************************";
	cout<<"\n1.Tea: 10/peice"<<endl<<"2.Coffee: 15/piece "<<endl<<
	"3.Milk: 15/piece"<<endl<<"4.Samosa: 20/piece"<<endl;
	cout<<"*********************************************";
	cout<<"\n Enter the choice ";
	cin>>j;
	switch(j)
	{
	case 1:
	cout<<"Enter the no of tea";
	cin>>choice[0];
	break;
	case 2:
	cout<<"Enter the no of coffee";
	cin>>choice[1];
	break;
	case 3:cout<<"Enter the no of Milk ";
	cin>>choice[2];
	break;
	case 4:
	cout<<"Enter the no of Samosa";
	cin>>choice[3];
	break;
	default:cout<<"CHECK YOUR CHOICE";
	}
	cout<<"Want to enter anything(y/n) ";
	ch=getch();

}while(ch=='y');
calcprice();
}
void showdata()
{
cout<<"Bewarges"<<"\t"<<"Total Nos"<<"\t"<<"Price "<<endl;
cout<<"Tea"<<"\t\t"<<choice[0]<<"\t"<<choice[0]*10<<endl;
cout<<"Cofee"<<"\t\t"<<choice[1]<<"\t"<<choice[1]*15<<endl;
cout<<"Milk"<<"\t\t"<<choice[2]<<"\t"<<choice[2]*15<<endl;
cout<<"Samosa"<<"\t\t"<<choice[3]<<"\t"<<choice[3]*20<<endl;
cout<<"\t\t\t\t"<<"Total: "<<price;
}
void calcprice()
{
price=10*choice[0]+15*choice[1]+15*choice[2]+20*choice[3];
}
int retid()
{
	return orderid ;

}
};
void rec()
{
ofstream i;
i.open("Order.dat");
restaurant r;
r.getdata();
i.write((char*)&r,sizeof(r));
i.close();
}
void search()
{
cout<<"Enter the order id you want to search ";
int o;
cin>>o;
ifstream i;
i.open("Order.dat");
restaurant r;
while(i.read((char*)&r,sizeof(r)))
{
if(r.retid()==o)
r.showdata();
else cout<<"Not Such order exists so Please check the orderid ";
}
i.close();
}
void modify()
{int n;
cout<<"Enter the order id you want to change ";
cin>>n;
restaurant s;
fstream i;
int found=0;
i.open("Order.dat",ios::in|ios::out);
while(i.read((char*)&s,sizeof(s)))
{	if(s.retid()==n)
	{cout<<"Enter the new data "<<endl;
	s.getdata();
	int pos=(-1) * sizeof(s);
	i.seekp(pos,ios::cur);
	i.write((char*)&s,sizeof(s));
	found++;
	}
}

}
void menu()
{        char ch1='y';
	int choice;
	do
	{clrscr();
	closegraph();
	cout<<"\n***********************************************************";
	cout<<"\n\t1. ENTER THE ORDER";
	cout<<"\n\t2. SEARCH ANY RECORD";
	cout<<"\n\t3. MODIFY ANY RECORD";
	cout<<"\n***********************************************************";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: rec();
			getch();
			break;
		case 2: search();
			getch();
			break;
		case 3: modify();
			getch();
			break;
		default: cout<<"Check the choice ";

	}
	cout<<endl<<"Want to do any more(y/n) ";
	ch1=getch();
	}while(ch1=='y'||ch1=='Y');

}
//yes or no function
void Ray(int x,int y)
{
setcolor(BLUE);
outtextxy(x,y,"_");
}

int y()
{
int ch;
int x=10,y=50;
setcolor(7);
outtextxy(x,y,"1.YES");
outtextxy(x,y+10,"2.NO");
while(1)
{
ch=getch();
if(ch==119)
{setcolor(3);
moveto(x-10,y+10);
outtextxy(x-10,y+10,"_");
Ray(x-10,y);
}
else if(ch==115)
{setcolor(3);
moveto(x-10,y);
outtextxy(x-10,y,"_");
Ray(x-10,y+10);
}
else if(ch==13)
{
if(gety()==50)
return 0;
else if(gety()==60)
return 1;
}
}
}
//welcome function
void welcome()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:/TC/BGI");
int i,j;
for(i=0;i<=getmaxx();i++)
{
for(j=0;j<=getmaxy();j++)
putpixel(i,j,3);
delay(3);
}
setcolor(WHITE);
outtextxy(getmaxx()/3,10,"INSTRUCTIONS: ");
delay(3);
for(int k=0;k<15;k++)
{setcolor(k);
outtextxy(getmaxx()/3,20,"Press W to Move Up");
delay(100);
outtextxy(getmaxx()/3,30,"Press S to Move down" );
delay(100);
outtextxy(getmaxx()/3,40,"Press Enter to select");
}
}
//loading function
void loading()
{       int g=DETECT,m;
initgraph(&g,&m,"c:/tc/bgi");
	setbkcolor(BLACK);
    int d=3,i,x1=120,y1=350,x2=x1+400,y2=y1+15;
    char arr[10];
    cleardevice();
    setcolor(7);
    settextstyle(4,0,10);
    outtextxy(260,50,"KJ");
    settextstyle(1,0,1);
    outtextxy(250,200,"PRODUCTION");
    delay(600);

    setcolor(RED);
    setfillstyle(1,3);
     rectangle(x1-d,y1-d,x2+d,y2+d);
    setcolor(7);
    settextstyle(8,0,1);
    outtextxy(x1,y1-30,"Loading...");
       for(i=0;i<100;i++)
    {
	delay(100);
	bar(x1+1,y1+1,x1+i*4+3,y2-1);
	gotoxy(x2/8-2,y1/17+1);
	cout<<"%"<<i+1;
    }
    setcolor(RED);
    outtext("Press a Key to continue...");
    getch();
}

//front page
void fp()
{
for(int y=0;y<15;y++)
setbkcolor(y);
outtextxy(getmaxx()/3,120,"MADE BY KARAN JAYSWAL");
outtextxy(getmaxx()/3,150,"ON ONLINE RETAIL MANAGEMENT");
outtextxy(getmaxx()/3,180,"K.V.ONGC.BRD - 4 ");
outtextxy(getmaxx()-120,getmaxy()-120,"Press a Key to continue ");
}



void main()
{
	clrscr();
	char ch[120];
	int g=DETECT,h;
	initgraph(&g,&h,"c:/tc/bgi");
	fp();
	welcome();
	setcolor(8);
	outtextxy(10,30,"Do you have account");
	setbkcolor(3);
	int r=y();
	if(r==1)
	{
	closegraph();
	cout<<"Enter the user name ";
	gets(ch);
	ifstream ik;
	ik.open(ch);
	if(ik)
		{
		loading();
		menu();
		}
	else
	{cout<<"Check the user name \n It is no in our database";
	}
	}
       else
       {
       cleardevice();
       welcome();
       outtextxy(10,30,"Want to create ");
       int h=y();
       if(h==1)
	 {closegraph();
	 cout<<"Enter the user name ";
	 char k[20];
	 gets(k);
	 ifstream i(ch);
	 i.close();
	 }
	 else cout<<"Exitting in few sec ";
	 exit(120);
       }




	getch();
	closegraph();
	restorecrtmode();
}