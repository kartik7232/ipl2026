#include <stdio.h>
#include <math.h>

typedef struct circle{
    int center_x;
    int center_y;
    int radius;
};

void initialize_buffer(int heigth, int width, char buffer[heigth][width]);
void draw_circle(int heigth, int widht, char buffer[heigth][width], circle c);
void print_buffer(int heigth, int width, char buffer[heigth][width]);
float calculate_distance(int x1, int x2, int y1, int y2);

int main() {
    int width, heigth;
    printf("Enter circle width:");
    scanf("%d", &width);

    printf("Enter circle heigth:");
    scanf("%d", &height);

    char buffer[height][width];

    circle c;
    return 0;
}