/*

// g++ divideGraphLteKparts.cpp
// ./a.exe

Divide a network of data centers into optimal local regions.

Given a network of g_nodes data centers and g edges bidirectional connections, the i-th connection connects data centers g_from[i] and g_to[i] with a latency of g_weight[i]. The max-latency of a network is the maximum latency of any connection.

Divide this network into k or fewer networks by removing some of the connections such that the maximum latencies of all the regions are minimized. Find the minimum possible value of the maximum max-latency of the networks formed.

Function Description

Complete the function getMinMaxLatency in the editor below.

getMinMaxLatency has the following parameter(s): g_nodes: the number of data centers g fromig edges): one end of the connections gtolg edges): another end of the connections gweightig edges); the latency of the connections k: the maximum number of networks after removing some connections

Returns

long int: the minimum possible value of the max-latency of the networks formed

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int node, int max_latency) {
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        int neighbor_node = neighbor.first;
        int weight = neighbor.second;

        if (!visited[neighbor_node] && weight <= max_latency) {
            dfs(graph, visited, neighbor_node, max_latency);
        }
    }
}

bool canDivideNetwork(vector<vector<pair<int, int>>>& graph, int k, int max_latency) {
    vector<bool> visited(graph.size(), false);
    int count = 0;

    for (int node = 1; node < graph.size(); node++) {
        if (!visited[node]) {
            dfs(graph, visited, node, max_latency);
            count++;

            if (count > k) {
                return false;
            }
        }
    }

    return true;
}

int max_element(vector<int>& vec){

    int mx = 0;
    for(int i=0; i<vec.size(); i++){
        mx = max(mx, vec[i]);
    }
    return mx;
}

int getMinMaxLatency(int g_nodes, vector<int>& g_from, vector<int>& g_to, vector<int>& g_weight, int k) {
    // Build the adjacency list representation of the graph
    vector<vector<pair<int, int>>> graph(g_nodes + 1);

    for (int i = 0; i < g_from.size(); i++) {
        int u = g_from[i];
        int v = g_to[i];
        int weight = g_weight[i];

        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    // Binary search range [low, high] for the possible values of the maximum max-latency
    int low = 0;
    int high = max_element(g_weight);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canDivideNetwork(graph, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int g_nodes = 3;
    vector<int> g_from = {1, 2, 1};
    vector<int> g_to = {2, 3, 3};
    vector<int> g_weight = {4, 5, 3};
    int k = 2;

    int minMaxLatency = getMinMaxLatency(g_nodes, g_from, g_to, g_weight, k);

    cout << "Minimum possible value of the maximum max-latency: " << minMaxLatency << endl;

    return 0;
}

/*
Certainly! Let's go through the code step by step:

1. The code starts by including the necessary headers, which are `<iostream>` for input/output operations and `<vector>` for working with dynamic arrays.

2. The `dfs` function is a depth-first search implementation that explores the connected nodes in the graph. It takes the graph, a vector of visited nodes, the current node, and the maximum latency as input.

   - It marks the current node as visited.
   - For each neighbor of the current node, it checks if the neighbor is not visited and the latency is within the maximum latency.
   - If the conditions are satisfied, it recursively calls the `dfs` function for the neighbor.

3. The `canDivideNetwork` function checks if it is possible to divide the network into k or fewer networks with a given maximum latency. It takes the graph, k, and the maximum latency as input.

   - It initializes a vector of visited nodes with false values.
   - It iterates through all the nodes in the graph.
   - For each unvisited node, it calls the `dfs` function to explore the connected nodes within the maximum latency.
   - It increments the count of visited networks and checks if the count exceeds k. If it does, it returns false, indicating that it is not possible to divide the network into k or fewer networks.
   - If all nodes are visited and the count is less than or equal to k, it returns true, indicating that it is possible to divide the network into k or fewer networks.

4. The `getMinMaxLatency` function calculates the minimum possible value of the maximum max-latency of the networks formed. It takes the number of nodes, the from, to, and weight arrays representing the connections, and the value of k as input.

   - It builds the adjacency list representation of the graph based on the from, to, and weight arrays.
   - It initializes the binary search range [low, high] where low starts at 0 and high starts at the maximum weight among all connections.
   - It performs a binary search to find the minimum possible value of the maximum max-latency.
   - In each iteration, it checks if it is possible to divide the network into k or fewer networks with the current mid value (midway between low and high) using the `canDivideNetwork` function.
   - If it is possible, it updates the high value to mid, narrowing down the search range.
   - If it is not possible, it updates the low value to mid + 1, moving the search range to the upper half.
   - The binary search continues until low is equal to high, which represents the minimum possible value of the maximum max-latency.
   - Finally, it returns the low value as the result.

5. In the `main` function, sample inputs are provided to demonstrate the usage of the `getMinMaxLatency` function.
   - The number of nodes is set to 3.
   - The `g_from`, `g_to`, and `g_weight` arrays represent the connections between nodes, and the `k` value represents the desired number of networks.
   - The `getMinMaxLatency` function is called with these inputs, and the result is stored in the `minMaxLatency` variable.
   - The minimum possible value of the maximum max-latency is printed as output.

That's the explanation of the provided code. It calculates the minimum possible value of the maximum max-latency by dividing the network into k or fewer networks.
*/