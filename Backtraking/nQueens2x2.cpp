#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----\n";
}
bool isSafe(vector<vector<char>>board,int row,int col){
    int n = board.size();
    //horizental
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    //vertical
    for(int j=0;j<row;j++){
        if(board[j][col]=='Q'){
            return false;
        }
    }

    //Diagonal Left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //Daigonal Right
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}

void nQueen(vector<vector<char>> board,int row){
    int n = board.size();
    if(row==n){
        printBoard(board);
        return;
    }

    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i] = 'Q';
            nQueen(board,row+1);    
            board[row][i] = '.';
        }
    }
}

int main(){
    int n=4;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    nQueen(board,0);

    return 0;
}