#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

int main() {
    int n, i;
    FILE *fp;
    Student student;
    
    printf("xEnter number of records: ");
    scanf("%d", &n);
    getchar();
    
    // Open file in binary write mode
    fp = fopen("records.bin", "wb");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Read and store records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        
        printf("Roll No: ");
        scanf("%d", &student.roll_no);
        getchar();
        
        printf("Name: ");
        fgets(student.name, sizeof(student.name), stdin);
        student.name[strcspn(student.name, "\n")] = '\0';
        
        printf("Marks: ");
        scanf("%f", &student.marks);
        
        // Write record to binary file
        fwrite(&student, sizeof(Student), 1, fp);
    }
    
    fclose(fp);
    printf("\nRecords stored successfully in records.bin\n");
    
    // Display records
    fp = fopen("records.bin", "rb");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("\n--- Records from file ---\n");
    while (fread(&student, sizeof(Student), 1, fp)) {
        printf("\nRoll No: %d\n", student.roll_no);
        printf("Name: %s\n", student.name);
        printf("Marks: %.2f\n", student.marks);
    }
    
    fclose(fp);
    return 0;
}
