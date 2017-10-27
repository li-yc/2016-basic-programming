//
//  main.cpp
//  3
//
//  Created by lyc on 2016/12/20.
//  Copyright © 2016年 lyc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <new>
using namespace std;
typedef int value;
typedef struct node
{
    value val;
    node *next;
};
void insert(node *head, int x, value v);
int search(node *head, value v);
bool is_equal(value a, value b);

int main() {
    node *head = new node;
    head -> next = NULL;
    head -> val = 0;
    insert(head, 1, 1);
    insert(head, 2, 2);
    if (search(head, 0) == 1 &&
        search(head, 1) == 2 &&
        search(head, 2) == 3 &&
        search(head, 3) == -1)
        cout << "Accept\n";
    else
        cout << "Wrong answer\n";
}

void insert(node *head, int x, value v)
{
    int i;
    node *n=head,*n1;  //  n = node
    for (i=1; i<x; i++)
        n = n->next;
    n1 = new node {v, n->next};
    n->next = n1;
}
int search(node *head, value v)
{
    int i=0;
    node *n = head;
    while (n!=NULL)
    {
        i++;
        if (is_equal(n->val, v))
            return i;
        n = n->next;
    }
    return -1;
}
bool is_equal(value a, value b)
{
    return (a==b);
}
