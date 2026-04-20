#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        // negetive distance
        priority_queue<tuple<int, int, int, int>> pq; //{dis,color,row,col}
        for (int i = 0; i < sources.size(); i++)
        {
            int row = sources[i][0];
            int col = sources[i][1];
            int color = sources[i][2];
            ans[row][col] = color;
            dis[row][col] = 0;
            pq.push({0, color, row, col});
        }
        while (!pq.empty())
        {
            auto it = pq.top();

            int negd = get<0>(it);
            int color = get<1>(it);
            int row = get<2>(it);
            int col = get<3>(it);
            int d = -negd;
            pq.pop();
            if (d > dis[row][col])
                continue;
            int dr[4] = {0, 1, -1, 0};
            int dc[4] = {1, 0, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int newR = row + dr[k];
                int newC = col + dc[k];
                if (newR < 0 || newC < 0 || newR >= n || newC >= m)
                    continue;
                if (dis[newR][newC] > d + 1)
                {
                    ans[newR][newC] = color;
                    dis[newR][newC] = d + 1;
                    pq.push({-(d + 1), color, newR, newC});
                }
                else if (dis[newR][newC] == d + 1 && ans[newR][newC] < color)
                {
                    ans[newR][newC] = color;
                    pq.push({-(d + 1), color, newR, newC});
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n = 3;
    int m = 3;

    vector<vector<int>> sources = {
        {0, 0, 1},
        {2, 2, 2}};

    Solution obj;
    vector<vector<int>> result = obj.colorGrid(n, m, sources);

    // print result
    for (auto &row : result)
    {
        for (auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}