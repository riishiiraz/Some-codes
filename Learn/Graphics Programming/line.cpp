#include <graphics.h>
#include <conio.h>
#include <iostream>

int sign(int v){
    if(v==0)    return 0;
    if(v>1)    return 1;
    return -1;
}

int main(){
    int gd=DETECT, gm;
    char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver);


    int x1 = 90 , y1 = 90,  x2 = 600, y2 = 400;

    putpixel(x1,y1,RED);
    putpixel(x2,y2,RED);

    int dx = (x2-x1), dy = (y2-y1);

    int length = abs(dx)>abs(dy) ? abs(dx):abs(dy);

    float Dx = (float)dx/length;
    float Dy = (float)dy/length;
    
    float x = x1 + 0.5*sign(dx), 
          y = y1 + 0.5*sign(dy);
    int i=1;
    while(i<=length){
        putpixel((int)x, (int)y, WHITE);

        x+=Dx;
        y+=Dy;

        i++;

        // delay(50);
    }




    getch();
    closegraph();

}