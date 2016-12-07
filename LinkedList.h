#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
template <class T> class LinkedList;

template <class T>
class ListNode {
public:

    // ListNode constructor
    ListNode(T x = 0, ListNode* n = nullptr):
        data(x), next(n), prev(nullptr){}

    // Returns ListNode value
    T getData()
    {
        return data;
    }

    void setData(T val)
    {
        data = val;
    }

    friend class LinkedList<T>;

private:

    T data;
    // Pointer to the next node
    ListNode<T>* next;
    // Pointer to the previous node
    ListNode<T>* prev;
};

template<class T>
class LinkedList {

public:

    // Default constructor
    LinkedList();
    // Constructs a LinkedList with one ListNode
    LinkedList(T);
    // Copy Constuctor
    LinkedList(const LinkedList<T>&);
    // Destructor
    ~LinkedList(void);

    // Inserts a value at the specified location
    void insert(T, int);
    // Adds an element to the start of the LinkedList
    void addToFront(T);
    // Adds an element to the end of the LinkedList
    void add(T);


    // Returns the data value of the specified ListNode
    T get(int);
    // Returns the size of the LinkedList
    int size() const;
    // Remove the specified ListNode from the LinkedList
    T remove(int);
    // Remove every element in the LinkedList
    void removeAll(ListNode<T> *);
    // Checks if the LinkedList is empty
    bool isEmpty();
    // Prints all values in the LinkedList
    void printList();

    // Getters for pointers
    ListNode<T>* getHead() const;
    ListNode<T>* getTail() const;

    // Overloaded subscript operator
    T operator[] (int);
    // Overloaded assignment operator
    LinkedList<T>& operator=(LinkedList<T>&);

private:

    // Pointer to the first node in the list
    ListNode<T>* head;
    // Pointer to the last node in the list
    ListNode<T>* tail;
    // Number of elements in the list
    int num_elements;

};

// Default constructor
template<class T>
LinkedList<T>::LinkedList()
{
    // Initialize empty pointers and the number of elements
    this->head = nullptr;
    this->tail = nullptr;
    this->num_elements = 0;
}

// Constructs a list with one node in it
template<class T>
LinkedList<T>::LinkedList(T val)
{
    // Initialize one node with the value passed in
    ListNode<T>* x = new ListNode<T>(val);

    // Initialize the member variables
    this->num_elements = 1;
    this->head = x;
    this->tail = x;
}

// Copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    // If rhs is empty, assign null values
    if (rhs.getHead() == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        num_elements = 0;
    }
    else
    {
        // oldCurr points to rhs values
        ListNode<T>* oldCurr = rhs.head;
        this->head = new ListNode<T>(oldCurr->getData());

        // newCurr points to this values
        ListNode<T>* newCurr = head;

        oldCurr = oldCurr->next;

        while (oldCurr != nullptr)
        {
            // Copied node equals rhs data
            ListNode<T>* temp = new ListNode<T>(oldCurr->getData());

            // Set this's curr->next to point to temp
            newCurr->next = temp;
            // Set temp's previous pointer to point to this's curr
            temp->prev = newCurr;

            // Increment both currs to move to the next nodes
            newCurr = newCurr->next;
            oldCurr = oldCurr->next;

        }
        // Number of elements equals the size of rhs
        num_elements = rhs.size();
    }
}

