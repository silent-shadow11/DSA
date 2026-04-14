#include <iostream>
using namespace std;

class Solution
{
public:
    int slove(vector<int> &cpy)
    {
        int n = cpy.size();
        int mst = INT_MIN;
        int lst = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (cpy[i] > 0)
            {
                mst = max(mst, cpy[i]);
                lst = min(lst, cpy[i]);
                found = true;
            }
        }
        if (found)
            return mst - lst;
        else
            return 0;
    }
    int beautySum(string s)
    {
        int n = s.size();
        int i = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> pfx(26, 0);
            for (int j = i; j < n; j++)
            {
                pfx[s[j] - 'a']++;
                ans += slove(pfx);
            }
        }
        return ans;
    }
};