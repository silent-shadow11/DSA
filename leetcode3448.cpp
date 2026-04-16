// circular array concept⭐⭐

class Solution
{
public:
    int binary_search(vector<int> &idx, int target)
    {
        int n = idx.size();
        int i = 0;
        int j = n - 1;
        int lb = n;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (idx[mid] >= target)
            {
                lb = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return lb;
    }
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        int m = queries.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int tgtpos = queries[i];
            int tgtval = nums[tgtpos];
            vector<int> &idx = mp[tgtval];
            int sze = idx.size();
            if (idx.size() == 1)
            {
                ans.push_back(-1);
                continue;
            }
            int d = binary_search(idx, tgtpos);

            int result = INT_MAX;
            int right = idx[(d + 1) % sze];
            int dis1 = abs(right - tgtpos);
            int circulardst1 = n - dis1;
            result = min({result, dis1, circulardst1});

            int left = idx[(d - 1 + sze) % sze];
            int dis2 = abs(left - tgtpos);
            int circulardst2 = n - dis2;
            result = min({result, dis2, circulardst2});

            ans.push_back(result);
        }
        return ans;
    }
};