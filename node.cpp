#include <iostream>

const int n = 20;

struct node_t
{
    int data;
    node_t* next;
};

void goThrough(node_t* p)
{
    while (true) //(p != nullptr)
    {
        std::cout << p->data << "\n";
        p = p->next;
    }
}

int main()
{
    node_t A[n];

    for (int i = 0; i < n; i++)
    {
        A[i].data = i + 1;
        if (i == n - 1) A[i].next = nullptr;
        else A[i].next = A + i + 1;
    }

    node_t* p_begin = A;
    goThrough(p_begin);


    return 0;
}
