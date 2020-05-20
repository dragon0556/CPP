#include <iostream>

using namespace std;

char boardGame[3][3] = {{'*','*','*'}, {'*','*','*'}, {'*','*','*'}};
class Player {
    public:
    int id;
    char mark;
    void play(char mark, int id);
};

class Game{
    
    public:
    void startGame();
    void showBoard();
    bool validLocation(int loc, char mark);
    bool checkresult(char mark);
    
};

int main()
{
    Game game;
    
    char gameStart;
    
    cout<<"\t\tTic Toc Toe\n";
    cout<<"=================================\n";
    cout<<"\nShall we start the game(y/n):\t";
    cin >>gameStart;
    
    if(gameStart=='y' || gameStart =='Y'){
        game.startGame();
    }

    return 0;
}

void Player::play(char mark, int id){
    Game game;
    int loc;
    game.showBoard();
    cout << "\nPlayer "<<id<<" Select your location\n";
    cin >> loc;
    while(!game.validLocation(loc, mark)){
        cout<< "Select valid location:\t ";
        cin >> loc;
    }
    
}

void Game::startGame(){
    Player player1 ;
    Player player2 ;
    int startPlayer;
    bool player1Turn = false;
    bool player2Turn = false;
    int i = 0;
    bool resultDeclared = false;
    cout<< "Enter first player mark:\t";
    cin>>player1.mark;
    cout<< "\nEnter first player mark:\t";
    cin>>player2.mark;
    
    do{
       cout<<"\nSelect Player to start game(1/2):\t";
        cin>>startPlayer;
        if(startPlayer == 1){
            player1Turn = true;
        }
        else{
            player2Turn = true;
        } 
    }while(startPlayer != 1 && startPlayer != 2);
    
        
        while(i<9){
            if(player1Turn){
                player1.play(player1.mark,1);
                if(checkresult(player1.mark)){
                    showBoard();
                    cout<< "\nPlayer1 is the winner";
                    resultDeclared = true;
                    break;
                }
                player1Turn = false;
                player2Turn = true;
                
            }
            else{
                player2.play(player2.mark, 2);
                if(checkresult(player2.mark)){
                    showBoard();
                    cout<< "\nPlayer2 is the winner";
                    resultDeclared = true;
                    break;
                }
                player2Turn = false;
                player1Turn = true;
                
            }
            
            i++;
        }
        
        if(!resultDeclared){
            cout<< "Game draw";
        }
}

void Game::showBoard(){
    int j,k;
    int p = 1;
    cout<<"\nCurrent Game Board Position\n";
    for(j=0; j<3; j++){
        for(k =0; k < 3; k++){
            cout<< p <<"  "<<boardGame[j][k];
            cout<<"\t|";
            p++;
        }
        cout <<"\n-------------------------------\n";
    }
}

bool Game::validLocation(int loc, char mark){
    bool valid = false;
    switch(loc){
        case 1:
        if(boardGame[0][0] == '*'){
            boardGame[0][0] = mark;
            valid = true;
        }
        
        break;
        case 2:
        if(boardGame[0][1] == '*'){
            boardGame[0][1] = mark;
            valid = true;
        }
        break;
        case 3:
        if(boardGame[0][2] == '*'){
            boardGame[0][2] = mark;
            valid = true;
        }
        break;
        case 4:
        if(boardGame[1][0] == '*'){
            boardGame[1][0] = mark;
            valid = true;
        }
        break;
        case 5:
        if(boardGame[1][1] == '*'){
            boardGame[1][1] = mark;
            valid = true;
        }
        break;
        case 6:
        if(boardGame[1][2] == '*'){
            boardGame[1][2] = mark;
            valid = true;
        }
        break;
        case 7:
        if(boardGame[2][0] == '*'){
            boardGame[2][0] = mark;
            valid = true;
        }
        break;
        case 8:
        if(boardGame[2][1] == '*'){
            boardGame[2][1] = mark;
            valid = true;
        }
        break;
        case 9:
        if(boardGame[2][2] == '*'){
            boardGame[2][2] = mark;
            valid = true;
        }
        break;
    }
    
    return valid;
}

bool Game::checkresult(char mark){
    bool firstRow = (boardGame[0][0]==mark && boardGame[0][1] == mark && boardGame[0][2] == mark);
    bool secondRow = (boardGame[1][0]==mark && boardGame[1][1] == mark && boardGame[1][2] == mark);
    bool thirdRow = (boardGame[2][0]==mark && boardGame[2][1] == mark && boardGame[2][2] == mark);
    bool firstColumn = (boardGame[0][0]==mark && boardGame[1][0] == mark && boardGame[2][0] == mark);
    bool secondColumn = (boardGame[0][1]==mark && boardGame[1][1] == mark && boardGame[2][1] == mark);
    bool thirdColumn = (boardGame[0][2]==mark && boardGame[1][2] == mark && boardGame[2][2] == mark);
    bool firstDiagonal = (boardGame[0][0]==mark && boardGame[1][1] == mark && boardGame[2][2] == mark);
    bool secondDiagonal = (boardGame[2][0]==mark && boardGame[1][1] == mark && boardGame[0][2] == mark);
    
    return (firstRow || secondRow || thirdRow || firstColumn || secondColumn || thirdColumn || firstDiagonal || secondDiagonal);
}
