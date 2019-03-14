### Feedback for Proj 01

Run on March 13, 20:51:20 PM.

+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Compile Tests

+ Pass: Clean project.



+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>cd src; make -j
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
==== Auto-Generating Dependencies for light.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/light.d -MP -MT ../build/obj/src/light.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 light.cc
==== Auto-Generating Dependencies for motion_behavior.cc. ====
==== Auto-Generating Dependencies for rgb_color.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/motion_behavior.d -MP -MT ../build/obj/src/motion_behavior.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 motion_behavior.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/rgb_color.d -MP -MT ../build/obj/src/rgb_color.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 rgb_color.cc
==== Auto-Generating Dependencies for graphics_arena_viewer.cc. ====
==== Auto-Generating Dependencies for motion_behavior_differential.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/graphics_arena_viewer.d -MP -MT ../build/obj/src/graphics_arena_viewer.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 graphics_arena_viewer.cc
==== Auto-Generating Dependencies for controller.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/motion_behavior_differential.d -MP -MT ../build/obj/src/motion_behavior_differential.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 motion_behavior_differential.cc
==== Auto-Generating Dependencies for braitenberg_vehicle.cc. ====
==== Auto-Generating Dependencies for food.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/controller.d -MP -MT ../build/obj/src/controller.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 controller.cc
==== Auto-Generating Dependencies for main.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/braitenberg_vehicle.d -MP -MT ../build/obj/src/braitenberg_vehicle.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 braitenberg_vehicle.cc
==== Auto-Generating Dependencies for arena.cc. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/food.d -MP -MT ../build/obj/src/food.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 food.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/main.d -MP -MT ../build/obj/src/main.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 main.cc
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -MM -MF ../build/obj/src/arena.d -MP -MT ../build/obj/src/arena.o -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0 arena.cc
==== Compiling rgb_color.cc into ../build/obj/src/rgb_color.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/rgb_color.o rgb_color.cc
==== Compiling food.cc into ../build/obj/src/food.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/food.o food.cc
==== Compiling motion_behavior_differential.cc into ../build/obj/src/motion_behavior_differential.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/motion_behavior_differential.o motion_behavior_differential.cc
==== Compiling light.cc into ../build/obj/src/light.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/light.o light.cc
==== Compiling motion_behavior.cc into ../build/obj/src/motion_behavior.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/motion_behavior.o motion_behavior.cc
==== Compiling braitenberg_vehicle.cc into ../build/obj/src/braitenberg_vehicle.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/braitenberg_vehicle.o braitenberg_vehicle.cc
==== Compiling arena.cc into ../build/obj/src/arena.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/arena.o arena.cc
==== Compiling graphics_arena_viewer.cc into ../build/obj/src/graphics_arena_viewer.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/graphics_arena_viewer.o graphics_arena_viewer.cc
==== Compiling main.cc into ../build/obj/src/main.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/main.o main.cc
==== Compiling controller.cc into ../build/obj/src/controller.o. ====
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wno-missing-field-initializers -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Weffc++ -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -g -std=c++14 -c -I.. -I. -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/nanovg -isystem/classes/grades/Spring-2019/csci3081/csel-s19c3081/include/MinGfx-1.0  -c -o  ../build/obj/src/controller.o controller.cc
In file included from ../src/arena.h:20:0,
                 from arena.cc:14:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from arena.cc:14:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/motion_behavior.h:15:0,
                 from motion_behavior.cc:12:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/motion_behavior.h:13:0,
                 from motion_behavior.cc:12:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/light.h:16:0,
                 from light.cc:11:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena_entity.h:18:0,
                 from ../src/arena_mobile_entity.h:16,
                 from ../src/light.h:16,
                 from light.cc:11:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
cc1plus: all warnings being treated as errors
In file included from ../src/braitenberg_vehicle.h:18:0,
                 from braitenberg_vehicle.cc:11:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/braitenberg_vehicle.h:17:0,
                 from braitenberg_vehicle.cc:11:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
Makefile:109: recipe for target '../build/obj/src/motion_behavior.o' failed
make[1]: *** [../build/obj/src/motion_behavior.o] Error 1
make[1]: *** Waiting for unfinished jobs....
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/arena.o' failed
make[1]: *** [../build/obj/src/arena.o] Error 1
In file included from ../src/motion_behavior.h:15:0,
                 from ../src/motion_behavior_differential.h:16,
                 from motion_behavior_differential.cc:10:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/motion_behavior_differential.h:13:0,
                 from motion_behavior_differential.cc:10:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/light.o' failed
