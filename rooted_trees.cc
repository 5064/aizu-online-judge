#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = (n); i--;)
#define rrep2(i, n) for (ll i = (n); i--;)
#define rrep3(i, a, b) for (ll i = (b); i-- > (a);)
#define rrep4(i, a, b, c) for (ll i = (a) + ((b) - (a)-1) / (c) * (c); i >= (a); i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
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

const int MAX = 100000;

struct Node
{
    int parent, left, right;
};
struct Node T[MAX]; //tree
vector<int> D(MAX); // All nodes depth
const int NIL = -1;

void setDepth(int u, int p)
{
    D[u] = p;
    if (T[u].right != NIL)
    {
        setDepth(T[u].right, p);
    }
    if (T[u].left != NIL)
    {
        setDepth(T[u].left, p + 1);
    }
}

string printNodeType(int u)
{
    if (T[u].parent == NIL)
    {
        return "root";
    }
    if (T[u].left == NIL)
    {
        return "leaf";
    }
    return "internal node";
}
void printChildren(int u)
{
    int c = T[u].left;
    cout << '[';
    while (c != NIL)
    {
        cout << c;
        c = T[c].right;
        if (c != NIL)
            cout << ", ";
    }
    cout << ']';
}
void print(int i)
{
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << D[i] << ", ";
    cout << printNodeType(i) << ", ";
    printChildren(i);
    cout << endl;
}

int main()
{

    int n;
    cin >> n;
    rep(i, n)
    {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    int c, l;
    int id, childrenU;
    rep(i, n)
    {
        cin >> id >> childrenU;
        rep(j, childrenU)
        {
            cin >> c;
            if (j == 0)
            {
                T[id].left = c;
            }
            else
            {
                T[l].right = c;
            }
            l = c;
            T[c].parent = id;
        }
    }

    int root;
    rep(i, n) if (T[i].parent == NIL) root = i;
    setDepth(root, 0);

    rep(i, n)
    {
        print(i);
    }
}
