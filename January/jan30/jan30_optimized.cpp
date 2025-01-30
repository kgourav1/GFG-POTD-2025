//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void fillSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
        vector<int> temp;
        for(int col=0;col<n;col++){
            for(int row=0;row<n;row++){
                if(board[row][col]==1){
                    temp.push_back(row+1);
                    break;
                }
            }
        }
        ans.push_back(temp);
    }
  
    void solve(int col,int n,vector<vector<int>> &board, vector<vector<int>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
        if(col==n){
            fillSolution(ans,board,n);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1-row+col]==0){
                board[row][col] = 1;
                
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1-row+col]=1;
                
                solve(col+1,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col] = 0;
                
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1-row+col]=0;
            }
        }
        
    }
  
  
  
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);
        solve(0,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};
