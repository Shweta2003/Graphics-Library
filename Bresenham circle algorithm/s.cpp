#include <iostream>
#include<graphics.h>
#include <conio.h>
#include <string.h>
using namespace std;


void bresenham_circle(int x, int r)
{
    int cx = 0;
    int cy = r;
    // make_circle(cx,cy);
    float d = 3 - 2*r;
    while (cx <= cy)
    {
        if (d >= 0)
        {
            d += (cx - cy) * 4 + 10;
            cx ++;
            cy --;

        }
        else
        {
            d += 4 * cx + 6;
            cx ++;


        }
        int a = 250;
        int b = 250;
        putpixel(a + cx, b + cy, WHITE);
        putpixel(a - cx, b + cy, WHITE);
        putpixel(a + cx, b - cy, WHITE);
        putpixel(a - cx, b - cy, WHITE);
        putpixel(a + cy, b + cx, WHITE);
        putpixel(a + cy, a - cx, WHITE);
        putpixel(a - cy, b + cx, WHITE);
        putpixel(a - cy, b - cx, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout << "enter radius of circle : " ;
    int rad;
    cin >> rad;
    delay(50);
    bresenham_circle(0, rad);
    getch();
    closegraph();
    return 0;
}