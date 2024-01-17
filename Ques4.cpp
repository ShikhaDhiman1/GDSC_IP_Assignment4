#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], vector<int> colorMap, int v, int m, int n){
        for(int i=0; i<n; i++){
            if(graph[v][i] && colorMap[i] == m) return false;
        }
        return true;
    }
    
    bool solve(bool graph[101][101], vector<int> colorMap, int m, int n, int v){
        if(v==n) return true;
        for(int i = 1; i<=m; i++) {
            if(isSafe(graph, colorMap, v, i, n)){
                colorMap[v] = i;
                if(solve(graph, colorMap, m, n, v+1))
                    return true;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colorMap(n);
        return solve(graph, colorMap, m, n, 0);
    }
};