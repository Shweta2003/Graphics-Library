#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class clip{
    char code [4];
    int xmin = 100;
    int ymin = 100;
    int xmax = 500;
    int ymax = 400;
    public :
        void find_code(int* ,float xn,float yn);
        void screen(){
            rectangle(xmin,ymin,xmax,ymax);
        }
        void crop(int* , float m, float & , float &);
        
};
void clip :: find_code(int* code, float xn, float yn)
{
    if (yn < ymin){
        code[0] = 1;
    }
    else{
        code[0] = 0;
    }
    if (yn > ymax){
        code[1] = 1;
    }
    else{
        code[1] = 0;
    }
    if (xn > xmax){
        code[2] = 1;
    }
    else
    {
        code[2] = 0;
    }
    if (xn < xmin){
        code[3] = 1;
    }
    else{
        code[3] = 0;
    }
    
    
}   

float find_slope(float x1, float y1, float x2, float y2){
    float m = (y2 - y1) / (x2 - x1);
    return m;
}

int check(int* c, int* d)
{
    int i = 0;
    int cor = 0;
    int cand = 0;
    for (i; i < 4; i++)
    {
        if (c[i] == 0 && d[i] == 0)
        {
            cor += 1;
        }
        else
        {
            if (c[i] == 1 && d[i] == 1)
            {
                cand +=1;
            }
        }
    }
    if (cor == 4){
        return 0;
    }
    else if (cand == 4){
        return -1;
    }
    else{
        return 1;
    }
}

void clip :: crop(int* c, float m, float &x, float &y)
{
    if (c[3] == 1)
    {
        y += m * (xmin - x);
        x = xmin;
    }
    else if (c[2] == 1)
    {
        y -= m * (x - xmax);
        x = xmax;
    }
    if (c[1] == 1)
    {
        x -= (y - ymax) / m;
        y = ymax;

    }
    else if (c[0] == 1)
    { 
        x += abs(ymin - y) / m;
        
        y = ymin;
    }
}

int main()
{
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    clip c;
    c.screen();
    cout << "enter coordinates of line :" << endl;
    float x1;
    float y1;
    cout << "enter x1 coordinate : ";
    cin >> x1;
    cout << "enter y1 coordinate : ";
    cin >> y1;
    float x2;
    float y2;
    cout << "enter x2 coordinate : ";
    cin >> x2;
    cout << "enter y2 coordinate : ";
    cin >> y2;
    setcolor(RED);
    line(x1,y1,x2,y2);
    float m = find_slope(x1,y1,x2,y2);
    int incode[4];
    int ficode[4];
    c.find_code(incode, x1, y1);
    c.find_code(ficode, x2, y2);
    int tri = check(incode, ficode);
    if (tri == 0)
    {
        line(x1, y1, x2, y2);
    }
    else if (tri == -1)
    {
        cout << "nothing to do";
    }
    else
    {
        c.crop(incode, m, x1, y1);
        c.crop(ficode, m, x2, y2);
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        }
    getch();
    closegraph();
    return 0;
}