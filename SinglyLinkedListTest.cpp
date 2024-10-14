#include <iostream>
using namespace std;
template<typename T>
struct Node
{
    Node<T>* next;
    T data;
    Node(T value);
};
template<typename T>
class SingleLinearLinkedList
{
    Node<T>* head;
public:
    SingleLinearLinkedList();
    ~SingleLinearLinkedList();
    void addAtHead(T value);
    void addAtTail(T value);
    void addBefore(T targetValue, T newValue);
    void addAfter(T targetValue, T newValue);
    T deleteAtHead();
    T deleteAtTail();
    void deleteBefore(T targetValue);
    void remove(T targetValue);
    void deleteAfter(T targetValue);
    int getSize(); 
    void reverse();
    void sortedInsert(Node<T>& a);
    void display();
    Node<T>* search(T key);
    Node<T>* getMiddle()
}; 
template<typename T>
Node<T>::Node(T value):data(value), next(nullptr)
{
}
template<typename T>
SingleLinearLinkedList<T>::SingleLinearLinkedList()
{
    head = nullptr;
}
template<typename T>
SingleLinearLinkedList<T>::~SingleLinearLinkedList()
{
    while (head)
    {
        deleteAtHead();
    }
}
template<typename T>
void SingleLinearLinkedList<T>::addAtHead(T value)
{
    if (!head)
    {
        head = new Node<T>(value);
    }
    else
    {
        Node<T>* temp = new Node<T>(value);
        temp->next = head;
        head = temp;
    }
}
template<typename T>
void SingleLinearLinkedList<T>::addAtTail(T value)
{
    if (!head)
    {
        head = new Node<T>(value);
    }
    else
    {
        Node<T>* itr = head;
        while (itr->next != nullptr)
            itr = itr->next;
        itr->next = new Node<T>(value);
    }
}
template<typename T>
void SingleLinearLinkedList<T>::addBefore(T key, T val)
{
    if (!head)
        return;
    if (head->data == key)
    {
        Node<T>* p = new Node<T>(val);
        p->next = head;
        head = p;
        return;
    }
    Node<T>* prev = head;
    Node<T>* p = head->next;
    while (p != nullptr && p->data != key)
    {
        prev = p;
        p = p->next;
    }
    if (p)
    {
        Node<T>* x = new Node<T>(val);
        x->next = p;
        prev->next = x;
    }
    return;
}
template<typename T>
void SingleLinearLinkedList<T>::addAfter(T key, T val)
{
    if (!head)
        return;
    if (head->data == key&&head->next==nullptr)
    {
        Node<T>* p = new Node<T>(val);
        p->next = nullptr;
        return;
    }
    if (head->next != nullptr && head->data == key)
    {
        Node<T>* p = head->next;
        Node<T>* q = head->next = new Node<T>(val);
        q->next = p;
        return;
    }
    Node<T>* prev = head;
    Node<T>* p = head->next;
    while (p != nullptr && p->data != key)
    {
        prev = p;
        p = p->next;
    }
    if (p)
    {
        Node<T>* x = new Node<T>(val);
        x->next = p->next;
        prev->next->next = x;
    }
    return;
}
template<typename T>
T SingleLinearLinkedList<T>::deleteAtHead()
{
    if (head)
    {
        T val = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    exit(0);
}
template<typename T>
T SingleLinearLinkedList<T>::deleteAtTail()
{
    T val;
    if (head)
    {
        Node<T>* tail = head;
        Node<T>* prev = nullptr;
        while (tail->next)
        {
            prev = tail;
            tail = tail->next;
        }
        delete tail;
        prev->next = nullptr;
    }
    else if (head->next == nullptr)
    {
        val = head->data;
        delete head;
        head = nullptr;
        return val;
    }
    else
    {
        exit(0);
    }
}
template<typename T>
void SingleLinearLinkedList<T>::deleteBefore(T key)
{
    if (head->next->data == key)
    {
        Node<T>* q = head->next;
        delete head;
        head = q;
        return;
    }
    Node<T>* p = head;
    while (p->next->next != nullptr&&p->next->next->data!=key)
    {
        p = p->next;
    }
    if (p->next->next == nullptr)
        return;
    Node<T>* x = p->next;
    p->next = p->next->next;
    delete x;
}
template<typename T>
void SingleLinearLinkedList<T>::deleteAfter(T targetValue)
{
    if (search(targetValue) == nullptr)
        return;
    if (search(targetValue)->next == nullptr)
        return;
    else if (search(targetValue)->next->next == nullptr)
    {
        delete search(targetValue)->next;
        search(targetValue)->next = nullptr;
    }
    else
    {
        Node<T>* temp = search(targetValue)->next->next;
        delete search(targetValue)->next;
        search(targetValue)->next = temp;
    }
}
template<typename T>
void SingleLinearLinkedList<T>::remove(T targetValue)
{
    if (search(targetValue) == nullptr)
        return;
    Node<T>* p = head;
    if (p == search(targetValue)&&p->next==nullptr)
    {
        delete search(targetValue);
        head = nullptr;
        return;
    }
    while (p->next->next != nullptr)
    {
        p = p->next;
    }
    if (p->next->next == nullptr&&(p->next->data==search(targetValue)->data))
    {
        deleteAtTail();
    }
    else
    {
        deleteBefore(search(targetValue)->next->data);
    }
}
template<typename T>
int SingleLinearLinkedList<T>::getSize()
{
    int size = 0;
    Node<T>* itr = head;
    while (itr != nullptr)
    {
        itr = itr->next;
        size++;
    }
    return size;
}
template<typename T>
void SingleLinearLinkedList<T>::reverse()
{
    Node<T>* temp = nullptr;
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    while (current != nullptr) 
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
        head = prev;
}
template<typename T>
void SingleLinearLinkedList<T>::display()
{
    Node<T>* itr = head;
    while (itr != nullptr)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << "\n";
}
template<typename T>
Node<T>* SingleLinearLinkedList<T>::search(T key)
{
    Node<T>* temp = head;

    while (temp->next != nullptr)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr && temp->data == key)
        return temp;
    return nullptr;
}
template<typename T>
inline void SingleLinearLinkedList<T>::sortedInsert(Node<T>& a)
{
    Node<T>* temp = head;
    while (temp->next != nullptr && temp->data <= a.data)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
        insertAtTail(a.data);
    else if (temp->next != nullptr)
    {
        insertBefore(temp->data, a.data);
    }
}
template<typename T>
inline Node<T>* SingleLinearLinkedList<T>::getMiddle()
{
    Node<T>* fast = head;
    Node<T>* slow = head;
    while (fast != nullptr || slow != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
