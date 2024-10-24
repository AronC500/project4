#include "Appetizer.hpp"

/**
 * Default constructor.
 * Initializes all private members with default values.
 */
Appetizer::Appetizer()
    : Dish(), serving_style_(PLATED), spiciness_level_(0), vegetarian_(false) {}

/**
 * Parameterized constructor.
 * @param name The name of the appetizer.
 * @param ingredients The ingredients used in the appetizer.
 * @param prep_time The preparation time in minutes.
 * @param price The price of the appetizer.
 * @param cuisine_type The cuisine type of the appetizer.
 * @param serving_style The serving style of the appetizer.
 * @param spiciness_level The spiciness level of the appetizer.
 * @param vegetarian Flag indicating if the appetizer is vegetarian.
 */
Appetizer::Appetizer(const std::string& name, const std::vector<std::string>& ingredients, const int &prep_time, const double &price, const CuisineType &cuisine_type, const ServingStyle &serving_style, const int &spiciness_level, const bool &vegetarian)
    : Dish(name, ingredients, prep_time, price, cuisine_type), serving_style_(serving_style), spiciness_level_(spiciness_level), vegetarian_(vegetarian) {}

/**
 * Sets the serving style of the appetizer.
 * @param serving_style The new serving style.
 * @post Sets the private member `serving_style_` to the value of the parameter.
 */
void Appetizer::setServingStyle(const ServingStyle &serving_style) {
    serving_style_ = serving_style;
}

/**
 * @return The serving style of the appetizer.
 */
Appetizer::ServingStyle Appetizer::getServingStyle() const {
    return serving_style_;
}

/**
 * Sets the spiciness level of the appetizer.
 * @param spiciness_level An integer representing the spiciness level of the appetizer.
 * @post Sets the private member `spiciness_level_` to the value of the parameter.
 */
void Appetizer::setSpicinessLevel(const int &spiciness_level) {
    spiciness_level_ = spiciness_level;
}

/**
 * @return The spiciness level of the appetizer.
 */
int Appetizer::getSpicinessLevel() const {
    return spiciness_level_;
}

/**
 * Sets the vegetarian flag of the appetizer.
 * @param vegetarian A boolean indicating if the appetizer is vegetarian.
 * @post Sets the private member `vegetarian_` to the value of the parameter.
 */
void Appetizer::setVegetarian(const bool &vegetarian) {
    vegetarian_ = vegetarian;
}

/**
 * @return True if the appetizer is vegetarian, false otherwise.
 */
bool Appetizer::isVegetarian() const {
    return vegetarian_;
}





   /**
    * Displays the appetizer's details.
    * @post Outputs the appetizer's details, including name, ingredients,
    preparation time, price, cuisine type, serving style, spiciness level, and
    vegetarian status, to the standard output.
    * The information must be displayed in the following format:
    *
    * Dish Name: [Name of the dish]
    * Ingredients: [Comma-separated list of ingredients]
    * Preparation Time: [Preparation time] minutes
    * Price: $[Price, formatted to two decimal places]
    * Cuisine Type: [Cuisine type]
    * Serving Style: [Serving style: Plated, Family Style, or Buffet]
    * Spiciness Level: [Spiciness level]
    * Vegetarian: [Yes/No]
    */
void Appetizer::display(){
    std::cout << "Dish Name: " << getName()  <<  std::endl <<
    "Ingredients: " << IngredientsHelper(getIngredients()) << std::endl <<
    "Preparation Time: " << getPrepTime() << " minutes" << std::endl <<
    "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl << 
    "Cuisine Type: " << getCuisineType() << std::endl <<
    "Serving Style: " << ServingString(getServingStyle()) << std::endl <<
    "Spiciness Level: " << spiciness_level_ << std::endl <<
    "Vegetarian: " << (isVegetarian() ? "Yes" : "No") << std::endl;
    


}



/**
* Modifies the appetizer based on dietary accommodations.
* @param request A DietaryRequest structure specifying the dietary
accommodations.
* @post Adjusts the appetizer's attributes to meet the specified
MainCourse Class
dietary needs.
* - If `request.vegetarian` is true:
* - Sets `vegetarian_` to true.
* - Searches `ingredients_` for any non-vegetarian
ingredients and replaces the first occurrence with "Beans". If there are
other non-vegetarian ingredients, the next non-vegetarian ingredient is
replaced with "Mushrooms". If there are more, they will be removed
without substitution.
* Non-vegetarian ingredients are: "Meat", "Chicken",
"Fish", "Beef", "Pork", "Lamb", "Shrimp", "Bacon".
* - If `request.low_sodium` is true:
* - Reduces `spiciness_level_` by 2 (minimum of 0).
* - If `request.gluten_free` is true:
* - Removes gluten-containing ingredients from
`ingredients_`.
* Gluten-containing ingredients are: "Wheat", "Flour",
"Bread", "Pasta", "Barley", "Rye", "Oats", "Crust".
*/
void Appetizer::dietaryAccommodations(const DietaryRequest& request)  {
    std::vector<std::string> ingredList = getIngredients();
    int count = 0;
    if (request.vegetarian) {
        vegetarian_ = true;
        for (int i = 0; i < ingredList.size();i++) {
            if (ingredList[i] == "Meat" || ingredList[i] == "Chicken" || ingredList[i] == "Fish"
            || ingredList[i] == "Beef" || ingredList[i] == "Pork" || ingredList[i] == "Lamb"
            || ingredList[i] == "Shrimp" || ingredList[i] == "Bacon") {
                if (count == 0) {
                    ingredList[i] = "Beans";
                }
                else if (count == 1 ) {
                    ingredList[i] = "Mushrooms";
                }
                else if (count > 1 ) {
                    ingredList.erase(ingredList.begin() + i); 
                    i--;
                }
                count++;
            }
        }
        setIngredients(ingredList);

    }
    if (request.low_sodium) {
        spiciness_level_ -= 2;
        if (spiciness_level_ < 0) {
            spiciness_level_ = 0;
        }

    }
    if (request.gluten_free) {
        for (int i = 0; i < ingredList.size();i++) {
             if (ingredList[i] == "Wheat" || ingredList[i] == "Flour" || ingredList[i] == "Bread"
            || ingredList[i] == "Pasta" || ingredList[i] == "Barley" || ingredList[i] == "Oats"
            || ingredList[i] == "Rye" || ingredList[i] == "Crust") {
                ingredList.erase(ingredList.begin()+i);
                i--;
            }

        }
        setIngredients(ingredList);

    }
}





//A helper function that returns the string version of the Serving type of the dish
//@pre The passed in value have to be an  enum value in enum ServingStyle in the
//Appetizer class
//@param const Appetizer::ServingStyle& m, a enum value in ServingStyle that describes the
//Serving style the Appetizer food is in and ensure the value remain unchanged.
//@return returns a string
//@post returns a string version of the options in enum ServingStyle in the Appetizer
//class
std::string ServingString(const Appetizer::ServingStyle& m) {
      switch(m) {
        case Appetizer::ServingStyle::PLATED:
        return "Plated";
        case Appetizer::ServingStyle::FAMILY_STYLE:
        return "Family Style";
        case Appetizer::ServingStyle::BUFFET:
        return "Buffet";
        default:
        return "UNKNOWN";
      }
}

std::string IngredientsHelper(const std::vector<std::string>& g) {
    std::string ingredList;
    for (int i = 0; i < g.size(); i++) {
        if (i != 0) {
            ingredList += ", "; 
        }
        ingredList += g[i];
    }
    return ingredList;
}
