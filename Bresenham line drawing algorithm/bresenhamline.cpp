#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void bresenham_line(int x1,int y1, int x2, int y2)
{
    int dx; int dy;
    if (x2 > x1){
        dx = x2 - x1;
    }
    else{
        dx = x1 - x2;
        int temp = x2;
        x2 = x1;
        x1 = temp;
    }
    if (y2 > y1){
        dy = y2 - y1;
    }
    else{
        dy = y1 - y2;
        int temps = y2;
        y2 = y1;
        y1 = temps;
    }
    
    int p = 2*dy - dx;
    while ((x1 != x2) && ( y1 != y2))
    {
        putpixel(x1,y1,WHITE);
        if (p >= 0){
            p += 2*dy - 2*dx;
            x1 += 1;
            y1 += 1;
        }
        else{
            p += 2*dy;
            x1 += 1;
        }

    }
}
int main()
{
    
    int gd = DETECT , gm;
    
    cout << " enter x1 and y1 : ";
    int x1,y1;
    cin >> x1 >> y1 ;
    cout << " enter x2 and y2 : ";
    int x2,y2;
    cin >> x2 >> y2;
    initgraph(&gd, &gm, NULL );
    bresenham_line(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}