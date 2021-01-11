#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    int votes;
}President;
void addNamePresident(President president[],int Num__p){
    for (int i = 0;i<Num__p;i++){
        printf("==>Enter the Name of the President %d : ",i+1);
        scanf(" %[^\n]s", president[i].name);
        president[i].votes = 0;
    }
}
typedef struct{
    char CIN[10];
}electors;
void voting(int i,electors CIN){
    printf("==>You're Elector %d, Please Enter your CNI : ",i+1);
    scanf("%s",CIN.CIN);
}
void main(){
    int Num_P;
    int Num_E;
    int choice;
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);
    President P[Num_P];
    addNamePresident(P,Num_P);
    system("clear");
    printf("=>Enter The Number of electors :");
    scanf("%d",&Num_E);
    electors E[Num_E];
    for (int j = 0;j<Num_E; j++){
        voting(j, E[j]);
        printf("==>Choice one of The Presidents : \n");
        for (int k = 0;k<Num_P;k++){
            printf(" %d.%s\t",k+1,P[k].name);
        }
        printf(":");
        scanf("%d", &choice);
        P[choice-1].votes += 1;
        printf("P[%d].votes = %d\n",choice,P[choice-1].votes);
    }
    printf("Final Result:\n");
    for(int l =0;l<Num_P;l++){
        printf("%s\t =\t %d\n", P[l].name,P[l].votes);
    }
};