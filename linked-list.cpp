#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
    Node *last;

public:
    LinkedList()
    {
        first = last = nullptr;
    }

    LinkedList(int *arr, int n);             // done
    ~LinkedList();                           // done
    int Length();                            // done
    void InsertAtBegin(int x);               // done
    void InsertAtPos(int x, int pos);        // done
    void InsertAtEnd(int x);                 // done
    int DeleteFromBegin();                   // done
    int DeleteFromEnd();                     // done
    int DeleteVal(int x);                    // done
    int FindPosOfVal(int x);                 // done
    void DisplayList();                      // done
    void ReverseList();                      // done
    bool isSorted();                         // done
    void RemoveDuplicates();                 // done
    Node *Merge(Node *first1, Node *first2); // done
};

LinkedList::LinkedList(int *arr, int n)
{
    first = new Node[sizeof(Node)];
    first->val = arr[0];
    first->next = nullptr;
    Node *temp;
    Node *last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node[sizeof(Node)];
        temp->val = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList()
{
    Node *temp = first;
    while (!temp)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

int LinkedList::Length()
{
    int cnt = 0;
    Node *temp = first;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void LinkedList::InsertAtBegin(int x)
{
    Node *temp = nullptr;
    temp = new Node[(sizeof(Node))];
    if (!temp)
    {
        cout << "Memory full\n";
        return;
    }

    if (!first)
    {
        first = new Node[sizeof(Node)];
        first->val = x;
        first->next = nullptr;
    }
    else
    {
        temp->val = x;
        temp->next = first;
        first = temp;
    }
}

void LinkedList::InsertAtPos(int x, int pos)
{
    // indexed 1
    if (pos < 0 || pos > Length())
    {
        cout << "Improper position\n";
        return;
    }

    if (pos == 0)
    {
        InsertAtBegin(x);
        return;
    }

    pos--;
    Node *justBefore = first;
    for (int i = 0; i < pos; i++)
    {
        justBefore = justBefore->next;
    }

    Node *temp = nullptr;
    temp = new Node[sizeof(Node)];
    if (!temp)
    {
        cout << "Full memory\n";
        return;
    }

    temp->val = x;
    temp->next = justBefore->next;
    justBefore->next = temp;
}

void LinkedList::InsertAtEnd(int x)
{
    // cout << first->val << endl;
    Node *temp = first;
    Node *trail = nullptr;
    if (!temp)
    {
        InsertAtBegin(x);
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *t;
    t = new Node[sizeof(Node)];
    t->val = x;
    t->next = nullptr;
    temp->next = t;
}

int LinkedList::DeleteFromBegin()
{
    if (!first)
    {
        return -1;
    }

    int deletedval = first->val;
    Node *t = first;
    first = first->next;
    delete t;
    return deletedval;
}

int LinkedList::DeleteFromEnd()
{
    Node *temp = first;
    if (!temp)
    {
        return -1;
    }

    Node *trail = nullptr;

    while (temp->next != nullptr)
    {
        trail = temp;
        temp = temp->next;
    }

    trail->next = nullptr;
    int deletedVal = temp->val;
    delete temp;
    return deletedVal;
}

int LinkedList::DeleteVal(int x)
{
    Node *temp = first;
    Node *trail = nullptr;
    if (!temp)
    {
        return -1;
    }

    while (temp && temp->val != x)
    {
        trail = temp;
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Not found \n";
        return -1;
    }
    trail->next = temp->next;
    int deletedVal = temp->val;
    delete temp;
    return deletedVal;
}

int LinkedList::FindPosOfVal(int x)
{
    Node *temp = first;
    if (!temp)
    {
        return -1;
    }
    int ans = 1;

    while (temp && temp->val != x)
    {
        ans++;
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Not found\n";
        return -1;
    }

    return ans;
}

void LinkedList::ReverseList()
{
    if (first == nullptr || first->next == nullptr)
    {
        return;
    }

    Node *p = first->next;
    Node *q = first;
    Node *r = nullptr;
    while (p != nullptr)
    {
        q->next = r;
        r = q;
        q = p;
        p = p->next;
    }
    q->next = r;
    first = q;
}

bool LinkedList::isSorted()
{
    Node *temp = first;
    if (first == nullptr || first->next == nullptr)
    {
        return true;
    }

    while (temp->next != nullptr)
    {
        if (temp->val > temp->next->val)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void LinkedList::RemoveDuplicates()
{
    map<int, int> mp;
    Node *temp = first;
    Node *trail = nullptr;
    int flag = 0;
    Node *t;
    while (temp != nullptr)
    {
        if (mp[temp->val] == 1)
        {
            trail->next = temp->next;
            t = temp;
            flag = 1;
        }
        else
        {
            mp[temp->val] = 1;
        }
        trail = temp;
        temp = temp->next;
        if (flag == 1)
        {
            delete t;
            flag = 0;
        }
    }
}

Node *LinkedList::Merge(Node *first1, Node *first2)
{
    Node *t1 = first1;
    Node *t2 = first2;
    Node *t3 = nullptr;
    Node *t;
    if (t1 == nullptr || t2 == nullptr)
    {
        if (t1)
        {
            return t1;
        }
        if (t2)
        {
            return t2;
        }
        return t3;
    }

    t = new Node[sizeof(Node)];
    if (t1->val < t2->val)
    {
        t->val = t1->val;
        t1 = t1->next;
    }
    else
    {
        t->val = t2->val;
        t2 = t2->next;
    }
    t->next = nullptr;

    t3 = t;
    Node *p = t3;

    while (t1 != nullptr && t2 != nullptr)
    {
        t = new Node[sizeof(Node)];
        if (t1->val < t2->val)
        {
            t->val = t1->val;
            t1 = t1->next;
        }
        else
        {
            t->val = t2->val;
            t2 = t2->next;
        }
        t->next = nullptr;
        p->next = t;
        p = t;
    }
    while (t1 != nullptr)
    {
        t = new Node[sizeof(Node)];
        t->val = t1->val;
        t->next = nullptr;
        p->next = t;
        p = t;
        t1 = t1->next;
    }
    while (t2 != nullptr)
    {
        t = new Node[sizeof(Node)];
        t->val = t2->val;
        t->next = nullptr;
        p->next = t;
        p = t;
        t2 = t2->next;
    }
    return t3;
}

void LinkedList::DisplayList()
{
    Node *temp = first;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    LinkedList list;
    int flag = 0;
    while (1)
    {
        int choice;
        cin >> choice;
        int x, pos;
        switch (choice)
        {
        case 1:
            cin >> x;
            list.InsertAtBegin(x);
            break;
        case 2:
            cin >> x;
            cin >> pos;
            list.InsertAtPos(x, pos);
            break;
        case 3:
            cout << list.Length();
            break;
        case 4:
            list.DisplayList();
            break;
        case 5:
            cin >> x;
            list.InsertAtEnd(x);
            break;
        case 6:
            cout << list.DeleteFromBegin() << "\n";
            break;
        case 7:
            cout << list.DeleteFromEnd() << "\n";
            break;
        case 8:
            cin >> x;
            cout << list.DeleteVal(x) << "\n";
            break;
        case 9:
            cin >> x;
            cout << list.FindPosOfVal(x) << "\n";
            break;
        case 10:
            list.ReverseList();
            break;
        case 11:
            cout << list.isSorted() << "\n";
            break;
        case 12:
            list.RemoveDuplicates();
            break;
        default:
            flag = 1;
        }
        if (flag == 1)
        {
            break;
        }
    }
    return 0;
}