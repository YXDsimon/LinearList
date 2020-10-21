#include <iostream>
#include <string>
using namespace std;
struct LNode
{
    float c;
    int e;
};

class LinkNode
{
public:
    float coef;
    int expn;
    LinkNode *next;
    LinkNode() {}
    LinkNode(float c, int e)
    {
        coef = c;
        expn = e;
        next = NULL;
    }
    LinkNode(struct LNode l)
    {
        coef = l.c;
        expn = l.e;
        next = NULL;
    }
    LinkNode(float c, int e, LinkNode *Next)
    {
        coef = c;
        expn = e;
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
    LinkedList(struct LNode *list, int len)
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
    LinkedList()
    {
        LinkNode *HeadNode = new LinkNode();
        head = HeadNode;
        curr = HeadNode;
        tail = HeadNode;
        Len = 0;
    }
    bool insert_list(int index, struct LNode l)
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
        LinkNode *newnode = new LinkNode(l);
        newnode->next = curr->next;
        curr->next = newnode;
        curr = head;
        Len++;
        return 1;
    }
    bool insert_list(int index, LinkNode *n)
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
        n->next = curr->next;
        curr->next = n;
        curr = head;
        Len++;
        return 1;
    }
    LinkedList operator+(LinkedList b)
    {
        LinkedList *newl = new LinkedList();
        struct LNode *p = new struct LNode[5];
        this->curr = this->head;
        b.curr = b.head;
        while (1)
        {
            if (this->curr->next = NULL)
            {
                if (b.curr->next = NULL)
                {
                    break;
                }
                while (b.curr->next != NULL)
                {
                    newl->insert_list(newl->Len, b.curr->next);
                }
            }
            if (b.curr->next = NULL)
            {
                while (this->curr->next != NULL)
                {
                    newl->insert_list(newl->Len, this->curr->next);
                }
            }
            
        }
    }
    void print()
    {
        curr = head;
        cout << "The List is:" << endl;
        while (curr->next != NULL)
        {
            curr = curr->next;
            cout << curr->coef << ' ' << curr->expn;
            cout << ' ';
        }
        cout << endl;
        curr = head;
    }
};
int main()
{
    struct LNode a1;
    a1.c = 3;
    a1.e = 14;
    struct LNode a2;
    a1.c = 3;
    a1.e = 10;
    struct LNode a3;
    a1.c = 5;
    a1.e = 8;
    struct LNode a4;
    a1.c = 0;
    a1.e = 2;
    struct LNode b1;
    a1.c = 8;
    a1.e = 14;
    struct LNode b2;
    a1.c = -3;
    a1.e = 10;
    struct LNode b3;
    a1.c = 10;
    a1.e = 6;
}