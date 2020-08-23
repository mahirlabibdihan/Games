#include<bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include<conio.h>
using namespace std;

char c=223;
bool gameover,start;

int p=0,bx=50,by=44,dirx=0,diry=0,score=0;

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
  gotoxy(1,46);for(int i=0;i<99;i++)cout<<c;

}
void bat()
{
  gotoxy(47+p,45);cout<<" "<<c<<c<<c<<c<<c<<c<<c<<" "<<endl;//cout<<" ▀▀▀▀▀▀▀ ";
}

void ball()
{
      gotoxy(4,48); cout<<"SCORE : "<<score; 
      gotoxy(bx,by); cout<<"   ";
      bx+=dirx; by+=diry;  
      if(bx<0)bx=0; else if(bx>98) bx=98;
      if(by<0)by=0; else if(by>45) by=45;    
      gotoxy(bx+(start?0:p),by); cout<<" o ";
}
void input()
{
    if(_kbhit())
    {
      switch(_getch())
      {
        case 'a': if(p>-47)p--; break;
        case 'd': if(p<45)p++; break;
        case ' ': if(!start){start=true; diry=-2;bx+=p;} break;
        case 'x': gameover=true; break;
      }
  }
}
void logic()
{
   if(diry>0&by>=44)
   {  
      if(bx+1==47+p+0) {dirx=-3;diry=-1; score+=10;}
      else if(bx+1==47+p+1) {dirx=-2;diry=-1;score+=10;}
      else if(bx+1==47+p+2) {dirx=-2;diry=-2;score+=10;}
      else if(bx+1==47+p+3) {dirx=-1;diry=-2;score+=10;}
      else if(bx+1==47+p+4) {dirx=0;diry=-2;score+=10;}
      else if(bx+1==47+p+5) {dirx=1;diry=-2;score+=10;}
      else if(bx+1==47+p+6) {dirx=2;diry=-2;score+=10;}
      else if(bx+1==47+p+7) {dirx=2;diry=-1;score+=10;}
      else if(bx+1==47+p+8) {dirx=3;diry=-1;score+=10;}
      else if(by==45) gameover=true;
   }
   else if(diry<0&by==0) diry=-diry;   
   else if(dirx>0&bx==98) dirx=-dirx;
   else if(dirx<0&bx==0) dirx=-dirx;
   else if(diry>0&by>44) gameover=true;   
}

int main()
{
	system("mode con: lines=50 cols=101");
	setup();
	for(int i=0;!gameover;i++)
	{
	     bat();
       if(i%5==0|!start)ball();
       input();
       logic();  
       delay(20);   
	}

}