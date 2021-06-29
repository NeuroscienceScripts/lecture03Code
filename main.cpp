#include <iostream> // Input output stream
using namespace std;  // Standard namespace

int InnerFunction(int outerFunctionNumber){ // Used by OuterFunction()
    return outerFunctionNumber+1; // returns the number incremented by 1
}

int OuterFunction(int startingNumber){  // Decreases startingNumber then uses InnerFunction() to increment number
    return InnerFunction(startingNumber -1); // Calls InnerFunction on decremented number
}

struct Node{
    char nodeChar;
    Node* nodePtr;

    Node(char character, Node* nodePointer):nodeChar(character), nodePtr(nodePointer){}
    bool HasNextNode(){return this -> nodePtr; } // Special syntax, if the pointer exists (not nullptr) it returns true
    ~Node()   // Destructor
    {
        delete nodePtr;
        nodePtr = nullPtr;
    }
   Node(Node& copyFrom) // Copy Constructor
   {
        nodeChar = copyFrom.nodeChar;
       nodePtr = new Node(copyFrom.nodeChar, nullptr); // Does not copy the node after the next node!!
   }
   Node& operator=(const Node& copyFrom) // Copy Assignment
   {
        nodeChar = copyFrom.nodeChar;
        nodePtr = new Node(copyFrom.nodeChar, nullptr); // Does not copy the node after the next node!!
   }
};


class LinkedList{
private:
    Node firstNode = Node('a', nullptr);
public:
    LinkedList(Node start): firstNode(start){}
    void PrintList();
    ~LinkedList(){ /* Code that deletes all Nodes */}   // Destructor
    LinkedList(LinkedList& copyFrom){ /* Code to copy each Node */} // Copy Constructor
    LinkedList& operator=(const LinkedList& copyFrom){ /* Code to copy each Node */} // Copy Assignment
};

void LinkedList::PrintList(){
    Node currentNode = firstNode; // is directly equal to (same location in memory)
    cout << currentNode.nodeChar << endl;
    do{
        currentNode = currentNode.nodePtr;
        cout << currentNode.nodeChar << endl;

    }while(currentNode.HasNextNode());
}

int main() {
    Node linkedList = Node('a', new Node('b', new Node('c',
                                                       new Node('d',nullptr))));
    LinkedList startAtFirstNode = LinkedList(linkedList);
    startAtFirstNode.PrintList();
}

//Pointer deleting code:

//int* pointerToInt = new int; // Creates a new int and points to it
//    delete pointerToInt; // Deletes the new int
//    cout << pointerToInt << endl; // Prints the location being pointed to by the pointer
//    pointerToInt = nullptr; // Now we point to nowhere
//    cout << "Made it to the end!" << endl;
//    return 0;