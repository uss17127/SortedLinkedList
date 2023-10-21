#include <iostream>
#include <vector>
#include "ListNode.h"
#include "SortedLinkedList.h"
using namespace std;

/*
  Constructor that initializes a sorted linked list object
*/
SortedLinkedList::SortedLinkedList() {
    this->head = NULL;
    this->currentPos = NULL;
    this->lengthL = 0;
    this->reset = 0;
    this->endList = 0;
}

/*
  Free up all the user allocated memory and destruct the SortedLinkedList instance
*/
SortedLinkedList::~SortedLinkedList() {
    ListNode *ptr;
    while (this->head != NULL) {
        ptr = this->head;
        this->head = this->head->next;
        delete ptr;
    }
}

/*
  Return the length of the linked list.
*/
int SortedLinkedList::length() const {
    return this->lengthL;
}

/*
  Inserts Item within the list and can handle insertion as the first element,
  in an empty list, or warn of duplicate items.
*/
void SortedLinkedList::insertItem(ItemType item) {
    // Putting in first item of the list that is empty
    if (this->head == NULL) {
        ListNode *node = new ListNode;
        node->info = item;
        node->next = NULL;
        this->head = node;
        this->currentPos = head;
        this->lengthL++;
    // If item is a lesser value then head it becomes the head
    } else if (item.compareTo(this->head->info) == Comparison::LESS) {
        ListNode *node2 = new ListNode;
        node2->info = item;
        node2->next = this->head;
        this->head = node2;
        this->lengthL++;
    // General Case
    } else {
        ListNode *predLoc = new ListNode;
        ListNode *location = this->head;
        ListNode *temp = new ListNode;
        while (location != NULL) {
            if (item.compareTo(location->info) == Comparison::LESS) {
                break;
            }
            // Duplicate item
            if (item.compareTo(location->info) == Comparison::EQUAL) {
                cout << "Sorry. You cannot insert duplicate item." << endl;
                return;
            }
            predLoc = location;
            location = location->next;
        }
        this->lengthL++;
        temp->info = item;
        temp->next = location;
        predLoc->next = temp;
    }
}

/*
  Removes the ListNode that contains an item equal to the item parameter.
  Can handle deleting the first element, the only element, warn that the
  element the user wishes to delete does not exist, and warns the user
  that they cannot delete from an empty list.
*/
void SortedLinkedList::deleteItem(ItemType item) {
    int equal = 0;
    // Deleting from an empty list
    if (lengthL == 0) {
        cout << "You cannot delete from an empty list"  <<endl;
    // Deleting first element
    } else if (item.compareTo(this->head->info) == Comparison::EQUAL) {
        ListNode *temp = this->head;
        this->head = this->head->next;
        lengthL--;
        delete temp;
    // General Case
    } else {
        ListNode *location = this->head;
        ListNode *predLoc = location;
        while(location != NULL) {
            if (item.compareTo(location->info) == Comparison::EQUAL) {
                equal = 1;
                break;
            }
            predLoc = location;
            location = location->next;
        }
        if (equal == 1) {
            lengthL--;
            predLoc->next = location->next;
            delete location;
         // We use equal 1 to determine if item matches another item on the list
        // If it never equals 1 this means that the item does not exist in this list
        } else {
            cout << "Item not found." << endl;
        }
    }
}

/*
  Searches the ListNode that contains an item equal to the parameter item
  and return its index. Prints “Item not found” if the item was not found
  in the list.

*/
int SortedLinkedList::searchItem(ItemType item) {
    int index = -1;
    ListNode *temp = this->head;
    while(temp != NULL) {
        index++;
        if(item.compareTo(temp->info) == Comparison::EQUAL) {
            return index;
        }
        temp = temp->next;
    }
    index = -1;
    if (index == -1) {
        cout << "Item not found." << endl;
    }
    return index;
}

/*
  “Item not found” if the item was not found in the list.
  Handles and warns the user that list is empty or then end of the
  list has been reached.

*/
ItemType SortedLinkedList::GetNextItem() {
    ItemType item;
    ListNode *node;
    if (lengthL == 0) {
        cout << "List is empty." << endl;
    } else {
        if (this->currentPos == NULL) {
            this->currentPos = this->head;
        }
        node = this->currentPos->next;
        item = this->currentPos->info;
        this->currentPos = this->currentPos->next;
        if (node != NULL && node->next == NULL) {
            item = node->info;
            return item;
        }
        if (this->currentPos == NULL) {
            this->endList = 1;
            cout << "The end of the list has reached" << endl;
        }
    }

    return item;
}

/*
  Prints the items values within the list.
*/
void SortedLinkedList::printList() {
    ListNode *temp;
    temp = this->head;
    if (lengthL != 0) {
        for(int i = 0; i < this->lengthL; i++) {
            cout << temp->info.getValue() << " ";
            temp = temp->next;
        }
    }
    cout << " " << endl;
}

/*
  This will initialize the currentPos pointer to null. See the description
  below to check how you need to call these functions.
*/
void SortedLinkedList::ResetList() {
    this->currentPos = NULL;
    this->endList = 0;
    cout << "Iterator reset." << endl;
}

/*
  This function will take another list as input, merge the input list to the
  original list, and then print the output. Warns user list cannot be merged
  if it includes duplicate items.
*/
int SortedLinkedList::merge(ItemType item) {
    int index = -1;
    ListNode *temp = this->head;
    while(temp != NULL) {
        index++;
        if(item.compareTo(temp->info) == Comparison::EQUAL) {
            return index;
        }
        temp = temp->next;
    }
    index = -1;
    return index;
}

/*
  This function will delete alternate nodes from the list.
*/
void SortedLinkedList::DeleteAlternateNodes() {
    if (this->head == NULL) {
        cout << "Your list is empty" << endl;
        return;
    }
    ListNode *start = this->head;
    ListNode * node = this->head->next;
    while (start != NULL && node != NULL) {
        start->next = node->next;
        start = start->next;
        lengthL--;
        if (start != NULL) {
            node = start->next;
        }
    }
    delete node;
}

/*
  This function will take another list as input, find the
  common elements between input list and original list, and then print the output.
*/
int SortedLinkedList::FindCommonElements(ItemType item) {
    int index = -1;
    ListNode *temp = this->head;
    while(temp != NULL) {
        index++;
        if(item.compareTo(temp->info) == Comparison::EQUAL) {
            return index;
        }
        temp = temp->next;
    }
    index = -1;
    return index;
}

/*
  Returns int value that indicates if the currentPos is at the end of the list.
  i = 1 indicates that the currentPos has reached the end of the list, and
  i = 0 indicates currentPos has not reached the end of the list.
*/
int SortedLinkedList::EndList() {
    int i = this->endList;
    return i;
}
