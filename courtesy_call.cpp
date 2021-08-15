#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, x = 0, home = 0;
    /* 標準入力受け取り */
    cin >> n;
    cin >> home;
    vector<int> X;
    X.push_back(home);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        X.push_back(x);
    }

    int east = *max_element(X.begin(), X.end());
    int west = *min_element(X.begin(), X.end());
    int ed = east - home;
    int wd = home - west;
    if (ed > wd)
    {
        cout << (2 * wd) + ed << endl;
    }
    else
    {
        cout << (2 * ed) + wd << endl;
    }
}
