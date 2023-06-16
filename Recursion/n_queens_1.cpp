#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;  //temp storing row and col
      int dupcol = col;

      while (row >= 0 && col >= 0) {  //checking upward left diagonal
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;  //same left row
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {  //bottom left, row increasing, col decreasing
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {  //we are traversiong the columns, if matched, store ans
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {  //going each row of each column once
        if (isSafe1(row, col, board, n)) {  //checking if safe in left diagonal, right diagonal and row
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);  //if safe, then move to next column
          board[row][col] = '.';  //remmove any changes for backtracking
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);  //string vector n
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;  //storing n size s string in each row
      }
      solve(0, board, ans, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}