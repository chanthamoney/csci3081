/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include <iostream>

#include "src/graphics_arena_viewer.h"
#include "src/rgb_color.h"
#include "src/braitenberg_vehicle.h"
#include "src/behaviors.h"
#include "src/behavior_enum.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/love.h"
#include "src/explore.h"
#include "src/none.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(
    int width, int height,
    Controller * controller) :
    GraphicsApp(
        width + GUI_MENU_WIDTH + GUI_MENU_GAP * 2,
        height + 150,
        "Robot Simulation"),
    controller_(controller),
    arena_(nullptr),
    xOffset_(0),
    nanogui_intialized_(false),
    gui(nullptr),
    window() {
      xOffset_ = GUI_MENU_WIDTH + GUI_MENU_GAP;
}

void GraphicsArenaViewer::InitNanoGUI() {
    if (!nanogui_intialized_) {
      gui = new nanogui::FormHelper(screen());
    } else {
      window->dispose();
    }

    window =
          gui->addWindow(
              // Eigen::Vector2i(window_width()
              // - GUI_MENU_WIDTH - GUI_MENU_GAP * 2, 0),
              Eigen::Vector2i(0, 0),
              "Menu");
    window->setFixedWidth(GUI_MENU_WIDTH);
    window->setLayout(new nanogui::GroupLayout());

    // Creating a panel impacts the layout. Widgets, sliders, buttons can be
    // assigned to either the window or the panel.

    nanogui::Widget *panel = new nanogui::Widget(window);
    panel->setLayout(new nanogui::BoxLayout(
      nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 0));
    // *************** Add GUI ************************//

    AddEntityPanel(window);

    panel = new nanogui::Widget(window);
    panel->setLayout(new nanogui::BoxLayout(
      nanogui::Orientation::Vertical, nanogui::Alignment::Middle, 0, 0));
    // Lays out all the components with "15" units of inbetween spacing
    // panel->setLayout(new nanogui::BoxLayout(
    //  nanogui::Orientation::Vertical,nanogui::Alignment::Middle, 0, 15));

    new nanogui::Label(window, "Game Control", "sans-bold");
    playing_button_ =
      gui->addButton(
        "Play",
        std::bind(&GraphicsArenaViewer::OnPlayingBtnPressed, this));
    reset_button_ =
      gui->addButton(
        "Reset",
        std::bind(&GraphicsArenaViewer::OnResetButtonPressed, this));
    screen()->performLayout();

    nanogui_intialized_ = true;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
  if (!paused_) {
    controller_->AdvanceTime(dt);
  }
}

