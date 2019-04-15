/**
 * @file observer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief A template Observer class for observing a subject
  * The observer for the observing pattern
  * The class is used as a cookie cutter for different types of obsevers
  */
template <class T>
class Observer {
 public:
   /**
   *  @brief Observer Deconstructor.
   */
  virtual ~Observer() = default;
  /**
  *  @brief UpdateState observes a type T attribute of the subject
  *
  *  @param[in] arg The pointer of arg of some type T
  *
  *  @return The updated value for the pointer of arg of type T
  */
  virtual void UpdateState(const T* arg) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSERVER_H_
