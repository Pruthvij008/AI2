#include <iostream>
#include <vector>

using namespace std;

bool is_safe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there's a queen in the same row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false; // If a queen is found in the upper diagonal, it's not safe
        }
        --i;
        --j;
    }

    // Check lower diagonal on left side
    i = row;
    j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) {
            return false; // If a queen is found in the lower diagonal, it's not safe
        }
        ++i;
        --j;
    }

    return true;
}

bool solve_n_queens_util(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        return true;
    }

    for (int i = 0; i < n; ++i) {
        if (is_safe(board, i, col, n)) {
            board[i][col] = 1;
            if (solve_n_queens_util(board, col + 1, n)) {
                return true;
            }
            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool solve_n_queens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solve_n_queens_util(board, 0, n)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution exists. The board configuration is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    int n = 4;
    solve_n_queens(n);
    return 0;
}
