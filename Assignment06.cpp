#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class NQueen{
public:
    NQueen(int n): N(n), Board(n, vector<int>(n, 0)){}

    bool solveNQueen(){
        if(solve(0)){
            cout<<"\nSolution found!"<<endl;
            PrintBoard();
            return true;
        }
        else{
            cout<<"\nNo solution found"<<endl;
            return false;
        }
    }
private:
    int N;
    vector<vector<int>> Board;
    void PrintBoard(){
        cout<<"\nChessBoard: "<<endl;
        cout<<"---------------\n";
        for(int i=0;i<N;i++){
            for(int j = 0;j< N;j++){
                if(Board[i][j] == 1)
                    cout<<setw(2)<<"Q ";
                else
                    cout<<setw(2)<<". ";
            }
            cout<<endl;
        }
        cout<<"---------------\n";
    }

    bool isSafe(int row, int col){
        //Check the same col
        for(int i=0;i<row;i++)
            if(Board[i][col])
                return false;
        
        //Check upper left diagonal
        for(int i = row - 1, j = col - 1;i >= 0 && j>=0; i--,j--)
            if(Board[i][j])
                return false;
        //Check upper right diagonal
        for(int i = row - 1,j = col + 1; i >= 0 && j < N;i--, j++)
            if(Board[i][j])
                return false;
        return true;
    }

    bool solve(int row){
        if(row == N)
            return true;

        //Try placing a queen in each column of the current row
        for(int col = 0; col < N; col++){
            if(isSafe(row, col)){
                Board[row][col] = 1;

                if(solve(row + 1))
                    return true;
                
                //Backtrack and remove queen
                Board[row][col] = 0;
            }
        }
        return false;
    }
};

int main(){
    int n;
    cout<<"\nEnter the value of N(size of board): ";
    cin>>n;
    NQueen nQueen(n);
    nQueen.solveNQueen();

    return 0;
}