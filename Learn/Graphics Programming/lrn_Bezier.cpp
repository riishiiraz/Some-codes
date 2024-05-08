#include <graphics.h>
#include <conio.h>
#include <iostream>

struct line_
{
    int x1,y1,x2,y2;
};

struct point{
    int x,y;
};

struct point section(struct line_ line, float div){
    struct point pt;

    pt.x = ((div*line.x2) + ((1-div) * line.x1 ) );

    pt.y = ((div*line.y2) + ((1-div) * line.y1 ) );


    return pt;
}

void Bezier(struct line_ l1, struct line_ l2){

    line(l1.x1,l1.y1, l1.x2,l1.y2);
    line(l2.x1,l2.y1, l2.x2,l2.y2);

    line(l1.x1,l1.y1, l2.x2,l2.y2);

    float passed = 0;

    struct point first,second,thirdPoint;
    struct line_ thirdLine;

    while (passed<=1){

        first = section(l1,passed);
        second = section(l2,passed);

        thirdLine.x1 = first.x;
        thirdLine.y1 = first.y;
        thirdLine.x2 = second.x;
        thirdLine.y2 = second.y;

        thirdPoint = section(thirdLine, passed);

        putpixel(thirdPoint.x, thirdPoint.y,YELLOW);
        passed+=0.001;
    }


}


int main()
{
    int gm,gd = DETECT, i;
    int key;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    // struct line_ l1 {100,300,300,300};
    // struct line_ l2 {l1.x2,l1.y2,400,100};

    struct line_ l1 {50,300,600,300};
    struct line_ l2 {l1.x2,l1.y2,300,50};

    // for(int x=50;x<400;x++){
    //     l1.x1 = x;
    //     Bezier(l1,l2);
    //     cleardevice();
    //     delay(10);
    // }

    Bezier(l1,l2);

    #if 0

    line(l1.x1,l1.y1, l1.x2,l1.y2);
    line(l2.x1,l2.y1, l2.x2,l2.y2);

    line(l1.x1,l1.y1, l2.x2,l2.y2);


    float passed = 0;

    struct point first,second,thirdPoint;
    struct line_ thirdLine;

    while (passed<=1){

        first = section(l1,passed);
        second = section(l2,passed);

        thirdLine.x1 = first.x;
        thirdLine.y1 = first.y;
        thirdLine.x2 = second.x;
        thirdLine.y2 = second.y;

        thirdPoint = section(thirdLine, passed);

        putpixel(thirdPoint.x, thirdPoint.y,YELLOW);
        passed+=0.001;
    }

    #endif

    getch();

}