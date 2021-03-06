#include "TXlib.h"

void BackgroundDraw();
void ScreenSet();
void GrassGreenDraw();
void SpruceDraw  (int x, int y, int sizeX, int sizeY, int triangleUp, COLORREF spruceColor);
void KolobokDraw (int x, int y);
void FoxDraw     (int x, int y, int tail, int legs, int earR, int earL);
void WolfDraw    (int x, int y);
void HareDraw    (int x, int y);
void PigDraw     (int x, int y, int sizeX, int sizeY, COLORREF spruceColor);
void TwitterDraw (int x, int y);
void HomeDraw    (int x, int y);

int main()
    {
    ScreenSet();

    int x = 50;
    while (x <= 800)
        {
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txClear();
        BackgroundDraw();
        FoxDraw (x, 520, x%2*10, 0, 0, 0);
        x++;
        txSleep (10);
        }
    
    KolobokDraw (400, 300);
    WolfDraw    (450, 500);
    HareDraw    (490, 200);
    PigDraw     (300, 260, 1, 1, TX_PINK);
    PigDraw     (200, 180, 2, 2, TX_PINK);
    PigDraw     (400, 300, 2, 2, TX_MAGENTA);
    TwitterDraw (250, 210);

    return 0;
    }

void ScreenSet()
    {
    txCreateWindow (1200, 600);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 600, 1200, 600);
    }

void GrassGreenDraw()
    {
    txSetFillColor (TX_LIGHTGREEN);
    txRectangle (0, 500, 1200, 600);
    }

void BackgroundDraw()
    {
    GrassGreenDraw();
    HomeDraw    (950, 290);

    int x = 50;
    while (x <= 1200)
        {
        SpruceDraw (x,   120,  1,   1, 0,  TX_GREEN);
        x+=70;
        SpruceDraw (x,   80,  1,   1, 0,  TX_YELLOW);
        x+=70;
        }

    }

void SpruceDraw (int x, int y, int sizeX, int sizeY, int triangleUp, COLORREF spruceColor)
    {
    txSetFillColor (spruceColor);
    POINT spruce[] =
    {
    {x, y},                                    {x + 20*sizeX, y},            {x + 20*sizeX + triangleUp, y - 10*sizeY},
    {x + 50*sizeX + triangleUp, y - 10*sizeY}, {x + 20*sizeX + triangleUp, y - 40*sizeY}, {x + 40*sizeX + triangleUp, y - 40*sizeY},
    {x + 20*sizeX + triangleUp, y - 60*sizeY}, {x + 30*sizeX + triangleUp, y - 60*sizeY}, {x + 10*sizeX + triangleUp, y - 80*sizeY},
    {x - 10*sizeX + triangleUp, y - 60*sizeY}, {x + triangleUp,            y - 60*sizeY}, {x - 20*sizeX + triangleUp, y - 40*sizeY},
    {x + triangleUp,            y - 40*sizeY}, {x - 30*sizeX + triangleUp, y - 10*sizeY}, {x + triangleUp,            y - 10*sizeY}
    };
    txPolygon (spruce, 15);
    }

void KolobokDraw (int x, int y)
    {
    txSetFillColor (TX_RED);
    txCircle (x, y, 40);

    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 30);

    txSetColor (TX_RED);
    txCircle (x, y, 20);

    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW);
    txRectangle (x - 20, y - 20, x + 20, y);

    txSetFillColor (TX_RED);
    txCircle (x - 10, y - 5, 5);
    txCircle (x + 10, y - 5, 5);
    }

void FoxDraw (int x, int y, int tail, int legs, int earR, int earL)
    {
    txSetColor (TX_ORANGE);
    txSetFillColor (TX_ORANGE);
    POINT fox[] =
        {
        {x, y},                    {x + 40,         y - 40},  {x + 40,        y - 70},  {x - 10,         y - 70},  {x - 50,  y - 110 + earL},
        {x - 30,         y - 110}, {x + 20,         y - 150}, {x + 20 + earR, y - 170}, {x + 60,         y - 120}, {x + 50,  y - 80},
        {x + 80,         y - 30},  {x + 50,         y + 40},  {x + 70 + legs, y + 60},  {x + 30 + legs,  y + 60},  {x + 20,  y + 40},
        {x - 10,         y + 40},  {x + legs,       y + 60},  {x - 50 + legs, y + 60},  {x - 60,         y + 40},  {x - 100, y - 40},
        {x - 110 + tail, y - 110}, {x - 100 + tail, y - 160}, {x - 70 + tail, y - 170}, {x - 50 + tail,  y - 150}, {x - 70,  y - 40},
        {x - 40,         y}
        };
    txPolygon (fox, 26);
    }

void WolfDraw (int x, int y)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    POINT wolf[] =
        {
        {x - 90,  y - 10},  {x - 150, y + 40},  {x - 120, y + 70},  {x - 30,  y + 50},  {x - 30,  y + 90},
        {x,       y + 80},  {x + 70,  y + 100}, {x + 80,  y + 80},  {x + 120, y + 80},  {x + 110, y + 40},
        {x + 140, y + 40},  {x + 130, y},       {x + 150, y},       {x + 120, y - 30},  {x + 100, y - 40},
        {x + 120, y - 40},  {x + 80,  y - 50},  {x + 90,  y - 60},  {x + 60,  y - 80},  {x + 70,  y - 90},
        {x,       y - 110}, {x - 10,  y - 120}, {x - 30,  y - 130}, {x - 30,  y - 110}, {x - 20,  y - 90},
        {x - 50,  y - 90},  {x - 60,  y - 80},  {x - 70,  y - 100}, {x - 90,  y - 110}, {x - 90,  y - 80},
        {x - 80,  y - 70},  {x - 100, y - 30}
        };
    txPolygon (wolf, 32);

    txSetColor (TX_LIGHTGRAY, 5);
    txCircle (x - 60, y - 30, 3);
    }

