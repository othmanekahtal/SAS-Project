#include <stdio.h>

void main() {
    int Num_P;
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections: ");
    scanf("%d",&Num_P);
    int Table[Num_P];
    for (int i = 0; i <Num_P ; i++) {
        printf("Enter The Name of The Presidents %d :",i+1);
        scanf(" %d", &Table[i]);
        printf("\n");
    }
}
