#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//struct stock the president in all tour;
typedef struct {
    char name[50];
    float votes;
    // i change the type of votes
    int winOrLose;
}
President;

// struct for store the CIN of the voters:
typedef struct {
    char CIN[10];
}
electors;

// function for add name of the president in struct (President):
void addNamePresident(President president[], int Num__p) {
    for (int i = 0; i < Num__p; i++) {
        printf("==>Enter the Name of the President %d : ", i + 1);
        /***note : for ignore the white space but is not ignore the break line***/
        scanf(" %[^\n]s", president[i].name);
        president[i].votes = 0;
    }
}

// function for add cin in instance of struct (electors) :
void voting(int i, electors CIN) {
    printf("==>You're Elector %d, Please Enter your CNI : ", i + 1);
    scanf("%s", CIN.CIN);
}

// Function for show the name of the president in specified table of instance of the President struct :
void showPresidentName(int president_Number, President presidents[]) {
    for (int i = 0; i < president_Number; i++) {
        printf(" %d.%s\n", i + 1, presidents[i].name);
    }
    printf("==>Choice one of The Presidents :");
}

// function for add voters to a specified table of instance of the president struct :
void addVotersToStruct(int choice, int NumberOfPresident, President president[]) {
    while (choice > NumberOfPresident) {
        printf("You enter %d ,Please Enter Valid Choice !! :\n", choice);
        printf("*********MENU OF PRESIDENTS:************\n");
        showPresidentName(NumberOfPresident, president);
        scanf("%d", & choice);
    }
    president[choice - 1].votes += 1;
    printf("Thanks! You voted on %s\n", president[choice - 1].name);
}

//function for Initialize the Structs:
void TourOneRepeat(int Num_P_second_tour, int NumberOfPresident, President president[]) {
    if (Num_P_second_tour == NumberOfPresident) {
        printf("\nThe First Tour has been Repeated\n\n");
        for (int i = 0; i < NumberOfPresident; i++) {
            president[i].votes = 0;
            president[i].winOrLose = 0;
        }
    }
}