// Destructor
template<class T>
LinkedList<T>::~LinkedList(void)
{
    // If the LinkedList isn't empty, it deletes all the nodes in the list
    if (head != nullptr)
    {
        ListNode<T>* curr = head;


        while (curr != nullptr)
        {
            ListNode<T>* temp;
            temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }
}

// Insert function: inserts a value at the location passed in
template<class T>
void LinkedList<T>::insert(T val, int loc)
{

    // Adds element to the front for these conditions
    if (loc < 0 || loc == 0 || this->isEmpty() == true)
        addToFront(val);
    // If the passed value is greater than the size, add the element to the back
    else if (loc > num_elements)
        add(val);
    else
    {
        ListNode<T>* curr = head;
        ListNode<T>* temp = new ListNode<T>;
        // Setting the new node to the element value
        *temp = val;

        // Go to the node behind the new node
        for (int i = 0; i < loc - 1 && curr != nullptr; i++)
            curr = curr->next;

        // "curr node" is the node before the new node
        // "temp node" is the new node in between curr node and loc node
        // "loc node" is the node after the new node

        // Assign temp's next pointer to point to loc node
        temp->next = curr->next;
        // Reassign the loc node's previous pointer to point to temp node
        temp->next->prev = temp;
        // Assign temp's previous pointer to point to the curr node
        temp->prev = curr;
        // Reassign curr node's next pointer to point to the temp node
        curr->next = temp;

        this->num_elements++;
    }
}

// Add to the front of the list
template<class T>
void LinkedList<T>::addToFront(T val)
{
    if (this->isEmpty() == true)
    {
        head = new ListNode<T>(val);
        tail = head;
        num_elements++;
    }
    else
    {
        ListNode<T>* curr = head;
        ListNode<T>* x = new ListNode<T>(val);

        // Assign curr->prev to a new node
        curr->prev = x;
        // Reassign head to the new node
        head = curr->prev;
        // Assign head->next to the old head
        head->next = curr;

        this->num_elements++;
    }
}

// Add to the back of the list
template<class T>
void LinkedList<T>::add(T val)
{
    if (this->isEmpty() == true)
    {
        tail = new ListNode<T>(val);
        head = tail;
        num_elements++;
    }
    else
    {
        ListNode<T>* curr = tail;
        ListNode<T>* x = new ListNode<T>(val);

        // Get curr to point to the end of the LinkedList
        while (curr->next != nullptr)
            curr = curr->next;

        // Assign curr to a new node
        curr->next = x;
        // Reassign tail to the new node
        tail = curr->next;

        this->num_elements++;
    }
}

// Get the value of the specified node
template<class T>
T LinkedList<T>::get(int index)
{
    ListNode<T>* curr = head;

    if (index > this->num_elements)
    {
        std::cout << "You went too far" << std::endl;
    }
    else
    {
        // Go to the wanted node
        for (int i = 0; i < index; i++)
            curr = curr->next;

        return curr->getData();
    }
}

// Returns the number of elements in the list
template<class T>
int LinkedList<T>::size() const
{
    return num_elements;
}

// Remove a node at the specified index of the list
template<class T>
T LinkedList<T>::remove(int rhs)
{
    ListNode<T>* temp = new ListNode<T>;
    ListNode<T>* curr = head;

    // Go to the wanted node
    for (int i = 0; i < rhs; i++)
        curr = curr->next;

    // Assign temp to curr node
    temp = curr;
    // Reassign the next node to point to the previous node
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;
    // Reassign the previous node to point to the next node
    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    // Reassign curr to head so you don't lose the curr pointer
    curr = head;

    // Save temp node's value
    T val = temp->getData();
    // Delete temp which points to the node that needs to be removed
    delete temp;

    this->num_elements--;

    // Return the value that was stored in the removed node
    return val;
}

// Remove every element in the LinkedList
template<class T>
void LinkedList<T>::removeAll(ListNode<T>* ptr)
{
    if (ptr->next != nullptr)
    {
        // Recursively calls to get to the last node
        removeAll(ptr->next);
    }
    // Once the last node is reached, it deletes all the nodes
    delete ptr;

    this->num_elements = 0;
}

// Check if the list is empty or not
template<class T>
bool LinkedList<T>::isEmpty()
{
    if (num_elements == 0)
        return true;
    else
        return false;
}

// Print each node in the list
template<class T>
void LinkedList<T>::printList()
{
    if (head != nullptr)
    {
        ListNode<T>* curr = head;

        // As long as curr doesn't point at the end of the LinkedList
        while (curr != nullptr)
        {
            // Print the current node
            std::cout << curr->data << std::endl;
            // Move to the next node
            curr = curr->next;
        }
    }
}

template<class T>
ListNode<T>* LinkedList<T>::getHead() const
{
    return head;
}

template<class T>
ListNode<T>* LinkedList<T>::getTail() const
{
    return this->tail;
}

// Overloaded subscript operator
template<class T>
T LinkedList<T>::operator[] (int rhs)
{
    ListNode<T>* curr = head;

    // Go to the wanted node
    for(int i = 0; i < rhs; i++)
        curr = curr->next;

    // Return its stored value
    return curr->getData();
}

// Overloaded assignment operator
template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& rhs)
{
    // If this is not empty, delete every node
    if (this->isEmpty() == false)
        this->removeAll(this->head);

    // If rhs is empty, set values to null
    if (rhs.isEmpty() == true)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->num_elements = 0;
    }
    else
    {
        // oldCurr points to rhs values
        ListNode<T>* oldCurr = rhs.head;
        this->head = new ListNode<T>(oldCurr->getData());

        // newCurr points to this values
        ListNode<T>* newCurr = head;

        oldCurr = oldCurr->next;

        while (oldCurr != nullptr)
        {
            // Copied node equals rhs data
            ListNode<T>* temp = new ListNode<T>(oldCurr->getData());

            // Set this's curr->next to point to temp
            newCurr->next = temp;
            // Set temp's previous pointer to point to this's curr
            temp->prev = newCurr;

            // Increment both currs to move to the next nodes
            newCurr = newCurr->next;
            oldCurr = oldCurr->next;

        }
        // Number of elements equals the size of rhs
        num_elements = rhs.size();
    }
}

#endif
