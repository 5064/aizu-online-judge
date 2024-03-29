// TLE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
//x:コンテナ
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

//---------------------------------------

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> A(n);
    int h = 0, start = INF + 1, end = -1;
    rep(i, n)
    {
        cin >> h;
        A[i] = h;
        chmin(start, h);
        chmax(end, h);
    }

    if (end == 0) // ugly
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    rep(h, start - 1, end)
    {
        int land = 0;
        bool isNewLand = true;
        rep(i, n)
        {
            if (A[i] > h)
            {
                if (isNewLand)
                {
                    land++;
                    isNewLand = false;
                }
            }
            else
            {
                isNewLand = true;
            }
        }
        chmax(ans, land);
    }
    cout << ans << endl;
}
