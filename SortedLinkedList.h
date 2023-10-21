#include "ListNode.h"

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList {
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
    int merge(ItemType item);
    void DeleteAlternateNodes();
    int FindCommonElements(ItemType item);
    int EndList();
};


#endif
