#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct stock the president in all tour;
typedef struct
{
    char name[50];
    float votes;
    float winOrLose;
} President;

// struct for store the CIN of the voters:
typedef struct{
    char CIN[10];
}electors;

// function for add name of the president in struct (President):
void addNamePresident(President president[], int Num__p){
    for (int i = 0;i<Num__p;i++){
        printf("==>Enter the Name of the President %d : ",i+1);
        /***note : for ignore the white space but is not ignore the break line***/
        scanf(" %[^\n]s", president[i].name);
        president[i].votes = 0;
    }
}

// function for add cin in instance of struct (electors) :
void voting(int i,electors CIN){
    printf("==>You're Elector %d, Please Enter your CNI : ",i+1);
    scanf("%s",CIN.CIN);
}

// Function for show the name of the president in specified table of instance of the President struct :
void showPresidentName(int president_Number,President presidents[]){
    for (int i=0;i<president_Number;i++){
        printf(" %d.%s\n",i+1,presidents[i].name);
    }
    printf("==>Choice one of The Presidents :");
}

// function for add voters to a specified table of instance of the president struct :
void addVotersToStruct(int choice,int NumberOfPresident,President president[]){
    while (1){
            if (choice>NumberOfPresident){
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


//function for Initialize the Structs:
void inRepeatingCase(int counter,int *count,int NumberOfPresident,President president[]){
    if(counter == NumberOfPresident){
        printf("\nThe First Tour has been Repeated\n\n");
        for (int i = 0;i<NumberOfPresident;i++){
            president[i].votes = 0;
            president[i].winOrLose = 0;
        }
    }
    *count = 0;
}

void main(){
    //Variables declaration :
    int Num_P;
    int Num_E;
    int choice;
    char ignore;
    int counter = 0;
    int Second_to_final =0;
    char cin[10];
    int counterSecondary = 0;
    float minimumPre;
    float maximumPre;

    printf("*****WELCOME TO PRESIDENTIAL ELECTION*****\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d",&Num_P);

    while (Num_P<5){
        printf("You Enter %d , it\'s not valid !!!\n",Num_P);
        printf("=>Re-enter the number of presidents nominated for the presidential elections (minimum 5) : ");
        scanf("%d", &Num_P);
    }

    President P[Num_P];

    addNamePresident(P,Num_P);

    //system("clear");
    printf("=>Enter The Number of electors (minimum 10):");
    scanf("%d",&Num_E);

    while (Num_E<10){
        //system("clear");
            printf("You Enter %d , it\'s not valid !!!\n",Num_E);
            printf("=>Re-enter the number of electors (minimum 10) : ");
            scanf("%d", &Num_E);
            //system("clear");
    }

    electors E[Num_E];

    // tour 1
    do{
        inRepeatingCase(counter,&counter, Num_P, P);

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
    }while (counter == Num_P);

    President P_for_secondTour[counter];

    int countOfFirstTour = 0;
    for(int i =0;i<counter;i++){
        while (!countOfFirstTour==Num_P){
            P_for_secondTour[i].votes=0;
            if ( ((P[countOfFirstTour].votes/Num_E)*100)>15 ){
                strcpy(P_for_secondTour[i].name,P[countOfFirstTour].name);
            }
            countOfFirstTour++;
        }
    }
    // in case the voters are vote in one president , Election is done!!
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
        scanf("%c",&ignore);
        //system("clear");
        do{printf("\n****SECOND TOUR****\n");
        printf("Presidents have qualified for the second tour :\n");
        for (int i = 0;i<Num_E;i++){
            printf("*********MENU OF PRESIDENTS:************\n");
            showPresidentName(counter,P_for_secondTour);
            addVotersToStruct(choice, counter, P_for_secondTour);
            scanf("%d",&choice);
        }

        printf("\n*******SECOND TOUR :*******\n");
        printf("Result:\n");
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
        }while(counterSecondary==counter);
        President P_for_Final[Second_to_final];
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
        }
        printf("Presidents have qualified for the final tour :");
        // we use here Function :
        printf("*********MENU OF PRESIDENTS:************\n");
        showPresidentName(Second_to_final, P_for_Final);
        scanf("%d",&scanf);
        addVotersToStruct(choice, Second_to_final, P_for_Final);
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
    };
};