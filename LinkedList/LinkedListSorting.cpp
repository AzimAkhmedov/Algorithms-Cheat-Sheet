//
// Created by Azim on 2023-05-01.
//
#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(int x, Node *next) : value(x), next(next) {}
};

struct a
{
    int i : 1;
};
class List{
private:
    Node *head;

public:
    List() { head = nullptr; }

    Node *insert_front(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *insert_back(int x)
    {
        Node *newNode = new Node(x);
        if (!head)
        {
            head = newNode;
        }
        else
        {

            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return head;
    }

    Node *erase_front()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *erase_back()
    {
        if (!head)
        {
            return nullptr;
        }

        if (!head->next)
        {
            delete head;
            return nullptr;
        }

        Node *prev = nullptr;
        Node *curr = head;

        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;

        return head;
    }

    void displayList()
    {
        if (!head)
            return;
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    };

    int size()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        delete temp;
        return count;
    }

    void bubbleSort()
    {
        Node *ptr = head;
        for (int i = 0; i < size() - 1; i++)
        {
            a flag;
            flag.i = 1;
            ptr = head;
            for (int j = 0; j < size() - i - 1; j++)
            {
                if (ptr->value > ptr->next->value)
                {
                    swap(ptr->value, ptr->next->value);
                    flag.i = 0;
                }
                ptr = ptr->next;
            }
            if (flag.i)
            {
                break;
            }
        }
    }

    void selectionSort()
    {
        Node *curr = head;
        while (curr)
        {
            Node *minNode = curr;
            Node *ptr = curr->next;
            while (ptr != nullptr)
            {
                if (ptr->value < minNode->value)
                {
                    minNode = ptr;
                }
                ptr = ptr->next;
            }
            if (minNode != curr)
            {
                swap(curr->value, minNode->value);
            }
            curr = curr->next;
        }
    }

    //    ADDITIONAL POINTS
    Node *getTail(Node *ptr)
    {
        while (ptr && ptr->next)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
    void insertionSort()
    {
        if (!head || !head->next)
        {
            return;
        }

        Node *sortedList = new Node();
        Node *ptr = head;
        while (ptr)
        {
            Node *nextNode = ptr->next;
            if (!sortedList || ptr->value < sortedList->value)
            {
                ptr->next = sortedList;
                sortedList = ptr;
            }
            else
            {
                Node *temp = sortedList;
                while (!temp->next && ptr->value > temp->next->value)
                {
                    temp = temp->next;
                }
                ptr->next = temp->next;
                temp->next = ptr;
            }
            ptr = nextNode;
        }
        head = sortedList;
    }
};

int main(int argc, const char *argv[])
{
    List l;
    l.insert_back(2);
    l.insert_back(10);
    l.insert_back(1);
    l.insert_back(6);
    l.insert_back(7);
    l.insert_back(3);
    l.displayList();
    l.bubbleSort();
    l.quickSort();
    l.insertionSort();
    l.displayList();

    List l1;
    l1.insert_back(34);
    l1.insert_back(1);
    l1.insert_back(90);
    l1.insert_back(61);
    l1.insert_back(57);
    l1.insert_back(9);
    l1.insert_back(7);
    l1.displayList();
    l1.selectionSort();
    l1.displayList();
    return 0;
}