#include<bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
/*
▄

█

▀

▓

↕A*/

int p=0,i,j,score=0,k;

char a=219,b=220,c=223,d=178,e=254,f=157;
bool gameover;
char dir;

vector<vector<int>> bull(90,vector<int>(35)),obj(90,vector<int>(35));

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
	gotoxy(0,35);for(int i=0;i<90;i++)cout<<c;

}

void shooter()
{
  gotoxy(4,37); cout<<"SCORE : "<<score; 
  gotoxy(41+p,32);cout<<"   ^   "<<endl;              //cout<<"   ^   "; 
  gotoxy(41+p,33);cout<<"  |"<<d<<"|  "<<endl;        //cout<<"  |▓|  ";
  gotoxy(41+p,34);cout<<" "<<b<<a<<c<<a<<b<<" "<<endl;//cout<<" ▄█▀█▄ ";
}

void bullet()
{
	for(i=0;i<90;i++)
		for(j=0;j<35;j++)
   	    	if(bull[i][j]) { gotoxy(i,j); if(bull[i][j]==1){cout<<e; gotoxy(i,j+1); cout<<' ';}else cout<<a;}
    gotoxy(0,0); for(i=0;i<90;i++)cout<<' ';
}

void object()
{
    for(i=89;i>-1;i--)
   	     for(j=35;j>-1;j--)
   	    	   if(obj[i][j]) 
   	    	   	 {if(!bull[i][j]&j<35) {gotoxy(i,j); cout<<f;obj[i][j]++; } else {obj[i][j]=0; if(bull[i][j]) score+=10;} if(j>0) gotoxy(i,j-1); cout<<' ';}
}

void input()
{
	if(_kbhit())
    {
		switch(_getch())
		{
			case 'a': if(p>-41)p--; break;
			case 'd': if(p<42)p++; break;
			case 'w': bull[41+p+3][32]=1;bull[41+p+3][31]=2;bull[41+p+4][32]=1;bull[41+p+2][32]=1;break;
			case ' ': bull[41+p+3][32]=1;break;
			case 'x': gameover=true; break;
		}
	}

}

void logic()
{
	    if(obj[41+p+3][32]|obj[41+p+2][33]|obj[41+p+4][33]|obj[41+p+1][34]|obj[41+p+5][34]) gameover=true;
        clock_t a=clock()/50; 
   	    if(a%50==0){k=rand()%89; obj[k][0]++;}

   	    for(i=0;i<90;i++)
   	    	for(j=0;j<35;j++)
   	    	    if(bull[i][j]) { if(j>0) bull[i][j-1]=bull[i][j];bull[i][j]=0;}

   	    for(i=89;i>-1;i--)
   	    	for(j=34;j>-1;j--)
   	    	    if(obj[i][j]==20) {obj[i][j]=0; if(j<35) obj[i][j+1]++; else {gotoxy(i,j); cout<<' ';}}

}

int main()
{
	system("mode con: lines=40 cols=90");
	setup();
	while(!gameover)
	{
	   shooter();
	   bullet();
	   object();
       input();
       logic();  
       delay(50);   
	}
	system("cls");
}