void HareDraw (int x, int y)
    {
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    POINT hare[] =
        {
        {x, y},           {x + 10, y + 50}, {x + 20, y + 50}, {x + 10, y + 30}, {x + 10, y},
        {x + 20, y - 10}, {x + 30, y - 10}, {x + 40, y - 20}, {x + 20, y - 40}, {x + 10, y - 70},
        {x,      y - 90}, {x - 10, y - 70}, {x + 10, y - 40}, {x - 10, y - 20}, {x - 60, y},
        {x - 70, y + 30}, {x - 80, y + 20}, {x - 80, y + 30}, {x - 60, y + 50}, {x - 10, y + 50},
        {x - 20, y + 40}, {x - 30, y + 40}
        };
    txPolygon (hare, 22);

    txSetColor (TX_BLACK, 5);
    txCircle (x + 20, y - 30, 3);
    }

void PigDraw (int x, int y, int sizeX, int sizeY, COLORREF spruceColor)
    {
    txSetColor (spruceColor);
    txSetFillColor (spruceColor);
    POINT pig[] =
        {
        {x, y},                           {x,              y - 5 * sizeY}, {x + 5 * sizeX,  y - 5 * sizeY},  {x + 15 * sizeX, y - 10 * sizeY}, {x + 20 * sizeX, y - 20 * sizeY},
        {x + 30 * sizeX, y - 25 * sizeY}, {x + 25 * sizeX, y - 20*sizeY},  {x + 30 * sizeX, y - 20 * sizeY}, {x + 30 * sizeX, y - 15 * sizeY}, {x + 32 * sizeX, y - 20 * sizeY},
        {x + 45 * sizeX, y - 15 * sizeY}, {x + 50 * sizeX, y - 10*sizeY},  {x + 75 * sizeX, y - 10 * sizeY}, {x + 90 * sizeX, y + 5 * sizeY},  {x + 80 * sizeX, y},
        {x + 80 * sizeX, y + 15 * sizeY}, {x + 75 * sizeX, y + 15*sizeY},  {x + 75 * sizeX, y + 25 * sizeY}, {x + 70 * sizeX, y + 25 * sizeY}, {x + 70 * sizeX, y + 15 * sizeY},
        {x + 60 * sizeX, y + 15 * sizeY}, {x + 40 * sizeX, y + 15*sizeY},  {x + 35 * sizeX, y + 20 * sizeY}, {x + 35 * sizeX, y + 25 * sizeY}, {x + 30 * sizeX, y + 25 * sizeY},
        {x + 30 * sizeX, y + 15 * sizeY}, {x + 25 * sizeX, y + 10*sizeY},  {x + 15 * sizeX, y + 5 * sizeY},  {x + 5 * sizeX,  y + 5 * sizeY},  {x + 15 * sizeX, y}
        };
    txPolygon (pig, 30);
    }

void TwitterDraw (int x, int y)
    {
    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    POINT twitter[] =
        {
        {x, y},           {x + 10, y - 20}, {x + 30, y - 40}, {x + 50, y - 30}, {x + 60, y - 20},
        {x + 80, y - 30}, {x + 60, y - 10}, {x + 80, y - 10}, {x + 60, y},      {x + 60, y + 20},
        {x + 40, y + 50}, {x + 10, y + 80}, {x - 40, y + 80}, {x - 70, y + 60}, {x - 20, y + 60},
        {x - 40, y + 50}, {x - 50, y + 40}, {x - 30, y + 40}, {x - 50, y + 30}, {x - 60, y + 10},
        {x  -50, y + 10}, {x - 60, y},      {x - 50, y - 30}, {x - 20, y}
        };
    txPolygon (twitter, 24);
    }

void HomeDraw (int x, int y)
    {
    txSetColor (TX_RED);
    txSetFillColor (TX_RED);
    txRectangle (x, y, x + 200, y + 200);

    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txRectangle (x + 60, y + 60, x + 140, y + 140);

    txSetColor (TX_RED, 5);

    POINT home1[] =
        {
        {x + 80, y + 200},  {x + 80, y + 220},  {x, y + 240},       {x + 90, y + 230}, {x + 100, y + 260},
        {x + 110, y + 230}, {x + 200, y + 240}, {x + 120, y + 220}, {x + 120, y + 200}
        };
    POINT home2[] = { {x, y},             {x + 100, y - 95},  {x + 200, y} };
    POINT home3[] = { {x + 75,  y + 100}, {x + 80,  y + 85},  {x + 100, y + 100} };
    POINT home4[] = { {x + 125, y + 100}, {x + 120, y + 85},  {x + 100, y + 100} };
    POINT home5[] = { {x + 91,  y + 123}, {x + 109, y + 123}, {x + 100, y + 100} };

    txPolygon(home1, 9);

    txSetColor (TX_YELLOW);
    txPolygon (home2, 3);
    txTextOut (x + 55, y + 15, "ROSKOMNADZOR");

    txSetFillColor (TX_BLACK);
    txCircle (x + 100, y + 100, 30);

    txSetFillColor (TX_YELLOW);
    txCircle (x + 100, y + 100, 25);

    txSetFillColor (TX_BLACK);
    txPolygon (home3, 3);
    txPolygon (home4, 3);
    txPolygon (home5, 3);

    txCircle (x + 100, y + 100, 5);
    }

