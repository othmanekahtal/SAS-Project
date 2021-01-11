#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    int votes;
}President;
President addNamePresident(int i,President president){
    printf("==>Enter the Name of the President %d : ",i+1);
    /*
        scanf("%s",president.name);
        you can't use the scanf in this case scanf not read whitespaces;
    */
    scanf(" %[^\n]s", president.name);
    printf("%s\n",president.name);
    return president;
}
typedef struct{
    char CIN[10];
}electors;
electors voting(int i,electors CIN){
    printf("==>You're Elector %d, Please Enter your CNI : ",i+1);
    scanf("%s",CIN.CIN);
    return CIN;
}
void main(){
    int Num_P;
    int Num_E;
    int choice;
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);
    President P[Num_P];
    P[Num_P].votes = 0;
    for (int i = 0; i < Num_P; i++){
        addNamePresident(i,P[i]);
    }
    system("clear");
    printf("=>Enter The Number of electors :");
    scanf("%d",&Num_E);
    electors E[Num_E];
    for (int j = 0;j<Num_E; j++){
        voting(j, E[j]);
        system("clear");
        printf("==>Choice one of The Presidents : ");
        for (int k = 0;k<Num_P;k++){
            printf(" %d.%s",k+1,P[k].name);
        }
        scanf("%d", &choice);
            for (int l = 0;l<Num_P;l++){
                if(choice==l){
                    P[l].votes += 1;
                }
            }
    }
};
