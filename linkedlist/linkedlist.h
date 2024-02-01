#include <iostream>
class linkedlist
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *head, *tail;

public:
    int length()
    {
        int len = 0;
        node *tmp = head;
        while (tmp != NULL)
        {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void add_node(int n)
    {
        node *tmp = new node;
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
    void delete_node(int pos)
    {
        node *tmp = head;
        if (pos == 0)
        {
            head = tmp->next;
            delete tmp;
            return;
        }
        for (int i = 0; tmp != NULL && i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        if (tmp == NULL || tmp->next == NULL)
            return;
        node *next = tmp->next->next;
        delete tmp->next;
        tmp->next = next;
    }
    void insert_node(int n, int pos)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if (pos == 0)
        {
            tmp->next = head;
            head = tmp;
        }
        else
        {
            node *prev = head;
            for (int i = 0; i < pos - 1; i++)
            {
                prev = prev->next;
            }
            tmp->next = prev->next;
            prev->next = tmp;
        }
    }
    int operator[](int pos)
    {
        node *tmp = head;
        for (int i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
};