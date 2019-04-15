/**
 * @file mainpage.h
  * @copyright 2017 3081 Staff and Cassandra Chanthamontry, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage Project: Iteration 2
 *
 * \section intro_sec Introduction to Iteration 2
 *
 * This project is a simulation of BraitenbergVehicle[s] in an Arena. BraitenbergVehicle[s] is a concpet from a
 * thought experiment by Valentino Braitenberg. These vehicles exhibit aggressive, coward, explore, and love behaviors
 * through sensor motor connections. For more information on BraitenbergVehicle[s] view the links below.
 *
 * https://en.wikipedia.org/wiki/Braitenberg_vehicle \n
 * https://en.wikipedia.org/wiki/Valentino_Braitenberg \n
 * http://robohub.org/simple-robots-complex-behaviors-a-control-systems-perspective-on-braitenberg-vehicles/ (Watch this video for a quick, informative lesson
 * on Braitenberg Vehicles). \n
 * https://mitpress.mit.edu/books/vehicles \n
 *
 * When compiling this project, it will create a rudimentary robot simulator in which robot behavior is visualized within a graphics window,
 * and to set up, observe, and
 * document the results of experiments involving the entites in the simulator. The robots are modeled after BraitenbergVehicle[s], which
 * uses simple design to realize a complex behavior. The enviroment/arena will contain multiple robots as well as stimuli, such as
 * Light[s], Food[s], and Predator[s]. The robots will exhibit different behavior when they sense stimuli in the arena, depending
 * on the sensor motor connections related to the stimulus.
 *
 * The code is organized in such a way that the BraitenbergVehicle[s] behavior in the Arena (i.e Model) is separated from the
 * visualization/ GraphicsArenaViewer (i.e view). There is also a Controller (i.e controller) that handles the communcation between the model and the view.
 * The BraitenbergVehicle[s] class is composed of many other classes that control various aspect of the behavior and enviroment interaction. For example,
 * the WheelVelocity class composes the wheel velocity aspect of the BraitenbergVehicle[s].
 *
 * To make graphics the simulator has the GraphicsArenaViewer class. In this class the library MinGfx and nanogui is used to include
 * buttons for controlling the simulator and is used to draw the entities (food, light, etc). All graphics related changes
 * are made in the GraphicsArenaViewer such as adding a slider, button, or pull down menu.
 * For more information on nangui view this github: https://github.com/wjakob/nanogui \n
 * For more information on MinGfx view this github: https://github.com/ivlab/MinGfx \n
 *
 * While the GraphicsArenaViewer handles all the graphics information, the Arena class handles the data and all entities. This class
 * manges the interaction among the entites, such as collosions or when a BraitenbergVehicle consumes Food.
 *
 * A json library is used to create the Arena and the entites (Food, Light, BraitenbergVehicle, and Predator). The json library is
 * picojson. The LoadFromObject function from ArenaEntity utilzies the json.
 * For more information on picojson view this github: https://github.com/kazuho/picojson \n
 *
 * After a sucessful complitation, a json file can be used to load ArenaEntity[s] into the Arena.
 * For example, ./build/bin/arenaviewer scenes/2_lights_4_bots.json
 * or ./build/bin/arenaviewer "json file"
 */

#endif  //  SRC_MAINPAGE_H_
