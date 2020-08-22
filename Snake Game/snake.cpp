#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

bool gameover;
string name;

int x,y,fx,fy,score,i,j,k,ntail=0,difficulty,a;
vector<int> tailx,taily;

const int n=15,m=30;
char dir,c;


void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x; coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void setup()
{
	system("cls");

    gameover=false; dir=0;
	x=n/2;
	y=m/2; y=2*(y/2);
    a=0;

   	 while(!a)
   	 {
   	 	fx=rand()%n;
        fy=rand()%m; fy=2*(fy/2);
        for(i=0;i<ntail;i++)
        {
        	if(fx==tailx[i]&fy==taily[i]) break;
        } 
        if(i==ntail) a=1;
   	 }

   	
   for(i=-1;i<=n;i++)
	  { 
   	 for(j=-1;j<=m;j++)
		{
			if(i==-1|i==n) {gotoxy(j+2,i+2);c=219; cout<<c;}	
            else if(j==-1) {gotoxy(j+++2,i+2); c=219; cout<<c<<c;}
            else if(j==m) {gotoxy(j+2,i+2);  c=219;cout<<c<<c; }       			
		}
		if(i==-1|i==n){char c=219; cout<<c;}
	  }
}


void draw()
{
   
	gotoxy(1,19);
	cout<<name<<"'s SCORE: "<<score<<endl;

 if(tailx.size()>ntail+1){tailx.pop_back(),taily.pop_back();}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
		    if(i==x&j==y) {gotoxy(j+3,i+2);c=178; cout<<c;}			
			else if(i==fx&j==fy) {gotoxy(j+3,i+2);char c=254; cout<<c;}	
			else 
				{ 
					for(k=0;k<tailx.size();k++)
					{
						if(i==tailx[k]&j==taily[k]) break;
					}
					if(k<ntail) {gotoxy(j+3,i+2);c=177; cout<<c;}
					else if(k==ntail){gotoxy(j+3,i+2);cout<<' ';}
	
				}
		}
	} 
}

void input()
{
	if(_kbhit())
    {
		switch(_getch())
		{
			case 'a': if(dir!='R') dir='L'; break;
			case 'd': if(dir!='L') dir='R'; break;
			case 'w': if(dir!='D') dir='U'; break;
			case 's': if(dir!='U') dir='D'; break;
			case 'x': gameover=true; break;
		}
	}
}

void logic()
{
	for(i=0;i<ntail;i++)
		if(tailx[i]==x&taily[i]==y) gameover=true;
       
    tailx.insert(tailx.begin(),x);
	taily.insert(taily.begin(),y);
	
   	if(dir=='L') y-=2;
   	if(dir=='R') y+=2;
   	if(dir=='U') x--; 
   	if(dir=='D') x++;

    (x<0)?(difficulty==2)?gameover=true:x=n+x:x=x;
    (x>n-1)?(difficulty==2)?gameover=true:x=n-x:x=x;
    (y<0)?(difficulty==2)?gameover=true:y=m+y:y=y;
    (y>m-1)?(difficulty==2)?gameover=true:y=m-y:y=y;

    if(x==fx&y==fy)
    {
   	  score+=(difficulty==2)?20:10;
   	  a=0;
   	  while(!a)
   	  {
   	 	fx=rand()%n;
        fy=rand()%m; fy=2*(fy/2);  
        for(i=0;i<ntail;i++)
        {
        	if(fx==tailx[i]&fy==taily[i]) break;
        } 
        if(i==ntail) a=1;
   	  }   	 
   	  ntail++;
    }
}

int main()
{
    system("mode con: lines=22 cols=44");
	system("cls");
	cout<<"ENTER USER NAME: ";
	cin>>name;

	system("cls");

    cout<<"INSTRUCTIONS:"<<endl<<"UP -> w"<<endl<<"DOWN -> s"<<endl<<"LEFT -> a"<<endl<<"RIGHT -> d"<<endl<<"END GAME -> x"<<endl;
	cout<<"CHOOSE DIFFICULTY :"<<endl<<"1. EASY"<<endl<<"2. HARD"<<endl;
	cin>>difficulty;

    setup();

	while(!gameover)
	{
		draw();
		input();
		logic();
		delay(120);
	}

	system("cls");
	for(i=-1;i<=n;i++)
	  { 
   	 for(j=-1;j<=m;j++)
		{
			if(i==-1|i==n) {gotoxy(j+2,i+2);c=219; cout<<c;}	
            else if(j==-1) {gotoxy(j+++2,i+2); c=219; cout<<c<<c;}
            else if(j==m) {gotoxy(j+2,i+2);  c=219;cout<<c<<c; }   
            else if(i==n/2-1&j==m/3) {gotoxy(j+2,i+2);cout<<"GAME OVER";}    
            else if(i==n/2&j==m/3-1) {gotoxy(j+2,i+2);cout<<"SCORE: "<<score; }			
		}
		if(i==-1|i==n){char c=219; cout<<c;}
	  }
}
