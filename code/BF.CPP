#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void bfill(int x, int y, int fillcolor, int boundrycolor);
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboC3\\BGI");
    setcolor(BLACK);
    circle(300, 200, 40);
    bfill(300, 200, 4, 5);

    getch();
}
void bfill(int x, int y, int fillcolor, int boundrycolor)
{
    if (getpixel(x, y) != boundrycolor && getpixel(x, y) != fillcolor)
    {
        putpixel(x, y, fillcolor);
        bfill(x + 1, y, fillcolor, boundrycolor);
        bfill(x - 1, y, fillcolor, boundrycolor);
        bfill(x, y + 1, fillcolor, boundrycolor);
        bfill(x, y - 1, fillcolor, boundrycolor);
    }
}
