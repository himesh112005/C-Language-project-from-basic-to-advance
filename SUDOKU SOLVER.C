#include <stdio.h>

 
 void input_puzzle(int puzzle[9][9]);
 void print_puzzle(int puzzle[9][9]);
 int valid_move(int puzzle[9][9], int row, int col, int val);
 int solve_puzzle(int puzzle[9][9], int row, int col);


int main() {
   int puzzle[9][9];
   printf("\n\tWelcome to SUDOKU Solver !!!");

  
    printf("\n\nPlease enter your Sudoku puzzle (use 0 for empty cells):\n");
    input_puzzle(puzzle);
    printf("\nOriginal Puzzle:");
    print_puzzle(puzzle);
    if (solve_puzzle(puzzle, 0, 0)) {
printf("\nThe puzzle is solved:");
   print_puzzle(puzzle);
 } else {
        printf("\nThis puzzle is not solvable\n");
 }
    return 0;
}

void input_puzzle(int puzzle[9][9]) {
  for (int i = 0; i < 9; i++) {
  for (int j = 0; j < 9; j++) {
 printf("Enter value for cell (%d, %d): ", i + 1, j + 1);
  scanf("%d", &puzzle[i][j]);
 }
}
}

int solve_puzzle(int puzzle[9][9], int row, int col) {
    if (col == 9) {
  if (row == 8) {
   return 1; // Puzzle solved
}
  row++;
col = 0;
  }


    if (puzzle[row][col] > 0) {
        return solve_puzzle(puzzle, row, col + 1);
    }


    for (int i = 1; i <= 9; i++) {
  if (valid_move(puzzle, row, col, i)) {
       puzzle[row][col] = i;
    if (solve_puzzle(puzzle, row, col + 1)) {
                return 1;
     }
   puzzle[row][col] = 0;
   }
    }
   return 0;
}


int valid_move(int puzzle[9][9], int row, int col, int val) {
  for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == val) {
  return 0;
        }
    }



    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == val) {
      return 0;
        }
    }
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
   if (puzzle[r + i][c + j] == val) {
  return 0;
  }
    }
    }

    return 1;
}

void print_puzzle(int puzzle[9][9]) {
    printf("\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++) {
    if (row % 3 == 0 && row != 0) {
   printf("\n|-------+-------+-------|");
    }
        printf("\n");
     for (int col = 0; col < 9; col++) {
  if (col % 3 == 0) {
   printf("| ");
  }
     if (puzzle[row][col] != 0) {
     printf("%d ", puzzle[row][col]);
   } else {
       printf("  ");
  }
}
 printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}
