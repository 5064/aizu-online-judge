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
#define MAX 200002
#define VMAX 10000

vector<int> A(MAX);
vector<int> B(MAX);
vector<int> C(VMAX + 1);

int main()
{
    int n = 0, a = 0;
    /* 標準入力受け取り */
    cin >> n;

    rep(i, n)
    {
        cin >> a;
        A[i] = a;
        C[a] += 1;
    }
    rep(i, 1, VMAX)
    {
        C[i] = C[i] + C[i - 1];
    }
    rep(i, 0, n)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] -= 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << B[i];
    }
    cout << endl;
}
