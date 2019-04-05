/**
 * @file observer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef OBSERVER_H_
#define OBSERVER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
// We use template as cookie cutter for different subject types
//ABSTRACT CLASS SHOULD NOT HAVE KNOWLEDGE OF SPECFIC INFORMAITON
#include <iostream>

NAMESPACE_BEGIN(csci3081);

template <class T>
class Observer {
public:
  virtual ~Observer() = default;
  virtual void Notify(const T* arg) = 0;

};

NAMESPACE_END(csci3081);

#endif
