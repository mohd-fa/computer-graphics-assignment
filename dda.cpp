#include <graphics.h>
#include <math.h>
#include <stdio.h>

 

void DDA(int x0, int y0, int x1, int y1){
    int dx, dy,steps,i;
    float xinc,yinc,x,y;
    dx = x1 - x0;
    dy = y1 - y0;
 
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;
 
    x = x0;
    y = y0;
    for (i = 0; i <= steps; i++) {
        printf("x = %d , y = %d \n",x,y);
        putpixel(round(x), round(y),WHITE); 
        x += xinc; 
        y += yinc; 
        delay(100); 
    }
}
 
int main(){
    int gd = DETECT, gm;
    int x0 = 2, y0 = 2, x1 = 500, y1 = 350;
 
    printf("DDA line Drawing Algorithm:\n\n");
    initgraph(&gd, &gm, (char*)"");
    printf("Enter the x cordinate of starting point:");
    scanf("%d",&x0);
    printf("Enter the y cordinate of starting point:");
    scanf("%d",&y0);
    printf("Enter the x cordinate of starting point:");
    scanf("%d",&x1);
    printf("Enter the y cordinate of starting point:");
    scanf("%d",&y1);
 
    DDA(x0, y0, x1, y1);
    printf("\n\nDrawing completed.");

    getch();
    return 0;
}