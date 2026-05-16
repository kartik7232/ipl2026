#include <stdio.h>

typedef struct{
    int SRN;
    char name[50];
    float marks;
}Student;

void storeRecords(int n);
void mthRecord(int m);
void deleteRecord(int SRN);

int main() {
    int n, m, SRN;

    printf("Enter number of records:\n");
    scanf("%d", &n);
    
    storeRecords(n);

    printf("\nEnter mth record to display:\n");
    scanf("%d", &m);

    mthRecord(m);

    printf("\nEnter SRN to delete:");
    scanf("%d", &SRN);

    deleteRecord(SRN);
    return 0;
}

void storeRecords(int n){
    FILE* fp;
    Student s;
    fp = fopen("recoders.bin", "wb");
    
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    
    for(int i = 0; i<n; i++){
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
    
    printf("Records Stored successfully\n");
    
}

void mthRecord(int m){
    FILE *fp;
    Student s;

    fp = fopen("recoders.bin", "rb");

    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }

    fseek(fp, (m-1)*sizeof(Student), SEEK_SET);

    if(fread(&s, sizeof(Student), 1, fp) == 1){
        printf("SRN: %d\n",  s.SRN);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f", s.marks);
    }else{
        printf("Record not found");
    }

    fclose(fp);

}


void deleteRecord(int SRN){
    FILE *fp, *temp;
    Student s;

    int found = 0;

    fp = fopen("recoders.bin", "rb");
    temp = fopen("temp.bin", "wb");
    if(fp == NULL || temp == NULL){
        printf("Error opening file\n");
        return;
    }

    while(fread(&s, sizeof(Student), 1, fp)){
        if(s.SRN == SRN){
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    
    remove("records.bin");
    rename("temp.bin", "records.bin");

    if(found){
        printf("Record deleted successfully\n");
    }else{
        printf("Record not found\n");
    }
}

