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
    LinkedList *operator+(LinkedList b)
    {
        LinkedList *newl = new LinkedList();
        this->curr = this->head;
        b.curr = b.head;
        while (1)
        {
            if (this->curr->next == NULL)
            {
                if (b.curr->next == NULL)
                {
                    break;
                }
                while (b.curr->next != NULL)
                {
                    newl->insert_list(newl->Len, b.curr->next);
                    b.curr = b.curr->next;
                }
                break;
            }
            if (b.curr->next == NULL)
            {
                while (this->curr->next != NULL)
                {
                    newl->insert_list(newl->Len, this->curr->next);
                    this->curr = this->curr->next;
                }
                break;
            }
            if (this->curr->next->expn == b.curr->next->expn)
            {
                if (this->curr->next->coef + b.curr->next->coef != 0)
                {
                    struct LNode tl;
                    tl.c = this->curr->next->coef + b.curr->next->coef;
                    tl.e = this->curr->next->expn;
                    newl->insert_list(newl->Len, tl);
                }
                this->curr = this->curr->next;
                b.curr = b.curr->next;
                continue;
            }
            if (this->curr->next->expn < b.curr->next->expn)
            {
                struct LNode tl;
                tl.c = b.curr->next->coef;
                tl.e = b.curr->next->expn;
                newl->insert_list(newl->Len, tl);
                b.curr = b.curr->next;
                continue;
            }
            if (this->curr->next->expn > b.curr->next->expn)
            {
                struct LNode tl;
                tl.c = this->curr->next->coef;
                tl.e = this->curr->next->expn;
                newl->insert_list(newl->Len, tl);
                this->curr = this->curr->next;
                continue;
            }
        }
        return newl;
    }
    void print()
    {
        curr = head;
        cout << "The List is:" << endl;
        while (curr->next != NULL)
        {
            curr = curr->next;
            cout << curr->coef << "*X^" << curr->expn;
            if (curr->next != NULL)
                cout << " + ";
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
    a2.c = 3;
    a2.e = 10;
    struct LNode a3;
    a3.c = 5;
    a3.e = 8;
    struct LNode a4;
    a4.c = 2;
    a4.e = 0;
    struct LNode *a = new struct LNode[5];
    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    a[3] = a4;
    LinkedList La(a, 4);
    struct LNode b1;
    b1.c = 8;
    b1.e = 14;
    struct LNode b2;
    b2.c = -3;
    b2.e = 10;
    struct LNode b3;
    b3.c = 10;
    b3.e = 6;
    struct LNode *b = new struct LNode[5];
    b[0] = b1;
    b[1] = b2;
    b[2] = b3;
    LinkedList Lb(b, 3);
    (La + Lb)->print(); //重载+运算符来实现两个线性表的相加
}