make[1]: *** [../build/obj/src/light.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/motion_behavior_differential.o' failed
make[1]: *** [../build/obj/src/motion_behavior_differential.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/braitenberg_vehicle.o' failed
make[1]: *** [../build/obj/src/braitenberg_vehicle.o] Error 1
In file included from ../src/arena.h:20:0,
                 from ../src/controller.h:17,
                 from main.cc:12:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from ../src/controller.h:17,
                 from main.cc:12:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena.h:20:0,
                 from ../src/graphics_arena_viewer.h:15,
                 from graphics_arena_viewer.cc:14:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from ../src/arena.h:18:0,
                 from ../src/graphics_arena_viewer.h:15,
                 from graphics_arena_viewer.cc:14:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
In file included from ../src/arena.h:20:0,
                 from ../src/controller.h:17,
                 from controller.cc:16:
../src/arena_mobile_entity.h:37:46: error: expected class-name before { token
 class ArenaMobileEntity : public ArenaEntity {
                                              ^
../src/arena_mobile_entity.h:52:41: error: EntityType has not been declared
   virtual void HandleCollision(__unused EntityType ent_type,
                                         ^~~~~~~~~~
../src/arena_mobile_entity.h:53:41: error: ArenaEntity has not been declared
                                __unused ArenaEntity * object = NULL) { }
                                         ^~~~~~~~~~~
../src/arena_mobile_entity.h:37:7: error: class ArenaMobileEntity has virtual functions and accessible non-virtual destructor [-Werror=non-virtual-dtor]
 class ArenaMobileEntity : public ArenaEntity {
       ^~~~~~~~~~~~~~~~~
../src/arena_mobile_entity.h: In constructor ArenaMobileEntity::ArenaMobileEntity():
../src/arena_mobile_entity.h:44:7: error: class ArenaMobileEntity does not have any field named ArenaEntity
     : ArenaEntity(),
       ^~~~~~~~~~~
../src/arena_mobile_entity.h:47:9: error: set_mobility was not declared in this scope
         set_mobility(true);
         ^~~~~~~~~~~~
In file included from controller.cc:15:0:
../src/arena_mobile_entity.h: At global scope:
../src/common.h:31:29: error: expected declaration before } token
 #define NAMESPACE_END(name) }
                             ^
../src/arena_mobile_entity.h:67:1: note: in expansion of macro NAMESPACE_END
 NAMESPACE_END(csci3081);
 ^~~~~~~~~~~~~
cc1plus: all warnings being treated as errors
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/graphics_arena_viewer.o' failed
make[1]: *** [../build/obj/src/graphics_arena_viewer.o] Error 1
Makefile:109: recipe for target '../build/obj/src/main.o' failed
make[1]: *** [../build/obj/src/main.o] Error 1
cc1plus: all warnings being treated as errors
Makefile:109: recipe for target '../build/obj/src/controller.o' failed
make[1]: *** [../build/obj/src/controller.o] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
Makefile:4: recipe for target 'all' failed
make: *** [all] Error 2
</pre>



+ Skip: Check that file "build/bin/arenaviewer" exists.

  This test was not run because of an earlier failing test.


#### Documentation Tests

+ Fail: Check that file "docs/uml_design.pdf" exists.

     "docs/uml_design.pdf" not found.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Fail: Check git commit history
Insufficient commits (found=4,required=25)

+ Pass: Run git ls-remote gather all branches in repo

e327972b0d29dd2d607b476cc329853748e11322	refs/heads/devel

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

1dac2f2294ed86205bfda61ad954ea112819b02c	refs/heads/feature/03-implement_factory_pattern

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

ecd168bfb34409760c7f271f5ebdb6282e14b10c	refs/heads/master

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

f13e9913bac7aee4768d83207922dd44df443949	refs/heads/style

4df659524279791a45b7c7529058b54b00b66a59	refs/heads/tests




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 1)

[OPEN issue #/bin/sh:] : ghi: command not found





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 1)

[CLOSED issue #/bin/sh:] : ghi: command not found






#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
==== Checking style is correct ====
/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:47:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
graphics_arena_viewer.cc:39:  Missing spaces around =  [whitespace/operators] [4]
graphics_arena_viewer.cc:46:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
graphics_arena_viewer.cc:46:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
arena_entity.h:141:  Is this a non-const reference? If so, make const or use a pointer: json_object& entity_config  [runtime/references] [2]
arena.h:52:  Zero-parameter constructors should not be marked explicit.  [runtime/explicit] [5]
arena.h:55:  Is this a non-const reference? If so, make const or use a pointer: json_object& arena_object  [runtime/references] [2]
behavior_enum.h:37:  Add #include <string> for string  [build/include_what_you_use] [4]
common.h:15:  <chrono> is an unapproved C++11 header.  [build/c++11] [5]
common.h:22:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:23:  Is this a non-const reference? If so, make const or use a pointer: json_value& v  [runtime/references] [2]
common.h:24:  Tab found; better to use spaces  [whitespace/tab] [1]
common.h:23:  Add #include <string> for string  [build/include_what_you_use] [4]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing controller.cc
Done processing food.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
Done processing main.cc
Done processing motion_behavior.cc
Done processing motion_behavior_differential.cc
Done processing rgb_color.cc
Done processing arena_entity.h
Done processing arena.h
Done processing arena_immobile_entity.h
Done processing arena_mobile_entity.h
Done processing arena_viewer.h
Done processing behavior_enum.h
Done processing braitenberg_vehicle.h
Done processing common.h
Done processing controller.h
Done processing entity_type.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 18
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Unit Tests

+ Fail: Check that file "build/bin/unittest" exists.

     "build/bin/unittest" not found.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

