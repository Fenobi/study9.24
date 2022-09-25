#include <stdio.h>
#include <assert.h>

typedef struct Note
{
    int num;
    struct Node* next;
    struct Node* prev;
}Node;

void InitNote(Node* ps)
{
    ps = (Node*)malloc(sizeof(Node));
    ps->num = 1;
    ps->next = ps;
    ps->prev = ps;
}

void PushNode(Node* ps)
{
    assert(ps);
    Node* cur = (Node*)malloc(sizeof(Node));
    cur->next = ps->next;
    cur->prev = ps;
    ps->next = cur;
    cur->num = ps->num + 1;
}
void PopNode(Node* ps)
{
    assert(ps);
    Node* prev = ps->prev;
    Node* next = ps->next;
    prev->next = ps->next;
    next->prev = ps->prev;
}
int num(Node* ps)
{
    if (ps->next == ps)
    {
        return 1;
    }
    return 0;
}
void NodeNext(Node* ps)
{
    ps = ps->next;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Node p;
    InitNote(&p);
    for (int i = 0; i < n; i++)
    {
        PushNode(&p);
    }
    while (!num(&p))
    {
        for (int i = 0; i < m; i++)
        {
            NodeNext(&p);
        }
        PopNode(&p);
    }
    return 0;
}