/*
- Tic Tac Toe Porject
- TicTacToeProj.c
- Original Game By: Vibhutesh Singh
- Adapted and Edited further by: Oisin Keogh (C00301085) & Simon Thibault (C00301604)
- Final Adaptation/Version: 11/12/2024
- Version: 1.1.5 (Final)
========================================================================================================================================================================================================================================================
*/



/* Includes:
==================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>


//===Struct For Profile Creation and Saving==============================================================================================================================================================================================================

struct Profiles { //Structure for the username and password arrays that correspond to created profiles
    char username[20];
    char password[25];
};

//======================================================================================================================================================================================================================================================



//===Lowercase String Function==========================================================================================================================================================================================================================

void to_lowercase(char *str) { // Function to convert a string to lowercase (Used for entering guest, sign up, sign in modes)
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);//no matter the case of the string entered it converts it lowercase so it can accept more variations incase of accidental case changes like: "sigN UP"
    }
}

//======================================================================================================================================================================================================================================================

//===Game Board Arrays==================================================================================================================================================================================================================================

char num[10] = {'o','1','2','3','4','5','6','7','8','9'};   //array for tictactoe
char conn[17] = {'o','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q'};  //array for connect four

int tttWinningArr[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};    //array for winning arrangements for tictactoe
int connFourWinningArr[10][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16},{1,6,11,16},{4,7,10,13}};    //array for winning arrangements of connect four

//======================================================================================================================================================================================================================================================


//===Ai Difficulty Function=============================================================================================================================================================================================================================

/*
    Function to return status 1 for game over with a success,
    -1 for game in progress & 0 for game over & draw situation.
*/
void computerAI(int gameSelect, int aiSelect)   {
int move;
char m = 'O', playerOne = 'X';
int foundMove = 0, emptySlot = -1, playerOneCount = 0, aiCount = 0;

switch (gameSelect) {   //for picking the ai for either tictactoe or connect four

    case 1:

        switch(aiSelect)    {   //For TicTacToe

            case 1: //easy mode

        do  {
            move = (rand() % 9) + 1;    //randomly picks a number between 1 and 9
        }while (num[move] == 'X' || num[move] == 'O');  //checks to make sure the option chosen isn't already filled
        num[move] = m;  //makes the move if the option is available
        printf("Computer chooses: %d\n", move); //prints the chosen option to the user

            break;

            case 2: //medium mode // only blocks

            for (int i = 0; i < 8; i++)    {    //for looping through the win conditions array

                for (int j = 0; j< 3; j++)  {  //checks each line to make sure to see what moves have been made
                    if (num[tttWinningArr[i][j]] == playerOne)   { //checks to see what moves the play has made
                        playerOneCount++;   //for each time the player places one, adds to a tally
                    }
                    else if (num[tttWinningArr[i][j]]!= 'X' && num[tttWinningArr[i][j]]!= 'O'){
                        emptySlot = tttWinningArr[i][j];    //keeps a tally of each space that hasn't been moved
                    }
                }
                if (playerOneCount == 2 && emptySlot != -1)  {//if the player has made a move, and the slot isn't filled
                    num[emptySlot] = m;// makes its move based on this
                    printf("Computer chooses: %d\n", emptySlot);   //prints what move is made
                    printf("Nice try!");
                    foundMove = 1;  //changes status off of random move
                    break;
                }
                if (foundMove!= 1) {   //runs till enough moves are made so that the computer can make moves based on inputs
                    do  {
                        move = (rand() % 9) + 1;    //works the same as above code used in easy mode
                    }while (num[move] == 'X' || num[move] == 'O');
                        num[move] = m;
                        printf("Computer chooses: %d\n", move);
                break;
                }
            }
            break;

            case 3: //hard mode // blocks and tries to win

            for (int i = 0; i < 8; i++)    {    //for looping through the win conditions array
            char m = 'X', playerOne = 'O';
                for (int j = 0; j< 3; j++)  {  //checks each line to make sure to see what moves have been made
                    if (num[tttWinningArr[i][j]] == m) {    //checks to see what moves have been made by the computer
                        aiCount++;  //for each time the computer places one, adds to a tally
                    }
                    else if (num[tttWinningArr[i][j]] == playerOne)   { //checks to see what moves the play has made
                        playerOneCount++;   //for each time the player places one, adds to a tally
                    }
                    else {
                        emptySlot = tttWinningArr[i][j];    //keeps a tally of each space that hasn't been moved
                    }
                }
                if (aiCount == 2 && emptySlot != -1 && num[emptySlot] != 'X' && num[emptySlot] != 'O')    { //if the computer has made 2 moves, and the slot isn't filled
                    num[emptySlot] = m; // it makes its move
                    printf("Computer chooses: %d\n", emptySlot);   //prints move made by computer
                    printf("Try harder!");  //taunts player
                    foundMove = 1;  //changes status off of random move
                    break;
                }
                if (playerOneCount == 2 && emptySlot != -1 && num[emptySlot] != 'X' && num[emptySlot] != 'O')  {//if the player has made a move, and the slot isn't filled
                    num[emptySlot] = m;// makes its move based on this
                    printf("Computer chooses: %d\n", emptySlot);   //prints what move is made
                    printf("Nice try!");
                    foundMove = 1;  //changes status off of random move
                    break;
                }
                if (foundMove!= 1) {   //runs till enough moves are made so that the computer can make moves based on inputs
                    do  {
                        move = (rand() % 9) + 1;    //works the same as above code used in easy mode
                    }while (num[move] == 'X' || num[move] == 'O');
                        num[move] = m;
                        printf("Computer chooses: %d\n", move);
                break;
                }
            }

            break;
    }
        break;

    case 2:

        switch(aiSelect)    {   //For Connect 4
            case 1: //easy mode
        do  {
            move = rand() % 16 +1;  //selects a number between 1 and 17
        }while (conn[move] == 'X' || conn[move] == 'O');    //checks if a move has already been made
        conn[move] = m; //makes the move if a move hasn't been made in the spot
        printf("Computer chooses: %c\n", conn[move]);   //prints the option to the user

            break;

            case 2: //medium mode   // only blocks

            for (int i = 0; i < 10; i++)    {   //runs through all winning selections

                for (int j = 0; j< 4; j++)  {  //checks each line

                    if (conn[connFourWinningArr[i][j]] == playerOne)   {   // checks if the player made a move in a spot
                        playerOneCount++;   //adds to the move counter
                    }
                    else if (conn[connFourWinningArr[i][j]] != 'X' && (conn[connFourWinningArr[i][j]]) != 'O'){
                        emptySlot = connFourWinningArr[i][j]; //for empty spots
                    }
                }
                }
                if (playerOneCount == 3 && emptySlot != -1)  {  //once the player makes a move
                    printf("Computer chooses: %c\n", conn[emptySlot]);
                    conn[emptySlot] = m;
                    printf("Nice try!");
                    foundMove = 1;
                    break;
                }
                if (foundMove !=1) {   //runs at the start until the player/ai count is reached to make a move
                    do  {
                        move = rand() % 16 +1; //same as easy mode above
                    }while (conn[move] == 'X' || conn[move] == 'O');
                        printf("Computer chooses: %c\n", conn[move]);
                        conn[move] = m;
                break;
                }


            break;

            case 3: //hard mode blocks and tries to win

            for (int i = 0; i < 10; i++)    {   //runs through all winning selections
            char m = 'X', playerOne = 'O';
                for (int j = 0; j< 4; j++)  {  //checks each line
                    if (conn[connFourWinningArr[i][j]] == m) {  // checks if the computer has made a move in a spot
                        aiCount++;  //adds to the move counter
                    }
                    else if (conn[connFourWinningArr[i][j]] == playerOne)   {   // checks if the player made a move in a spot
                        playerOneCount++;   //adds to the move counter
                    }
                    else {
                        emptySlot = connFourWinningArr[i][j]; //for empty spots
                    }
                }
                if (aiCount == 3 && emptySlot != -1 && conn[emptySlot] != 'X' && conn[emptySlot] != 'O')    {   //once the computer makes a move it will try block the user
                    printf("Computer chooses: %c\n", conn[emptySlot]);  //prints to the user what spot it chose
                    conn[emptySlot] = m;    //makes a move based on this info
                    printf("Try harder!");
                    foundMove = 1;  //ends the random cycle
                    break;
                }
                if (playerOneCount == 3 && emptySlot != -1 && conn[emptySlot] != 'X' && conn[emptySlot] != 'O')  {  //once the player makes a move
                    printf("Computer chooses: %c\n", conn[emptySlot]);
                    conn[emptySlot] = m;
                    printf("Nice try!");
                    foundMove = 1;
                    break;
                }
                if (foundMove !=1) {   //runs at the start until the player/ai count is reached to make a move
                    do  {
                        move = rand() % 16 +1; //same as easy mode above
                    }while (conn[move] == 'X' || conn[move] == 'O');
                        printf("Computer chooses: %c\n", conn[move]);
                        conn[move] = m;
                break;
                }
            }
            break;
}break;
}
}