int GraphicsArenaViewer::getIndexOfBehavior(const std::string& type) {
  if (type == "Aggressive") {
    return 1;
  }
  if (type == "Love") {
    return 4;
  }
  if (type == "Coward") {
    return 2;
  }
  if (type == "Explore") {
    return 3;
  }
  return 0;
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnPlayingBtnPressed() {
  if (!paused_) {
    playing_button_->setCaption("Play");
    paused_ = true;
  } else {
    playing_button_->setCaption("Pause");
    paused_ = false;
  }
}

void GraphicsArenaViewer::OnResetButtonPressed() {
  paused_ = true;
  playing_button_->setCaption("Play");
  controller_->Reset();
}

void GraphicsArenaViewer::SetArena(Arena *arena) {
  arena_ = arena;
  selected_entity = arena_->get_entities()[0];
  if (selected_entity->get_type() == kBraitenberg) {
    static_cast<BraitenbergVehicle*>(selected_entity)->RegisterObserver(this);
  }
  if (nanogui_intialized_) {
    InitNanoGUI();
  }
}


/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/
void GraphicsArenaViewer::DrawArena(NVGcontext *ctx) {
  nvgBeginPath(ctx);
  // Creates new rectangle shaped sub-path.
  nvgRect(ctx, xOffset_, 0, arena_->get_x_dim(), arena_->get_y_dim());
  nvgStrokeColor(ctx, nvgRGBA(255, 255, 255, 255));
  nvgStroke(ctx);
}

void GraphicsArenaViewer::DrawEntity(NVGcontext *ctx,
                                       const ArenaEntity *const entity) {
  nvgBeginPath(ctx);
  float x = static_cast<float>(entity->get_pose().x);
  float y = static_cast<float>(entity->get_pose().y);
  float rad = static_cast<float>(entity->get_radius());
  // draw food with a radius of 5 less than actual radius. BraitenbergVehicles
  // will 'eat' when withing 5 radius of the food
  if (entity->get_type() == kFood) rad -= 5;

  nvgCircle(ctx, xOffset_ + x, y, rad);
  nvgFillColor(ctx,
               nvgRGBA(entity->get_color().r, entity->get_color().g,
                       entity->get_color().b, entity->get_color().a));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, entity->get_color().a));
  nvgStroke(ctx);
  nvgSave(ctx);
  // draw the sensors if the entity is a BraitenbergVehicle
  // the nvg calls are porobably not perfect, but we haven't been taught them
  /************************* DRAWING SENSORS *********************************/
  if (entity->get_type() == kBraitenberg) {
    int sensor_a_color = 255;
    if (entity->isDead()) {
      sensor_a_color = 90;
    }
    auto bv = static_cast<const BraitenbergVehicle * const>(entity);
    std::vector<Pose> sensors = bv->get_light_sensors_const();
    Pose left_sens_pose = sensors[0];
    Pose right_sens_pose = sensors[1];
    // left sensor drawing save the ctx twice, once for the circle and
    // once for the text
    nvgSave(ctx);
    nvgSave(ctx);
    nvgBeginPath(ctx);
    nvgCircle(ctx,
            xOffset_ + static_cast<float>(left_sens_pose.x),
            static_cast<float>(left_sens_pose.y),
            static_cast<float>(SENSOR_LIGHT_RAD));
    nvgFillColor(ctx, nvgRGBA(255, 0, 0, sensor_a_color));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);
    nvgRestore(ctx);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgRestore(ctx);
    nvgSave(ctx);
    nvgBeginPath(ctx);
    // right sensor drawing
    nvgCircle(ctx,
            xOffset_ + static_cast<float>(right_sens_pose.x),
            static_cast<float>(right_sens_pose.y),
            static_cast<float>(SENSOR_LIGHT_RAD));
    nvgFillColor(ctx, nvgRGBA(255, 0, 0, sensor_a_color));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);
    nvgRestore(ctx);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  } else if (entity->get_type() == kPredator) {
    auto pred = static_cast<const Predator * const>(entity);
    std::vector<Pose> sensors = pred->get_light_sensors_const();
    Pose left_sens_pose = sensors[0];
    Pose right_sens_pose = sensors[1];
    // left sensor drawing save the ctx twice, once for the circle and
    // once for the text
    nvgSave(ctx);
    nvgSave(ctx);
    nvgBeginPath(ctx);
    nvgCircle(ctx,
            xOffset_ + static_cast<float>(left_sens_pose.x),
            static_cast<float>(left_sens_pose.y),
            static_cast<float>(SENSOR_LIGHT_RAD));
    nvgFillColor(ctx, nvgRGBA(255, 0, 0, 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);
    nvgRestore(ctx);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgRestore(ctx);
    nvgSave(ctx);
    nvgBeginPath(ctx);
    // right sensor drawing
    nvgCircle(ctx,
            xOffset_ + static_cast<float>(right_sens_pose.x),
            static_cast<float>(right_sens_pose.y),
            static_cast<float>(SENSOR_LIGHT_RAD));
    nvgFillColor(ctx, nvgRGBA(255, 0, 0, 255));
    nvgFill(ctx);
    nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgStroke(ctx);
    nvgRestore(ctx);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  }
  /*********************** END DRAWING SENSORS *******************************/
  nvgRestore(ctx);
  // light id text label
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  std::string name = entity->get_name();
  nvgText(ctx,
          xOffset_ + static_cast<float>(entity->get_pose().x),
          static_cast<float>(entity->get_pose().y),
          name.c_str(), nullptr);
}

void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // initialize text rendering settings
  nvgFontSize(ctx, 18.0f);
  nvgFontFace(ctx, "sans-bold");
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  /*if (game_won_) {
    nvgTextBox(ctx, xOffset_ + 300, 300, 500, "WINNER", NULL);
  } else if (game_lost_) {
    nvgTextBox(ctx, xOffset_ + 300, 300, 500, "GAME OVER", NULL);
  }*/
  DrawArena(ctx);
  std::vector<ArenaEntity *> entities = arena_->get_entities();
  for (auto &entity : entities) {
    DrawEntity(ctx, entity);
  } /* for(i..) */
  // DrawRobot(ctx, arena_->robot());
}

