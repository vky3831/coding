/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Input: board = 
[   ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]]
Visualisation Link: https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
Output: [
    ["5","3","4","6","7","8","9","1","2"],
    ["6","7","2","1","9","5","3","4","8"],
    ["1","9","8","3","4","2","5","6","7"],
    ["8","5","9","7","6","1","4","2","3"],
    ["4","2","6","8","5","3","7","9","1"],
    ["7","1","3","9","2","4","8","5","6"],
    ["9","6","1","5","3","7","2","8","4"],
    ["2","8","7","4","1","9","6","3","5"],
    ["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
Visualisation Link: https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

#include<bits/stdc++.h>
using namespace std;
void print(vector<char>& vect);
void print(vector<vector<char> >& vect);

bool isValid(int row, int col, char c, vector<vector<char> >& board){
    for(int i=0; i<9; i++){
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c) return false;
    }
    return true;
}

bool util(vector<vector<char> >& board){
    int n = 9;
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(board[row][col] == '.'){
                for(char c='1'; c<='9'; c++){
                    if(isValid(row, col, c, board)){
                        board[row][col] = c;
                        if(util(board) == true) return true;
                        else board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void sudoku(vector<vector<char> >& board){
   util(board);
}

int main() {
    int n=9;
	int a[][9] = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    
	vector<vector<char> > arr(n);
    for(int i=0; i<9; i++){
        vector<char> v(a[i], a[i]+n);
        arr[i] = v;
    }
    print(arr);
    cout<<"-------------------"<<endl;
    sudoku(arr);
    print(arr);
	
}

void print(vector<char>& vect){
	cout<<"[";
	int n = vect.size();
	for(int i=0; i < n; i++){
		
		cout<<vect[i];
		if(i < n-1)
		cout<<" ";
	}
	cout<<"]"<<endl;
}

void print(vector<vector<char> >& vect){
	int n = vect.size();
    for(int i=0; i<n; i++){
        print(vect[i]);
    }
}

