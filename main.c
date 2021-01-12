#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    int votes;
    int winOrLose;
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
void showPresidentName(int loops_again,President presidents[]){
    system("cls");
    printf("*********MENU OF PRESIDENTS:************\n");
    for (int k=0;k<loops_again;k++){
        printf(" %d.%s\n",k+1,presidents[k].name);
    }
    printf("==>Choice one of The Presidents :");
}
void main(){
    int Num_P;
    int Num_E;
    int choice;
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);
    while (1){
        if (Num_P<5){
        system("cls");
        printf("You Enter %d , it\'s not valid !!!\n",Num_P);
        printf("=>Re-enter the number of presidents nominated for the presidential elections (minimum 5) : ");
        scanf("%d", &Num_P);
        system("cls");
        }else{
            break;
        }
    }
    President P[Num_P];
    addNamePresident(P,Num_P);
    system("cls");
    printf("=>Enter The Number of electors (minimum 10):");
    scanf("%d",&Num_E);
    while (1){
        system("cls");
        if (Num_E<10){
            printf("You Enter %d , it\'s not valid !!!\n",Num_E);
            printf("=>Re-enter the number of electors (minimum 10) : ");
            scanf("%d", &Num_E);
            system("cls");
        }else{
            break;
        }
    }
    electors E[Num_E];
    for (int j = 0;j<Num_E; j++){
        voting(j, E[j]);
        showPresidentName(Num_P,P);
        scanf("%d", &choice);
        while (1){
            if (choice>Num_P){
                printf("You enter %d ,Please Enter Valid Choice !! :\n",choice);
                showPresidentName(Num_P,P);
                scanf("%d", &choice);
            }else{
                break;
            }
        }
        P[choice-1].votes += 1;
        printf("Thanks! You voted on %s\n",P[choice-1].name);
        system("cls");
    }
    printf("\n*******FIRST TOUR :*******\n");
    printf("Result:\n");
    for(int l =0;l<Num_P;l++){
        printf("%s\t =\t %d\n", P[l].name,P[l].votes);
        if (((P[l].votes/Num_E)*100)>15){
            P[l].winOrLose = 1;
        }else{
            P[l].winOrLose = 0;
        }
    }
    printf("*******The Loser and Winner Presidents in first Tour :*******\n");
    for (int s = 0;s<Num_P; s++){
        if (P[s].winOrLose){
            printf("%s : winner\n",P[s].name);
        }else{
            printf("%s : loser\n",P[s].name);
        }
    }
};