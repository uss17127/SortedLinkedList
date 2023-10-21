Program: main.cpp ItemType.cpp SortedLinkedList.cpp
-----------------------------------------------------------------------------
ItemType file functions and variables
private:
    int value;

public:
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
-----------------------------------------------------------------------------
RUNTIME EXPLANATION BELOW
SortedLinkedList file functions and variables
private:
    ListNode *head;
    ListNode *currentPos;
    int lengthL;
    int reset;
    int endList;
public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType GetNextItem();
    void printList();
    void ResetList();

    RUNTIME EXPLANATION:
    int merge(ItemType item);
    The complexity of this function is O(n^2) or O(n^2) + 2O(N) as it is dependent on the size
    of the list being merged, and it iterates through the list twice.
    PSEUDO-CODE: i includes code from main and SortedLinkedList
    while (ss >> i) {
          //uses int from string stream to intialize an item - O(n) - size of second list
    }

    while(temp != NULL) {
               //iterates through list and checks if there are any duplicates -O(n)
    }

    while (ss >> i) {
    //runs through string stream again and adds items to to the list.- O(n^2)
           while(node->next != NULL) {
           }
    }

    void DeleteAlternateNodes();
    RUNTIME EXPLANATION:
    This functions runs on O(n^2) time complexity as well as it iterates
    through both lists in a nested while loop
    while(s >> i) {
            //runs through stream of second list and iterates through
            the second list to see if there are any common elements O(n^2)
            while(node->next != NULL) {
            }
    }

}
    PSUEDO-CODE: - includes code from main and SortedLinkedList

    int FindCommonElements(ItemType item);
    int EndList();
-----------------------------------------------------------------------------
CODER: Urja Shah
Credit/Contribution:
- Assignment 2 pdf - also used for comments

How to Compile:
g++ main.cpp ItemType.cpp SortedLinkedList.cpp -o main
