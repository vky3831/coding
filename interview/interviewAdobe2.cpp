#include<bits/stdc++.h>
using namespace std;

/*
clang++ interviewAdobe2.cpp
./a.out
*/

/*
Find the minimum number of steps required in a 2D array of size (n, m) to reach (n-1, m-1) from (0, 0). 
The array contains only 0(s) and 1(s) where cells with value 1 are not accessible.
up down right left
*/

struct locus{
    int curr_row;
    int curr_col;
    int lvl;
    struct locus* prev;
};

int numberOfSteps(vector<vector<int>> maze){
    if(maze[0][0] == 1) return -1;
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> visited(n, vector<boo>(m, false));
    queue<pair<int, pair<int, int>>> tracker;
    tracker.push(make_pair(0, make_pair(0, 0)));

    while(!tracker.empty()){
        int lvl = tracker.front().first;
        int row = tracker.front().second.first;
        int col = tracker.front().second.second;
        pathlog.push_back(make_pair(row, col));
        tracker.pop();

        if(row == n-1 && col == m-1) return lvl;

        int dir_row[] = {-1, 0, 1, 0};
        int dir_col[] = {0, 1, 0, -1};
        for(int i=0; i<=3; i++){
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && visited[new_row][new_col] == false && maze[new_row][new_col] == 0){
                visited[new_row][new_col] = true;
                tracker.push(make_pair(lvl+1, make_pair(new_row, new_col)));
            }
        }
    }
    return -1;
}

int main(){

    int arr[][] = 


}