#include<bits/stdc++.h>
using namespace std;
/*
g++ interview.cpp
a.exe

clang++ interview.cpp
./a.out
*/

/*
A B C D E F
0 1 2 3 4 5
A -> D
F -> B
B -> D
F -> A
D -> C
E 

F-> A, B
F E A B D C

A -> D
B -> D
C ->
D -> C
E ->
F -> B, A

VISITED: A D C B E
STK: C D A B E F

dfs(A)
- dfs(D)
- - dfs(C)
dfs(B)
dfs(E)

TIME: O(V+E)
SPACE: O(V) + O(V*V)
*/

vector<int> topologicalSort(vector<vector<int>>& edges, int n){
    vector<int> graph[n];
    int en = edges.size();
    for(int i=0; i<en; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
    }

    vector<bool> visited(n, false);
    stack<int> stk; 
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            dfs(i, visited , graph, stk)
        } 
    }

    vector<int> ans;
    for(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

void dfs(int v, vector<bool>& visited , vector<int> graph[], stack<int>& stk){
    visited[v] = true;
    for(int i=0; i < graph[v].size(); i++){
        if(visited[graph[v][i]] == false){
            // visited[graph[v][i]] = true;
            dfs(graph[v][i], visited, graph, stk);
        }  
    }
    stk.push(v);
}


int main(){
    
}