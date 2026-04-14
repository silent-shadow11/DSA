#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> mat(r, vector<char>(c, '.'));
    int chg = c - 1;
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
                mat[i][j] = '#';
        }
        else
        {
            mat[i][chg] = '#';
            if (chg == c - 1)
                chg = 0;
            else
                chg = c - 1;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}