#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "ArrayBag.hpp"
#include "Dish.hpp"
// for round
#include <cmath>
// for reading file
#include <fstream>
#include <vector>




class Kitchen : public ArrayBag<Dish> {
    public:
        Kitchen();



        /**
* Parameterized constructor.
* @param filename The name of the input CSV file containing dish
information.
* @pre The CSV file must be properly formatted.
* @post Initializes the kitchen by reading dishes from the CSV file and
storing them as `Dish*`.
*/
        Kitchen(const std::string& filename);
        /**
* Destructor.
* @post Deallocates all dynamically allocated dishes to prevent memory
leaks.
*/      
        ~Kitchen();

        /**
* Adjusts all dishes in the kitchen based on the specified dietary
accommodation.
* @param request A DietaryRequest structure specifying the dietary
accommodations.
* @post Calls the `dietaryAccommodations()` method on each dish in the
kitchen to adjust them accordingly.
*/
        void dietaryAdjustment(const Dish::DietaryRequest& request);

/**
* Displays all dishes currently in the kitchen.
* @post Calls the `display()` method of each dish.
*/
        void displayMenu();
        bool newOrder(const Dish* new_dish);
        bool serveDish(const Dish* dish_to_remove);
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