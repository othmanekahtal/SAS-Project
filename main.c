#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//system
typedef struct
{
    char name[50];
    float votes;
    float winOrLose;
} President;
void addNamePresident(President president[], int Num__p)
{
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
void showPresidentName(int president_Number,President presidents[]){
    //printf("*********MENU OF PRESIDENTS:************\n");
    for (int i=0;i<president_Number;i++){
        printf(" %d.%s\n",i+1,presidents[i].name);
    }
    printf("==>Choice one of The Presidents :");
}

void addVotersToStruct(int choice,int NumberOfPresident,President president[]){
    while (1){
            if (choice>NumberOfPresident){
                //system("clear");
                printf("You enter %d ,Please Enter Valid Choice !! :\n",choice);
                printf("*********MENU OF PRESIDENTS:************\n");
                showPresidentName(NumberOfPresident,president);
                scanf("%d", &choice);
            }else{
                break;
            }
        }
        president[choice-1].votes += 1;
        printf("Thanks! You voted on %s\n",president[choice-1].name);
}
void main(){
    int Num_P;
    int Num_E;
    int choice;
    char ignore;
    int counter = 0;
    int Second_to_final =0;
    char cin[10];
    printf("welcome to Presidential election\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);
    while (1){
        if (Num_P<5){
        //system("clear");
        printf("You Enter %d , it\'s not valid !!!\n",Num_P);
        printf("=>Re-enter the number of presidents nominated for the presidential elections (minimum 5) : ");
        scanf("%d", &Num_P);
        //system("clear");
        }else{
            break;
        }
    }
    President P[Num_P];
    addNamePresident(P,Num_P);
    //system("clear");
    printf("=>Enter The Number of electors (minimum 10):");
    scanf("%d",&Num_E);
    while (1){
        //system("clear");
        if (Num_E<10){
            printf("You Enter %d , it\'s not valid !!!\n",Num_E);
            printf("=>Re-enter the number of electors (minimum 10) : ");
            scanf("%d", &Num_E);
            //system("clear");
        }else{
            break;
        }
    }
    electors E[Num_E];


    for (int i = 0;i<Num_E; i++){
        voting(i, E[i]);
        printf("*********MENU OF PRESIDENTS:************\n");
        showPresidentName(Num_P,P);
        scanf("%d", &choice);
        addVotersToStruct(choice, Num_P, P);
    }


    printf("\n*******FIRST TOUR :*******\n");
    printf("Result:\n");
    for (int i = 0; i < Num_P; i++){
        printf("%s\t =\t %.0f\n", P[i].name, P[i].votes);
        if (((P[i].votes / Num_E) * 100) > 15)
        {
            P[i].winOrLose = 1;
            counter++;
        }
        else
        {
            P[i].winOrLose = 0;
        }
    }
    // verify counter prisedent:
    //printf("\n counter is %d\n",counter);
    President P_for_secondTour[counter];
    int xc = 0;
    for(int i =0;i<counter;i++){
        while (1){
            P_for_secondTour[i].votes=0;
            if(xc==Num_P){
                break;
            }
            if ( ( ((P[xc].votes/Num_E)*100)>15 ) || (xc<Num_P) ){
                strcpy(P_for_secondTour[i].name,P[xc].name);
                i++;
            }
            xc++;
        }
    }
    if (counter==1){
        printf("The election is Done !\n");
        printf("%s is winner\n", P_for_secondTour[counter - 1].name);
    }else{
    printf("*******The Loser and Winner Presidents in first Tour :*******\n");
    for (int i = 0;i<Num_P; i++){
        if (P[i].winOrLose){
            printf("%s : winner\n",P[i].name);
        }else{
            printf("%s : loser\n",P[i].name);
        }
    }
    printf("Press Enter to got to second Tour : ");
    scanf("%99[^\n]%*c",&ignore);
    //system("clear");
    printf("\n****SECOND TOUR****\n");
    printf("Presidents have qualified for the second tour :\n");
    for (int i = 0;i<Num_E;i++){
        printf("*********MENU OF PRESIDENTS:************\n");
        showPresidentName(counter,P_for_secondTour);
        scanf("%d",&choice);
        addVotersToStruct(choice, counter, P_for_secondTour);
    }

    printf("\n*******SECOND TOUR :*******\n");
    printf("Result:\n");
    float minimumPre;
    for (int i = 1; i < counter - 1; i++){
        if (P_for_secondTour[i-1].votes>P_for_secondTour[i].votes){
            minimumPre = P_for_secondTour[i].votes;
        }else{
            minimumPre = P_for_secondTour[i-1].votes;
        }
    };
    for (int i = 0; i < counter; i++){
        if (P_for_secondTour[i].votes==minimumPre){
            printf("%d.%s President is loser : %.f \n", i + 1,P_for_secondTour[i].name,P_for_secondTour[i].votes);
        }
        else{
            printf("%d.%s President is winner: %.f \n", i + 1,P_for_secondTour[i].name,P_for_secondTour[i].votes);
            Second_to_final++;
        }
    };
    President P_for_Final[Second_to_final];
    int counterSecondary = 0;
    for (int i = 0; i < Second_to_final; i++){
        while(1){
            if ( counterSecondary==counter){
                break;
            }
            if (P_for_secondTour[counterSecondary].votes!=minimumPre){
            P_for_Final[i].votes = 0;
            strcpy(P_for_Final[i].name,P_for_secondTour[counterSecondary].name);
        }
        counterSecondary++;
        }
    };
    printf("Presidents have qualified for the final tour :");
    // we use here Function :
    printf("*********MENU OF PRESIDENTS:************\n");
    showPresidentName(Second_to_final, P_for_Final);
    scanf("%d",&scanf);
    addVotersToStruct(choice, Second_to_final, P_for_Final);
    int maximumPre=0;
    for (int i = 1; i > Second_to_final - 1; i++){
        if (P_for_Final[i-1].votes>P_for_Final[i].votes){
            maximumPre = P_for_Final[i].votes;
        }else{
            maximumPre = P_for_Final[i-1].votes;
        }
    };

    for (int i = 0; i < Second_to_final; i++){
        if (P_for_Final[i].votes==maximumPre){
            printf("%d.%s President is winner : %.f \n", i + 1,P_for_Final[i].name,P_for_Final[i].votes);
        }
        else{
            printf("%d.%s President is loser: %.f \n", i + 1,P_for_Final[i].name,P_for_Final[i].votes);
        }
    };
}
};