#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string ham;
    cin >> ham;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll rb;
    cin >> rb;
    int B = 0;
    int S = 0;
    int C = 0;
    for (auto ch : ham)
    {
        if (ch == 'B')
            B++;
        else if (ch == 'C')
            C++;
        else
            S++;
    }
    ll low = 0;
    ll high = 1e13;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll z = 0;
        ll b = max(B * mid - nb, z);
        ll s = max(S * mid - ns, z);
        ll c = max(C * mid - nc, z);
        ll price = pb * b + ps * s + pc * c;
        if (price <= rb)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high;

    return 0;
}