//function for voting and add vote to instance variable :
void voting_repetition(int Number_President, President presidents[], int choice) {
    printf("*********MENU OF PRESIDENTS:************\n");
    showPresidentName(Number_President, presidents);
    scanf("%d", & choice);
    addVotersToStruct(choice, Number_President, presidents);
}
void main() {
    //Variables declaration :
    int Num_P;
    int Num_E;
    int choice;
    int Num_P_second_tour = 0;
    int Second_to_final = 0;
    char cin[10];
    int repetitionMin = 0;
    float minimumPre;
    float maximumPre;
    int Numbermin = 0;
    int Numbermax = 0;

    printf("*****WELCOME TO PRESIDENTIAL ELECTION*****\n");
    printf("=>Enter the number of presidents nominated for the presidential elections (minimum 5) : ");
    scanf("%d", & Num_P);

    while (Num_P < 5) {
        printf("You Enter %d , it\'s not valid !!!\n", Num_P);
        printf("=>Re-enter the number of presidents nominated for the presidential elections (minimum 5) : ");
        scanf("%d", & Num_P);
    }

    President P[Num_P];

    addNamePresident(P, Num_P);

    //system("clear");
    printf("=>Enter The Number of electors (minimum 10):");
    scanf("%d", & Num_E);

    while (Num_E < 10) {
        //system("clear");
        printf("You Enter %d , it\'s not valid !!!\n", Num_E);
        printf("=>Re-enter the number of electors (minimum 10) : ");
        scanf("%d", & Num_E);
        //system("clear");
    }

    electors E[Num_E];

    // tour 1
    do {
        TourOneRepeat(Num_P_second_tour, Num_P, P);
        Num_P_second_tour = 0;
        for (int i = 0; i < Num_E; i++) {
            voting(i, E[i]);
            voting_repetition(Num_P, P, choice);
        }
        printf("\n*******FIRST TOUR :*******\n");
        printf("Result:\n");
        for (int i = 0; i < Num_P; i++) {
            printf("%s\t =\t %.0f\n", P[i].name, P[i].votes);
            if (((P[i].votes / Num_E) * 100) > 15) {
                P[i].winOrLose = 1;
                Num_P_second_tour++;
            } else {
                P[i].winOrLose = 0;
            }
        }
    } while (Num_P_second_tour == Num_P);

    President P_for_secondTour[Num_P_second_tour];

    // for copy the element to the new instance of struct :
    int a = 0;
    for (int i = 0; i < Num_P; i++) {
        if (P[i].winOrLose) {
            strcpy(P_for_secondTour[a].name, P[i].name);
            a++;
        }
    }

    // in case the voters are vote in one president , Election is done!!
    if (Num_P_second_tour == 1) {
        printf("The election is Done !\n");
        printf("%s is winner\n", P_for_secondTour[0].name);
    } else {
        printf("\n*******The Loser and Winner Presidents in first Tour :*******\n");
        for (int i = 0; i < Num_P; i++) {
            if (P[i].winOrLose) {
                printf("%s : winner\n", P[i].name);
            } else {
                printf("%s : loser\n", P[i].name);
            }
        }
        //system("clear");
        do {
            if (Numbermin > 1) {
                printf("\nThe second Tour has been Repeated\n\n");
                minimumPre = 0;
                Numbermin = 0;
                Second_to_final = 0;
            }
            printf("\n****SECOND TOUR****\n");
            printf("Presidents have qualified for the second tour :\n");
            for (int i = 0; i < Num_E; i++) {
                voting_repetition(Num_P_second_tour, P_for_secondTour, choice);
            }
            printf("\n*******SECOND TOUR :*******\n");
            printf("Result:\n");
            for (int i = 0; i < Num_P_second_tour; i++) {
                printf("%s\t =\t %.0f\n", P_for_secondTour[i].name, P_for_secondTour[i].votes);
            }

            // for geting the minimum value in table :
            minimumPre = P_for_secondTour[0].votes;
            for (int i = 0; i < Num_P_second_tour; i++) {
                if (minimumPre > P_for_secondTour[0].votes) {
                    minimumPre = P_for_secondTour[i].votes;
                }
            }
            printf("\nminimumPre: %.f\n", minimumPre);

            for (int i = 0; i < Num_P_second_tour; i++) {
                if (P_for_secondTour[i].votes == minimumPre) {
                    Numbermin++;
                    printf("%d.%s President is loser : %.f \n", i + 1, P_for_secondTour[i].name, P_for_secondTour[i].votes);
                } else {
                    printf("%d.%s President is winner: %.f \n", i + 1, P_for_secondTour[i].name, P_for_secondTour[i].votes);
                    Second_to_final++;
                }
            };
        } while (Numbermin > 1);
        President P_for_Final[Second_to_final];
        for (int i = 0; i < Num_P_second_tour; i++) {
            if (!P_for_secondTour[i].votes == minimumPre) {
                strcpy(P_for_Final[repetitionMin].name, P_for_secondTour[i].name);
                repetitionMin++;
            }
        }
        if (Second_to_final == 1) {
            printf("\nThe election is done!! President winner is%s\n", P_for_Final[0].name);
        } else {
            printf("\nPresidents have qualified for the final tour :\n");
            // we use here Function :
            for (int i = 0; Num_E; i++) {
                voting_repetition(Second_to_final, P_for_Final, choice);
            }

            maximumPre = P_for_Final[0].votes;
            for (int i = 0; i < Num_P_second_tour; i++) {
                if (maximumPre < P_for_Final[0].votes) {
                    maximumPre = P_for_Final[i].votes;
                }
            }
            for (int i = 0; i < Second_to_final; i++) {
                if (P_for_Final[i].votes == maximumPre) {
                    printf("%d.%s President is winner : %.f \n", i + 1, P_for_Final[i].name, P_for_Final[i].votes);
                } else {
                    printf("%d.%s President is loser: %.f \n", i + 1, P_for_Final[i].name, P_for_Final[i].votes);
                }
            };
        }
    };
};