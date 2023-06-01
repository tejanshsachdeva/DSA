#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
         return 0;

         int m=grid.size();
         int n=grid[0].size();
         int total=0;
         int k=0;
         int count=0;
         int days=0;

         queue<pair<int,int>>rotten;

         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++)
             {
                 if(grid[i][j]==2)
                 rotten.push({i,j});

                 if(grid[i][j]!=0)
                 total++;
             }
         }

        int delRow[4] = {0, 0, 1, -1};
        int delCol[4] = {1, -1, 0, 0};

         while(!rotten.empty()){
             k=rotten.size();
             count=count+k;

             while(k--){
                 int row=rotten.front().first;
                 int col=rotten.front().second;
                 rotten.pop();

                 for(int i=0;i<4;i++){
                     int nRow=row + delRow[i];
                     int nCol=col + delCol[i];

                     if(nRow >=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1){
                         grid[nRow][nCol]=2;
                         rotten.push({nRow,nCol});
                     }

                 }
             }
             if(!rotten.empty())
             days++;
         }

         if(total==count)
         return days;
         else
         return -1;
        
    }
};

int main() {

  vector<vector<int>>grid{{0,1,2},{0,1,2},{2,1,1}};
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";

  return 0;
}