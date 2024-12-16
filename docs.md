
================================================================================
                           LINKED LISTS IN C++: A COMPLETE GUIDE
================================================================================

Linked lists are a dynamic data structure, widely used in scenarios where the size 
of the data structure changes frequently. Unlike arrays, linked lists provide 
flexibility but require more memory due to the storage of pointers.

--------------------------------------------------------------------------------
1. WHAT IS A LINKED LIST?
--------------------------------------------------------------------------------

In C++, a linked list is a sequence of nodes. Each node contains:
   - **Data**: The value or information stored in the node.
   - **Pointer**: A reference (address) to the next node.

Types of Linked Lists in C++:
   1. **Singly Linked List (SLL)**: Each node points to the next node.
   2. **Doubly Linked List (DLL)**: Each node has pointers to both the next and 
      previous nodes.
   3. **Circular Linked List (CLL)**: The last node connects back to the first 
      node, forming a circle.

--------------------------------------------------------------------------------
2. IMPLEMENTING A SINGLY LINKED LIST IN C++
--------------------------------------------------------------------------------

Here’s a step-by-step guide to create and use a singly linked list in C++.

### NODE STRUCTURE:
Each node in the linked list is represented as a structure or class.

```cpp
#include <iostream>
using namespace std;

// Define a Node
struct Node {
    int data;        // Data part of the node
    Node* next;      // Pointer to the next node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();  // Allocate memory for a new node
    newNode->data = value;       // Assign data to the node
    newNode->next = nullptr;     // Initialize next as NULL
    return newNode;
}
```

### INSERTION INTO THE LINKED LIST:
We can add nodes at the beginning, end, or a specific position.

```cpp
// Insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode; // If list is empty, newNode becomes the head
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
}
```

### DISPLAY THE LINKED LIST:
To print all elements of the linked list:

```cpp
// Display all elements in the linked list
void displayList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl; // Indicate end of the list
}
```

### DELETION FROM THE LINKED LIST:
Removing a node from the list can be tricky, but here's how:

```cpp
// Delete the first node with the given value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return; // List is empty

    // If the node to be deleted is the head
    if (head->data == value) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        delete temp;
        return;
    }

    // Traverse to find the node
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    // If node found, unlink and delete
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next; // Unlink the node
        delete nodeToDelete;
    }
}
```

### MAIN FUNCTION:
Here’s how you can test the linked list implementation:

```cpp
int main() {
    Node* head = nullptr; // Initialize the head of the linked list

    // Insert elements into the linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Display the linked list
    cout << "Linked List: ";
    displayList(head);

    // Delete a node and display the list again
    cout << "Deleting node with value 20..." << endl;
    deleteNode(head, 20);
    cout << "Linked List after deletion: ";
    displayList(head);

    return 0;
}
```

### OUTPUT:
```
Linked List: 10 -> 20 -> 30 -> NULL
Deleting node with value 20...
Linked List after deletion: 10 -> 30 -> NULL
```

--------------------------------------------------------------------------------
3. ADVANTAGES AND DISADVANTAGES OF LINKED LISTS
--------------------------------------------------------------------------------

**Advantages:**
   - Dynamic size: No need to define an initial size.
   - Efficient insertion and deletion at arbitrary positions.

**Disadvantages:**
   - More memory usage due to pointers.
   - Sequential access: Cannot directly access an element (unlike arrays).

--------------------------------------------------------------------------------
4. EXPANDING TO DOUBLY LINKED LISTS
--------------------------------------------------------------------------------

In a **Doubly Linked List (DLL)**, each node contains two pointers:
   - `prev`: Points to the previous node.
   - `next`: Points to the next node.

Example structure for a doubly linked list node:
```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;
};
```

You can follow similar logic to implement insertion, deletion, and traversal for 
doubly or circular linked lists.

================================================================================
```
