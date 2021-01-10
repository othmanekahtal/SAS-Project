#include <stdio.h>

void main() {
    int Num_P;
    char Name[50];
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections: ");
    scanf("%d",&Num_P);
    for (int i = 1; i <=Num_P ; ++i) {
        printf("Enter The Name of The Presidents %d :",i);
        printf("\n");
    }
}
