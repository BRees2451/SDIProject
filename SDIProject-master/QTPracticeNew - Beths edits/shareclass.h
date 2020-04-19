#ifndef SHARECLASS_H
#define SHARECLASS_H
#include <QtCore>
#include <iostream>
using namespace std;

class shareClass
{
public:
    shareClass();

    struct fileData{
        QString name;
        QDateTime dateModified;
    };
};


struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }

    static void concatenate(node* a, node* b)
    {
        if (a != NULL && b != NULL)
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next, b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }


    /**
     * @brief search
     * @param head
     * @param data
     * @return
     * https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
     */
    bool search(node* head, int data)
    {
        node* current = head;
        while (current != NULL)
        {
            if(current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};
#endif // SHARECLASS_H
