#include <bits/stdc++.h>
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
        vector<int> a(n);
        vector<int> b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && a[j] > b[i])
                j++;
            if (j == n)
            {
                ans = -1;
                break;
            }
            for (int k = j; k > i; k--)
            {
                swap(a[k], a[k - 1]);
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}