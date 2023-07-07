#include<bits/stdc++.h>
#include<bits/graphics.h>

void rect(){
    setcolor(7);
    rectangle(200,200,400,320);
    setfillstyle(SOLID_FILL,2);
    floodfill(250,300,7);
}

void trin()
{
    setcolor(5);
    line(300,250,240,390);
    line(300,250,360,390);
    line(240,390,360,390);
    setfillstyle(SOLID_FILL,4);
    floodfill(300,380,5);
}

void cir(){
    setcolor(3);
    circle(210,340,70);
    setfillstyle(SOLID_FILL,6);
    floodfill(210,340,3);
}

using namespace std;
int main()
{
    initwindow(700,700,"HiddenSurface",200,20);
    string seq;
    cout << "Give the sequence : ";
    cin >> seq;
    for(auto it : seq){
        if(it=='C') cir();
        else if(it=='R') rect();
        else trin();
    }
    
    getch();
}