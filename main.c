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
        }
        else{
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
        /*
        ******Replaced By function******
        for (int k = 0;k<Num_P;k++){
            printf(" %d.%s\t",k+1,P[k].name);
        }*/
        showPresidentName(Num_P,P);
        scanf("%d", &choice);
        while (1){
            if (choice>Num_P){
                printf("You enter %d ,Please Enter Valid Choice !! :\n",choice);
                /*
                ******Replaced By function******
                for (int k = 0;k<Num_P;k++){
                    printf(" %d.%s\t",k+1,P[k].name);
                }*/
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
    printf("Final Result:\n");
    for(int l =0;l<Num_P;l++){
        printf("%s\t =\t %d\n", P[l].name,P[l].votes);
    }
};