#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;

void pixel(int g,int h,int x,int y){
    putpixel(g+x,h+y,7);
    putpixel(g+x,h-y,7);
    putpixel(g-x,h+y,7);
    putpixel(g-x,h-y,7);
    putpixel(g+y,h+x,7);
    putpixel(g+y,h-x,7);
    putpixel(g-y,h+x,7);
    putpixel(g-y,h-x,7);
    delay(100);
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "MidpointCircle");

    int g=300,h=300,r=100;
    // cout << "Enter the center point and radius : \n";
    // cin >> g >> h >> r;

    int p=1-r,y=r,x=0;
    while(x<y){
        pixel(g,h,x,y);
        if(p<0){
            p+= 2*x+1;
        }
        else{
            y--;
            p+=2*x+1-2*y;
        }
        x++;
    }


    getch();
    closegraph();
    return 0;
}