#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>

int main()
{
	int x,y;
	int fx=300,fy=300;
	int dir,direction,i;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	
	x=200,y=200;
	
	//initial-food
	setfillstyle(1,GREEN);
	bar(fx,fy,fx+10,fy+10);

	for(;;)
	{
		if(kbhit())
			break;

		setfillstyle(1,BLACK);
		floodfill(1,1,WHITE);
		
		//boundary
		setfillstyle(1,GREEN);
		bar(0,0,640,10);		 //top bar
		bar(0,470,640,480);	 	 //bottom bar
		bar(0,0,10,480); 		 //left bar
		bar(630,0,640,480);		 //right bar

		setfillstyle(1,RED);
		bar(x,y,x+10,y+10);

		if(x==fx && y==fy)
		{
			do
			{
				fx=(10+rand()%620);
				fy=(10+rand()%460);
			}
			while(getpixel(fx,fy)!=0 && fx >= 20 && fy >= 20);

			fx=fx/10;
			fx=fx*10;

			fy=fy/10;
			fy=fy*10;
		}

		setfillstyle(1,YELLOW);
		bar(fx,fy,fx+10,fy+10);

			if(x>fx)
				direction=1;
			else if(x<fx)
				direction=3;
			else if(y>fy)
				direction=5;
			else if(y<fy)
				direction=2;
			else
				dir=0;

			switch(direction)
			{
				case 3:
					x+=10;
					direction=1;
					break;
				case 1:
					x-=10;
					direction=2;
					break;
				case 5:
					direction=3;
					y-=10;
					break;
				case 2:
					direction=4;
					y+=10;
					break;
				case 0:
					if(direction==1)
						x+=10;
					else if(direction==2)
						x-=10;
					else if(direction==3)
						y-=10;
					else if(direction==4)
						y+=10;
					else
						dir=0;
					break;

			}
			delay(50);
	}
	getch();
	closegraph();
	return 0;
}