void GraphicsArenaViewer::AddEntityPanel(nanogui::Widget * panel) {
  if (arena_->get_entities().size() == 0) {
    return;
  }

  ArenaEntity* defaultEntity = arena_->get_entities()[0];

  new nanogui::Label(panel, "Entity", "sans-bold");
  std::vector<ArenaEntity *> entities = arena_->get_entities();
  std::vector<std::string> entityNames;
  for (auto &entity : entities) {
    entityNames.push_back(entity->get_name());
  }
  nanogui::ComboBox* entitySelect = new nanogui::ComboBox(panel, entityNames);
  entitySelect->setFixedWidth(COMBO_BOX_WIDTH);


  nanogui::CheckBox* isMobile = new nanogui::CheckBox(panel, "Mobile");
  isMobile->setChecked(defaultEntity->is_mobile());
  isMobile->setVisible(defaultEntity->is_mobile());

  std::vector<std::string> behaviorNames;
  behaviorNames.push_back("Default");
  behaviorNames.push_back("Aggressive");
  behaviorNames.push_back("Coward");
  behaviorNames.push_back("Explore");
  behaviorNames.push_back("Love");

  std::vector<nanogui::Widget*> robotWidgets;

  robotWidgets.push_back(new nanogui::Label(
    panel, "Light Behavior", "sans-bold"));
  nanogui::Widget * robotPanel = new nanogui::Widget(panel);
  robotWidgets.push_back(robotPanel);
  robotPanel->setLayout(new nanogui::BoxLayout(
    nanogui::Orientation::Vertical, nanogui::Alignment::Minimum, 0, 0));
  nanogui::ComboBox* lightBehaviorSelect =
    new nanogui::ComboBox(robotPanel, behaviorNames);
  lightBehaviorSelect->setFixedWidth(COMBO_BOX_WIDTH -10);
  nanogui::Widget *space = new nanogui::Widget(robotPanel);
  nanogui::Widget * sliderPanel = new nanogui::Widget(robotPanel);
  space->setFixedHeight(10);
  sliderPanel->setLayout(
    new nanogui::BoxLayout(
      nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 0));
  nanogui::Widget *lbl = new nanogui::Label(
    sliderPanel, "Intensity", "sans-bold");
  lbl->setFixedWidth(50);
  nanogui::Slider *slider = new nanogui::Slider(sliderPanel);
  slider->setFixedWidth(90);
  space->setVisible(false);
  sliderPanel->setVisible(false);

  robotWidgets.push_back(new nanogui::Label(
    panel, "Food Behavior", "sans-bold"));
  robotPanel = new nanogui::Widget(panel);
  robotWidgets.push_back(robotPanel);
  robotPanel->setLayout(new nanogui::BoxLayout(
    nanogui::Orientation::Vertical, nanogui::Alignment::Minimum, 0, 0));
  nanogui::ComboBox* foodBehaviorSelect = new nanogui::ComboBox(
    robotPanel, behaviorNames);
  foodBehaviorSelect->setFixedWidth(COMBO_BOX_WIDTH -10);
  space = new nanogui::Widget(robotPanel);
  sliderPanel = new nanogui::Widget(robotPanel);
  space->setFixedHeight(10);
  sliderPanel->setLayout(
    new nanogui::BoxLayout(
      nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 0));
  lbl = new nanogui::Label(sliderPanel, "Intensity", "sans-bold");
  lbl->setFixedWidth(50);
  slider = new nanogui::Slider(sliderPanel);
  slider->setFixedWidth(90);
  space->setVisible(false);
  sliderPanel->setVisible(false);

  robotWidgets.push_back(new nanogui::Label(
    panel, "Braitenberg Behavior", "sans-bold"));
  robotPanel = new nanogui::Widget(panel);
  robotWidgets.push_back(robotPanel);
  robotPanel->setLayout(new nanogui::BoxLayout(
    nanogui::Orientation::Vertical, nanogui::Alignment::Minimum, 0, 0));
  nanogui::ComboBox* bvBehaviorSelect = new nanogui::ComboBox(
    robotPanel, behaviorNames);
  bvBehaviorSelect->setFixedWidth(COMBO_BOX_WIDTH -10);

  nanogui::Widget *spaceHT = new nanogui::Widget(robotPanel);
  nanogui::Widget * sliderPanelHT = new nanogui::Widget(robotPanel);
  spaceHT->setFixedHeight(10);
  sliderPanelHT->setLayout(
    new nanogui::BoxLayout(
      nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 0));
  nanogui::Widget *lblHT = new nanogui::Label(
    sliderPanelHT, "Hungry Time", "sans-bold");
  lblHT->setFixedWidth(50);
  nanogui::Slider *sliderHT = new nanogui::Slider(sliderPanelHT);
  sliderHT->setValue(0.5);
  sliderHT->setFixedWidth(90);
  spaceHT->setVisible(true);
  sliderPanelHT->setVisible(true);

  nanogui::TextBox *textBoxHT = new nanogui::TextBox(robotPanel);
  textBoxHT->setValue("300");
  sliderHT->setCallback([textBoxHT](float value) {
    textBoxHT->setValue(std::to_string(static_cast<int>(value * 600)));
  });

  sliderHT->setFinalCallback([&](float value) {
    for (auto &entity : arena_->get_entities()) {
      if (entity->get_type() == kBraitenberg) {
        int ht = value * 600;
        static_cast<BraitenbergVehicle*>(entity)->set_hungry_time(ht);
      }
    }
  });

  // ************************************************ //
  // ******* Create the Wheel Velocity Grid  ******** //
  robotWidgets.push_back(new nanogui::Label(
    panel, "Wheel Velocities", "sans-bold"));
  nanogui::Widget* grid = new nanogui::Widget(panel);
  // A grid with 3 columns
  grid->setLayout(
    new nanogui::GridLayout(nanogui::Orientation::Horizontal, 3,
      nanogui::Alignment::Middle, /*int margin = */0, /*int spacing = */0));
  robotWidgets.push_back(grid);

  // Columns Headers Row
  // Notice that it is assigning these items to grid locations row by row
  new nanogui::Label(grid, "", "sans-bold");
  new nanogui::Label(grid, "Left", "sans-bold");
  new nanogui::Label(grid, "Right", "sans-bold");

  // Next Row for wheel velocities from light behavior
  new nanogui::Label(grid, "Light", "sans-bold");
  light_value_left_ = new nanogui::TextBox(grid, "0.0");
  light_value_left_->setFixedWidth(75);
  light_value_right_ = new nanogui::TextBox(grid, "0.0");
  light_value_right_->setFixedWidth(75);

  // Next Row for wheel velocities from food behavior
  new nanogui::Label(grid, "Food", "sans-bold");
  food_value_left_ = new nanogui::TextBox(grid, "0.0");
  food_value_left_->setFixedWidth(75);
  food_value_right_ = new nanogui::TextBox(grid, "0.0");
  food_value_right_->setFixedWidth(75);

  // Next Row for wheel velocities from bv behavior
  new nanogui::Label(grid, "BV", "sans-bold");
  bv_value_left_ = new nanogui::TextBox(grid, "0.0");
  bv_value_left_->setFixedWidth(75);
  bv_value_right_ = new nanogui::TextBox(grid, "0.0");
  bv_value_right_->setFixedWidth(75);

  space = new nanogui::Widget(robotPanel);
  sliderPanel = new nanogui::Widget(robotPanel);
  space->setFixedHeight(10);
  sliderPanel->setLayout(
    new nanogui::BoxLayout(
      nanogui::Orientation::Horizontal, nanogui::Alignment::Middle, 0, 0));
  lbl = new nanogui::Label(sliderPanel, "Intensity", "sans-bold");
  lbl->setFixedWidth(50);
  slider = new nanogui::Slider(sliderPanel);
  slider->setFixedWidth(90);
  space->setVisible(false);
  sliderPanel->setVisible(false);

  for (unsigned int f = 0; f < robotWidgets.size(); f++) {
    robotWidgets[f]->setVisible(defaultEntity->get_type() == kBraitenberg);
  }

  if (defaultEntity->get_type() == kBraitenberg) {
    lightBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
      static_cast<BraitenbergVehicle*>(defaultEntity)->get_light_behavior()->
      getBehaviorType()));
    foodBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
      static_cast<BraitenbergVehicle*>(defaultEntity)->get_food_behavior()->
      getBehaviorType()));
    bvBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
      static_cast<BraitenbergVehicle*>(defaultEntity)->get_bv_behavior()->
      getBehaviorType()));
  }

  entitySelect->setCallback(
    [this, isMobile, robotWidgets, lightBehaviorSelect,
    foodBehaviorSelect, bvBehaviorSelect](int index) {
      if (selected_entity->get_type() == kBraitenberg) {
        static_cast<BraitenbergVehicle*>(selected_entity)->UnregisterObserver();
      }
      ArenaEntity* entity = this->arena_->get_entities()[index];
      selected_entity = entity;
      if (entity->is_mobile()) {
        ArenaMobileEntity* mobileEntity =
        static_cast<ArenaMobileEntity*>(entity);
        isMobile->setChecked(mobileEntity->is_moving());
      }

      isMobile->setVisible(entity->is_mobile());

      for (unsigned int f = 0; f < robotWidgets.size(); f++) {
        robotWidgets[f]->setVisible(entity->get_type() == kBraitenberg);
      }

      if (entity->get_type() == kBraitenberg) {
        static_cast<BraitenbergVehicle*>(entity)->RegisterObserver(this);
        lightBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
          static_cast<BraitenbergVehicle*>(entity)->get_light_behavior()->
          getBehaviorType()));
        foodBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
          static_cast<BraitenbergVehicle*>(entity)->get_food_behavior()->
          getBehaviorType()));
        bvBehaviorSelect->setSelectedIndex(getIndexOfBehavior(
          static_cast<BraitenbergVehicle*>(entity)->get_bv_behavior()->
          getBehaviorType()));
        }

      screen()->performLayout();
    });

  lightBehaviorSelect->setCallback(
    [this, entitySelect](int index) {
      ArenaEntity* entity =
      this->arena_->get_entities()[entitySelect->selectedIndex()];
      Behaviors * behavior;
      switch (index) {
        case 0:
          behavior = new None();
          break;
        case 1:
          behavior = new Aggressive();
          break;
        case 2:
          behavior = new Coward();
          break;
        case 3:
          behavior = new Explore();
          break;
        default:
          behavior = new Love();
          break;
      }
      if (entity->get_type() == kBraitenberg) {
        static_cast<BraitenbergVehicle*>(entity)->set_light_behavior(behavior);
      }
    });

  foodBehaviorSelect->setCallback(
    [this, entitySelect](int index) {
      ArenaEntity* entity =
      this->arena_->get_entities()[entitySelect->selectedIndex()];
      Behaviors * behavior;
      switch (index) {
        case 0:
          behavior = new None();
          break;
        case 1:
          behavior = new Aggressive();
          break;
        case 2:
          behavior = new Coward();
          break;
        case 3:
          behavior = new Explore();
          break;
        default:
          behavior = new Love();
          break;
      }
      if (entity->get_type() == kBraitenberg) {
        static_cast<BraitenbergVehicle*>(entity)->set_food_behavior(behavior);
      }
    });

    bvBehaviorSelect->setCallback(
      [this, entitySelect](int index) {
        ArenaEntity* entity =
        this->arena_->get_entities()[entitySelect->selectedIndex()];
        Behaviors * behavior;
        switch (index) {
          case 0:
            behavior = new None();
            break;
          case 1:
            behavior = new Aggressive();
            break;
          case 2:
            behavior = new Coward();
            break;
          case 3:
            behavior = new Explore();
            break;
          default:
            behavior = new Love();
            break;
        }
        if (entity->get_type() == kBraitenberg) {
          static_cast<BraitenbergVehicle*>(entity)->set_bv_behavior(behavior);
        }
      });

  isMobile->setCallback(
    [this, entitySelect](bool moving) {
      ArenaEntity* entity =
      this->arena_->get_entities()[entitySelect->selectedIndex()];
      ArenaMobileEntity* mobileEntity = static_cast<ArenaMobileEntity*>(entity);
      mobileEntity->set_is_moving(moving);
    });
}
// Velocity container for light
void GraphicsArenaViewer::my_velocity_containers_light_(
  const WheelVelocity* wv) {
  light_value_left_->setValue(std::to_string(wv->left).substr(0, 4));
  light_value_right_->setValue(std::to_string(wv->right).substr(0, 4));
}
// Velocity container for food
void GraphicsArenaViewer::my_velocity_containers_food_(
  const WheelVelocity* wv) {
  food_value_left_->setValue(std::to_string(wv->left).substr(0, 4));
  food_value_right_->setValue(std::to_string(wv->right).substr(0, 4));
}
// Velocity container for bv
void GraphicsArenaViewer::my_velocity_containers_bv_(const WheelVelocity* wv) {
  bv_value_left_->setValue(std::to_string(wv->left).substr(0, 4));
  bv_value_right_->setValue(std::to_string(wv->right).substr(0, 4));
}

// Updating the 3 columns for the velocity
void GraphicsArenaViewer::UpdateState(
  __unused const std::vector<WheelVelocity*>* arg) {
  my_velocity_containers_light_((*arg)[0]);
  my_velocity_containers_food_((*arg)[1]);
  my_velocity_containers_bv_((*arg)[2]);
}

bool GraphicsArenaViewer::RunViewer() {
  return Run();
}

NAMESPACE_END(csci3081);
