#include <iostream>

#include "object.h"
#include "derived.h"
#include "composed.h"

using std::cout;
using std::endl;

int main() {

  cout << endl;

<<<<<<< HEAD
  // ObjectClass base_object_default;
  // cout << "Base default: ";
  // base_object_default.Print();
  //
  // cout << endl;
  // ObjectClass base_object_2_3(2,3);
  // cout << "Base 2,3 : ";
  // base_object_2_3.Print();
  //
  // cout << endl;
  // ComposedClass hasa_object_default;
  // cout << "Composed default : ";
  // hasa_object_default.Print();
  //
  // cout << endl;
  // DerivedClass isa_object_default;
  // cout << "Derived default : ";
  // isa_object_default.Print();
  //
  //
  // cout << endl;
  // DerivedClass isa_object_4_5(4,5); //can't call object.h constructor from a dervied class ojb
  // cout << "Derived 4,5 : ";
  // isa_object_4_5.Print();


    cout << endl;
    DerivedClass isa_object_4_5(4,5,6,7); //can't call object.h constructor from a dervied class ojb
    cout << "Derived : ";
    isa_object_4_5.Print();

=======
  ObjectClass base_object_default;
  cout << "Base default: ";
  base_object_default.Print();

  cout << endl;
  ObjectClass base_object_2_3(2,3);
  cout << "Base 2,3 : ";
  base_object_2_3.Print();

  cout << endl;
  ComposedClass hasa_object_default;
  cout << "Composed default : ";
  hasa_object_default.Print();

  cout << endl;
  DerivedClass isa_object_default;
  cout << "Derived default : ";
  isa_object_default.Print();

  /*
  cout << endl;
  DerivedClass isa_object_4_5(4,5);
  cout << "Derived 4,5 : ";
  isa_object_4_5.Print();
  */
>>>>>>> support-code

  return 1;
}
