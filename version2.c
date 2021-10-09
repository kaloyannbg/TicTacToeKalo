#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

char Squares[10] = {'k', '1','2','3','4','5','6','7','8','9'};

void resetSquares();

void printMenu();

void printSquares();

int checkWin();

int main() {

system("color 07");

int choice = 0;

char mark = 'X';

int player = 0;

int playerPrint = 1;

int squareChoice = 0;

int xWins = 0;

int zeroWins = 0;

int draws = 0;

    do {

    printMenu();

    printf(" -- Enter your choice: ");

    scanf("%d", &choice);

    player = 0;

    if(choice == 1) {

         system("cls");

        printf("\n\n -- You start new game. \n\n");

        resetSquares();

        do {

        printSquares();

        if(player % 2 == 0 ) {
            mark = 'X';
            playerPrint = 1;
        } else {
            mark = '0';
            playerPrint = 2;
        }


        printf("\n\n -- Player: %d (%c): ", playerPrint, mark);

        scanf("%d", &squareChoice);

        if(squareChoice < 1 || squareChoice > 9 ) {
            printf("\n\n -- Invalid square choice. Try again.\n\n ");
        } else {
            if(Squares[squareChoice] == squareChoice + '0') {
                Squares[squareChoice] = mark;
                player++;
                system("cls");

            } else {
                printf("\n\n -- Invalid square choice. Try again\n\n");
            }
        }



        } while(checkWin() == -1);

        if(checkWin() == 1) {

            printSquares();

            printf("\n\n -- The winner is Player: %d (%c)", playerPrint, mark);

            if(playerPrint == 1) {
                xWins++;
            } else if(playerPrint == 2) {
                zeroWins++;
            }

        } else if(checkWin() == 2) {
            printf("\n\n -- No one win!");
            draws++;
        }

    } else if(choice == 2) {
        printf("\n\n");
        printf(" -- Player 1 (X) Wins: %d -- ", xWins);
        printf("\n\n -- Player 2 (0) Wins: %d -- ", zeroWins);
        printf("\n\n -- Draws: %d -- ", draws);
    } else if(choice == 0) {
        printf("\n\n -- Bye Bye");
    } else {
        printf("\n\n -- Invalid choice");
    }



    } while(choice != 0);

    return 0;
}

void resetSquares() {

    int i;

    for(i = 1; i < 10; i++) {
        Squares[i] = i + '0';
    }

}

void printMenu() {

    printf("\n\n -- 1. Enter 1 for Start new game");
    printf("\n -- 2. Enter 2 to check Wins and Draws.");
    printf("\n -- 0. Enter 0 for Quit");
    printf("\n\n");
}

void printSquares(void) {

    //printf("\033[0;33m");

    int i;
    printf("   _________________ \n");
    printf("  |     |     |     |   \n");

    for(i = 1; i < 10; i++) {
        printf("  |");
    if(Squares[i] == 'X') {
        printf("\033[1;33m");
       printf("  %c", Squares[i]);
         printf("\033[0m");
    } else if(Squares[i] == '0') {
        printf("\033[1;36m");
       printf("  %c", Squares[i]);
       printf("\033[0m");
    } else {
        printf("\033[0m");
       printf("  %c", Squares[i]);
    }

        if(i % 3 == 0) {
            printf("  |");
            printf("\n  |_____|_____|_____| \n\n");
        }
    }
    /*
    printf("\033[1;33m"); // Yellow
    printf("   _________________ \n");
    printf("  |     |     |     |   \n ");
    printf(" |  %c  |  %c  |  %c  |\n", Squares[1], Squares[2], Squares[3]);
    printf("  |_____|_____|_____| \n");
    printf("  |     |     |     |   \n ");
    printf(" |  %c  |  %c  |  %c  |\n", Squares[4], Squares[5], Squares[6]);
    printf("  |_____|_____|_____|\n");
    printf("  |     |     |     |   \n ");
    printf(" |  %c  |  %c  |  %c  |\n", Squares[7], Squares[8], Squares[9]);
    printf("  |_____|_____|_____|\n\n");
    printf("\033[0m");
    */



}

int checkWin() {

    if(Squares[1] == Squares[2] && Squares[2] == Squares[3]) {
        return 1;
    } else if(Squares[4] == Squares[5] && Squares[5] == Squares[6]) {
        return 1;
    } else if(Squares[7] == Squares[8] && Squares[8] == Squares[9]) {
        return 1;
    } else if(Squares[1] == Squares[4] && Squares[4] == Squares[7]) {
        return 1;
    } else if(Squares[2] == Squares[5] && Squares[5] == Squares[8]) {
        return 1;
    } else if(Squares[3] == Squares[6] && Squares[6] == Squares[9]) {
        return 1;
    } else if(Squares[1] == Squares[5] && Squares[5] == Squares[9]) {
        return 1;
    } else if(Squares[7] == Squares[5] && Squares[5] == Squares[3]) {
        return 1;
    } else if(Squares[1] != '1' && Squares[2] != '2' && Squares[3] != '3' && Squares[4] != '4'
    && Squares[5] != '5' && Squares[6] != '6' && Squares[7] != '7' && Squares[8] != '8'
     && Squares[9] != '9') {
        return 2;
    } else {
        return -1;
    }

}
