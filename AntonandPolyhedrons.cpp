#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    unordered_map<string, int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int ans = 0;
    while (t--)
    {
        string ch;
        cin >> ch;
        ans += mp[ch];
    }
    cout << ans;
    return 0;
}