#include <bits/stdc++.h>
using namespace std;

// ノードを表す構造体
struct Node
{
    int key;
    Node *prev, *next;
};

// リストの先頭を指す特別なノード（番兵）を設置する
// リストの先頭は番兵のnextに、最後は番兵のprevに指し示される
Node *nullpo = nullptr;
void init()
{
    nullpo = new Node;
    nullpo->next = nullpo;
    nullpo->prev = nullpo;
}

// リストの先頭にキーxを持つ要素を継ぎ足す
void insert(int key)
{
    Node *node;
    node = new Node;
    node->key = key;
    //番兵の直後に追加
    node->next = nullpo->next;
    nullpo->next->prev = node;
    nullpo->next = node;
    node->prev = nullpo;
}
Node *search(int key)
{
    Node *current = nullpo->next;
    while (current != nullpo && current->key != key)
    {
        current = current->next;
    }
    return current;
}
void deleteNode(Node *node)
{
    if (node == nullpo)
        return;
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
}
void deleteFirst()
{
    deleteNode(nullpo->next);
}
void deleteLast()
{
    deleteNode(nullpo->prev);
}
void deleteKey(int key)
{
    deleteNode(search(key));
}

void printList()
{
    Node *current = nullpo->next;
    bool isFirst = true;
    while (1)
    {
        if (current == nullpo)
            break;
        if (!isFirst)
            printf(" ");
        printf("%d", current->key);
        isFirst = false;
        current = current->next;
    }
    printf("\n");
}

int main()
{
    /* 標準入力受け取り */
    int n;
    char command[16];
    int key;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", command, &key);
        if (command[0] == 'i')
        { // insert X
            insert(key);
        }
        else if (command[0] == 'd')
        {
            if (command[6] == 'F')
            { //deleteFirst
                deleteFirst();
            }
            else if (command[6] == 'L')
            { // deleteLast
                deleteLast();
            }
            else // delete X
            {
                deleteKey(key);
            }
        }
    }
    printList();
}
