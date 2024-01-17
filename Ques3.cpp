#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void solve(int row, int col, vector<vector<int>>&maze, int n, vector<vector<int>>visited, string par_res, vector<string>&res){
        if(row==n-1 && col==n-1){
            res.push_back(par_res);
            return;
        }
        int di[]={1, 0, 0, -1};
        int dj[]={0, -1, 1, 0};
        string s="DLRU";
        for(int k=0; k<4; k++){
            int i=row+di[k];
            int j=col+dj[k];
            if(i>=0 && j>=0 && i<n && j<n && maze[i][j]==1 && visited[i][j]!=1){
                visited[row][col]=1;
                solve(i, j, maze, n, visited, par_res+s[k], res);
                visited[row][col]=0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        string par_res="";
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(m[0][0]==1) solve(0, 0, m, n, visited, par_res, res);
        return res;
    }
};