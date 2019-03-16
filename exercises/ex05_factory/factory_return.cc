#include <iostream>
#include <cmath>

#include "factory_return.h"

FactoryReturn::FactoryReturn(int etype){
  Robot * robot[2];
  robot[0] = new Robot(etype);
  robot[1] = new Robot(etype);

}

FactoryReturn::Create(){
  if(etype == 2)
  {
    //two legged
  }
  //default is plain robot
}
