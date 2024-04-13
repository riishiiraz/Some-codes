#include <graphics.h>
#include <conio.h>

#if 1
    #include <iostream>
    // using namespace std;
#endif

class Window{
    public:
    int wX_Min, wY_Min, wX_Max, wY_Max;

    Window(){};
    Window(int wX_Min,int wY_Min, int wX_Max, int wY_Max):wX_Min(wX_Min), wY_Min(wY_Min), wX_Max(wX_Max), wY_Max(wY_Max){

    }
};

class Line{
    public:

    int getCodeStart(Window window){
        return (x1<window.wX_Min) | ((x1>window.wX_Max)<<1) | ((y1<window.wY_Min)<<2) | ((y1>window.wY_Max)<<3) ;
    }
    int getCodeEnd(Window window){
        return (x2<window.wX_Min) | ((x2>window.wX_Max)<<1) | ((y2<window.wY_Min)<<2) | ((y2>window.wY_Max)<<3) ;
    }

    int isCompletelyInside(Window window){
        return getCodeStart(window)==0 && getCodeEnd(window)==0;
    }

    int isCompletelyOutside(Window window){
        return (getCodeStart(window) & getCodeEnd(window)) != 0;
    }

    
    int isPartiallyInside(Window window){
        return (getCodeStart(window) & getCodeEnd(window)) == 0;
    }

    void printLine(){
        std::cout<<"( "<<x1<<" , "<<y1<<" ) : ( "<<x2<<" , "<<y2<<" )\n";
    }

    

    int x1,y1,x2,y2;

    Line(){};
    Line(int x1,int y1,int x2,int y2):x1(x1), y1(y1), x2(x2), y2(y2){
        
    }
};

void midPoint(Line line_, Window window){
    
    if(line_.isCompletelyInside(window)){
        // IF THE LINE IS COMPLETELY VISIBLE, DRAW THE LINE.
        line(line_.x1, line_.y1,line_.x2,line_.y2);
        return;
    }
    else if(line_.isCompletelyOutside(window)){
        // IF THE LINE IS COMPLETELY INVISIBLE, DISCARD THE LINE SIMPLY.
        return;
    }
    
    else if (line_.isPartiallyInside(window)){
        // IF THS LINE IS PARTIALLY VISIBLE, DIVIDE THE LINE INTO 2 PARTS.

        int midX = (line_.x1 + line_.x2)/2;
        int midY = (line_.y1 + line_.y2)/2;

        Line lineA = Line(line_.x1, line_.y1, midX, midY);  // THE FIRST HALF OF THE LINE.
        Line lineB = Line( midX, midY, line_.x2, line_.y2); // THE SECOND HALF OF THE LINE.

        if(midX != window.wX_Min && midX != window.wX_Max && midY != window.wY_Min && midY != window.wY_Max){
            // CHECKING IF MIDPOINT DOES NOT TOUCHES THE BOUNDARY OF THE WINDOW.
            // RECURSIVELY CALLING UNTILL "MIDPOINT IS IN THE BOUNDARY".
            midPoint(lineA, window);
            midPoint(lineB, window);

        }
    }
}

int main(){

    int gd = DETECT, gm;
    char driver[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, driver);

    int wX_Min = 80, wX_Max = 550;
    int wY_Min = 80, wY_Max = 400;

    int x1 = 50, y1 = 300, x2 = 600, y2 = 150;

    rectangle(wX_Min,wY_Min,wX_Max,wY_Max); // CLIPPING WINDOW
    rectangle(wX_Min-1,wY_Min+1,wX_Max+1,wY_Max+1); // CLIPPING WINDOW TO LOOK BOLD

    // line(x1,y1, x2, y2);


    Window window(wX_Min, wY_Min, wX_Max, wY_Max);
    Line line_(x1, y1, x2,y2);

    setcolor(YELLOW);
    midPoint(line_, window);

    getch();

    closegraph();
}