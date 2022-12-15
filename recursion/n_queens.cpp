/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]
 
Constraints:

1 <= n <= 9
*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int col, int row, vector<string>& board, int n){
   int tempCol = col; int tempRow = row;
   while(tempCol >= 0){
    if(board[tempRow][tempCol] == 'Q') return false;
    tempCol--;
   }
   tempCol = col; tempRow = row;
   while(tempCol >= 0 && tempRow >= 0){
    if(board[tempRow][tempCol] == 'Q') return false;
    tempCol--; tempRow--;
   }
   tempCol = col; tempRow = row;
   while(tempCol >= 0 && tempRow < n){
    if(board[tempRow][tempCol] == 'Q') return false;
    tempCol--; tempRow++;
   }
   return true;
}

void util(int col, vector<string>& board, vector<vector<string> >& ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(isSafe(col, row, board, n)){
            board[row][col] = 'Q';
            util(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}



vector<vector<string> > nqueens(int n){
    vector<vector<string> > ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    int col=0;
    util(col, board, ans, n);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<string> > ans = nqueens(4);
    cout<<"[";
    for(int i=0; i< ans.size(); i++){
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
            if(j < ans[i].size() - 1)
		        cout<<", ";
        }
        cout<<"]"<<endl;
        if(i < ans.size() - 1)
		cout<<", ";
    }
    cout<<"]"<<endl;
}