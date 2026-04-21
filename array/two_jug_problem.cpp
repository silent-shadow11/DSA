#include <iostream>

#include <algorithm>
using namespace std;

class Solution
{
public:
    int gcd(int m, int n)
    {
        if (n == 0)
            return m;
        return gcd(n, m % n); // fixed
    }

    int pour(int fromcap, int tocap, int d)
    {
        int from = fromcap;
        int to = 0;
        int step = 1;

        while (from != d && to != d)
        {
            int temp = min(from, tocap - to);
            to += temp;
            from -= temp;
            step++;

            if (from == d || to == d)
                break;

            if (from == 0)
            {
                from = fromcap;
                step++;
            }

            if (to == tocap)
            {
                to = 0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d)
    {

        // edge cases
        if (m == 0)
            return (d == n ? 1 : -1);
        if (n == 0)
            return (d == m ? 1 : -1);

        if (d > max(m, n))
            return -1;
        if (d % gcd(m, n) != 0)
            return -1;

        return min(pour(m, n, d), pour(n, m, d));
    }
};

int main()
{
    Solution obj;

    int m = 3, n = 5, d = 4;
    cout << obj.minSteps(m, n, d) << endl;

    return 0;
}