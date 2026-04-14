#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> sl(t);
    int mini = 0;
    int maxi = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> sl[i];
    }
    for (int i = 0; i < t; i++)
    {
        if (sl[mini] >= sl[i])
        {
            mini = i;
        }
        if (sl[maxi] <= sl[i])
        {
            maxi = i;
        }
    }
    int ans = maxi + abs(t - mini);
    if (mini < maxi)
        cout << ans - 1;
    else
    {
        cout << ans;
    }

    return 0;
}