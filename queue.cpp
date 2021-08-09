#include <bits/stdc++.h>
using namespace std;

const int LEN = 100000;

// プロセスを表す構造体
struct process
{
    string name;
    int time;
};

process q[LEN]; // queue
int head, tail; // queueのポインタ

void enqueue(process p)
{
    q[tail] = p;
    tail = (tail + 1) % LEN;
}
process dequeue()
{
    process p = q[head];
    head = (head + 1) % LEN;
    return p;
}

int main()
{
    head = 1, tail = 1; //ポインタ初期化
    /* 標準入力受け取り */
    int n, quantum;
    string name;
    int time;
    cin >> n >> quantum;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> time;
        process p;
        p.name = name;
        p.time = time;
        enqueue(p);
    }

    int elaps = 0;       //全体の経過時間
    while (head != tail) // headとtailが同じ位置＝キューが空
    {
        process p = dequeue();
        int executionTime = min(quantum, p.time);
        p.time -= executionTime;
        elaps += executionTime;
        if (p.time > 0)
        {
            enqueue(p);
        }
        else
        {
            cout << p.name << " " << elaps << endl;
        }
    }
}
