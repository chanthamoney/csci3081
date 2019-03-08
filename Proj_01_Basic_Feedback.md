### Feedback for Proj 01

Run on March 07, 18:04:09 PM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Documentation Tests

+ Fail: Check that file "src/mainpage.h" exists.

     "src/mainpage.h" not found.

+ Pass: Check that file "docs/uml_design.pdf" exists.

+ Fail: Check that file "docs/design.pdf" exists.

     "docs/design.pdf" not found.


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-chant077/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-chant077/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:246:  At least two spaces is best between code and comments  [whitespace/comments] [2]
arena.cc:246:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
arena.cc:246:  Should have a space between // and comment  [whitespace/comments] [4]
arena.cc:49:  Add #include <string> for string  [build/include_what_you_use] [4]
controller.cc:36:  Extra space for operator !   [whitespace/operators] [4]
controller.cc:41:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
controller.cc:41:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
factory_bv.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:31:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
factory_bv.cc:31:  You don't need a ; after a }  [readability/braces] [4]
factory_bv.cc:31:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_bv.cc:31:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_bv.cc:31:  Should have a space between // and comment  [whitespace/comments] [4]
factory_bv.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:39:  You don't need a ; after a }  [readability/braces] [4]
factory_bv.cc:37:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_bv.cc:37:  Should have a space between // and comment  [whitespace/comments] [4]
factory_bv.cc:38:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_bv.cc:39:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:26:  You don't need a ; after a }  [readability/braces] [4]
factory_food.cc:26:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_food.cc:26:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_food.cc:26:  Should have a space between // and comment  [whitespace/comments] [4]
factory_food.cc:32:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:34:  You don't need a ; after a }  [readability/braces] [4]
factory_food.cc:32:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_food.cc:32:  Should have a space between // and comment  [whitespace/comments] [4]
factory_food.cc:33:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.cc:34:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:10:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:28:  You don't need a ; after a }  [readability/braces] [4]
factory_light.cc:28:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_light.cc:28:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_light.cc:28:  Should have a space between // and comment  [whitespace/comments] [4]
factory_light.cc:34:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:36:  You don't need a ; after a }  [readability/braces] [4]
factory_light.cc:34:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_light.cc:34:  Should have a space between // and comment  [whitespace/comments] [4]
factory_light.cc:35:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.cc:36:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
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
factory_entity.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_entity.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_entity.h:26:  Should have a space between // and comment  [whitespace/comments] [4]
factory_entity.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_entity.h:30:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
factory_entity.h:30:  At least two spaces is best between code and comments  [whitespace/comments] [2]
factory_entity.h:30:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
factory_entity.h:30:  Should have a space between // and comment  [whitespace/comments] [4]
factory_entity.h:31:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
factory_food.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_food.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_food.h:29:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_food.h:31:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:13:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.h:18:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
factory_light.h:28:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:29:  Tab found; better to use spaces  [whitespace/tab] [1]
factory_light.h:31:  Tab found; better to use spaces  [whitespace/tab] [1]
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
Total errors found: 80
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-chant077/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)

