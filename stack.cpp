#include <iostream>
#include <string>
#include <algorithm>
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
    string str;
    getline(cin, str);
    // str.erase(remove(str.begin(), str.end(), ' '), str.end());

    const char *s = str.c_str();
    for (auto i = s; *i != '\0'; i++)
    {
        if (i[0] == '+')
        {
            int a = pop();
            int b = pop();
            push(a + b);
        }
        else if (i[0] == '-')
        {
            int a = pop();
            int b = pop();
            push(a - b);
        }
        else if (i[0] == '*')
        {
            int a = pop();
            int b = pop();
            push(a * b);
        }
        else
        {
            push(int(i[0] - '0')); // convert char to int
        }
    }
    cout << pop() << endl;
}
