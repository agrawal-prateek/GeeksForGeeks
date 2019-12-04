/*
Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list 
can contain self loop.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains 
length of linked list and next line contains the data of linked list.

Output:
For each testcase, print "True", if linked list contains loop, else print "False".

User Task:
The task is to complete the function detectloop() which contains reference to the head as only 
argument. This function should return 1 if linked list contains loop, else return 0.

Constraints:
1 <= T <= 50
1 <= N <= 300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
True
False

Explaination:
Testcase 1: In above test case N = 3. The linked list with nodes N = 3 is given. Then value of x=2 
is given which means last node is connected with xth node of linked list. Therefore, there exists a 
loop. 

Testcase 2: For N = 4
x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);

int main()
{
    int t, n, c, x, i;
    cin >> t;
    while (t--)
    {

        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++)
        {
            cin >> x;
            push(&head, x);
        }

        cin >> c;
        if (c > 0)
        {
            c = c - 1;
            temp = head;
            while (c--)
                temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True";
        else
            cout << "False";
    }
    return 0;
}

int detectloop(Node *head)
{
    struct Node *slow_pointer = head, *fast_pointer = head;
    while (slow_pointer && fast_pointer && fast_pointer->next)
    {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if (slow_pointer == fast_pointer)
        {
            return 1;
        }
    }
    return 0;
}
