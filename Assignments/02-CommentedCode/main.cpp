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
//       Program creates 2 objects from List class and then concatenates them into a third List, 
//       and then makes printing manipulations to them.
//
// Usage:
//       JUST RUN THE PROGRAM MAN
//
// Files:
//       main.cpp   :   driver program
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];     // an array with 100 integers

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
 *      - List L;
 *      - L.Push(19);
 *      - L.PrintTail(); 
 *      - L3 = L1 + L2; 
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

     /**
     * Public : Push
     * 
     * Description:
     *      Pushes a new Node to the end of List
     * 
     * Params:
     *      int     :   value from new Node
     * 
     * Returns:
     *      void
     */
    void Push(int val) {                    
        // allocate new memory and init node
        Node *Temp = new Node(val);         // creates pointer *Temp which points to a new Node with val value

        if (!Head && !Tail) {               // if List is empty
            Head = Tail = Temp;             // pointers Head and Tail will point to the Node newly added
        } else {                            // if List is NOT empty
            Tail->next = Temp;              // adds new Node to the end of List
            Tail = Temp;                    // makes pointer Tail point to the newly added Node
        }
        Size++;                             // size of List increases by 1
    }

     /**
     * Public : Insert
     * 
     * Description:
     *      Inserts a new Node to the beginning of List
     * 
     * Params:
     *      int     :   value from new Node
     * 
     * Returns:
     *      void
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);        // creates pointer *Temp which points to a new Node with val value

        // figure out where it goes in the list

        Temp->next = Head;                 // new Node points to what Head points
        Head = Temp;                       // makes Head point to new Node
        if (!Tail) {                       // if list was empty
            Tail = Head;                   // makes Tail point to new Node
        }
        Size++;                            // size increases by 1
    }

     /**
     * Public : PrintTail
     * 
     * Description:
     *      Prints value from Tail's Node
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void
     */
    void PrintTail() {
        cout << Tail->x << endl;        // gets Tail's value to print
    }
   
     /**
     * Public : Print
     * 
     * Description:
     *      Makes a string list with all List's Nodes' values
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      string   :   list with all List's values to be printed
     */
    string Print() {                
        Node *Temp = Head;          // makes temporary Node pointer pointing to Head
        string list;                // makes a string avriable

        while (Temp != NULL) {                      // while temporary Node pointer doesn't reach end of List
            list += to_string(Temp->x) + "->";      // concatenates all the values to one string
            Temp = Temp->next;                      // goes to the next Node
        }

        return list;                // final string to be printed
    }

    // not implemented
     /**
     * Public : Pop
     * 
     * Description:
     *      Decreases size of List and returns value 0
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      int     :   0
     */
    int Pop() {
        Size--;         // decreases List's size by 1
        return 0;       // returns value 0
    }

     /**
     * Public : +
     * 
     * Description:
     *      Creates a new list with all Nodes from both Lists
     * 
     * Params:
     *      List    :   an object List to be added to object that called the method
     * 
     * Returns:
     *      List    :   a final List with the concatenation from both objects List
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {          // while Temp points to a Node from List
            NewList.Push(Temp->x);      // adds temporary Node to the end of NewList
            Temp = Temp->next;          // points to next Node
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {          // while Temp points to a Node from List
            NewList.Push(Temp->x);      // adds temporary Node to the end of NewList
            Temp = Temp->next;          // points to next Node
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
     /**
     * Public : []
     * 
     * Description:
     *      Gets a value and searches for the Node's value from that parameter order
     * 
     * Params:
     *      int    :   Node's number of order in List
     * 
     * Returns:
     *      int    :   Node's value
     */
    int operator[](int index) {
        // Get a reference to beginning of local list
        Node *Temp = Head;

        if (index >= Size) {    // if ordering desired is bigger than size of List
            cout << "Index out of bounds, exiting";
            exit(0);            // exits
        } else {

            for (int i = 0; i < index; i++) {   // goes through all List's Nodes until the desired order number
                Temp = Temp->next;
            }
            return Temp->x;                     // returns value from Node in order from parameter
        }
    }


     /**
     * Public : <<
     * 
     * Description:
     *      Enables to print a friend's List
     * 
     * Params:
     *      ostrean    :    output stream variable
     *      List       :    List from which the method will get the string to be printed
     * 
     * Returns:
     *      ostream    :    output stream variable
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();    // Inserts the returned List.Print() string into os operator
        return os;          // returns ostream
    }
    
};  // END OF LIST CLASS


///////////////////////////////////////////////////////////////////////////////
// 
//      MAIN
//
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    List L1;                        // creates List L1
    List L2;                        // creates List L2

    for (int i = 0; i < 25; i++) {  // creates a List with 25 Nodes with values in 
        L1.Push(i);                 // ascending order from 0 to 24 
    }

    for (int i = 50; i < 100; i++) {    // creates a List with 50 Nodes with values in 
        L2.Push(i);                     // ascending order from 50 to 99 
    }

    //cout << L1 << endl;           //
    L1.PrintTail();                 // prints List L1's Tail's value
    L2.PrintTail();                 // prints List L2's Tail's value

    List L3 = L1 + L2;              // concatenates Lists L1 and L2
    cout << L3 << endl;             // prints string from values of List L3

    cout << L3[5] << endl;          // prints value from Node at position 5 in List L3
    return 0;                       // END OF MAIN
}
