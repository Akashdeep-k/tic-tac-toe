//Akashdeep-k
//Tic Tac Toe console based game
#include<iostream>
#include<conio.h>
using namespace std;
void scrclr(){
    #if __linux__
    system("clear");
    #elif _WIN64
    system("CLS");
    #else
    system("clear");
    #endif 
}
void boardPrint(char board[][3]){
    (board[0][0] == ' ') ? cout<<"1" : cout<<board[0][0]; cout<<" | ";
    (board[0][1] == ' ') ? cout<<"2" : cout<<board[0][1]; cout<<" | ";
    (board[0][2] == ' ') ? cout<<"3" : cout<<board[0][2]; cout<<endl<<"---------"<<endl;
    (board[1][0] == ' ') ? cout<<"4" : cout<<board[1][0]; cout<<" | ";
    (board[1][1] == ' ') ? cout<<"5" : cout<<board[1][1]; cout<<" | ";
    (board[1][2] == ' ') ? cout<<"6" : cout<<board[1][2]; cout<<endl<<"---------"<<endl;;
    (board[2][0] == ' ') ? cout<<"7" : cout<<board[2][0]; cout<<" | ";
    (board[2][1] == ' ') ? cout<<"8" : cout<<board[2][1]; cout<<" | ";
    (board[2][2] == ' ') ? cout<<"9" : cout<<board[2][2]; cout<<endl;
}
void addSymbol(char board[][3], int choice, int i){
    char symbol;
    if(i%2==0)
    symbol = 'X';
    else
    symbol = 'O';

    if(choice == 1) {board[0][0] = symbol; }
    if(choice == 2) {board[0][1] = symbol; }
    if(choice == 3) {board[0][2] = symbol; }
    if(choice == 4) {board[1][0] = symbol; }
    if(choice == 5) {board[1][1] = symbol; }
    if(choice == 6) {board[1][2] = symbol; }
    if(choice == 7) {board[2][0] = symbol; }
    if(choice == 8) {board[2][1] = symbol; }
    if(choice == 9) {board[2][2] = symbol; }
}
bool win_check(char board[][3], int i){
    char symbol;
    if (i % 2 == 0)
        symbol = 'X';
    else
        symbol = 'O';
    if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) return true;
    if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) return true;
    if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) return true;
    if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) return true;
    if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) return true;
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;

    return false;
}
int main(){
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    int choice;
    int i = 0;
    while(i < 9){
        scrclr();
        cout << endl;
        boardPrint(board);
        if (i % 2 == 0)
            cout << "Player 1 Turn (Symbol : X) " << endl << endl;
        else
            cout << "Player 2 Turn (Symbol : O) " << endl << endl;
        cout << "Enter your choice for the symbol from above matrix : ";
        cin >> choice;
        addSymbol(board, choice, i);
        if (win_check(board, i)){
            scrclr();
            cout << endl;
            boardPrint(board);
            if (i % 2 == 0)
                cout << endl << "*** Player 1 Won ***";
            else
                cout << endl << "*** Player 2 Won ***";
            break;
        }
        i++;
    }
    if (i == 9){
        scrclr();
        cout << endl;
        boardPrint(board);
        cout << "*** Match Draw ***";
    }
    return 0;
}