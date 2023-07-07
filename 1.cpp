#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;
int main()
{
    initwindow(700,700,"NationalFlag",200,20);
    setcolor(7);
    rectangle(200,200,400,320);
    setfillstyle(SOLID_FILL,2);
    floodfill(250,300,7);
    setcolor(6);
    circle(300,260,40);
    setfillstyle(SOLID_FILL,4);
    floodfill(300,260,6);
    rectangle(196,195,200,500);
    setfillstyle(SOLID_FILL,7);
    floodfill(197,197,6);
    ellipse(198,500,0,360,100,20);
    setfillstyle(SOLID_FILL,5);
    floodfill(198,505,6);
    getch();
}