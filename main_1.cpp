#include "TXlib.h"

void ScreenSet();
void GrassGreenDraw();

void SpruceDrawMin(int x, int y);
void SpruceDrawMax(int x, int y, int size);

void KolobokDraw(int x, int y);
void FoxDraw(int x, int y);
void WolfDraw(int x, int y);
void HareDraw(int x, int y);
void PigDraw(int x, int y);

void HomeDraw(int x, int y);

int main()
{
    ScreenSet();
    GrassGreenDraw();

    SpruceDrawMin(50, 60);
    SpruceDrawMin(120, 30);
    SpruceDrawMin(190, 60);
    SpruceDrawMax(280, 0, 2);
    SpruceDrawMin(370, 50);

    KolobokDraw(400, 300);
    FoxDraw(355, 520);
    PigDraw(500, 300);
    WolfDraw(450, 500);
    HareDraw(490, 200);

    HomeDraw(30, 310);

    return 0;
}

void ScreenSet()
{
    txCreateWindow(600, 600);

    txSetFillColor(TX_WHITE);
    txRectangle(0, 0, 600, 600);
}
void GrassGreenDraw()
{
    txSetFillColor(TX_LIGHTGREEN);
    txRectangle(0, 500, 600, 600);
}

void SpruceDrawMin(int x, int y)
{
    txSetFillColor(TX_GREEN);

    POINT spruce1[] = { {x - 40, y + 40}, {x, y}, {x + 40, y + 40} };
    POINT spruce2[] = { {x - 40, y + 80}, {x, y + 40}, {x + 40, y + 80} };
    POINT spruce3[] = { {x - 40, y + 120}, {x + 40, y + 120}, {x, y + 80} };
    POINT spruce4[] = { {x - 40, y + 160}, {x + 40, y + 160}, {x, y + 120} };

    txPolygon(spruce1, 3);
    txPolygon(spruce2, 3);
    txPolygon(spruce3, 3);
    txPolygon(spruce4, 3);

    txSetFillColor(TX_DARKGRAY);
    txRectangle(x - 10, y + 160, x + 10, y + 180);
}

void SpruceDrawMax(int x, int y, int size)
{
    txSetFillColor(TX_GREEN);

    POINT spruce1[] = { {x - 40, y + 40 * size}, {x, y}, {x + 40, y + 40 * size} };
    POINT spruce2[] = { {x - 40, y + 80 * size}, {x, y + 40 * size}, {x + 40, y + 80 * size} };
    POINT spruce3[] = { {x - 40, y + 120 * size}, {x + 40, y + 120 * size}, {x, y + 80 * size} };

    txPolygon(spruce1, 3);
    txPolygon(spruce2, 3);
    txPolygon(spruce3, 3);

    txSetFillColor(TX_DARKGRAY);
    txRectangle(x - 10, y + 120 * size, x + 10, y + 130 * size);
}

void KolobokDraw(int x, int y)
{
    txSetFillColor(TX_RED);
    txCircle(x, y, 40);

    txSetFillColor(TX_YELLOW);
    txCircle(x, y, 30);

    txSetColor(TX_RED);
    txCircle(x, y, 20);

    txSetFillColor(TX_YELLOW);
    txSetColor(TX_YELLOW);
    txRectangle(x - 20, y - 20, x + 20, y);

    txSetFillColor(TX_RED);
    txCircle(x - 10, y - 5, 5);
    txCircle(x + 10, y - 5, 5);
}

void FoxDraw(int x, int y)
{
    txSetColor(TX_ORANGE);
    txSetFillColor(TX_ORANGE);

    txCircle(x - 40, y - 120, 40);

    POINT fox1[] = { {x-90, y}, {x, y}, {x-40, y-80} };
    POINT fox2[] = { {x-15, y-135}, {x+25, y-120}, {x-15, y-105} };
    POINT fox3[] = { {x-90, y}, {x-120, y-85}, {x-105, y-130}, {x-90, y} };
    POINT fox4[] = { {x-40, y-150}, {x-20, y-180}, {x-10, y-120} };
    POINT fox5[] = { {x-40, y-150}, {x-60, y-180}, {x-70, y-120} };

    txPolygon(fox1, 3);
    txPolygon(fox2, 3);
    txPolygon(fox3, 4);
    txPolygon(fox4, 3);
    txPolygon(fox5, 3);
}

