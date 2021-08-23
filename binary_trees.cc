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
vector<int> H(MAX); // All nodes height
const int NIL = -1;

void setDepth(int u, int d)
{
    if (u == NIL)
        return;
    D[u] = d;
    setDepth(T[u].right, d + 1);
    setDepth(T[u].left, d + 1);
}

int setHeight(int u)
{
    int h1 = 0, h2 = 0;
    if (T[u].right != NIL)
    {
        h1 = setHeight(T[u].right) + 1;
    }
    if (T[u].left != NIL)
    {
        h2 = setHeight(T[u].left) + 1;
    }
    return H[u] = max(h1, h2);
}

int getSibling(int u) // 兄弟のID
{
    int sibling = -1;
    int p = T[u].parent;
    if (p != NIL)
    {
        if (u == T[p].left)
        {
            sibling = T[p].right;
        }
        else
        {
            sibling = T[p].left;
        }
    }
    return sibling;
}
int getDegree(int u) // 子の数
{
    int d = 0;
    if (T[u].right != NIL)
    {
        d++;
    }
    if (T[u].left != NIL)
    {
        d++;
    }
    return d;
}
string printNodeType(int u)
{
    if (T[u].parent == NIL)
    {
        return "root";
    }
    if (T[u].left == NIL && T[u].right == NIL)
    {
        return "leaf";
    }
    return "internal node";
}
void print(int i)
{
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "sibling = " << getSibling(i) << ", ";
    cout << "degree = " << getDegree(i) << ", ";
    cout << "depth = " << D[i] << ", ";
    cout << "height = " << H[i] << ", ";
    cout << printNodeType(i);

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

    int id, l, r;
    rep(i, n)
    {
        cin >> id >> l >> r;
        T[id].left = l;
        T[id].right = r;
        if (l != NIL)
        {
            T[l].parent = id;
        }
        if (r != NIL)
        {
            T[r].parent = id;
        }
    }

    int root;
    rep(i, n) if (T[i].parent == NIL) root = i;
    setDepth(root, 0);
    setHeight(root);

    rep(i, n)
    {
        print(i);
    }
}
