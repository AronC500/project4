#include "MainCourse.hpp"

/**
 * Default constructor.
 * Initializes all private members with default values.
 */
MainCourse::MainCourse()
    : Dish(), cooking_method_(GRILLED), protein_type_("UNKNOWN"), side_dishes_(), gluten_free_(false) {}

/**
 * Parameterized constructor.
 * @param name The name of the main course.
 * @param ingredients The ingredients used in the main course.
 * @param prep_time The preparation time in minutes.
 * @param price The price of the main course.
 * @param cuisine_type The cuisine type of the main course.
 * @param cooking_method The cooking method used for the main course.
 * @param protein_type The type of protein used in the main course.
 * @param side_dishes The side dishes served with the main course.
 * @param gluten_free Flag indicating if the main course is gluten-free.
 */
MainCourse::MainCourse(const std::string& name, const std::vector<std::string>& ingredients, const int &prep_time, const double &price, const CuisineType &cuisine_type, const CookingMethod &cooking_method, const std::string& protein_type, const std::vector<SideDish>& side_dishes, const bool &gluten_free)
    : Dish(name, ingredients, prep_time, price, cuisine_type), cooking_method_(cooking_method), protein_type_(protein_type), side_dishes_(side_dishes), gluten_free_(gluten_free) {}

/**
 * Sets the cooking method of the main course.
 * @param cooking_method The new cooking method.
 * @post Sets the private member `cooking_method_` to the value of the parameter.
 */
void MainCourse::setCookingMethod(const CookingMethod &cooking_method) {
    cooking_method_ = cooking_method;
}

/**
 * @return The cooking method of the main course.
 */
MainCourse::CookingMethod MainCourse::getCookingMethod() const {
    return cooking_method_;
}

/**
 * Sets the type of protein in the main course.
 * @param protein_type A string representing the type of protein.
 * @post Sets the private member `protein_type_` to the value of the parameter.
 */
void MainCourse::setProteinType(const std::string& protein_type) {
    protein_type_ = protein_type;
}

/**
 * @return The type of protein in the main course.
 */
std::string MainCourse::getProteinType() const {
    return protein_type_;
}

/**
 * Adds a side dish to the main course.
 * @param side_dish A SideDish struct containing the name and category of the side dish.
 * @post Adds the side dish to the `side_dishes_` vector.
 */
void MainCourse::addSideDish(const SideDish& side_dish) {
    side_dishes_.push_back(side_dish);
}

/**
 * @return A vector of SideDish structs representing the side dishes served with the main course.
 */
std::vector<MainCourse::SideDish> MainCourse::getSideDishes() const {
    return side_dishes_;
}

/**
 * Sets the gluten-free flag of the main course.
 * @param gluten_free A boolean indicating if the main course is gluten-free.
 * @post Sets the private member `gluten_free_` to the value of the parameter.
 */
void MainCourse::setGlutenFree(const bool &gluten_free) {
    gluten_free_ = gluten_free;
}

/**
 * @return True if the main course is gluten-free, false otherwise.
 */
bool MainCourse::isGlutenFree() const {
    return gluten_free_;
}






    /**
* Displays the main course's details.
* @post Outputs the main course's details, including name, ingredients,
preparation time, price, cuisine type, cooking method, protein type,
side dishes, and gluten-free status to the standard output.
* The information must be displayed in the following format:
*
* Dish Name: [Name of the dish]
* Ingredients: [Comma-separated list of ingredients
* Preparation Time: [Preparation time] minutes
* Price: $[Price, formatted to two decimal places]
* Cuisine Type: [Cuisine type]
* Cooking Method: [Cooking method: e.g., Grilled, Baked, etc.]
* Protein Type: [Type of protein: e.g., Chicken, Beef, etc.]
* Side Dishes: [Side dish name] (Category: [Category: e.g., Starches,
Vegetables])
* Gluten-Free: [Yes/No]
*/

void MainCourse::display() const {
    std::cout << "Dish Name: " << getName() << std::endl <<
    "Ingredients: " << IngredientsHelper(getIngredients()) << std::endl <<
    "Preparation Time: " << getPrepTime() << " minutes" << std::endl <<
    "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl << 
    "Cuisine Type: " << getCuisineType() << std::endl <<
    "Cooking Method: " << CookingString(getCookingMethod()) << std::endl <<
    "Protein Type: " << getProteinType() << std::endl <<
    "Side Dishes: " << outputSides(getSideDishes()) << std::endl <<
    "Gluten-Free: " << (isGlutenFree() ? "Yes" : "No") << std::endl;
    
}



