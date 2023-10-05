#include <iostream>
#include <string>


using namespace std;
struct Node
{
    int num;
    Node * p_node;
};

Node * head;

void add_node(int n);
void printList();
void delete_end();
void delete_nd(int n);

int main()
{
    add_node(1);
    add_node(6);
    add_node(8);
    add_node(3);
    add_node(5);
    printList();
   delete_nd(8);
   printList();
   

    return 0;
}

void add_node(int n)
{
    Node * nd = new Node;
    nd->num = n;
    nd->p_node = nullptr;
    if(head == nullptr)
    {
        head = nd;
    }
    else
    {
        Node * current = head;
        while(current->p_node != nullptr)
        {
            current = current->p_node;
        }
        current->p_node = nd;
    }
}

void printList()
{
    Node * current = head;
    while(current != nullptr)
    {   
        cout << current->num << "  ";
        current = current->p_node;
    }
    cout << endl;
}

void delete_end()
{
    Node * current = head;
    while(current->p_node->p_node != nullptr)
    {
        current = current->p_node;
    }
    delete current->p_node;
    current->p_node = nullptr;
}

void delete_nd(int n)
{
    Node * current = head;
    while(current->p_node->num != n)
    {
        current = current->p_node;
    }
    Node * nd = current->p_node;
    current->p_node = nd->p_node;
    delete nd;
    
}