#include<bits/stdc++.h>
#include<bits/graphics.h>

#define Sin(x) sin(x*acos(-1)/180)
#define Cos(x) cos(x*acos(-1)/180)

using namespace std;
int points,px,py;
double angle;

void draw(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        line(x[i],y[i],x[(i+1)%points],y[(i+1)%points]);
    }
}

void rotate(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        int xShift = x[i] - px, yShift = y[i] - py;
        x[i] = px + (xShift * Cos(angle)) - (yShift * Sin(angle));
        y[i] = py + (xShift * Sin(angle)) + (yShift * Cos(angle));

        // x[i] = (px + ((x[i]-px) * cos(angle*acos(-1)/180)) - ((y[i]-py)*sin(angle*acos(-1)/180)));
        // y[i] = (py + ((x[i]-px) * sin(angle*acos(-1)/180)) + ((y[i]-py)*cos(angle*acos(-1)/180)));
        // In comments you are updating the x[i] value using the updated x[i], which leads to incorrect results. 
    }
}

int main()
{
    initwindow(700,700,"Scaling",200,20);
    vector<int> x(100),y(100);
    cout << "Enter total polygon vectices : ";
    cin >> points;
    cout << "Enter the vectices coordinates : ";
    for(int i=0;i<points;i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "Enter the rotation angle and pivot points : ";
    cin >> angle >> px >> py;
    setcolor(2);
    draw(x,y);
    rotate(x,y);
    setcolor(4);
    draw(x,y);
    getch();
}