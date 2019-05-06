/**
 * @file mainpage.h
  * @copyright 2017 3081 Staff and Cassandra Chanthamontry, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage csci3081 Project Documentation
 *
 * \tableofcontents
 *
 * \section intro_sec Introduction to Project
 *
 * This project is a simulation of BraitenbergVehicle[s] in an Arena. BraitenbergVehicle[s] is a concept from a
 * thought experiment by Valentino Braitenberg. These vehicles exhibit aggressive, coward, explore, and love behaviors
 * through sensor motor connections. For more information on BraitenbergVehicle[s] view the links below.
 *
 * https://en.wikipedia.org/wiki/Braitenberg_vehicle \n
 * https://en.wikipedia.org/wiki/Valentino_Braitenberg \n
 * http://robohub.org/simple-robots-complex-behaviors-a-control-systems-perspective-on-braitenberg-vehicles/ (Watch this video for a quick, informative lesson
 * on Braitenberg Vehicles). \n
 * https://mitpress.mit.edu/books/vehicles \n
 *
 * For information on how the behaviors change the BraitenbergVehicle view the image below:
 * \image html sensor_motor.png
 *
 * When compiling this project, it will create a rudimentary robot simulator in which robot behavior is visualized within a graphics window.
 * To set up, observe, and document the results of experiments involving the entites in the simulator, it can be seen within the graphics window.
 * The robots are modeled after BraitenbergVehicle[s], which
 * uses simple design to realize a complex behavior. The enviroment/arena will contain multiple robots as well as stimuli, such as
 * Light[s], Food[s], and Predator[s]. The robots will exhibit different behavior when they sense stimuli in the arena, depending
 * on the sensor motor connections related to the stimulus.
 * \subsection organization Organziation of the Simulation
 * The code is organized in such a way that the BraitenbergVehicle[s] behavior in the Arena (i.e Model) is separated from the
 * visualization/ GraphicsArenaViewer (i.e view). There is also a Controller (i.e controller) that handles the communcation between the model and the view.
 * The BraitenbergVehicle[s] class is composed of many other classes that control various aspect of the behavior and enviroment interaction. For example,
 * the WheelVelocity class composes the wheel velocity aspect of the BraitenbergVehicle[s]. The following sections below will discuss the classes that make up the braitenberg simulation.
 *
 * \section arena_sec Entities that make up the Arena
 * \subsection Light
 * The light entity inherits from the ArenaMobileEntity class. This enitity is a stimuli that either Predator[s] or BraitenbergVehicle[s] can exhibits behavior towards.
 * The light entity is colored white and only moves along it's heading angle.
 * \subsection Food
 * The food entity inherits from the ArenaImmobileEntity class. This entity is a stationary stimuli that the BraitenbergVehicle[s] can exhibts behavior towards.
 * When a BraitenbergVehicle "collides" with the food entity its opacity will decrease (to show it has been eaten) until it completly disapears and moves to a random position.
 * \subsection Predator
 * The predator entity is simply a BraitenbergVehicle with fixed behaviors towards light and predator. Towards light the predator is coward and towards BraitenbergVehicle it is aggressive.
 * The predator entity utilzies the Decorator pattern in order to decorate itself with either a light, food, or BraitenbergVehicle decorator in order to trick BraitenbergVehicle[s].
 * If the predator collides with a BraitenbergVehicle it will "eat" the vehicle and that vehicle will die and turn into a ghost.
 * \subsection BraitenbergVehicle
 * The BraitenbergVehicle entity inheritsfrom the ArenaMobileEntity class. This entity can exhibit behaviors towards light, food and other BraitenbergVehicle[s]. Depending on the hungry time
 * inputed in the Graphics Window, the braitenberg vehicle behavior can change into an aggressive food mode when the BraitenbergVehicle is starving.
 * \section GraphicsArenaViewer
 * To make graphics the simulator has the GraphicsArenaViewer class. In this class the library MinGfx and nanogui is used to include
 * buttons for controlling the simulator and is used to draw the entities (food, light, etc). All graphics related changes
 * are made in the GraphicsArenaViewer such as adding a slider, button, or pull down menu.
 * For more information on nangui view this github: https://github.com/wjakob/nanogui \n
 * For more information on MinGfx view this github: https://github.com/ivlab/MinGfx \n
 *
 * \section Arena
 * While the GraphicsArenaViewer handles all the graphics information, the Arena class handles the data and all entities. This class
 * manges the interaction among the entites, such as collosions or when a BraitenbergVehicle consumes Food.
 * \section Patterns
 * \subsection fact_pat Factory Pattern
 * A Factory Pattern is usesd to create Food, Light, Predator, and BraitenbergVehicle entites that will be present and operate in the Arena based on the configuration file.
 * The Factory Pattern is as a pure abstract class (an interface class) from which the factoryBraitenbergVehicle, factoryPredator, factoryLight, and factoryFood Factory classes will derive their common interface.
 * \subsection strat_pat Strategy Pattern
 * A Strategy Pattern is used to implement the Braitenberg Vehicle (BV) behaviors of Explore, Aggression, Coward, and Love.
 * Depending on the behavior the BraitenbergVehicle WheelVelocity is changed dynamically.
 * This pattern makes use of an abstract base class of a behavior [Behaviors] from which other behaviors are derived from.
 * The BV entities contain (i.e. are composed of) a behavior for each of its sensors.
 * \subsection obser_pact Observer Pattern
 * A Observer pattern is used to view the left and right wheel velocities calculated from the behaviors associated with the Light, food, and BraitenbergVehicle eneites for a user specified BV.
 * The Observer pattern is implemented by having the BraitenbergVehicle be the subject class with functions to RegisterObserver, UnregisterObserver, and Notify.
 * The Observer class is a template Observer with a UpdateState function to update the state of the observer after it is notified by the subject. The GraphicsArenaViewer is the observer in this case
 * and it inherits from the observer template class. When the GraphicsArenaViewer update it states, the WheelVelocity information is shown in the graphics window.
 * \subsection dec_pat Decorator Pattern
 * A Decorator pattern is used to enable a Predator to assume the identities of a food, light, or a Braitenberg vehicle entity.
 * The Decorator is implemented via inheritance and aggregation.
 * The LightDecorator, FoodDecorator, and BvDecorator inherits from it's respective class. The Predator class mangages the decorated predator within itself.
 * Therefore the Arena simply does not need to know when to decorate the predator, it only needs to know it's "true" type.
 * \subsection adapt_pat Adapter Pattern
 * The factories can configure entities using either a JSON configuration file or a text file that specifies the values for each entities with a comma separated value format.
 * However, instead of using a "Adapter Pattern", to configure the entity either with a JSON or CSV this is done in the Controller class.
 * \section comp_sec Compiling and Executing the Project
 * A json library is used to create the Arena and the entites (Food, Light, BraitenbergVehicle, and Predator). The json library is
 * picojson. The LoadFromObject function from ArenaEntity utilzies the json.
 * For more information on picojson view this github: https://github.com/kazuho/picojson \n
 *
 * After a sucessful complitation, a json file can be used to load ArenaEntity[s] into the Arena.
 * For example, ./build/bin/arenaviewer scenes/2_lights_4_bots.json
 * or ./build/bin/arenaviewer "json file"
 * If the file is a CSV file to load ArenaEntity[s] into the Arena, the user must include the x and y dimension of the Arena
 * For example, ./build/bin/areanviewer xdim ydim ConfigurationFile.csv
 * The recommended x and y dimension is 600 600.
 *
 * If the user incorrectly types in less arguments or more than needed, no arena will be loaded. Instead on the terminal there will be a message
 * saying that there an incorrect command line execution.
 */

#endif  //  SRC_MAINPAGE_H_