//===End of Ai Difficulty Function=======================================================================================================================================================================================================================



//===Ways To Win Function================================================================================================================================================================================================================================
int win(int select)
{
   switch(select)  {   //selected in main for which of the two games that's being played
        case 1: //for tictactoe win check
            for (int i = 0; i < 8; i++) {   //loops for each of the 8 sets of winning arrangements
                if (num[tttWinningArr[i][0]] == num[tttWinningArr[i][1]] && num[tttWinningArr[i][1]] == num[tttWinningArr[i][2]])   {   //checks if the values in the first, second and third column of the winning array to see if they match
                    return 1;   //if they match, the game is won
                }
            }
                 for (int i=0; i <=9; i++)  {   //for checking all the slots have been filled
                    if (num[i+1] == '1' + i)  { //checking if the numbers are still in place, so the game can continue
                    return -1;
                    }
                }
                 return 0;  //if neither of the above two are true, the game must be a draw as there is no more places to be filled
    break;
        case 2: //for connect four win check
            for (int i = 0; i < 10; i++) {   //loops for each of the 8 sets of winning arrangements
                if (conn[connFourWinningArr[i][0]] == conn[connFourWinningArr[i][1]] && conn[connFourWinningArr[i][1]] ==
                    conn[connFourWinningArr[i][2]] && conn[connFourWinningArr[i][2]] == conn[connFourWinningArr[i][3]])   { ////checks if the values in the first, second, third and fourth column of the winning array to see if they match
                    return 1;   //if they match the game is won
                }
            }
                 for (int i=0; i <=16; i++)  {  //for checking all slots have been filled
                    if (conn[i+1] == 'A' + i)  { //checking the letters are still in place, so the game can continue
                    return -1;
                    }
                }
                    return 0;   //if neither of the above are true, all slots have been filled and the game has not been won so must be a draw
    break;
}
}
//=======================================================================================================================================================================================================================================================


