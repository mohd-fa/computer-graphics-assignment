#include <graphics.h>
#include<math.h>
#include <stdio.h>

 

void bl(int x0, int y0, int x1, int y1){  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;
    if(abs(dx)>=abs(dy))
        while(x<x1){  
            printf("X = %d , Y = %d \n",x,y);

            if(p>=0){  
                putpixel(x,y,15);  
                y=y+1;  
                p=p+2*dy-2*dx;  
            }  
            else{  
                putpixel(x,y,15);  
                p=p+2*dy;
            }  
            x=x+1;  
            delay(100);
        }
    else
        while(y<y1){  
            printf("X = %d , Y = %d \n",x,y);

            if(p>=0){  
                putpixel(x,y,15);  
                x=x+1;  
                p=p+2*dx-2*dy;  
            }  
            else{  
                putpixel(x,y,15);  
                p=p+2*dx;
            }  
            y=y+1;  
            delay(100);
        }

}  
 
int main(){
    int gd = DETECT, gm;
    int x0, y0, x1, y1;
 
    printf("Bresenhams line Drawing Algorithm:\n\n");
    initgraph(&gd, &gm, (char*)"");
    printf("Enter the x cordinate of starting point:");
    scanf("%d",&x0);
    printf("Enter the y cordinate of starting point:");
    scanf("%d",&y0);
    printf("Enter the x cordinate of starting point:");
    scanf("%d",&x1);
    printf("Enter the y cordinate of starting point:");
    scanf("%d",&y1);
 
    bl(x0, y0, x1, y1);
    printf("\n\nDrawing completed.");

    getch();
    return 0;
}