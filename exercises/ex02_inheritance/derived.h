#ifndef DERIVED_H_
#define DERIVED_H_

#include "object.h"

using std::cout;
using std::endl;
//To inherit you need to have default
class DerivedClass : public ObjectClass {
public:
  DerivedClass(int a, int b, int derviedA, int derviedB) {
    var_a_ = derviedA;
    var_b_ = derviedB;
    ObjectClass::var_b_ = b;
    setVarA(a);
  }
  void Print() {
    cout << "in DerivedClass... " << endl;
    cout << "var_a_ " << var_a_ << endl;
    cout << "var_b_ " << var_b_ << endl; // 0 refers to int var_b_ in  the dervied class
    cout << "object var_a_ " << getVarA() << endl;
    cout << "object var_b_ " << ObjectClass::var_b_ << endl;
    ObjectClass::Print();
  }
private:
  int var_a_;
  int var_b_;
};

#endif
