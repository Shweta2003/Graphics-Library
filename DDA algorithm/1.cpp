#include <graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
int sign(int a){
    if (a > 0){
        return 1;
    }
    else if (a < 0){
        return -1;
    }
    else{
        return 0;
    }
}

// dda line algorithm
void dda(int x1, int y1, int x2, int y2)
{
    float dx;
    float dy;
    float length;
    if (x2 > x1){
        dx = x2 - x1;
    }
    else{
        dx = x1 - x2;
        float temp = x2;
        x2 = x1;
        x1 = temp;
    }

    if (y2 > y1){
        dy = y2 - y1;
    }
    else{
        dy = y1 - y2;
        float temp = y2;
        y2 = y1;
        y1 = temp;
    }

    if (dx > dy)
    {
        length = dx;
    }
    else
    {
        length = dy;
    }
    float xdiff = dx / length;
    float ydiff = dy / length;
    float x = x1 + 0.5*sign(length);
    float y = y1 + 0.5*sign(length);
    int i = 0;
    while (i < length)
    {
        putpixel(x, y, WHITE);
        x = x + xdiff;
        y = y + ydiff;
        i++;
    }
}
int main(){
    int gd = DETECT,gm;
    int get_x1,get_y1,get_x2,get_y2;
    cout << "enter initial coordinates x1 and y1 : "<<endl;
    cin >> get_x1 >> get_y1;
    cout << "enter last coordinates x2 and y2 : "<<endl;
    cin >> get_x2 >> get_y2;

    initgraph(&gd,&gm,NULL);
    int a = getmaxx()/2;
    int b = getmaxy()/2;
    
    dda(get_x1,get_y1,get_x2,get_y2);
    
    getch();
    closegraph();

    return 0;
}
