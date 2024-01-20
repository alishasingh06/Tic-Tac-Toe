#include <iostream>
#include <stdlib.h>
using namespace std;

int choice;
char option;
int row,column;
char turn = 'X';
bool draw = false;

//array for the board with position number
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void display_board() { //to display the current status of board
    cout << "     |     |     " << endl;
    cout << "  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<< endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<< endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<< endl;
    cout << "     |     |     " << endl;
    cout << "\nEnter the position to input your move" << endl;
}

void player_turn(){ //to get player input and update the board
    if(turn == 'X') {
        cout << "Player 1 [X] turn: " << endl;
    }
    else if(turn == 'O') {
        cout << "Player 2 [O] turn: " << endl;
    }

    cin >> choice;
    switch(choice){
        case 1:
            row=0;
            column=0;
            break;
        case 2:
            row=0;
            column=1;
            break;
        case 3:
            row=0; 
            column=2;
            break;
        case 4:
            row=1; 
            column=0;
            break;
        case 5:
            row=1;
            column=1;
            break;
        case 6:
            row=1;
            column=2;
            break;
        case 7:
            row=2;
            column=0;
            break;
        case 8:
            row=2;
            column=1;
            break;
        case 9:
            row=2;
            column=2;
            break;
        default:
            cout << "Invalid position!" << endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position already occupied
        cout << "Box is already filled! Please choose another position." << endl;
        player_turn();
    }
    display_board();
}

bool gameover(){ //to get game status
    for(int i=0; i<3; i++)
    if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
    return false; //checking the win for rows and columns

    if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
    return false; //checking the win for both diagonals

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true; //checking if the game is in continue mode or not


    draw = true;
    return false; //checking if the game already draw
}

void askPlayAgain() { //asking user to play again
    cout << "Do you want to play again? (Y/N)" << endl;
    cin >> option;

    while (option != 'Y' && option != 'y' && option != 'N' && option != 'n') {
        cout << "Invalid input! Enter again." << endl;
        cin >> option;
    }
}

int main()
{
    cout << "Welcome to the TIC-TAC-TOE game!" << endl; //starting game
    cout << "For 2 players: PLAYER 1 [X] - PLAYER 2 [O]\n" << endl;

    while (true) {
        while (gameover()) {
            display_board();
            player_turn();
            gameover();
        }

        if (turn == 'X' && draw == false) {
            cout << "Congratulations! Player 1 has won." << endl;
        }
        else if (turn == 'O' && draw == false) {
            cout << "Congratulations! Player 2 has won." << endl;
        }
        else {
            cout << "Oops! It's a draw." << endl;
        } //displaying game result

    askPlayAgain();

    if (option=='Y' || option=='y') { //reset game if playing again
        for (int i=0 ; i<3 ; i++) {
            for (int j=0 ; j<3; j++) {
                board[i][j] = (i*3 + j + 1) + '0'; //reset board to position numbers
            }
        }
        turn = 'X'; //reset turn to player 1
    }
    else {
        break; //exit the game loop
    }
  }
  return 0;
}
