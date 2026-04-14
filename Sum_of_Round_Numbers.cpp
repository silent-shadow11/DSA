#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        int size = 1;
        vector<int> ans;
        while (n != 0)
        {
            int rem = n % 10;
            n = n / 10;
            if (rem != 0)
            {
                ans.push_back(rem * size);
                cnt++;
            }
            size *= 10;
        }
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }

    return 0;
}