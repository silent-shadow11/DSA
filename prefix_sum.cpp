#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // max index
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[maxi])
            maxi = i;
    }

    // swap
    int temp = nums[0];
    nums[0] = nums[maxi];
    nums[maxi] = temp;

    // find prefix sum
    int ans = 0;
    int currentmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentmax = max(nums[i], currentmax);
        ans += currentmax;
    }
    cout << ans << endl;
    return 0;
}