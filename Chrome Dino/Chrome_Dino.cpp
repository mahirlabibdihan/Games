 #include<bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include<conio.h>
using namespace std;

int t,i,dir=0,d=1,p=0,score=0;
bool gameover;
const char a=219,b=220,c=223;

void delay(unsigned int ms)
{
    clock_t goal = ms + clock();
    while (goal > clock());
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x; coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

void setup()
{
    system("cls");
    gotoxy(10,27);printf("Press X to Exit, Press Space to Jump");
    gotoxy(62,2);printf("SCORE : ");
    gotoxy(0,25);for(int i=0;i<80;i++)cout<<c;
}
 

void dino()
{  
   gotoxy(0,15-t);cout<<"                      ";
   gotoxy(0,16-t);cout<<"          "<<b<<a<<c<<a<<a<<a<<a<<b;                   //cout<<"          ▄█▀████▄ "<<endl;
   gotoxy(0,17-t);cout<<"          "<<a<<a<<a<<a<<a<<a<<a<<a;                   //cout<<"          ████████ "<<endl;
   gotoxy(0,18-t);cout<<"          "<<a<<a<<a<<a<<a<<c<<c<<c;                   //cout<<"          █████▀▀▀ "<<endl;
   gotoxy(0,19-t);cout<<"  "<<a<<"      "<<b<<a<<a<<a<<a<<c<<c<<c<<"  ";        //cout<<"  █      ▄████▀▀▀  "<<endl;
   gotoxy(0,20-t);cout<<"  "<<a<<a<<b<<"  "<<b<<a<<a<<a<<a<<a<<a<<b<<b<<b<<"  ";//cout<<"  ██▄  ▄██████▄▄▄  "<<endl;
   gotoxy(0,21-t);cout<<"  "<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<"  "<<c<<"  ";//cout<<"  ▀███████████  ▀  "<<endl;
   gotoxy(0,22-t);cout<<"    "<<c<<a<<a<<a<<a<<a<<a<<a<<c<<"     ";             //cout<<"    ▀███████▀      "<<endl;
   gotoxy(0,23-t);
if(dir==2|dir==1)
{
   gotoxy(0,23-t);cout<<"     "<<a<<a<<c<<' '<<c<<a<<"       ";                 //cout<<"     ██▀ ▀█       "<<endl;
   gotoxy(0,24-t);cout<<"     "<<a<<b<<"   "<<a<<b<<"      ";                   //cout<<"     █▄   █▄      "<<endl;
if(t>0)
   gotoxy(0,25 -t);cout<<"                     ";
}
else if(d==1)
{
   gotoxy(0,23-t);cout<<"     "<<c<<a<<a<<c<<"  "<<c<<c<<c<<"    ";             //cout<<"    ▀██▀  ▀▀    "<<endl;
   gotoxy(0,24-t);cout<<"      "<<a<<b<<"         ";d=2;                        //cout<<"      █▄         "<<endl;
}
else if(d==2)
{
   gotoxy(0,23-t);cout<<"      "<<c<<a<<b<<" "<<c<<a<<"    ";                   //cout<<"     ▀█▄ ▀█    "<<endl;
   gotoxy(0,24-t);cout<<"           "<<a<<b<<"   ";d=1;                         //cout<<"          █▄   "<<endl;
}
}

void obs()
{
   gotoxy(76-p,21);cout<<a<<"   "<<a<<"  ";  //cout<<"█   █"<<endl;
   gotoxy(76-p,22);cout<<a<<"   "<<a<<"  ";  //cout<<"█   █"<<endl;
   gotoxy(76-p,23);cout<<c<<c<<a<<c<<c<<"  ";//cout<<"▀▀█▀▀"<<endl; 
   gotoxy(76-p,24);cout<<"  "<<a<<"  "<<"  ";//cout<<"  █  "<<endl;
}

void input()
{
	if(_kbhit())
    {
		switch(_getch())
		{
			case ' ': if(dir==0) dir=1; break;
			case 'x': gameover=true; break;
		}
	}
}
void logic()
{
	if(76-p<=16&76-p>=2&(t==0|(dir==2&t<=2))) gameover=true;
    if(dir==1&t<9) t++;
    else if(dir==1&t==9) {dir=2; t--;}
    else if(dir==2&t>0) t--;
    else dir=0;

    if(p==76) 
    {
     p=0; score+=10;
     gotoxy(0,21);cout<<"       ";
     gotoxy(0,22);cout<<"       ";
     gotoxy(0,23);cout<<"       ";
     gotoxy(0,24);cout<<"       ";    	
     gotoxy(70,2);cout<<"     ";
     gotoxy(70,2);cout<<score;}
    p+=2;
}


int main()
{
    system("mode con: lines=29 cols=80");
	setup();

	while(!gameover)
	{
	   dino();
	   obs();
       input();
       logic();  
       delay(100);   
	}
}