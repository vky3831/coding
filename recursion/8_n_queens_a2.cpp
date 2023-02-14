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

Approach 2: isSafe Optimized

For Lower Diagonal (towards left) [row + col]
  /
 /
* 
   0  1  2  3
0:[0][1][2][3]
1:[1][2][3][4]
2:[2][3][4][5]
3:[3][4][5][6]

For Upper Diagonal (towards left) [n - 1 + col - row]
*
 \
  \
   0  1  2  3
0:[3][4][5][6]
1:[2][3][4][5]
2:[1][2][3][4]
3:[0][1][2][3]
*/
#include<bits/stdc++.h>
using namespace std;

void util(int col, vector<string>& board, vector<vector<string> >& ans, int n, vector<bool>& leftRow, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(!leftRow[row] && !upperDiagonal[n - 1 + col - row] && !lowerDiagonal[row + col]){
            board[row][col] = 'Q';
            leftRow[row] = !leftRow[row]; 
            upperDiagonal[n - 1 + col - row] = !upperDiagonal[n - 1 + col - row];
            lowerDiagonal[row + col] = !lowerDiagonal[row + col];
            util(col+1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = !leftRow[row]; 
            upperDiagonal[n - 1 + col - row] = !upperDiagonal[n - 1 + col - row];
            lowerDiagonal[row + col] = !lowerDiagonal[row + col];
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
    vector<bool> leftRow(n, false);
    vector<bool> upperDiagonal(2 * n - 1, false);
    vector<bool> lowerDiagonal(2 * n - 1, false);
    util(col, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
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