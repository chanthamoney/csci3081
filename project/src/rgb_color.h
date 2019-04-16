/**
 * @file rgb_color.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_RGB_COLOR_H_
#define SRC_RGB_COLOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>

#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

enum RgbColorEnum {
  kRed,
  kGreen,
  kBlue,
  kYellow,
  kOrange,
  kPurple,
  kWhite,
  kBlack,
  kMaroon,
  kGold
};

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * @brief Struct representing a rgb_color.
 *
 * Internally uses RGBA values to represent the rgb_color.
 */
struct RgbColor {
 public:
   /**
    * @brief The r component Rgb
    */
  int r{0};
  /**
      * @brief The g component Rgb
   */
  int g{0};
  /**
    * @brief The g component Rgb
   */
  int b{0};
  /**
   * @brief The opacity component (a) of Rgba
   */
  int a{255};

  /**
   * @brief Default constructor.
   *
   * Initialize RGB all to 0 (kWhite).
   */
  RgbColor() {}

  /**
   * @brief Constructor for Rgb_Color.
   *
   * @param r_in The R component of the rgb_color.
   * @param g_in The G component of the rgb_color.
   * @param b_in The B component of the rgb_color.
   */
  RgbColor(int r_in, int g_in, int b_in) : r(r_in), g(g_in), b(b_in) {
    a = 255;
  }
  /**
   * @brief Constructor for Rgb_Color.
   *
   * @param r_in The R component of the rgb_color.
   * @param g_in The G component of the rgb_color.
   * @param b_in The B component of the rgb_color.
   * @param a_in The A component of the rgb_color (a is opacity)
   */
  RgbColor(int r_in, int g_in, int b_in, int a_in) : r(r_in), g(g_in), b(b_in),
  a(a_in) {
  }
  /**
   * @brief Takes in a predefined color and sets the values to the appropriate color
   * and the opacity is full
   *
   * @param[in] value A RgbColorEnum value
   */
  explicit RgbColor(RgbColorEnum value) : r(0), g(0), b(0), a(255) {
    Set(value);
  }

  void Set(RgbColorEnum value);
  /**
   * @brief Overriding the equals operator
   *
   * @param color The color with type Rgb
   *
   * @return The boolean value of RGB and it's component r, g, b, and a
   */
  bool operator==(const RgbColor& color) const {
    return r == color.r && g == color.g && b == color.b && a == color.a;
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_RGB_COLOR_H_
