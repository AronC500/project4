#include "ArrayBag.hpp"
#include "Appetizer.hpp"
#include "Dessert.hpp"
#include "MainCourse.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "MainCourse.hpp"
#include "Dessert.hpp"
#include "Appetizer.hpp"

int main() {

    Appetizer myAppetizer("Bruschetta",  {"Tomato", "Basil", "Olive Oil"}, 15, 7.50, Dish::ITALIAN, Appetizer::PLATED, 2, true);

    myAppetizer.display();
    myAppetizer.dietaryAccommodations({true,true,false,true,true,true});


    Dessert myAppetizer2("Bme",  {"Oli Oil"}, 15, 7.50, Dish::FRENCH, Dessert::SWEET, 2, true);

    myAppetizer2.display();
        myAppetizer2.dietaryAccommodations({true,false});


    MainCourse myAppetizer3("rawjna", {"Tomarwarto", "Basil"} , 15, 7.50, Dish::ITALIAN, MainCourse::RAW, "Chicken",{{"Mashed Potatoes",  MainCourse::Category::STARCHES},{"Green Beans",  MainCourse::Category::VEGETABLE}}, true);

    myAppetizer3.display();
    myAppetizer3.dietaryAccommodations({});


    
    return 0;
}