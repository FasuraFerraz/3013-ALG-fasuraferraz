///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Marina Fasura Ferraz
// Email:            marina19ff@gmail.com
// Label:            02-A02
// Title:            Commenting C++ Code
// Course:           3013-ALG
// Semester:         Spring 2020
//
// Description:
//       describe program here thoroughly 
//
// Usage:
//       how to use the program if necessary
//
// Files:            main.cpp   :   driver program
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];             // an array with 100 integers

/**
 * Structure: Node
 * 
 * Description:
 *      Structure named Node which holds an integer data and an address that points to another Node structure.
 * 
 * Contructors:
 *      - Default
 *      - Parameterized
 * 
 * Usage:  
 *      - Node myNewNode;
 *      - Node myNewNode(89);
 *      
 */
struct Node {           // definition of structure Node's variables, pointers, and constructors
    int x;              // integer data from structure Node
    Node *next;         // pointer in structure Node that points to another Node
    Node() {            // default constructor
        x = -1;         // sets the Node's int data to -1
        next = NULL;    // created Node's pointer is NULL
    }
    Node(int n) {       // parameterized constructor
        x = n;          // sets the Node's int data to parameterized integer
        next = NULL;    // created Node's pointer is NULL
    }
};


/**
 * Class: List
 * 
 * Description:
 *      - List class enables the creation of a sequence of connected Node structures, 
 *        as well as manipulations to the list.
 *      - Every list has a pointer Head to indicate the beginning, and another pointer 
 *        Tail to indicate its end; as well as an integer value Size.
 *
 * Public Methods:
 *      - List();
 *      - void Push(int val);
 *      - void Insert(int val);
 *      - void PrintTail();
 *      - string Print();
 *      - int Pop();
 *      - List operator+(const List &Rhs);
 *      - int operator[](int index);
 *      - friend ostream &operator<<(ostream &os, List L);
 *
 * Private Methods:
 *      - A list of 
 *      - each private method
 *      - with return types
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
class List {
private:
    Node *Head;     // pointer Head indicating the beginning of the List
    Node *Tail;     // pointer Head indicating the end of the List
    int Size;       // integer value indicating the size of list

public:
    List() {                    // default constructor for a List
        Head = Tail = NULL;     // when creating a List, all default pointers are NULL
        Size = 0;               // when creating a List, its size is 0
    }

    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};


///////////////////////////////////////////////////////////////////////////////
// 
//
//
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
