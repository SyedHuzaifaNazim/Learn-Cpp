#include <iostream>
#include <string.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

int main()
{
	cout << "Hello World";
  // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:\\Turboc3\\BGI");

    // Set the color for the circle
    setcolor(WHITE);

    // Draw a circle with center at (200, 200) and radius 100
    circle(200, 200, 100);

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}