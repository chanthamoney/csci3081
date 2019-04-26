
#ifndef BRAITENBERG_DECORATOR_H_
#define BRAITENBERG_DECORATOR_H_

#include <iostream>
#include <string>

#include "src/braitenberg_vehicle.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class BvDecorator : public BraitenbergVehicle {
  public:
    BvDecorator() {}
    BvDecorator(Predator *predator) : predator_(predator) {
       predator->set_color(BRAITENBERG_COLOR);
       predator->set_radius(DEFAULT_RADIUS);
       // predator->set_mobility(false);
       // predator->set_speed(0);
     }

    ~BvDecorator() {}

    /**
    *  @brief Deleting the copy constructor.
    */
    BvDecorator(const BvDecorator & rhs) = delete;
    /**
    *  @brief Deleting the copy assignment.
    */
    BvDecorator operator=(const BvDecorator & rhs) = delete;
    /**
     * @brief Get the name of the underlying arena entity
     *
     * @return Name of the entity.
     */
    std::string get_name() const override { return predator_->get_name(); }

    EntityType get_PredatorType() {
      return kPredator;
    }

    void Update() override {
      if ( predator_ != NULL) {
        WheelVelocity bv_wheel_velocity = WheelVelocity(0, 0);
        WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);
        WheelVelocity food_wheel_velocity = WheelVelocity(0, 0);

        // TODO: BV
        double light_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_light_entity());
        double light_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_light_entity());
        std::cout << "LIGHT LEFT " << light_left_sensor_reading << std::endl;
        std::cout << "LIGHT RIGHT " << light_right_sensor_reading << std::endl;

        double food_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_food_entity());
        double food_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_food_entity());

        double bv_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_bv_entity());
        double bv_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_bv_entity());


        if(dynamic_food_behavior_ == nullptr){
          dynamic_food_behavior_ = getRandomBehavior();
        }
        if(dynamic_light_behavior_ == nullptr) {
          dynamic_light_behavior_ = getRandomBehavior();
        }


        Behaviors * dynamic_bv_behavior = new None();

        if (dynamic_food_behavior_->getBehaviorType() == "Coward") {
          std::cout << "I am coward" << std::endl;
        }

        if (dynamic_food_behavior_->getBehaviorType() == "Aggressive") {
          std::cout << "I am angry" << std::endl;
        }

        // Behaviors * dynamic_light_behavior = randomBehaviorBv();

        dynamic_bv_behavior->getWheelVelocity(bv_left_sensor_reading,
                                               bv_right_sensor_reading,
                                               5,
                                               &bv_wheel_velocity);
        dynamic_light_behavior_->getWheelVelocity(light_left_sensor_reading,
                                                 light_right_sensor_reading,
                                                 5,
                                                 &light_wheel_velocity);
        dynamic_food_behavior_->getWheelVelocity(food_left_sensor_reading,
                                              food_right_sensor_reading,
                                              5,
                                              &food_wheel_velocity);


      // FOOD, LIGHT, BV
      // NNN, NNS, NSN, NSS, SNN, SNS, SSS
      bool light_behavior_set, food_behavior_set, bv_behavior_set;
      light_behavior_set = dynamic_light_behavior_->getBehaviorType() != "None";
      food_behavior_set = dynamic_food_behavior_->getBehaviorType() != "None";
      bv_behavior_set = dynamic_bv_behavior->getBehaviorType() != "None";

      if (!light_behavior_set && food_behavior_set) {
        predator_->set_color({0, 0, 255});

        if (bv_behavior_set) {
        predator_->set_wv(WheelVelocity(
            (bv_wheel_velocity.left + food_wheel_velocity.left)/2,
            (bv_wheel_velocity.right + food_wheel_velocity.right)/2,
            5));
        } else {
          predator_->set_wv(WheelVelocity(
            food_wheel_velocity.left, food_wheel_velocity.right, 5));
        }
        // if the BV has the light sensor on but not the food sensor
      } else if (light_behavior_set && !food_behavior_set) {
        predator_->set_color({255, 204, 51});

        if (bv_behavior_set) {
          predator_->set_wv(WheelVelocity(
            (light_wheel_velocity.left + bv_wheel_velocity.left)/2,
            (light_wheel_velocity.right + bv_wheel_velocity.right)/2,
            5));
        } else {
        predator_->set_wv(WheelVelocity(
            light_wheel_velocity.left, light_wheel_velocity.right, 5));
        }
        // if the BV has the light sensor and food sensor on
      } else if (light_behavior_set && food_behavior_set) {
        predator_->set_color({122, 0, 25});

        if (bv_behavior_set) {
          predator_->set_wv(WheelVelocity(
            (light_wheel_velocity.left + food_wheel_velocity.left +
               bv_wheel_velocity.left)/3,
            (light_wheel_velocity.right + food_wheel_velocity.right +
               bv_wheel_velocity.right)/3,
            5));
        } else {
          predator_->set_wv(WheelVelocity(
            (light_wheel_velocity.left + food_wheel_velocity.left)/2,
            (light_wheel_velocity.right + food_wheel_velocity.right)/2,
            5));
        }
        // if the BV has no sensors on or just the robot behavior sensor
      } else {
        predator_->set_color({122, 0, 25});

        if (bv_behavior_set) {
          predator_->set_wv(WheelVelocity(bv_wheel_velocity.left,
            bv_wheel_velocity.right, 5));
        } else {
          predator_->set_wv(WheelVelocity(0, 0, 5));
        }
      }

     }

  }

  Behaviors * getRandomBehavior() {
    std::cout <<"In Random Behavior" << std::endl;
    int randomNumber = random_num(0, 4);
    Behaviors * newBehavior;
    if (randomNumber == 0) {
      std::cout <<"In Random Behavior" << std::endl;
      newBehavior = new Aggressive();
    }
    else if (randomNumber == 1) {
      newBehavior = new Coward();
    }
    else if (randomNumber == 2) {
      newBehavior = new Explore();
    }
    else if (randomNumber == 3) {
      newBehavior = new Love();
    }
    else {
      std::cout <<"In Random Behavior" << std::endl;
      newBehavior = new None();
    }
    return newBehavior;
  }

  private:
  Predator* predator_{nullptr};
  Behaviors * dynamic_food_behavior_{nullptr};
  Behaviors * dynamic_light_behavior_{nullptr};
  };

  NAMESPACE_END(csci3081);

#endif /* BRAITENBERG_DECORATOR_H_ */
