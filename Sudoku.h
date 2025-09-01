#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int size = 9;

// class Cell
// {
//     private:
//         int number;
//     public:
//         Cell()
//         {
//             cout << "CREATING CELL!!!" << endl;
//             this->number = rand() % (size - 1 + 1) + 1;
//         }
//         ~Cell()
//         {
//             cout << "DESTRUCTING CELL!!!" << endl;
//         }
// };

// typedef int** Board;

class Original_Sudoku_Board
{
private:
    int **board;
    const int size = 9;

public:
    Original_Sudoku_Board()
    {
        board = new int *[size];
        for (int i = 0; i < size; i++)
        {
            board[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                board[i][j] = 0;
            }
        }
        // Create board with 9x9, filled with 0s.

        fill_the_Board(board);

        // It will create all the right numbers.

        return;
    }

    ~Original_Sudoku_Board()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] board[i];
        }
        delete[] board;
    }

    void fill_the_Board(int **board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int cell = rand() % 9 + 1;
                if (check_row_of_board(i, cell, board) == false)
                {
                    erase_row(i, board);
                    i--;
                    break;
                }
                if (check_col_of_board(j, cell, board) == false)
                {
                    erase_row(i, board);
                    i--;
                    break;
                }
                if (check_grid_of_board(i, j, cell, board) == false)
                {
                    erase_row(i, board);
                    i--;
                    break;
                }
                board[i][j] = cell;
            }
        }
    }

    bool check_row_of_board(const int &i, const int &cell, int **board) const
    {
        for (int k = 0; k < size; k++)
        {
            if (board[i][k] == cell)
            {
                return false;
            }
        }
        return true;
    }
    bool check_col_of_board(const int &j, const int &cell, int **board) const
    {
        for (int k = 0; k < size; k++)
        {
            if (board[k][j] == cell)
            {
                return false;
            }
        }
        return true;
    }
    bool check_grid_of_board(const int &i, const int &j, const int &cell, int **board) const
    {
        int grid_i = 3 * (i / 3);
        int grid_j = 3 * (j / 3);
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                if (board[grid_i + k][grid_j + l] == cell)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void erase_row(const int &i, int **board)
    {
        for (int k = 0; k < size; k++)
        {
            board[i][k] = 0;
        }
        return;
    }

    void print_Original_Sudoku_Board()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << (board[i][j] == 0 ? "[ ]" : "[" + to_string(board[i][j]) + "]");
            }
            cout << endl;
        }
        return;
    }

    // void copy_Original_Sudoku_Board(int **temp_board)
    // {
    //     int **temp_board = new int *[size];
    //     for (int i = 0; i < size; i++)
    //     {
    //         temp_board[i] = new int[size];
    //         for (int j = 0; j < size; j++)
    //         {
    //             temp_board[i][j] = board[i][j];
    //         }
    //     }
    //     return temp_board;
    // }

    void blind_Sudoku_Board()
    {
        int count = 0;
        int num_of_blinds = 81 - 34;
        int temp[num_of_blinds][2];

        while (count < num_of_blinds)
        {
            int i = rand() % 9;
            int j = rand() % 9;

            bool exists = false;
            for (int k = 0; k < count; k++)
            {
                if (temp[k][0] == i && temp[k][1] == j)
                {
                    exists = true;
                    break;
                }
            }

            if (exists == false)
            {
                temp[count][0] = i;
                temp[count][1] = j;
                count++;
            }
        }

        // Applying 0s
        for (int k = 0; k < num_of_blinds; k++)
        {
            board[temp[k][0]][temp[k][1]] = 0;
        }
    }

    void enter_sudoku(int i, int j, int answer)
    {
        if (board[i][j] != 0)
        {
            cout << "This Block is off limits..." << endl;
            return;
        }
        board[i][j] = answer;

        return;
    }
};