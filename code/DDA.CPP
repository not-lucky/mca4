#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawDDALine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        // putpixel((x), (y), WHITE);
        x += Xinc;
        y += Yinc;
        putpixel(floor(x + 0.5), floor(y + 0.5), WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Call drawDDALine with appropriate arguments
    drawDDALine(100, 100, 400, 400);

    getch();
    closegraph();
    return 0;
}