#include<bits/stdc++.h>
#include <bits/graphics.h>

double bezierfunc(int n, int i, double u) {
    double coeff = 1.0;
    for (int j = 1; j <= i; j++)
        coeff *= (double)(n - j + 1) / j;
    return coeff * pow(u, i) * pow(1 - u, n - i);
}

void beziercurve(const std::vector<int>& x, const std::vector<int>& y) {
    int n = x.size();
    double step = 0.0005;
    for (double u = 0; u <= 1; u += step) {
        double x1 = 0, y1 = 0;
        for (int i = 0; i < n; i++) {
            double c = bezierfunc(n - 1, i, u);
            x1 += x[i] * c;
            y1 += y[i] * c;
        }
        putpixel(x1, y1, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    std::vector<int> x = { 27, 101, 324, 437 };
    std::vector<int> y = { 243, 47, 197, 23 };
    beziercurve(x, y);

    setcolor(RED);
    for (size_t i = 0; i < x.size(); i++) {
        circle(x[i], y[i], 4);
    }

    getch();
    closegraph();
    return 0;
}
