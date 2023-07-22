#include <graphics.h>
#include<math.h>
#include <stdio.h>

 
void drawCircle(int x0, int y0, int x, int y)
{
    putpixel(x0+x, y0+y, WHITE);
    putpixel(x0-x, y0+y, WHITE);
    putpixel(x0+x, y0-y, WHITE);
    putpixel(x0-x, y0-y, WHITE);

    
    putpixel(x0+y, y0+x, WHITE);
    putpixel(x0-y, y0+x, WHITE);
    putpixel(x0+y, y0-x, WHITE);
    putpixel(x0-y, y0-x, WHITE);
}

void bc(int x0, int y0, int r){  
    int p = 3-2*r, y = r , x = 0;
    if (r>0){
        drawCircle(x,y,x0,y0);
    }
    while(x<y){
        x+=1;
        if (p<0){
            p+=4*x+6;
        }
        else{
            y-=1;
            p+=4*(x-y)+10;
        }
        drawCircle(x0,y0,x,y);
            delay(100);

    }


}  

int main(){
    int gd = DETECT, gm;
    int x0, y0, r;
 
    initgraph(&gd, &gm, (char*)"");
    printf("Bresenhams Circle Drawing Algorithm:\n\n");
    printf("Enter the x cordinate of origin:");
    scanf("%d",&x0);
    printf("Enter the y cordinate of origin:");
    scanf("%d",&y0);
    printf("Enter the radius:");
    scanf("%d",&r);
 
    bc(x0, y0, r);
    printf("\n\nDrawing completed.");

    getch();
    return 0;
}