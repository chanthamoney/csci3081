/**
 * @file controller.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

#include "src/arena.h"
#include "src/common.h"
#include "src/arena_viewer.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Controller that mediates Arena and GraphicsArenaViewer communication.
 *
 * The Controller instantiates the Arena and the GraphicsArenaViewer. The
 * viewer contains the main loop that keeps it live, but at each update, the
 * viewer sends a message to the controller to update its time.
 *
 * Other types of communication between Arena and Viewer include:
 * - keypresses intercepted by the Viewer.
 * - Play/Pause/New Game user input via the Viewer.
 * - Game status from arena to the viewer.
 **/
class Controller {
 public:
  /**
   * @brief Controller's constructor that will create Arena and Viewer.
   */
  Controller(int argc, char **argv);
  Controller(const Controller &control);
  virtual ~Controller();

  virtual ArenaViewer* CreateViewer(int width, int height);

  /**
   * @brief Run launches the graphics and starts the game.
   */
  void Run();

  /**
   * @brief AdvanceTime is communication from the Viewer to advance the
   * simulation.
   */
  void AdvanceTime(double dt);

 /**
  * @brief Completely destroy and remake the arena
  */
  void Reset();


  Controller &operator=(const Controller &other) = delete;
  // Controller (const Controller &control) = delete;


  // Add quotes around the string
  /**
   * @brief Add quotes around the to_string
   *
   * @param[in] word The word to add quotes around
   */
  std::string add_quotes(std::string word);


  // To determine if quotes should be put around the parsed word
  /**
   * @brief To determine if quotes should be put around the parsed word
   *
   * @param[in] word The word to determine add quotes around
   */
  inline bool in_number_set(std::string word);
  /**
   * @brief To determine if the file passed through is a CSV file
   *
   * @param[in] filename The name of the file
   *
   * @return a boolean value depending on if the filename is a CSV file (true)
   * or not (false)
   */
  bool checkCSV(std::string filename);
  /**
   * @brief To determine if the file passed through is a json file
   *
   * @param[in] filename The name of the file
   *
   * @return a boolean value depending on if the filename is a json file (true)
   * or not (false)
   */
  bool checkJSON(std::string filename);
  /**
   * @brief From the CSV file adapts the file and transform it to a json string
   *
   * @param[in] argv The arguments passed in
   *
   * @return a json string from the CSV file
   */
  std::string adapterCSV(char **argv);

 private:
  double last_dt{0};
  Arena* arena_{nullptr};
  ArenaViewer* viewer_{nullptr};
  std::vector<ArenaViewer*> viewers_;
  json_value* config_;
  double x_dim_ = 600.0;
  double y_dim_ = 600.0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_CONTROLLER_H_
