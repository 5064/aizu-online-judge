#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;
char HT[M][14];

int getChar(char c)
{
    if (c == 'A')
        return 1;
    if (c == 'C')
        return 2;
    if (c == 'G')
        return 3;
    if (c == 'T')
        return 4;
    return 0;
}

int getKey(char key[])
{
    int sum = 0, p = 1;
    for (int i = 0; i < strlen(key); i++)
    {
        sum += p * (getChar(key[i]));
        p *= 3;
    }
    return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

void insert(char str[])
{
    int key, i, h;
    key = getKey(str);
    for (i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(str, HT[h]) == 0)
        {
            return;
        }
        else if (strlen(HT[h]) == 0)
        {
            strcpy(HT[h], str);
            return;
        }
    }
}

bool find(char str[])
{
    int key, i, h;
    key = getKey(str);
    for (i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(str, HT[h]) == 0)
            return true;
        else if (strlen(HT[h]) == 0)
        {
            return false;
        }
    }
    return false;
}

int main()
{
    int n = 0;
    /* 標準入力受け取り */
    scanf("%d", &n);
    char command[16];
    char param[14];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", command, param);
        if (command[0] == 'i')
        {
            insert(param);
        }
        else if (command[0] == 'f')
        {
            if (find(param))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }
}
