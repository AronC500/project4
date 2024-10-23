#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "ArrayBag.hpp"
#include "Dish.hpp"
#include "Appetizer.hpp"
#include "Dessert.hpp"
#include "MainCourse.hpp"
// for round
#include <cmath>
// for reading file
#include <fstream>
#include <vector>




class Kitchen : public ArrayBag<Dish> {
    public:
        Kitchen();


        bool newOrder(const Dish& new_dish);
        bool serveDish(const Dish& dish_to_remove);
        int getPrepTimeSum() const;
        int calculateAvgPrepTime() const;
        int elaborateDishCount() const;
        double calculateElaboratePercentage() const;
        int tallyCuisineTypes(const std::string& cuisine_type) const;
        int releaseDishesBelowPrepTime(const int& prep_time);
        int releaseDishesOfCuisineType(const std::string& cuisine_type);
        void kitchenReport() const;

    private:
        int total_prep_time_;
        std::vector<Dish*> dishes;
        int count_elaborate_;
    
};

#endif // KITCHEN_HPP