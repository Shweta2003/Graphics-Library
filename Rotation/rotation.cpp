#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{
    
    int a; int b; int c; int d;
    cin >> a >> b >> c >> d;
    int an;
    int bn;
    int cn;
    int dn;
    float r;
    cout << "enter degree of rotation : ";
    cin >> r;
    double sinv = sin(r * 3.14 / 180);
    double cosv = cos(r * 3.14 / 180);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    
    int ox = getmaxx() / 2;
    int oy = getmaxy() / 2;
    line(ox, 0, ox, oy * 2);
    line(0, oy, ox * 2, oy);
    a += ox;
    b = oy - b;
    c += ox;
    d = oy - d;
    line(a,b,c,d);
    setcolor(GREEN);
    an = ox + (a - ox) * cosv - (b - oy) * sinv;
    bn = oy + (a - ox) * sinv + (b - oy) * cosv;
    cn = ox + (c - ox) * cosv - (d - oy) * sinv;
    dn = oy + (c - ox) * sinv + (d - oy) * cosv;
    line(an,bn,cn,dn);
    getch();
    closegraph();
    return 0;
}