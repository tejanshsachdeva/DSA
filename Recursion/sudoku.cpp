//bit sceptical 

#include <iostream>

#include <vector>

using namespace std;

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)  //check for same element in same row
      return false;

    if (board[row][i] == c)  //check for same element in same col
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)  //check in same box, in single loop from 0-9
      return false;                                                //row/3 gives the box number, i/3 gives the row number in that box
  }
  return true;
}

bool solveSudoku(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {   //if empty elememt is there
        for (char c = '1'; c <= '9'; c++) {  //check for all 1-9
          if (isValid(board, i, j, c)) {   //if valid, then place the element
            board[i][j] = c;  //place the element

            if (solveSudoku(board))  //move to next element, if true, then return true
              return true;
            else
              board[i][j] = '.'; //but if it return false, like not valid, then backtrack and place '.' again
          }
        }

        return false;  //if we cannot place any element, then return false
      }
    }
  }
  return true;
}
int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solveSudoku(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}