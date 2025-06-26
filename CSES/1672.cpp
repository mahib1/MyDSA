#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void Floyd_Warshall(vector<vector<ll>> &ms, int &countNode)
{
    for (int k = 0; k < countNode; ++k)
        for (int i = 0; i < countNode; ++i)
            for (int j = 0; j < countNode; ++j)
                if (ms[i][k] < LLONG_MAX && ms[k][j] < LLONG_MAX)
                    ms[i][j] = min(ms[i][j], ms[i][k] + ms[k][j]);
}
 
void solve()
{
    // cout.setf(std::ios::fixed);
    // cout.precision(2);
 
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> ms(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ms[i].push_back(LLONG_MAX);
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        if (c < ms[a][b])
            ms[a][b] = c, ms[b][a] = c;
    }
 
    Floyd_Warshall(ms, n);
 
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == b)
            cout << 0 << endl;
        else
            cout << (ms[a][b] == LLONG_MAX ? -1 : ms[a][b]) << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
 
    solve();
    //int t; cin >> t; while(t--) solve();
 
    return 0;
}
