/*

g++ 11_m_color_graph.cpp
./a.exe

Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(bool graph[][101], int cr, int node, vector<int>& color, int n){
    for(int v=0; v<n; v++){
        if(v != node && graph[node][v] && color[v] == cr) return false;
    }
    return true;
}
    
bool util(int node, bool graph[101][101], int m, int n, vector<int>& color){
    if(node == n){return true;}
    
    for(int cr=1; cr<=m; cr++){
        if(isPossible(graph, cr, node, color, n)){
            color[node] = cr;
            if(util(node+1, graph, m, n, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int node = 0;
    vector<int> color(n, 0);
    return util(node, graph, m, n, color);
}

int main(){
    int n, m, e;
    // n=4; m=3; e=5;// eg1

    n=3; m=2; e=3;// eg2

    bool graph[101][101];
    for(int i=0; i<n; i++){
        memset(graph[i], 0, sizeof(graph[i]));
    }
    // int end1[] = {0,1,2,3,0}; // eg1
    // int end2[] = {1,2,3,0,2}; // eg1

    int end1[] = {0,1,0}; // eg2
    int end2[] = {1,2,2}; // eg2

    for(int i=0; i<e; i++){
        int a, b;
        a = end1[i]; b = end2[i];
        graph[a][b] = graph[b][a] = 1;
    }

    cout<<graphColoring(graph, m, n);
}