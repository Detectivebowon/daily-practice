#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, n, len, tmp, tmp2;
vector<int> ans, t;
multiset<int> s;
void solve()
{
    ans.clear();
    t.clear();
    while (!s.empty())
    {
        tmp = (*s.begin());
        auto it = s.erase(s.begin());
        ans.push_back(tmp);
        tmp2 = t.size();
        for (int i = 0; i < tmp2; ++i)
        {
            auto it = s.find(tmp + t[i]);
            s.erase(it);
            t.push_back(tmp + t[i]);
        }
        t.push_back(tmp);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string t;
    cin >> q;
    while (q--)
    {
        cin >> n;
        s.clear();
        len = (int)(1 << n);
        for (int i = 0; i < len; ++i)
        {
            cin >> tmp;
            s.insert(tmp);
        }
        auto it = s.find(0);
        s.erase(it);
        solve();
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}