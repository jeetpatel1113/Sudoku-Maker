#include "Sudoku.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    Original_Sudoku_Board B;
    B.print_Original_Sudoku_Board();
    cout << endl;
    B.blind_Sudoku_Board();
    cout << endl;
    B.print_Original_Sudoku_Board();

    cout << endl;
    cout << "Please enter -1 at any point to exit... :)" << endl;
    while (true)
    {
        int i = 0;
        cout << endl;
        cout << "Please enter index i [1 to 9]: ";
        cin >> i;
        int j = 0;
        cout << "Please enter index j [1 to 9]: ";
        cin >> j;
        int answer = 0;
        cout << "Please enter index answer: ";
        cin >> answer;
        cout << endl;

        if (i == -1 || j == -1 || answer == -1)
        {
            break;
        }
        B.enter_sudoku(i - 1, j - 1, answer);
        B.print_Original_Sudoku_Board();
    }
    // Original_Sudoku_Board A;
    // A = copy_Original_Sudoku_Board(B);
    return 0;
}