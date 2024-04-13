#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gm,gd = DETECT, i;
    int key;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int x,y, r = 200, xEnd;

    xEnd = r / (pow(2,0.5f));

    int h=300,k=250;

    putpixel(h,k,WHITE);

    for (x=0; x<xEnd; x++){
        y = pow( ((r*r)-(x*x)) , 0.5f ) ;

        // line(h,k,x+h,y+k);
        // line(h,k,h-x,y+k);

        putpixel(x+h,y+k,BLUE);
        putpixel(h-x,y+k,BLUE);

        putpixel(y+h,x+k,GREEN);
        putpixel(y+h,k-x,GREEN);

        putpixel(x+h,k-y,WHITE);
        putpixel(h-x,k-y,WHITE);

        putpixel(h-y,x+k,RED);
        putpixel(h-y,k-x,RED);

        // delay(10);
    }

    getch();
}