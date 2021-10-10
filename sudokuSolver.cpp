#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool solver(vector<vector<char> > &sudoku, map<pair<int, int>, map<int, int> > &box, map<int, map<int, int> > &row, map<int, map<int, int> > &col, int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return solver(sudoku, box, row, col, i + 1, 0);
    }
    if (sudoku[i][j] != '.')
    {
        return solver(sudoku, box, row, col, i, j + 1);
    }
    for (int k = 1; k <= 9; k++)
    {
        if ((box[make_pair(i / 3, j / 3)][k] == 0) && (row[i][k] == 0) && (col[j][k] == 0))
        {
            box[make_pair(i / 3, j / 3)][k] = 1;
            row[i][k] = 1;
            col[j][k] = 1;
            if (solver(sudoku, box, row, col, i, j + 1))
            {
                sudoku[i][j] = ('0' + k);
                return true;
            }
            box[make_pair(i / 3, j / 3)][k] = 0;
            row[i][k] = 0;
            col[j][k] = 0;
        }
    }
    return false;
}
int main()
{
    vector<vector<char> > sudoku(9, vector<char>(9));
    map<pair<int, int>, map<int, int> > box;
    map<int, map<int, int> > row;
    map<int, map<int, int> > col;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != '.')
            {
                box[make_pair(i / 3, j / 3)][sudoku[i][j] - '0'] = 1;
                row[i][sudoku[i][j] - '0'] = 1;
                col[j][sudoku[i][j] - '0'] = 1;
            }
        }
    }
    solver(sudoku, box, row, col, 0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
