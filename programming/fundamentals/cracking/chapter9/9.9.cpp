#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Writen an algorithm to print all ways of arranging eight queens on an 8x8
 * chess board so that none of them share the same row, column or diagonal. In
 * this case, "diagonal" means all diagnoals, not just the two that bisect the
 * board.
 */

#define SIZE 5

bool noOtherQueens(int row, int col, const int board[SIZE][SIZE])
{
  for(int r = 0; r < row; r++)
  {
    if(board[r][col] == 1)
    {
      return false;
    }
  }
  for(int r = row; r < SIZE; r++)
  {
    if(board[r][col] == 1)
    {
      return false;
    }
  }
  for(int c = 0; c < col; c++)
  {
    if(board[row][c] == 1)
    {
      return false;
    }
  }
  for(int c = col; c < SIZE; c++)
  {
    if(board[row][c] == 1)
    {
      return false;
    }
  }

  for(int i = 1; i < 7; i++)
  {
    if((row+i < SIZE && col+i < SIZE) &&
       board[row+i][col+i] == 1)
    {
      return false;
    }
    if((row-i >= 0 && col-i >= 0) &&
       board[row-i][col-i] == 1)
    {
      return false;
    }
    if((row+i < SIZE && col-i >= 0) &&
       board[row+i][col-i] == 1)
    {
      return false;
    }
    if((row-i >= 0 && col+i < SIZE) &&
       board[row-i][col+i] == 1)
    {
      return false;
    }
  }
  return true;
}

void copyBoard(const int source[SIZE][SIZE], int dest[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      dest[i][j] = source[i][j];
    }
  }
}

int eightQueens(int row, int board[SIZE][SIZE])
{
  int r = row;
  int total = 0;
  for(int i = 0; i < SIZE; i++)
  {
    if(r >= SIZE)
    {
      r = 0;
    }

    for(int col = 0; col < SIZE; col++)
    {
      if(noOtherQueens(r, col, board))
      {
        int board2[SIZE][SIZE] = {0};
        copyBoard(board, board2);
        board2[r][col] = 1;
        if(row == SIZE-1)
        {
          return 1;
        }
        else 
        {
          total += eightQueens(r+1, board2);
        }
      }
      else 
      {
        return total;
      }
    }
    r++;
  }
  return total;
}

int main(int argc, const char *argv[])
{
  int board[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      board[i][j] = 0;
    }
  }
  //
  // TODO not right, outputs 46. true answer is 92.
  //
  std::cout << "Total num of ways: " << eightQueens(0, board) << std::endl;
  
  return 0;
}
