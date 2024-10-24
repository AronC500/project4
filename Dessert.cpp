#include "Dessert.hpp"

/**
 * Default constructor.
 * Initializes all private members with default values.
 */
Dessert::Dessert()
    : Dish(), flavor_profile_(SWEET), sweetness_level_(0), contains_nuts_(false) {}

/**
 * Parameterized constructor.
 * @param name The name of the dessert.
 * @param ingredients The ingredients used in the dessert.
 * @param prep_time The preparation time in minutes.
 * @param price The price of the dessert.
 * @param cuisine_type The cuisine type of the dessert.
 * @param flavor_profile The flavor profile of the dessert.
 * @param sweetness_level The sweetness level of the dessert.
 * @param contains_nuts Flag indicating if the dessert contains nuts.
 */
Dessert::Dessert(const std::string& name, const std::vector<std::string>& ingredients, const int &prep_time, const double &price, const CuisineType &cuisine_type, const FlavorProfile &flavor_profile, const int &sweetness_level, const bool &contains_nuts)
    : Dish(name, ingredients, prep_time, price, cuisine_type), flavor_profile_(flavor_profile), sweetness_level_(sweetness_level), contains_nuts_(contains_nuts) {}

/**
 * Sets the flavor profile of the dessert.
 * @param flavor_profile The new flavor profile.
 * @post Sets the private member `flavor_profile_` to the value of the parameter.
 */
void Dessert::setFlavorProfile(const FlavorProfile &flavor_profile) {
    flavor_profile_ = flavor_profile;
}

/**
 * @return The flavor profile of the dessert.
 */
Dessert::FlavorProfile Dessert::getFlavorProfile() const {
    return flavor_profile_;
}

/**
 * Sets the sweetness level of the dessert.
 * @param sweetness_level An integer representing the sweetness level of the dessert.
 * @post Sets the private member `sweetness_level_` to the value of the parameter.
 */
void Dessert::setSweetnessLevel(const int &sweetness_level) {
    sweetness_level_ = sweetness_level;
}

/**
 * @return The sweetness level of the dessert.
 */
int Dessert::getSweetnessLevel() const {
    return sweetness_level_;
}

/**
 * Sets the contains_nuts flag of the dessert.
 * @param contains_nuts A boolean indicating if the dessert contains nuts.
 * @post Sets the private member `contains_nuts_` to the value of the parameter.
 */
void Dessert::setContainsNuts(const bool &contains_nuts) {
    contains_nuts_ = contains_nuts;
}

/**
 * @return True if the dessert contains nuts, false otherwise.
 */
bool Dessert::containsNuts() const {
    return contains_nuts_;
}





/**
* Displays the dessert's details.
* @post Outputs the dessert's details, including name, ingredients,
preparation time, price, cuisine type, flavor profile, sweetness level, and
whether it contains nuts.
* The information must be displayed in the following format:
*
* Dish Name: [Name of the dish]
* Ingredients: [Comma-separated list of ingredients]
* Preparation Time: [Preparation time] minutes
* Price: $[Price, formatted to two decimal places]
* Cuisine Type: [Cuisine type]
* Flavor Profile: [Flavor profile: Sweet, Bitter, Sour, Salty, or Umami]
* Sweetness Level: [Sweetness level]
* Contains Nuts: [Yes/No]
*/
void Dessert::display()  {
    std::string ingredList = "";
    std::vector<std::string> g = getIngredients();
    for (int i = 0; i < g.size(); i++) {
        if (i != 0) {
            ingredList += ", "; 
        }
        ingredList += g[i];
    }

    FlavorProfile m = getFlavorProfile();
    std::string x;
    switch(m) {
        case Dessert::FlavorProfile::SWEET:
        x = "Sweet";
        break;
        case Dessert::FlavorProfile::SOUR:
        x = "Sour";
        break;
        case Dessert::FlavorProfile::BITTER:
        x =  "Bitter";
        break;
        case Dessert::FlavorProfile::SALTY:
        x = "Salty";
        break;
        case Dessert::FlavorProfile::UMAMI:
        x = "Umami";
        break;
        default:
        x = "UNKNOWN";
        break;
      }

    std::cout << "Dish Name: " << getName() << std::endl <<
    "Ingredients: " << ingredList << std::endl <<
    "Preparation Time: " << getPrepTime() << " minutes" << std::endl <<
    "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl << 
    "Cuisine Type: " << getCuisineType() << std::endl <<
    "Flavor Profile: " << x << std::endl <<
    "Sweetness Level: " << sweetness_level_ << std::endl <<
    "Contains Nuts: " << (containsNuts() ? "Yes" : "No") << std::endl;
    
}


/**
* Modifies the dessert based on dietary accommodations.
* @param request A DietaryRequest structure specifying the dietary
accommodations.
* @post Adjusts the dessert's attributes to meet the specified dietary
needs.
* - If `request.nut_free` is true:
* - Sets `contains_nuts_` to false.
* - Removes nuts from `ingredients_`.
* Nuts are: "Almonds", "Walnuts", "Pecans", "Hazelnuts",
"Peanuts", "Cashews", "Pistachios".
* - If `request.low_sugar` is true:
* - Reduces `sweetness_level_` by 3 (minimum of 0).
* - If `request.vegan` is true:
* - Removes dairy and egg ingredients from `ingredients_`.
* Dairy and egg ingredients are: "Milk", "Eggs", "Cheese",
"Butter", "Cream", "Yogurt".
*/

void Dessert::dietaryAccommodations(const DietaryRequest& request) {
    std::vector<std::string> ingredList = getIngredients();
    if (request.nut_free) {
        contains_nuts_ = false;
        for (int i = 0; i < ingredList.size();i++) {
             if (ingredList[i] == "Almonds" || ingredList[i] == "Walnuts" || ingredList[i] == "Pecans"
            || ingredList[i] == "Hazelnuts" || ingredList[i] == "Peanuts" || ingredList[i] == "Cashews"
            || ingredList[i] == "Pistachios") {
                ingredList.erase(ingredList.begin()+i);
                i--;
            }
        }
        setIngredients(ingredList);

    }
    if (request.low_sugar) {
        sweetness_level_ -= 3;
        if (sweetness_level_ < 0 ) {
            sweetness_level_ = 0;
        }
    }
    if (request.vegan) {
        for (int i = 0; i < ingredList.size();i++) {
             if (ingredList[i] == "Milk" || ingredList[i] == "Eggs" || ingredList[i] == "Cheese"
            || ingredList[i] == "Butter" || ingredList[i] == "Cream" || ingredList[i] == "Yogurt") {
                ingredList.erase(ingredList.begin()+i);
                i--;
            }

        }
        setIngredients(ingredList);


    }

}


