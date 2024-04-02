#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void ff(int sx, int sy, int fc, int oc)
{
    if (getpixel(sx, sy) == oc)
    {
        putpixel(sx, sy, fc);
        ff(sx + 1, sy, fc, oc);
        ff(sx - 1, sy, fc, oc);
        ff(sx, sy + 1, fc, oc);
        ff(sx, sy - 1, fc, oc);
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
    setcolor(1);
    line(100, 100, 150, 100);
    setcolor(2);
    line(100, 100, 100, 150);
    setcolor(3);
    line(100, 150, 150, 150);
    setcolor(4);
    line(150, 150, 150, 100);
    ff(125, 125, GREEN, 0);
    getch();
}