#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    float votes;
    float winOrLose;
} President;
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
    system("clear");
    printf("*********MENU OF PRESIDENTS:************\n");
    for (int k=0;k<loops_again;k++){
        printf(" %d.%s\n",k+1,presidents[k].name);
    }
    printf("==>Choice one of The Presidents :");
}
    void checkingElectron(int Number_of_electrons,electors electron[],char cin[]){

    }
void main(){
    int Num_P;
    int Num_E;
    int choice;
    char ignore[1];
    int counter = 0;
    char cin[10];
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);
    while (1){
        if (Num_P<5){
        system("clear");
        printf("You Enter %d , it\'s not valid !!!\n",Num_P);
        printf("=>Re-enter the number of presidents nominated for the presidential elections (minimum 5) : ");
        scanf("%d", &Num_P);
        system("clear");
        }else{
            break;
        }
    }
    President P[Num_P];
    addNamePresident(P,Num_P);
    system("clear");
    printf("=>Enter The Number of electors (minimum 10):");
    scanf("%d",&Num_E);
    while (1){
        system("clear");
        if (Num_E<10){
            printf("You Enter %d , it\'s not valid !!!\n",Num_E);
            printf("=>Re-enter the number of electors (minimum 10) : ");
            scanf("%d", &Num_E);
            system("clear");
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
    }
    printf("\n*******FIRST TOUR :*******\n");
    printf("Result:\n");
    for(int l =0;l<Num_P;l++){
        printf("%s\t =\t %.0f\n", P[l].name,P[l].votes);
        if (((P[l].votes/Num_E)*100)>15){
            P[l].winOrLose = 1;
            counter++;
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
    printf("Press any Button to got to second Tour");
    scanf("%s",&ignore);
    system("clear");
    printf("\n****SECOND TOUR****\n");
    printf("Presidents have qualified for the second tour :\n");
        for(int r =0;r<counter;r++){
            printf("%d.%s\n",r+1,P[r].name);
            P[r].votes = 0;
        }
    printf("=> Confirm Your CIN to vote : ");
    scanf("%s", cin);
    checkingElectron(Num_E,E,cin);
};