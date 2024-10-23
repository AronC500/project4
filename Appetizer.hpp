#ifndef APPETIZER_HPP
#define APPETIZER_HPP

#include "Dish.hpp"
#include <string>
#include <iomanip> //For std::setprecision and std::fixed


/**
 * @class Appetizer
 * @brief Represents an appetizer dish, inheriting from Dish.
 */
class Appetizer : public Dish {
public:
    /**
     * @enum ServingStyle
     * @brief Describes how the appetizer is served.
     */
    enum ServingStyle { PLATED, FAMILY_STYLE, BUFFET };

    /**
     * Default constructor.
     * Initializes all private members with default values.
     */
    Appetizer();

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
    Appetizer(const std::string& name, const std::vector<std::string>& ingredients, const int &prep_time, const double &price, const CuisineType &cuisine_type, const ServingStyle &serving_style, const int &spiciness_level, const bool &vegetarian);

    /**
     * Sets the serving style of the appetizer.
     * @param serving_style The new serving style.
     * @post Sets the private member `serving_style_` to the value of the parameter.
     */
    void setServingStyle(const ServingStyle &serving_style);

    /**
     * @return The serving style of the appetizer.
     */
    ServingStyle getServingStyle() const;

    /**
     * Sets the spiciness level of the appetizer.
     * @param spiciness_level An integer representing the spiciness level of the appetizer.
     * @post Sets the private member `spiciness_level_` to the value of the parameter.
     */
    void setSpicinessLevel(const int &spiciness_level);

    /**
     * @return The spiciness level of the appetizer.
     */
    int getSpicinessLevel() const;

    /**
     * Sets the vegetarian flag of the appetizer.
     * @param vegetarian A boolean indicating if the appetizer is vegetarian.
     * @post Sets the private member `vegetarian_` to the value of the parameter.
     */
    void setVegetarian(const bool &vegetarian);

    /**
     * @return True if the appetizer is vegetarian, false otherwise.
     */
    bool isVegetarian() const;

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
  void display() const override;


private:
    ServingStyle serving_style_; ///< The serving style of the appetizer.
    int spiciness_level_; ///< The spiciness level of the appetizer.
    bool vegetarian_; ///< Flag indicating if the appetizer is vegetarian.
};

#endif // APPETIZER_HPP