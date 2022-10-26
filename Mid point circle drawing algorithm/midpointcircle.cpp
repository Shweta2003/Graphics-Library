//midpoint circle drawing algorithm
#include <iostream>
#include <graphics.h>
using namespace std;

void make_circle(int r){
    int x = 0;
    int y = r;
    int a = getmaxx()/2;
    int b = getmaxy()/2;
    putpixel(a,b-y,WHITE);
    putpixel(a+x,b,WHITE);
    putpixel(a,b-y,WHITE);
    putpixel(a-x,b,WHITE);
    int ptr = 1 - r;
    while (x < y){
        if (ptr >= 0){
            ptr += 1 + 2*x - 2*y;
            x += 1;
            y -= 1;
        }
        else{
            ptr += 1 + 2*x;
            x +=1;
        }
    delay(100);
    putpixel(a+x,b-y,WHITE);
    putpixel(a+y,b-x,WHITE);
    putpixel(a+y,b+x,WHITE);
    putpixel(a+x,b+y,WHITE);
    putpixel(a-x,b+y,WHITE);
    putpixel(a-y,b+x,WHITE);
    putpixel(a-y,b-x,WHITE);
    putpixel(a-x,b-y,WHITE);

    }
}

int main()
{
    
    int gd = DETECT , gm;
    int n;
    cout << "enter radius of circle : ";
    cin >> n;
    initgraph(&gd, &gm, NULL );
    delay(500);
    make_circle(n);
    
    getch();
    closegraph();
    return 0;
}