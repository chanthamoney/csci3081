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
// We use template as cookie cutter for different subject types
// ABSTRACT CLASS SHOULD NOT HAVE KNOWLEDGE OF SPECFIC INFORMAITON
#include <iostream>
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <class T>
class Observer {
 public:
  virtual ~Observer() = default;
  virtual void UpdateState(const T* arg) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSERVER_H_
