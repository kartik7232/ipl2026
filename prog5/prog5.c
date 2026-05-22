#include <stdio.h>


struct field{
    unsigned int your_choice:1;
    unsigned int your_mothers_choice:1;
    unsigned int your_fathers_choice:1;
    unsigned int socially_acceptable:1;
    unsigned int financially_viable:1;
    unsigned int do_you_aptitude:1;
    unsigned int do_you_likeit:1;
    unsigned int decision:1;
};

union decision{
    unsigned char flags;
    struct field bits;
};

union decision input();
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags(union decision d);

int main() {
    union decision d;
    d = input();
    make_decision(&d);
    print_decision(d);
    print_conclusion_based_on_flags(d);
    return 0;
}

union decision input(){
    union decision d;
    int temp;
    d.flags = 0;

    printf("0 ---> NO , 1 ---> YES\n");
    printf("\nEnter your choice(0/1): ");
    scanf("%d", &temp);
    d.bits.your_choice = temp;

    printf("Enter your mothers choice(0/1): ");
    scanf("%d", &temp);
    d.bits.your_mothers_choice = temp;

    printf("Enter your fathers choice(0/1): ");
    scanf("%d", &temp);
    d.bits.your_fathers_choice = temp;

    printf("Is it socially acceptable(0/1): ");
    scanf("%d", &temp);
    d.bits.socially_acceptable = temp;

    printf("Is it financially viable(0/1): ");
    scanf("%d", &temp);
    d.bits.financially_viable = temp;

    printf("do you have aptitude for it(0/1): ");
    scanf("%d", &temp);
    d.bits.do_you_aptitude = temp;

    printf("do you like it(0/1): ");
    scanf("%d", &temp);
    d.bits.do_you_likeit = temp;

    return d;
}

void make_decision(union decision *d){
    d -> bits.decision = (
        d -> bits.do_you_likeit &&
        d -> bits.do_you_aptitude &&
        d -> bits.financially_viable &&
        (
            d -> bits.your_mothers_choice ||
            d -> bits.your_fathers_choice
        )
    );
}

void print_decision(union decision d){
    printf("\nYour choice: %s\n", d.bits.your_choice ? "YES" : "NO");
    printf("Your mother choice: %s\n", d.bits.your_mothers_choice ? "YES":"NO");
    printf("Your father choice: %s\n", d.bits.your_fathers_choice ? "YEs":"NO");
    printf("Socially acceptable: %s\n", d.bits.socially_acceptable ? "YES":"NO");
    printf("Financially viable:%s\n", d.bits.financially_viable ? "YES":"NO");
    printf("Aptitude: %s\n", d.bits.do_you_aptitude ? "YES":"NO");
    printf("Do you like it: %s\n", d.bits.do_you_likeit ? "YES":"NO");
    printf("Final decision: %s\n", d.bits.decision ? "YES":"NO");
}

void print_conclusion_based_on_flags(union decision d){
    if(d.bits.decision)
        printf("\nYou should go ahead with your decision");
    else
        printf("\nYou should reconsider your decision");
}