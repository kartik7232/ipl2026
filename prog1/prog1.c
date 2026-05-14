#include <stdio.h>

typedef struct{
    int SRN;
    char name[50];
    float marks;
}Student;
int main() {
    int i, n=3;
    Student s;
    FILE* fp;
    fp = fopen("recoders.bin", "wb");

    if(fp == NULL){
        printf("Error opening file\n");
        return 0;
    }

    for(i = 0; i<n; i++){
        printf("Students Record:%d\n", i+1);

        printf("SRN: ");
        scanf("%d", &s.SRN);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);
    return 0;
}