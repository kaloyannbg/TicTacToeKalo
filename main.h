#include <stdio.h>
#include <stdlib.h>

char square[10] = {'k', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void squareDesign(void) {

    int i = 1;

    for(i; i < 10; i++ ) {



        if( (i % 3) == 0 ) {
                if(square[i] == 'X' || square[i] == '0') {
                    printf("\t %c", square[i]);
                } else {
                    printf("\t[%c]", square[i]);
                }
            } else {
                if(square[i] == 'X' || square[i] == '0') {
                    printf("\t %c", square[i]);
                } else {
                    printf("\t[%c]", square[i]);
                }
                }


        if(i == 3 || i == 6 || i == 9) {

            printf("\n      _______ _______ _______\n\n");

        }
    }
}

int checkWin(void) {

           if(square[1] == square[2] && square[2] == square[3]) {
        return 1;
    } else if(square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if(square[7] == square[8] && square[8] == square[9]) {
        return 1;
    }  else if(square[2] == square[5] && square[5] == square[8]) {
        return 1;
    }  else if(square[7] == square[8] && square[8] == square[9]) {
        return 1;
    }  else if(square[3] == square[6] && square[6] == square[9]) {
        return 1;
    } else if(square[1] == square[5] && square[5] == square[9]) {
        return 1;
    } else if(square[3] == square[5] && square[5] == square[7]) {
        return 1;
    }
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' &&
              square[4] != '4' && square[5] != '5' && square[6] != '6' &&
              square[7] != '7' && square[8] != '8' && square[9] != '9' ) {
        return 0;
    } else {
        return 2; //If the game is not over!
    }


}

int main()
{
    printf("\n\n");
    printf("       Game X and 0 by Kalo");
    printf("\n\n\n");
    printf("Player (1) is (X) , Player(2) is (0)");
    printf("\n\n");

    int player, choice;

    char mark;

    player = 1;

    do {

    squareDesign();

    if( (player % 2) ==  1) {player = 1; } else { player = 2; }

    if(player == 1) { mark = 'X'; } else { mark = '0'; }

    printf("Player %d (%c) make your choice: ", player, mark);

    scanf("%d", &choice);

    printf("\n\n");

    if(square[1] == '1' && choice == 1) {
        square[1] = mark;
        player++;
    } else if(square[2] == '2' && choice == 2) {
        square[2] = mark;
        player++;
    } else if(square[3] == '3' && choice == 3) {
        square[3] = mark;
        player++;
    } else if(square[4] == '4' && choice == 4) {
        square[4] = mark;
        player++;
    } else if(square[5] == '5' && choice == 5) {
        square[5] = mark;
        player++;
    } else if(square[6] == '6' && choice == 6) {
        square[6] = mark;
        player++;
    } else if(square[7] == '7' && choice == 7) {
        square[7] = mark;
        player++;
    } else if(square[8] == '8' && choice == 8) {
        square[8] = mark;
        player++;
    } else if(square[9] == '9' && choice == 9) {
        square[9] = mark;
        player++;
    } else {
        printf("\n\nOption is already choosed or dont exist. Try again\n\n\n");
    }

    } while ( checkWin() == 2 );

    squareDesign();

    if(checkWin() == 1) {
        player--;
        if(player == 1) { mark = 'X'; } else { mark = '0'; }
        printf("\n\nWinner is Player %d (%c) \n\n\n", player, mark);
        system("pause");
    }

    if(checkWin() == 0) {
        printf("\n\nNo one is winner! :\(\n\n\n");
        system("pause");
    }

    printf("\n\n\n");
    return 0;
}
