#include <stdio.h>
#include <math.h>

typedef struct{
    int center_x;
    int center_y;
    int radius;
}circle;

void initialize_buffer(int height, int width, char buffer[height][width]);
void draw_circle(int height, int width, char buffer[height][width], circle c);
void print_buffer(int height, int width, char buffer[height][width]);
float calculate_distance(int x1, int x2, int y1, int y2);

int main() {
    int width, height;
    printf("Enter circle width: ");
    scanf("%d", &width);

    printf("Enter circle height: ");
    scanf("%d", &height);

    char buffer[height][width];

    circle c;

    c.center_x = width/2;
    c.center_y = height/2;

    printf("Enter radius: ");
    scanf("%d", &c.radius);

    initialize_buffer(height, width, buffer);
    draw_circle(height, width, buffer, c);
    print_buffer(height, width, buffer);

    return 0;
}

void initialize_buffer(int height, int width, char buffer[height][width]){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            buffer[i][j] = ' ';
        }
    }
}

float calculate_distance(int x1, int x2, int y1, int y2){
    return sqrt(pow(y2 - y1, 2)+ pow(x2 - x1, 2));
}

void draw_circle(int height, int width, char buffer[height][width], circle c){
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            float distance = calculate_distance(x, c.center_x, y, c.center_y);

            if (distance >= c.radius - 0.5 && distance <= c.radius + 0.5)
                buffer[y][x] = '*';
        }
    }
}

void print_buffer(int height, int width, char buffer[height][width]){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}