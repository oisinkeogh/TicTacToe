/*
    C Tic Tac Toe Game
    Original Author: Vibhutesh Kumar Singh
    Adapted from C++ to C by Vibhutesh Kumar Singh
    Original Version Written in November 2013
    Source: http://cncpp.divilabs.com/2013/11/c-tic-tac-toe-game-project-with-source.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num[10] = {'o','1','2','3','4','5','6','7','8','9'};
char conn[17] = {'o','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
/*
    Function to return status 1 for game over with a success,
    -1 for game in progress & 0 for game over & draw situation.
*/

int win(int select)
{
    int tttWinningArr[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
    int connFourWinningArr[10][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16},{1,6,11,16},{4,7,10,13}};

    switch(select)  {
        case 1:
            for (int i = 0; i < 8; i++) {
                if (num[tttWinningArr[i][0]] == num[tttWinningArr[i][1]] && num[tttWinningArr[i][1]] == num[tttWinningArr[i][2]])   {
                    return 1;
                }
            }
                 for (int i=0; i <=9; i++)  {
                    if (num[i] == '1' + i)  {
                    return 0;
                    }
                }
                    return -1;
    break;

        case 2:
            for (int i = 0; i < 8; i++) {
                if (conn[connFourWinningArr[i][0]] == conn[connFourWinningArr[i][1]] && conn[connFourWinningArr[i][1]] ==
                    conn[connFourWinningArr[i][2]] && conn[connFourWinningArr[i][2]] == conn[connFourWinningArr[i][3]])   {
                    return 1;
                }
            }
                 for (int i=0; i <=16; i++)  {
                    if (num[i] == 'A' + i)  {
                    return 0;

                    }
                }
                    return -1;
    break;
}
}

void tttPrint() // Function to draw the player's game board along with their input
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("\n");

    for (int i=0, j=0; i<3; i++, j+=3)    {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", num[j+1], num[j+2], num[j+3]);

    if (i<=2)  {
    printf("     |     |     \n");
    if (i<2)  {
    printf("_____|_____|_____\n");
    }
    }
    }
}

void connectFourPrint()
{
    printf("\n\n\tConnect 4\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("\n");

    for (int i=0, j=0; i<4; i++, j+=4)    {
    printf("     |     |     |     \n");
    printf("  %c  |  %c  |  %c  |  %c\n", conn[j+1], conn[j+2], conn[j+3], conn[j+4]);

    if (i<=3) {
    printf("     |     |     |     \n");
    if (i<3)   {
    printf("_____|_____|_____|_____\n");
    }
    }
    }
}

int tttCheck(int player, int gameSelect)    {
    int ch;
 player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &ch);

        char m = (player == 1) ? 'X' : 'O';

        for (int y=0; y <=9; y++)   {

        if (ch == y+1 && num[y+1] == '1' + y)   {
            num[y+1] = m;
            break;
        }

        else
        {
            printf("Invalid move ");
            player--;
            getchar(); // To consume the newline character
            getchar(); // Wait for user input
        }
        }
        return win(gameSelect);
        player++;

}

int connFourCheck(int player, int gameSelect) {
    char ch;
    player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%c", &ch);

        char m = (player == 1) ? 'X' : 'O';

        for (int y=0; y <=16; y++)   {

        if (ch == 'A' + y && num[y] == 'A' + y)   {
            num[y+1] = m;
        }

        else
        {
            printf("Invalid move ");
            player--;
            getchar(); // To consume the newline character
            getchar(); // Wait for user input
        }
        }
        return win(gameSelect);
        player++;

}

int tournament(int player, int n)    {
    int playerOneWin = 0, playerOneLoss = 0, playerTwoWin = 0, playerTwoLoss = 0;

    for(int i=0; i<n; i++)   {
    if (player == 1)    {
         playerOneWin++;
         playerTwoLoss++;
    }
    else {
         playerTwoWin++;
         playerOneLoss++;
    }
    }
    printf("Player One Wins: %d / Player Two Wins: %d", playerOneWin, playerTwoWin);
    printf("Player One Losses: %d / Player Two Losses: %d", playerOneLoss, playerTwoLoss);
}

void reset()    {
    char numReset[10] = {'o','1','2','3','4','5','6','7','8','9'};
    char connReset[17] = {'o','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

    strcpy(num, numReset);
    strcpy(conn, connReset);
}

int main()
{
    int player = 1, i, x, gameSelect, tourCount;

        printf("How many games would you like to play? ");
        scanf("%d", &tourCount);

        for (x=0; x <tourCount; x++) {

        printf("Select 1 for Tic Tac Toe or 2 for Connect-4! ");
        scanf("%d", &gameSelect);

        if (gameSelect == 1)    {
            tttPrint();
        }
        else if (gameSelect == 2)   {
            connectFourPrint();
        }
        else{
            printf("Invalid Option!");
        }
    do
    {

        if (gameSelect == 1)    {
            tttPrint;
            int i = tttCheck(player, gameSelect);
        }
        else if (gameSelect == 2)   {
            connectFourPrint;
            int i = connFourCheck(player, gameSelect);
        }
    } while (i == -1);


    if (i == 1) {
        printf("==> Player %d wins!\n", --player);
    }
    else    {
        printf("==> Game draw\n");
    }
    int tournamentCount = tournament(player, tourCount);
    reset();
        }
    getchar(); // Wait for user input before exiting
    return 0;

}
