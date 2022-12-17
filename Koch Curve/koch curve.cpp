#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void koch(int x1, int y1, int x2, int y2, int it){
    float pi = 3.14;
    float angle = (60*pi)/180;
    int x3 = ((2*x1) + x2)/3;
    int y3 = ((2*y1) + y2)/3;
    int x4 = ((2*x2) + x1)/3;
    int y4 = ((2*y2) + y1)/3;

    int x = x3 + ((x4 - x3)*cos(angle)) + ((y4 - y3)*sin(angle));
    int y = y3 - ((x4 - x3)*sin(angle)) + ((y4 - y3)*cos(angle));

    if (it > 1){
        koch(x1,y1,x3,y3,it-1);
        koch(x3,y3,x,y,it-1);
        koch(x,y,x4,y4,it-1);
        koch(x4,y4,x2,y2,it-1);
    }
    else{
        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}

int main()
{
    
    int gd = DETECT , gm;
    initgraph(&gd, &gm, NULL );
    char to_con = 'y';
    while(to_con == 'y'){
        cleardevice();
        int edges, x1, y1, x2, y2, it;
        cout << "enter number of edges : ";
        cin >> edges;
        for (int i = 0; i < edges ; i ++){
            cout << "enter x coordinate : ";
            cin >> x1;
            cout << "enter y coordinate : ";
            cin >> y1;
            cout << "enter x coordinate : ";
            cin >> x2;
            cout << "enter y coordinate : ";
            cin >> y2;
            cout << "enter number of iterations : ";
            cin >> it;
            cout << endl;
            koch(x1,y1,x2,y2,it);
        }
        cout << "curve printed \n";
        cout << "do you want to continue (y/n) : ";
        cin >> to_con;
    }
    getch();
    closegraph();
    return 0;
}