//===Game Board Print Function(3x3)======================================================================================================================================================================================================================
void tttPrint() // Function to draw the player's game board along with their input
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("\n");
    for (int i=0, j=0; i<3; i++, j+=3)    { //loop for printing the table for tictactoe
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n", num[j+1], num[j+2], num[j+3]);   //used to create a 3x3 where the elements from the array are correctly reflected
    if (i<2)  {
    printf("_____|_____|_____\n");
    }
    else   {
    printf("     |     |     \n");
              }
            }
}
//=======================================================================================================================================================================================================================================================

//===Game Board Print Function(4x4)======================================================================================================================================================================================================================
void connectFourPrint()
{
    printf("\n\n\tConnect 4\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("\n");
    for (int i=0, j=0; i<4; i++, j+=4)    { //loop for printing the table for connect four
    printf("      |      |      |      \n");
    printf("  %c   |  %c   |  %c   |  %c   \n", conn[j + 1], conn[j + 2], conn[j + 3], conn[j + 4]);    //used to create a 4x4 where the elements from the array are correctly reflected
    if (i<3) {
        printf("______|______|______|______\n");
    }
    else   {
        printf("      |      |      |      \n");
    }
    }
}
//=======================================================================================================================================================================================================================================================

//===User Input For Game(3x3)============================================================================================================================================================================================================================
void tttCheck(int player)    {
    int ch;
    char m = (player == 1) ? 'X' : 'O'; //for selecting X for player 1 and O for player 2
        printf("Player %d, enter a number: ", player);
        scanf("%d", &ch);   //inputs where on the board the user would like to play
        if (ch >= 1 && ch <= 9 && num[ch] == '0' + ch)   {  //loops to check if the placement from the user is already taken
            num[ch] = m;    //if the space is free, the slected placement is then taken by the user's token
        }
        else{
            printf("Invalid move! Try Again \n"); //if a user selects a square that's already been taken, they are promted to choose again
            tttCheck(player);
        }
}
//=======================================================================================================================================================================================================================================================

//===User Input For Game(4x4)============================================================================================================================================================================================================================
void connFourCheck(int player) {
    char ch, m = (player == 1) ? 'X' : 'O'; //for selecting X for player 1 and O for player 2

        printf("Player %d, enter a letter: ", player);
        scanf(" %c", &ch);   //inputs where on the board the user would like to play, done with characters between A and P
        ch = toupper(ch); // Convert input to uppercase
        if (ch >= 'A' && ch <= 'Q' && conn[ch - 'A' + 1] == ch)   { //loops to check if the placement from the user is already taken
            conn[ch - 'A' + 1] = m;   //if the space is free, the slected placement is then taken by the user's token
        }
        else{
            printf("Invalid move \n"); //if a user selects a square that's already been taken, they are promted to choose again
            connFourCheck(player);
        }
}
//=======================================================================================================================================================================================================================================================

//===Clear Board Function================================================================================================================================================================================================================================
void reset()    {
    for (int i = 1; i <= 9; i++) {
        num[i] = '0' + i; // Resetting num array for Tic Tac Toe
    }
    for (int i = 1; i <= 16; i++) {
        conn[i] = 'A' + (i - 1); // Resetting conn array for Connect Four
    }
}
//=======================================================================================================================================================================================================================================================

//===Main Program========================================================================================================================================================================================================================================
int main()
{
    //Decleration of all variable names used for characters, strings, integer
    char a, c, p[25];
    int w;
    char mode[20]; //type of mode regarding the sign in, sign up and guest process that the user inputs via a string input
    int sw_mode=-1; // switch_mode
    int n = 1;
    struct Profiles data[n]; //Profile struct

    printf("Welcome to Tic-Tac-Toe & Connect-4!\n");
    usleep(2000000);
    printf("\nWould you like to play as a guest, sign up, or sign in?\n(!Guest Does Not Keep Record or History!)\n");

//---Switch Cases for Login Type-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Beginning of loop for inputting the type of mode the user uses (guest, sign in, sign up)
  while (sw_mode == -1) {
        fgets(mode, sizeof(mode), stdin);//Used fgets for string for less problems later in the code
        mode[strcspn(mode, "\n")] = '\0'; // Removes the newline character


        for (int i = 0; mode[i]; i++) {
            mode[i] = tolower(mode[i]);//Lowercase function that takes in any character and converts it to string for "mode[i]"
        }

        //string compare for sw mitch that compares what the user inputted from fgets and compares it or == to the switch case options below
        if (strcmp(mode, "guest") == 0) {
            sw_mode = 0;
        }
        else if (strcmp(mode, "sign up") == 0 || strcmp(mode, "signup") == 0) {
            sw_mode = 1;
        }
        else if (strcmp(mode, "sign in") == 0 || strcmp(mode, "signin") == 0) {
            sw_mode = 2;
        }
        else {
            //if invalid mode is selected this message displays, then asks the user to input again (repeats until user enters correct input)
            printf("\nInvalid mode entered, please try again.\n");
            printf("Please choose between, guest, sign up, or sign in:\n");
        }

    }
    usleep(500000); //sleep timer just to make the program run smoothly

//***Switch Case Mode Types*******************************************************************************************************************************************************************************************************************************
switch (sw_mode) {//entering switch case modes

//***Guest************************************************************************************************************************************************************************************************************************************************
case (0):
    {
        //if "guest" was inputted, enters guest switch case
        printf("\nWelcome Guest!\n");
        usleep(1000000);
        break;
        //after break, goes to main game
    }

//***Sign Up***********************************************************************************************************************************************************************************************************************************************
case (1):
        //if sign up is inputted, enters sign up switch case
        for (int i = 0; i < n; i++) {
            //Asks user for username
            printf("\nPlease Create A Username: ");
            fgets(data[i].username, sizeof(data[i].username), stdin); //gets the username from fgets and stores it into struct username
            data[i].username[strcspn(data[i].username, "\n")] = '\0'; //copies username into the username array

            char p[25]; //Temporary password storage
            int j = 0;  //Index for the password array
            do {
                printf("\nPlease Create A Password (At Least 7 Characters Long): ");
                j = 0;                   //Resets the password array
                memset(p, 0, sizeof(p)); //Clears the password array

                while (j < 20) { //Limits the password to 20 characters (probably not necessary but creates a loop)
                    a = getch(); //Gets a character without echoing
                    if (a == '\r') { //So if enter is pressed it won't result in *
                        break;
                    } else if (a == '\b') { //So if backspace is entered it won't result in *
                        if (j > 0) {
                            printf("\b \b"); //Erases the last '*'
                            j--;             //Move back in the password array
                        }
                    } else {
                        // Stores the character and display '*'
                        p[j++] = a;
                        printf("*");//echos back "*" for every input by the user except backspace and enter
                    }
                }
                p[j] = '\0'; //Null-terminates the password string

                if (strlen(p) < 7) {
                    printf("\nPassword must be at least 7 characters long. Try again.\n");
                    //continous loop so everytime the user enters a password less than 7 letters it asks until the request is met
                }

            } while (strlen(p) < 7 || strcmp(data[i].username, p) == 0); //Repeat if the password is too short or matches the username

            // Stores the password in the profiles struct password array
            strcpy(data[i].password, p);

            // Save the new account to a file within the codes folder
            //Opens the file "accounts.txt" in the folder of this code in append mode ("a").
            FILE *file = fopen("accounts.txt", "a");
            //Checks if the file was opened.
            if (file == NULL) {
                printf("\nError: Unable to save account to file.\n");//Error message if it wasn't able to find file to save to
                return 1;
            }
            fprintf(file, "%s %s\n", data[i].username, data[i].password); //Writes username and password to file
            fclose(file);//Closes file as it won't be needed any further

            printf("\nThank you for signing up, %s\n", data[i].username);

            //printf("Your password has been set as: %s\n", data[i].password; (!To Check if Password Did Save for programming purposes uncomment this!)


            usleep(1000000); // Timer that waits for 1.5 seconds (to make it look smoother)
        }
        break;

//***Sign In***********************************************************************************************************************************************************************************************************************************************

case (2): {
        //beginning of sign in case switch
        char enteredUsername[20], enteredPassword[25];
        int authenticated = 0;

        do {
            // Prompt for username
            printf("\nPlease Enter Your Username: ");
            fgets(enteredUsername, sizeof(enteredUsername), stdin);
            enteredUsername[strcspn(enteredUsername, "\n")] = '\0';

            // Prompt for password
            printf("Please Enter Your Password: ");
            memset(enteredPassword, 0, sizeof(enteredPassword));
            int j = 0;
            //Below is the usage of the echoing of "*" when typing in password like in the sign up case
            while (j < 20) {
                a = getch();
                if (a == '\r') {
                    break;
                } else if (a == '\b') {
                    if (j > 0) {
                        printf("\b \b");
                        j--;
                    }
                } else {
                    enteredPassword[j++] = a;
                    printf("*");
                }
            }
            enteredPassword[j] = '\0'; //Null-terminates the password string

            // Open the file and check the entered credentials
            FILE *file = fopen("accounts.txt", "r");
            if (file == NULL) {
                printf("\nError: Unable to access accounts file.\n"); //If not able to find text file and open it, terminates code
                return 1;
            }

            char fileUsername[20], filePassword[25];
            //Below is the loop to compare usernames and passwords to already created account for the sign in process
            while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
                //compares the username and password from the file where created accounts are
                if (strcmp(fileUsername, enteredUsername) == 0 && strcmp(filePassword, enteredPassword) == 0) {
                    //if both username and the password match an account, int authenticcated is set to 1 or true.
                    authenticated = 1;
                    printf("\n\nWelcome back, %s!\n", fileUsername);
                    //exits loop
                    break;
                }
            }
            fclose(file);
            //if username and password doesn't match to any created accounts, it continuously asks until the request is met
            if (!authenticated) {
                printf("\n\nInvalid username or password. Please try again.\n");
            }
        } while (!authenticated); // Repeat until valid credentials are entered
        usleep(1000000);
        break;
    }
}

//---End of Log in Types-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---Main Game Playing Code--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int game = 1;
    while(game == 1){//loop that keeps playing the code below which is the entire main game, until the bottom actions are met
    int player, i, x,gameSelect=0, tourCount, playerOneWin = 0, playerTwoWin = 0, aiSelect, playerCount;
    srand(time(NULL));


    printf("\nHow many games would you like to play? ");
    printf("\nEnter 1 for a quick game, or as many as you'd like for a tournament\n");
       scanf("%d", &tourCount);    //takes in an input from the user for how many rounds they'd like to play in the tournament
        printf("Select 1 for Tic Tac Toe or 2 for Connect-4! ");
        scanf("%d", &gameSelect);   //used to select what mode the user would like to play
        printf("1 Player or 2 Player: ");
        scanf("%d", &playerCount);
        // Only ask for AI difficulty if the player selects 1 Player
        if (playerCount == 1) {
        printf("What difficulty of computer would you like to face: 1. Easy || 2. Medium || 3. Hard ");
        scanf("%d", &aiSelect);
    }
    for (x=0; x <tourCount; x++) {  //loop used for running the tournament
        player = 1;
        i = -1; //sets game state at start
    do
    {
    if (playerCount == 2)   {   //for player vs player games
        if (gameSelect == 1)    {   //if tictactoe is selected
            tttPrint(); //prints tictactoe
            tttCheck(player);   //runs the function to check if a input is valid or not
            i = win(gameSelect); //checks if the win condition is met
            player = (player % 2) ? 2 : 1;  //assigns what order the players go in
        }
        else if (gameSelect == 2)   {   //if connect four is selected
            connectFourPrint(); //prints connect four
            connFourCheck(player);  //runs the function to check if a input is valid or not
            i = win(gameSelect);    //checks if the game has been won after each move
            player = (player % 2) ? 2 : 1;  //assigns what order the players go in
        }
        else{
            printf("Invalid Option!");  //if user inputs an invalid option
        }
    }
    else    {   //for player vs computer games
        if (gameSelect == 1 && aiSelect !=3)    {   //if tictactoe is selected
            tttPrint(); //prints tictactoe
            if (player == 1)    {
                tttCheck(player);   //runs the function to check if a input is valid or not
            }
            else    {
                computerAI(gameSelect, aiSelect);
            }
                i = win(gameSelect);    //checks if the game has been won after each move
                player = (player % 2) ? 2 : 1;  //assigns what order the players go in
    }
        else if (gameSelect == 2 && aiSelect !=3)   {   //if connect four is selected
            connectFourPrint(); //prints connect four
            if (player == 1) {
            connFourCheck(player);  //runs the function to check if a input is valid or not
            }
            else    {
                computerAI(gameSelect,aiSelect);
            }
            i = win(gameSelect);    //checks if the game has been won after each move
                player = (player % 2) ? 2 : 1;  //assigns what order the players go in
        }
        else if (gameSelect == 1 && aiSelect == 3)    {   //if tictactoe is selected and hard mode
            tttPrint(); //prints tictactoe
            if (player == 1)    {
                computerAI(gameSelect, aiSelect);   //runs the function to check if a input is valid or not
            }
            else    {
                tttCheck(player);
            }
                i = win(gameSelect);    //checks if the game has been won after each move
                player = (player % 2) ? 2 : 1;  //assigns what order the players go in
    }
        else if (gameSelect == 2 && aiSelect == 3)   {   //if connect four is selected
            connectFourPrint(); //prints connect four
            if (player == 1) {
            computerAI(gameSelect,aiSelect);
            }
            else    {
                connFourCheck(player);  //runs the function to check if a input is valid or not
            }
            i = win(gameSelect);    //checks if the game has been won after each move
                player = (player % 2) ? 2 : 1;  //assigns what order the players go in
        }
        else    {
            printf("Invalid Option!");  //if user inputs an invalid option
        }
    }

//---End Game Playing Code---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    } while (i == -1);
    if (gameSelect == 1)    {   //if tictactoe is selected
            tttPrint(); }   //reprints the final screen value
    else if (gameSelect == 2)   {
            connectFourPrint(); }
    if (i == 1)    {
        if (player == 2)    {
         playerOneWin++;    //if the game is won and player selected is player 2, player one wins
         printf("==> Player 1 wins!\n");
    }
    else {
         playerTwoWin++;
         printf("==> Player 2 wins!\n");
         }
    }
    else if (i == 0)   {
        printf("==> Game draw\n");
    }
        reset();    //resets the values to allow for a new game
    }
    printf("Player One Wins: %d\n Player Two Wins: %d\n", playerOneWin, playerTwoWin);  //prints out the result of the tournament
    getchar(); // Wait for user input before exiting
    printf("\nPress 1 to Play again, or 0 to Quit:\n");//Asks user if it would like to play again, or quit the program
    scanf("%d", &game);//scans input 1 for play again, or 0 to close program
    }
    usleep(200000);
    printf("Thank You for Playing");
    return 0;

}
//===End of Program===========================================================================================================================================================================================================================================
