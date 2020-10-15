#include <iostream>
#include <string>
using namespace std;

class LinkNode
{
public:
    int value;
    LinkNode *next;
    LinkNode() {}
    LinkNode(int val)
    {
        value = val;
        next = NULL;
    }
    LinkNode(int val, LinkNode *Next)
    {
        value = val;
        next = Next;
    }
};

class LinkedList
{
private:
    LinkNode *head;
    LinkNode *curr;
    LinkNode *tail;
    int Len;

public:
    LinkedList(int *list, int len)
    {
        LinkNode *HeadNode = new LinkNode();
        head = HeadNode;
        curr = HeadNode;
        tail = HeadNode;
        for (int i = 0; i < len; i++)
        {
            LinkNode *newnode = new LinkNode(list[i]);
            tail->next = newnode;
            tail = newnode;
        }
        Len = len;
    }
    bool insert_list(int index, int val)
    {
        curr = head;
        if (index < 0 || index > Len)
        {
            cout << "illegal index!" << endl;
            return 0;
        }
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        LinkNode *newnode = new LinkNode(val);
        newnode->next = curr->next;
        curr->next = newnode;
        curr = head;
        Len++;
        return 1;
    }
    int delete_list(int index)
    {
        curr = head;
        if (index < 0 || index > Len)
        {
            cout << "illegal index!" << endl;
            return 0;
        }
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        if (index == Len - 1)
        {
            int deleted = curr->next->value;
            curr->next = NULL;
            Len--;
            return deleted;
        }
        LinkNode *Temp = curr->next->next;
        curr->next = Temp;
        return Temp->value;
    }
    void print()
    {
        curr = head;
        cout << "The List is:" << endl;
        while (curr->next != NULL)
        {
            curr = curr->next;
            cout << curr->value;
            cout << ' ';
        }
        cout << endl;
        curr = head;
    }
};
int main()
{
    
}