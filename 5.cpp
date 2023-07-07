#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "BresenhamLine");

    int x1,x2,y1,y2,c;
    cout << "Enter the end points : \n";
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1>x2) {swap(x1,x2); swap(y1,y2);}

    if(abs((y1-y2)/(x1-x2))>1) {cout << "Slope must be less then or equal to 1\n"; return 0;}

    int dx=abs(x1-x2),dy=abs(y1-y2),p=2*dy-dx;
    if(y1>y2) c=-1;
    else  c=1;
    int y=y1;
    for(double x=x1;x<=x2;x++){
        putpixel(x,y,7);
        if(p<0){
            p+= 2*dy;
        }
        else{
            y+=c;
            p+=2*(dy-dx);
        }
    }


    getch();
    closegraph();
    return 0;
}