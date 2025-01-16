#include <iostream>
using namespace std;

void SudokuBoard(int Sudoku[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << Sudoku[r][c] << " ";
        }
        cout << endl;
    }
}
bool safeSol(int Sudoku[9][9], int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (Sudoku[r][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (Sudoku[i][c] == num) {
            return false;
        }
    }
    int R = r - r % 3;
    int C = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Sudoku[i + R][j + C] == num) {
                return false;
            }
        }
    }

    return true;
}
bool Blank(int Sudoku[9][9], int &r, int &c) {
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++) {
            if (Sudoku[r][c] == 0) {
                return true;
            }
        }
    }
    return false;
}
bool solution(int Sudoku[9][9]) {
    int r, c;
    if (!Blank(Sudoku, r, c)) {
        return true;
    }
    for (int num = 1; num <=9; num++) {
        if (safeSol(Sudoku, r, c, num)) {
            Sudoku[r][c] = num;
            if (solution(Sudoku)) {
                return true;
            }
            Sudoku[r][c] = 0;
        }
    }
    return false;
}
int main() {
    int Sudoku[9][9];
    char yes='y';
    while(yes=='y'||yes=='Y'){
	cout << "\t\tSUDOKU SOLVER\n\nEnter the Sudoku puzzle row wise (use 0 for empty cells):" << endl;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> Sudoku[r][c];
        }
    }
    system("CLS");
    cout<<"Entered Sudoku:"<<endl;
    SudokuBoard(Sudoku);
    if (solution(Sudoku)) {
        cout << "Solved Sudoku puzzle:" << endl;
        SudokuBoard(Sudoku);
    } else {
        cout << "No solution exists!" << endl;
			}
    cout<<"Do you want to solve another Sudoku puzzle ?(y/n)";
    cin>>yes;
    system("CLS");
    }
    return 0;
}
