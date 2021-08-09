#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int stack[255];
int top; // スタックの頂点

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    top--;
    return stack[top + 1]; // topが指していた要素を返す
}
int main(int argc, char const *argv[])
{
    string str, s;
    vector<string> v;

    // 標準入力から受け取る
    getline(cin, str);
    stringstream ss{str};
    while (getline(ss, s, ' '))
    {
        v.push_back(s);
    }

    for (string token : v)
    {
        if (token == "+")
        {
            int a = pop();
            int b = pop();
            push(a + b);
        }
        else if (token == "-")
        {
            int a = pop();
            int b = pop();
            push(b - a);
        }
        else if (token == "*")
        {
            int a = pop();
            int b = pop();
            push(a * b);
        }
        else
        {
            push(stoi(token)); // convert str to int
        }
    }
    cout << pop() << endl;
}
