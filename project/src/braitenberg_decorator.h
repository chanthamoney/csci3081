
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

    void TimestepUpdate(__unused unsigned int dt) override {
      if ( predator_ != NULL) {
        set_pose(predator_->get_pose());

        if(dynamic_food_behavior_ == nullptr){
          dynamic_food_behavior_ = getRandomBehavior();
          // dynamic_food_behavior_ = new None();
        }
        if(dynamic_light_behavior_ == nullptr) {
          dynamic_light_behavior_ = getRandomBehavior();
          // dynamic_light_behavior_ = new None();
        }

        dynamic_bv_behavior_ = new Aggressive();
        set_bv_behavior(dynamic_bv_behavior_);
        set_food_behavior(dynamic_food_behavior_);
        set_light_behavior(dynamic_light_behavior_);
        set_no_disguise(false);
        BraitenbergVehicle::UpdateLightSensors();
         //
         double pred_light_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_light_entity());
         double pred_light_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_light_entity());

         double pred_food_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_food_entity());
         double pred_food_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_food_entity());

         double pred_bv_left_sensor_reading = predator_->get_sensor_reading_left(predator_->get_closest_bv_entity());
         double pred_bv_right_sensor_reading = predator_->get_sensor_reading_right(predator_->get_closest_bv_entity());
         // std::cout << "LEFT BV SENSOR DEC" << pred_bv_left_sensor_reading << std::endl;
         // std::cout << "RIGHT BV SENSOR " << pred_bv_right_sensor_reading << std::endl;
         // std::cout << "LEFT FOOD SENSOR " << pred_food_left_sensor_reading << std::endl;
         // std::cout << "RIGHT FOOD SENSOR " << pred_food_right_sensor_reading << std::endl;
         // std::cout << "LEFT LIGHT SENSOR " << pred_light_left_sensor_reading << std::endl;
         // std::cout << "RIGHT LIGHT SENSOR " << pred_light_right_sensor_reading << std::endl;
         set_bv_left_sensor_reading(pred_bv_left_sensor_reading);
         set_bv_right_sensor_reading(pred_bv_right_sensor_reading);
         set_food_left_sensor_reading(pred_food_left_sensor_reading);
         set_food_right_sensor_reading(pred_food_right_sensor_reading);
         set_light_left_sensor_reading(pred_light_left_sensor_reading);
         set_light_right_sensor_reading(pred_light_right_sensor_reading);

       //   if (dynamic_bv_behavior_->getBehaviorType() == "Aggressive") {
       //     std::cout << "I am angry bv" << std::endl;
       //   }
       //
       //   if (dynamic_food_behavior_->getBehaviorType() == "Coward") {
       //     std::cout << "I am coward food" << std::endl;
       //   }
       //
       //   if (dynamic_food_behavior_->getBehaviorType() == "Aggressive") {
       //     std::cout << "I am angry food" << std::endl;
       //   }
       //
       //   if (dynamic_food_behavior_->getBehaviorType() == "Explore") {
       //     std::cout << "I am explore food" << std::endl;
       //
       //   }
       //
       //  if (dynamic_food_behavior_->getBehaviorType() == "Love") {
       //    std::cout << "I am Love food" << std::endl;
       //
       //  }
       //
       //   if (dynamic_food_behavior_->getBehaviorType() == "None") {
       //     std::cout << "I am none food" << std::endl;
       //   }
       //
       //   if (dynamic_light_behavior_->getBehaviorType() == "Coward") {
       //     std::cout << "I am coward light" << std::endl;
       //   }
       //
       //   if (dynamic_light_behavior_->getBehaviorType() == "Aggressive") {
       //     std::cout << "I am angry light" << std::endl;
       //   }
       //
       //   if (dynamic_light_behavior_->getBehaviorType() == "Explore") {
       //     std::cout << "I am explore light" << std::endl;
       //
       //   }
       //
       //  if (dynamic_light_behavior_->getBehaviorType() == "Love") {
       //    std::cout << "I am Love light" << std::endl;
       //
       //  }
       //
       // if (dynamic_light_behavior_->getBehaviorType() == "None") {
       //   std::cout << "I am none light" << std::endl;
       // }

      BraitenbergVehicle::TimestepUpdate(1);
      predator_->set_color(BraitenbergVehicle::get_color());
      predator_->set_wv(BraitenbergVehicle::get_wv()); // TODO: ERROR I THINK IS IT STAYS ON THE LAST VELOCITY THAT IT HAD?
      predator_->set_pose(get_pose());

    }
  }

  Behaviors * getRandomBehavior() {
    std::cout <<"In Random Behavior" << std::endl;
    int randomNumber = random_num(0, 5);
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
  Behaviors * dynamic_bv_behavior_{nullptr};
  };

  NAMESPACE_END(csci3081);

#endif /* BRAITENBERG_DECORATOR_H_ */
