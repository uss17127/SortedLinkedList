#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum class Comparison {GREATER, LESS, EQUAL};

class ItemType {
private:
    int value;

public:
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
};

#endif