void WolfDraw(int x, int y)
{
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    POINT wolf[] =
    {
    {x - 90, y - 10},  {x - 150, y + 40}, {x - 120, y + 70}, {x - 30, y + 50},  {x - 30, y + 90},
    {x, y + 80},       {x + 70, y + 100}, {x + 80, y + 80},  {x + 120, y + 80}, {x + 110, y + 40},
    {x + 140, y + 40}, {x + 130, y},      {x + 150, y},      {x + 120, y - 30}, {x + 100, y - 40},
    {x + 120, y - 40}, {x + 80, y - 50},  {x + 90, y - 60},  {x + 60, y - 80},  {x + 70, y - 90},
    {x, y - 110},      {x - 10, y - 120}, {x - 30, y - 130}, {x - 30, y - 110}, {x - 20, y - 90},
    {x - 50, y - 90},  {x - 60, y - 80},  {x - 70, y - 100}, {x - 90, y - 110}, {x - 90, y - 80},
    {x - 80, y - 70},  {x - 100, y - 30}
    };
    txPolygon(wolf, 32);

    txSetColor(TX_LIGHTGRAY, 5);
    txCircle(x - 60, y - 30, 3);
}

void HareDraw(int x, int y)
{
    txSetColor(TX_GRAY);
    txSetFillColor(TX_GRAY);
    POINT hare[] =
    {
    {x, y},           {x + 10, y + 50}, {x + 20, y + 50}, {x + 10, y + 30}, {x + 10, y},
    {x + 20, y - 10}, {x + 30, y - 10}, {x + 40, y - 20}, {x + 20, y - 40}, {x + 10, y - 70},
    {x, y - 90},      {x - 10, y - 70}, {x + 10, y - 40}, {x - 10, y - 20}, {x - 60, y},
    {x - 70, y + 30}, {x - 80, y + 20}, {x - 80, y + 30}, {x - 60, y + 50}, {x - 10, y + 50},
    {x - 20, y + 40}, {x - 30, y + 40}
    };
    txPolygon(hare, 22);

    txSetColor(TX_BLACK, 5);
    txCircle(x + 20, y - 30, 3);
}

void PigDraw(int x, int y)
{
    txSetColor(TX_PINK);
    txSetFillColor(TX_PINK);
    POINT pig[] =
    {
    {x, y},           {x, y - 5},       {x + 5, y - 5},   {x + 15, y - 10}, {x + 20, y - 20},
    {x + 30, y - 25}, {x + 25, y - 20}, {x + 30, y - 20}, {x + 30, y - 15}, {x + 32, y - 20},
    {x + 45, y - 15}, {x + 50, y - 10}, {x + 75, y - 10}, {x + 90, y + 5},  {x + 80, y},
    {x + 80, y + 15}, {x + 75, y + 15}, {x + 75, y + 25}, {x + 70, y + 25}, {x + 70, y + 15},
    {x + 60, y + 15}, {x + 40, y + 15}, {x + 35, y + 20}, {x + 35, y + 25}, {x + 30, y + 25},
    {x + 30, y + 15}, {x + 25, y + 10}, {x + 15, y + 5},  {x + 5, y + 5},   {x + 15, y}
    };
    txPolygon(pig, 30);
}

void HomeDraw(int x, int y)
{
    txSetColor(TX_RED);
    txSetFillColor(TX_RED);
    txRectangle(x, y, x + 200, y + 200);

    txSetColor(TX_YELLOW);
    txSetFillColor(TX_YELLOW);
    txRectangle(x + 60, y + 60, x + 140, y + 140);

    txSetColor(TX_RED, 5);

    POINT home1[] =
    {
    {x + 80, y + 200},  {x + 80, y + 220},  {x, y + 240},       {x + 90, y + 230}, {x + 100, y + 260},
    {x + 110, y + 230}, {x + 200, y + 240}, {x + 120, y + 220}, {x + 120, y + 200}
    };
    POINT home2[] = { {x, y},         {x+100, y-95},  {x+200, y} };
    POINT home3[] = { {x+75, y+100},  {x+80, y+85},   {x+100, y+100} };
    POINT home4[] = { {x+125, y+100}, {x+120, y+85},  {x+100, y+100} };
    POINT home5[] = { {x+91, y+123},  {x+109, y+123}, {x+100, y+100} };


    txPolygon(home1, 9);
    txSetColor(TX_YELLOW);
    txPolygon(home2, 3);

    txTextOut(x + 35, y + 15, "РОСПОТРЕБНАДЗОР");

    txSetFillColor(TX_BLACK);
    txCircle(x + 100, y + 100, 30);

    txSetFillColor(TX_YELLOW);
    txCircle(x + 100, y + 100, 25);

    txSetFillColor(TX_BLACK);

    txPolygon(home3, 3);
    txPolygon(home4, 3);
    txPolygon(home5, 3);

    txCircle(x + 100, y + 100, 5);
}

