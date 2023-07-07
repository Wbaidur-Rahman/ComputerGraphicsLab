#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;

int x_min=150,x_max=320,y_min=140,y_max=260;

struct aline{
	int x1,y1,x2,y2;
};

void draw(struct aline &ln){
	line(ln.x1,ln.y1,ln.x2,ln.y2);
}

int region(double x,double y){
	int r=0;
	if(x<x_min) r+=1;
	if(x>x_max) r+=2;
	if(y>y_max) r+=4;
	if(y<y_min) r+=8;

	return r;
}

void clip(struct aline &ln){
	int x1=ln.x1,y1=ln.y1,x2=ln.x2,y2=ln.y2;

	int r1,r2;
	r1 = region(x1,y1);
	r2 = region(x2,y2);

	if((r1|r2) == 0) {cout << "inside\n"; return;}
	if(r1&r2){
		x1=x2;
		y1=y2;
		 {cout << "outside\n"; return;}
	} 
	
	double x,y;
	int r;
	double m = (double)(y2-y1)/(x2-x1);

	while(1){
		if(r1)	r=r1;
		else if(r2) r=r2;
		else break;

		if(r&1){
			x=x_min;
			y=y1+(double)m*(x-x1);
		}
		else if(r&2){
			x=x_max;
			y=y1+(double)m*(x-x1);
		}
		else if(r&4){
			y=y_max;
			x=x1+(double)(1/m)*(y-y1);
		}
		else if(r&8){
			y=y_min;
			x=x1+(double)(1/m)*(y-y1);
		}

		if(r1) {
			ln.x1=x,x1=x;
			ln.y1=y,y1=y;
			r1=region(ln.x1,ln.y1);
		}
		else{
			ln.x2=x,x2=x;
			ln.y2=y,y2=y;
			r2=region(ln.x2,ln.y2);
		}
	}

}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	rectangle(x_min,y_min,x_max,y_max);

	struct aline lines[3];

	lines[0].x1=100,lines[0].y1=100,lines[0].x2=400,lines[0].y2=300;
	lines[1].x1=170,lines[1].y1=160,lines[1].x2=400,lines[1].y2=140;
	lines[2].x1=200,lines[2].y1=100,lines[2].x2=300,lines[2].y2=400;

	for(int i=0;i<3;i++) draw(lines[i]);
	cout << "Press y to clip the lines\n";
	getch();

	setfillstyle(SOLID_FILL,BLACK);
	floodfill(1,1,1);
	rectangle(x_min,y_min,x_max,y_max);

	for(int i=0;i<3;i++)
		clip(lines[i]);

	setcolor(4);
	for(int i=0;i<3;i++) draw(lines[i]);
	
	getch();
	closegraph();
}