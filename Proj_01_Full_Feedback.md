### Feedback for Proj 01

Run on March 11, 22:57:53 PM.

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Compile Tests

+ Pass: Clean project.



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/arenaviewer" exists.


#### Documentation Tests

+ Pass: Check that file "docs/uml_design.pdf" exists.

+ Fail: Check that file "docs/design.pdf" exists.

     "docs/design.pdf" not found.

+ Pass: Documentation builds.



+ Pass: Check that file "docs/html/index.html" exists.


#### Git Usage

+ Pass: Check git commit history
Sufficient commits (found=50,required=25)

+ Pass: Run git ls-remote to check for # of branches in repo
Sufficient branches (found=10,required=4)

+ Pass: Run git ls-remote gather all branches in repo

e327972b0d29dd2d607b476cc329853748e11322	refs/heads/devel

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

1dc5def33f9bce81ca23751e88de5344234d3485	refs/heads/master

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

f13e9913bac7aee4768d83207922dd44df443949	refs/heads/style

4df659524279791a45b7c7529058b54b00b66a59	refs/heads/tests




#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
==== Checking style is correct ====
/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:246:  At least two spaces is best between code and comments  [whitespace/comments] [2]
arena.cc:246:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
arena.cc:246:  Should have a space between // and comment  [whitespace/comments] [4]
arena.cc:49:  Add #include <string> for string  [build/include_what_you_use] [4]
braitenberg_vehicle.cc:46:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:46:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:47:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:47:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:51:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:51:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:51:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:62:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:164:  Should have a space between // and comment  [whitespace/comments] [4]
braitenberg_vehicle.cc:165:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:169:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:169:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:169:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:173:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:173:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:173:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:176:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
factory_bv.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:32:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
factory_bv.cc:32:  You don't need a ; after a }  [readability/braces] [4]
factory_bv.cc:32:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_bv.cc:32:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_bv.cc:32:  Should have a space between // and comment  [whitespace/comments] [4]
factory_bv.cc:38:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:38:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
factory_bv.cc:61:  You don't need a ; after a }  [readability/braces] [4]
factory_bv.cc:38:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_bv.cc:38:  Should have a space between // and comment  [whitespace/comments] [4]
factory_bv.cc:39:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:40:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:41:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:42:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:43:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:44:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:45:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:46:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:47:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:48:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:49:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:50:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:51:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:52:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:53:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:54:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:55:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:56:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:57:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:58:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:59:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:60:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:61:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:30:  You don't need a ; after a }  [readability/braces] [4]
factory_food.cc:30:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_food.cc:30:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_food.cc:30:  Should have a space between // and comment  [whitespace/comments] [4]
factory_food.cc:36:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:40:  You don't need a ; after a }  [readability/braces] [4]
factory_food.cc:36:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_food.cc:36:  Should have a space between // and comment  [whitespace/comments] [4]
factory_food.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:38:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:39:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:40:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:28:  You don't need a ; after a }  [readability/braces] [4]
factory_light.cc:28:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_light.cc:28:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_light.cc:28:  Should have a space between // and comment  [whitespace/comments] [4]
factory_light.cc:34:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:38:  You don't need a ; after a }  [readability/braces] [4]
factory_light.cc:34:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_light.cc:34:  Should have a space between // and comment  [whitespace/comments] [4]
factory_light.cc:35:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:36:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:38:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
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
controller.h:82:  #endif line should be "#endif  // SRC_CONTROLLER_H_"  [build/header_guard] [5]
entity_type.h:14:  Found C++ system header after other header. Should be: entity_type.h, c system, c++ system, other.  [build/include_order] [4]
factory_bv.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_bv.h:29:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_bv.h:31:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_bv.h:35:  private: should be indented +1 space inside class factoryBraitenberg  [whitespace/indent] [3]
factory_entity.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_entity.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_entity.h:26:  Should have a space between // and comment  [whitespace/comments] [4]
factory_entity.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_entity.h:30:  Is this a non-const reference? If so, make const or use a pointer: json_object& config  [runtime/references] [2]
factory_entity.h:31:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
factory_food.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_food.h:29:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_food.h:31:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_food.h:32:  private: should be indented +1 space inside class factoryFood  [whitespace/indent] [3]
factory_food.h:33:  Missing spaces around =  [whitespace/operators] [4]
factory_light.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:29:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:31:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:33:  private: should be indented +1 space inside class factoryLight  [whitespace/indent] [3]
graphics_arena_viewer.h:171:  "virtual" is redundant since function is already declared as "override"  [readability/inheritance] [4]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing controller.cc
Done processing factory_bv.cc
Done processing factory_food.cc
Done processing factory_light.cc
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
Done processing factory_bv.h
Done processing factory_entity.h
Done processing factory_food.h
Done processing factory_light.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 124
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/classes/grades/Spring-2019/csci3081/dtorban/csci3081-grading-env/grading-scripts/grading/Proj_01_Full_Feedback/repo-chant077/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Unit Tests

+ Pass: Check that file "build/bin/unittest" exists.

+ Pass: Check that a GoogleTest test passes.
    passes the test: InstBraitenbergVehicle.ColorMatchesBehavior.



+ Pass: Check that a GoogleTest test passes.
    passes the test: InstBraitenbergVehicle.RobotMovesInEmptyScene.



