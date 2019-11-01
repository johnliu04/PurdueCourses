#include "Item.h"
#include <iostream>

int Item::getNumberOfItems( ) {
   return numberOfItems;
}

Item::Item(int i, float p) : itemNum(i), price(p) {
   numberOfItems++;
}

Item::Item( ) { }

Item::~Item( ) { }

void Item::print( ) {
   std::cout << "number of items: " << numberOfItems;
   std::cout << ", item number: " << itemNum;
   std::cout << ", price: " << price << std::endl;
}

int Item::numberOfItems = 0; // initialize statics like this

