#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> tower(n);
        for (int i = 0; i < n; i++)
        {
            cin >> tower[i];
        }
        int sum = tower[0];
        int lastheight = tower[0];
        for (int i = 1; i < n; i++)
        {
            if (lastheight < tower[i])
                sum += lastheight;
            else
            {
                sum += tower[i];
                lastheight = tower[i];
            }
        }
        cout << sum << endl;
    }

    return 0;
}