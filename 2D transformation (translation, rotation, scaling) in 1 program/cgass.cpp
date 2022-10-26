#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void object(int vertices[][2], int num)
{
    int ox = getmaxx() / 2;
    int oy = getmaxy() / 2;
    if (num <= 0)
    {
        cout << "Not enough vertices" << endl;
    }
    else
    {
        for (int k = 1; k < num; k++)
        {
            line(vertices[k][0] + ox, oy - vertices[k][1], ox + vertices[k - 1][0], oy - vertices[k - 1][1]);
        }
    }
}

// translation
void translate(int vertices[][2], int num)
{
    int tvertices[num][2];
    int tx;
    int ty;
    cout << "\t\tenter x space to increase :" << endl;
    cin >> tx;
    cout << "\t\tenter y space to increase :" << endl;
    cin >> ty;
    setcolor(GREEN);
    for (int k = 0; k < num; k++)
    {
        tvertices[k][0] = vertices[k][0] + tx;
        tvertices[k][1] = vertices[k][1] + ty;
    }
    object(tvertices, num);
}

// scaling
void scale(int vertices[][2], int num)
{
    int svertices[num][2];
    int sx;
    int sy;
    cout << "\t\tenter x scaling :" << endl;
    cin >> sx;
    cout << "\t\tenter y scaling :" << endl;
    cin >> sy;
    setcolor(GREEN);

    for (int l = 0; l < num; l++)
    {
        svertices[l][0] = vertices[l][0] * sx;
        svertices[l][1] = vertices[l][1] * sy;
    }
    object(svertices, num);
}

// rotation
void rotation(int vertices[][2], int num, int ox, int oy)
{
    int rvertices[num][2];
    int an;
    int bn;
    int cn;
    int dn;
    float r;
    cout << "enter degree of rotation : ";
    cin >> r;
    double sinv = sin(r * 3.14 / 180);
    double cosv = cos(r * 3.14 / 180);
    setcolor(GREEN);
    for (int u = 1; u < num; u++)
    {
        an = ox + ((ox + vertices[u][0]) - ox) * cosv - ((oy - vertices[u][1]) - oy) * sinv;
        bn = oy + ((ox + vertices[u][0]) - ox) * sinv + ((oy - vertices[u][1]) - oy) * cosv;
        cn = ox + ((ox + vertices[u - 1][0]) - ox) * cosv - ((oy - vertices[u - 1][1]) - oy) * sinv;
        dn = oy + ((ox + vertices[u - 1][0]) - ox) * sinv + ((oy - vertices[u - 1][1]) - oy) * cosv;
        line(an, bn, cn, dn);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int ox = getmaxx() / 2;
    int oy = getmaxy() / 2;
    int num;
    int xc;
    int i;
    int yc;
    cout << "enter total number of vertices : ";
    cin >> num;

    int vertices[num][2];
    for (i = 0; i < num; i++)
    {
        cout << "enter coordinate no : " << i + 1 << endl;
        cout << "\t\t x coordinate : ";
        cin >> xc;
        vertices[i][0] = xc;
        cout << "\t\t y coordinate : ";
        cin >> yc;
        vertices[i][1] = yc;
    }
    vertices[num][0] = vertices[0][0];
    vertices[num][1] = vertices[0][1];

    char to_con = 'y';
    while (to_con == 'y')
    {
        // original object
        cleardevice();
        setcolor(WHITE);
        line(ox, 0, ox, oy * 2);
        line(0, oy, ox * 2, oy);
        setcolor(YELLOW);
        object(vertices, num + 1);

        cout << "press 1 to perform transformation" << endl;
        cout << "press 2 to perform scaling" << endl;
        cout << "press 3 to perform rotation" << endl;
        cout << "enter choice : ";
        int ask;
        cin >> ask;
        switch (ask)
        {
        case 1:

            translate(vertices, num + 1);
            break;
        case 2:
            scale(vertices, num + 1);
            break;

        case 3:
            rotation(vertices, num + 1, ox, oy);
            break;

        default:
            cout << "wrong input try again" << endl;
            break;
        }
        cout << "do you want to continue(y/n) : ";
        cin >> to_con;
    }
    getch();
    closegraph();
    

    return 0;
}