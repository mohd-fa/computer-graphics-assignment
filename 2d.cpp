#include <graphics.h>
#include <cmath>
#include <stdio.h>

// Function to perform translation on a point
void translate(int& x, int& y, int tx, int ty) {
    x += tx;
    y += ty;
}

// Function to perform rotation on a point
void rotate(int& x, int& y, double angle) {
    double radian = angle * M_PI / 180.0;
    int xNew = round(x * cos(radian) - y * sin(radian));
    int yNew = round(x * sin(radian) + y * cos(radian));
    x = xNew;
    y = yNew;
}

// Function to perform scaling on a point
void scale(int& x, int& y, double sx, double sy) {
    x = round(x * sx);
    y = round(y * sy);
}

// Function to perform reflection on a point
void reflect(int& x, int& y) {
    x = -x;
    y = -y;
}

// Function to draw a polygon using Bresenham's line algorithm
void drawPolygon(int* x, int* y, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        int j = (i + 1) % numVertices;
        line(x[i], y[i], x[j], y[j]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int numVertices;
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &numVertices);

    int x[numVertices], y[numVertices];

    printf("Enter the coordinates of the vertices:\n");

    for (int i = 0; i < numVertices; ++i) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    int choice;
    do {
        printf("\n-------- Menu --------\n");
        printf("1. Translate\n");
        printf("2. Rotate\n");
        printf("3. Scale\n");
        printf("4. Reflect\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the screen
        cleardevice();

        setcolor(WHITE);
        // Draw the original polygon
        drawPolygon(x, y, numVertices);

        // Perform the chosen transformation
        switch (choice) {
            case 1: {
                int tx, ty;
                printf("Enter the translation vector (tx ty): ");
                scanf("%d %d", &tx, &ty);
                for (int i = 0; i < numVertices; ++i) {
                    translate(x[i], y[i], tx, ty);
                }
                break;
            }
            case 2: {
                double angle;
                printf("Enter the rotation angle (in degrees): ");
                scanf("%lf", &angle);

                for (int i = 0; i < numVertices; ++i) {
                    rotate(x[i], y[i], angle);
                }
                break;
            }
            case 3: {
                double sx, sy;
                printf("Enter the scaling factors (sx sy): ");
                scanf("%lf %lf", &sx, &sy);

                for (int i = 0; i < numVertices; ++i) {
                    scale(x[i], y[i], sx, sy);
                }
                break;
            }
            case 4: {
                for (int i = 0; i < numVertices; ++i) {
                    reflect(x[i], y[i]);
                }
                break;
            }
            case 5: {
                printf("Exiting the program...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }

        // Set a different color for transformed polygon
        setcolor(RED);

        // Draw the transformed polygon
        drawPolygon(x, y, numVertices);

        delay(1000); // Delay to observe the transformed polygon

    } while (choice != 5);

    closegraph();
    return 0;
}