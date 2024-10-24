#include "ArrayBag.hpp"
#include "Appetizer.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> ingredients = {"Tomato", "Basil", "Olive Oil"};
    Appetizer myAppetizer("Bruschetta", ingredients, 15, 7.50, Dish::ITALIAN, Appetizer::PLATED, 2, true);

    myAppetizer.display();

    
    return 0;
}