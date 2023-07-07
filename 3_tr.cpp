#include<bits/stdc++.h>
#include<bits/graphics.h>

using namespace std;
int points,tx,ty;

void draw(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        line(x[i],y[i],x[(i+1)%points],y[(i+1)%points]);
    }
}

void translate(vector<int> &x, vector<int> &y){
    for(int i=0;i<points;i++){
        x[i]+=tx;
        y[i]+=ty;
    }
}

int main()
{
    initwindow(700,700,"Translation",200,20);
    vector<int> x(100),y(100);
    cout << "Enter total polygon vectices : ";
    cin >> points;
    cout << "Enter the vectices coordinates : ";
    for(int i=0;i<points;i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "Enter the translation factors : ";
    cin >> tx >> ty;
    setcolor(2);
    draw(x,y);
    translate(x,y);
    setcolor(4);
    draw(x,y);
    getch();
}