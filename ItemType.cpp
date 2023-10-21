#include <iostream>
#include "ItemType.h"
using namespace std;

/*
   Constructore of the class.
   Sets value of item to 0
*/
ItemType::ItemType() {
    this->value = 0;
}

/*
  Compare the value of item with the current object's value and return GREATEr,
  LESS, or EQUAL
*/
Comparison ItemType::compareTo(ItemType item) {
    if(this->value > item.value) {
        return Comparison::GREATER;
    }
    if (this->value < item.value) {
        return Comparison::LESS;
    }
    return Comparison::EQUAL;
}

/*
  Return the value instance variable
*/
int ItemType::getValue() const {
    return this->value;
}

/*
  Intializes the data member by variable num
*/
void ItemType::initialize(int num) {
    this->value = num;
}