/**
* Modifies the main course based on dietary accommodations.
* @param request A DietaryRequest structure specifying the dietary
accommodations.
* @post Adjusts the main course's attributes to meet the specified
dietary needs.
* - If `request.vegetarian` is true:
* - Changes `protein_type_` to "Tofu".
* - Searches `ingredients_` for any non-vegetarian
ingredients and replaces the first occurrence with "Beans". If there are
other non-vegetarian ingredients, the next non-vegetarian ingredient is
replaced with "Mushrooms". If there are more, they will be removed
without substitution.
* Non-vegetarian ingredients are: "Meat", "Chicken",
"Fish", "Beef", "Pork", "Lamb", "Shrimp", "Bacon".
* - If `request.vegan` is true:
* - Changes `protein_type_` to "Tofu".
* - Removes dairy and egg ingredients from `ingredients_`.
* Dairy and egg ingredients are: "Milk", "Eggs", "Cheese",
"Butter", "Cream", "Yogurt".
* - If `request.gluten_free` is true:
* - Sets `gluten_free_` to true.
* - Removes side dishes from `side_dishes_` whose category
involves gluten.
* Gluten-containing side dish categories are: `GRAIN`,
`PASTA`, `BREAD`, `STARCHES`.
*/
void MainCourse::dietaryAccommodations(const DietaryRequest& request)  {
    std::vector<std::string> ingredList = getIngredients();
    int count = 0;
    if (request.vegetarian) {
        protein_type_ = "Tofu";
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
    if (request.vegan) {
        protein_type_ = "Tofu";
        for (int i = 0; i < ingredList.size();i++) {
             if (ingredList[i] == "Milk" || ingredList[i] == "Eggs" || ingredList[i] == "Cheese"
            || ingredList[i] == "Butter" || ingredList[i] == "Cream" || ingredList[i] == "Yogurt") {
                ingredList.erase(ingredList.begin()+i);
                i--;
            }

        }
        setIngredients(ingredList);


    }
    if (request.gluten_free) {
        gluten_free_ = true;
        for (int i = 0; i < side_dishes_.size();i++) {
             if (side_dishes_[i].category == Category::GRAIN || side_dishes_[i].category == Category::PASTA ||
             side_dishes_[i].category == Category::BREAD || side_dishes_[i].category == Category::STARCHES) {
                    side_dishes_.erase(side_dishes_.begin()+i);
                    i--;
                }
            }


        }



    
}


//A helper function that returns the string version of the Cooking Method of the
//dish
//@pre The passed in value have to be an  enum value in enum CookingMethod in the 
//Main Course class
//@param const MainCourse::CookingMethod& m, a enum value in CookingMethod that describes the 
//Cooking Method that is used  for the Main Course and ensures the value remain unchanged.
//@return returns a string
//@post returns a string version of the options in enum CookingMethod  in the Main Course
//class
std::string CookingString(const MainCourse::CookingMethod& m) {
      switch(m) {
        case MainCourse::CookingMethod::GRILLED:
        return "Grilled";
        case MainCourse::CookingMethod::RAW:
        return "Raw";
         case MainCourse::CookingMethod::STEAMED:
        return "Steamed";
        case MainCourse::CookingMethod::FRIED:
        return "Fried";
        case MainCourse::CookingMethod::BAKED:
        return "Baked";
        default:
        return "UNKNOWN";
      }
    
}


//A helper function that returns a string of sideDishes with their categories 
//in the right format separated by commas.
//@pre The passed in value have to be an object of the class MainCourse
//@param const MainCourse& mai ensures the passed in value is not changed and 
//an MainCourse object used is to get it's specific .getSideDishes() return values.
//@return A string cointaining all the sidedishes of const MainCourse& mai.
//@post A string containing either an empty string or an string with all the 
//sidedishes with their category with each sidedishes being separated by
//an comma if not empty.
std::string outputSides(const std::vector<MainCourse::SideDish>& mai) {
  std::string sidestring = "";
    for (int i = 0; i < mai.size();i++) {
            sidestring += mai[i].name + " (Category: " + categoryString(mai[i].category) + ")";
            if (i < mai.size() - 1) {
                sidestring += ", "; 
            }
    }
    return sidestring;
}


//A helper function that returns the string version of the category type of the dish
//@pre The passed in value have to be an  enum value in enum Category in the Main Course
//class
//@param const MainCourse::Category& g, a enum value in Category that describes the category
//the MainCourse food is in and ensure the value remain unchanged.
//@return returns a string
//@post returns a string version of the options in enum Category in the Main Course
//class
std::string categoryString(const MainCourse::Category& g) {
    switch(g) {
        case MainCourse::Category::GRAIN:
        return "Grain";
        case MainCourse::Category::PASTA:
        return "Pasta";
        case MainCourse::Category::LEGUME:
        return "Legume";
        case MainCourse::Category::BREAD:
        return "Bread";
        case MainCourse::Category::SALAD:
        return "Salad";
        case MainCourse::Category::SOUP:
        return "Soup";
        case MainCourse::Category::STARCHES:
        return "Starches";
        case MainCourse::Category::VEGETABLE:
        return "Vegetable";
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


