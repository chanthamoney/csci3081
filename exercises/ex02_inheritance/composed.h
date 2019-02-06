#ifndef COMPOSED_H_
#define COMPOSED_H_

#include "object.h"
using std::cout;
using std::endl;

class ComposedClass {
public:
  void Print() {
    cout << "in ComposedClass... " << endl;
    cout << "var_a_ " << var_a_ << endl; //compiles it give you random no intialize
    cout << "var_b_ " << var_b_ << endl; //compiles it give you random no intialize
    cout << "object var_a_ " << object_.getVarA() << endl;
    cout << "object var_b_ " << object_.getVarB() << endl;
    object_.Print();
  }
protected:
  int var_b_;
private:
  ObjectClass object_;
  int var_a_;
};

#endif
