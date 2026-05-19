#include <stdio.h>


struct field{
    unsigned int your_choice:1;
    unsigned int your_mothers_choice:1
    unsigned int your_fathers_choice:1;
    unsigned int socially_acceptable:1;
    unsigned int financially_viabel:1;
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
void print_conclusionb_based_on_flags(union decision d);

int main() {
    
    return 0;
}
