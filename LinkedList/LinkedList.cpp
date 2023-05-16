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

    Node *getTail(Node *ptr)
    {
        while (ptr && ptr->next)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
};
 
int main(){
    List l;
    l.insert_back(1);
    l.insert_back(21);
    l.insert_back(12);
    l.insert_back(11);
    l.insert_back(0);
    l.insert_back(9);
    l.displayList();
    
    
   
    
    return 0;
}