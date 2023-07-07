#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;
int points;
double sx,sy;

void draw(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        line(x[i],y[i],x[(i+1)%points],y[(i+1)%points]);
    }
}

void scale(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        x[i]*=sx;
        y[i]*=sy;
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
    cout << "Enter the scaling factors : ";
    cin >> sx >> sy;
    setcolor(2);
    draw(x,y);
    scale(x,y);
    setcolor(4);
    draw(x,y);
    getch();
}