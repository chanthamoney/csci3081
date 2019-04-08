### Feedback for Proj 02

Run on April 08, 15:03:43 PM.


***Note: This is just the basic feedback.  The full feedback is run daily as a batch process (click link below)***


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

+ Pass: Checkout devel branch.



+ Pass: Report branch name.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".


#### Git Usage

+ Pass: Check git commit history
Commits found=152

+ Pass: Run git ls-remote gather all branches in repo

83877c2fbe2a1d93a93506f585244762a4391dd7	refs/heads/chore

46cba3de3cf4e970eca7d1fc9d22fc297c7272be	refs/heads/devel

8ec39bc354dc57223870828b619ba1809445d1af	refs/heads/docs

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

5bef7862878037d7e4d998528a8ea5937f488e8c	refs/heads/feature/03-implement_factory_pattern

5774c9bb3c0746434b6a63df26a4f4b11c5b1b9c	refs/heads/feature/04-bv_sensors_for_other_bvs

26041de679a354824169aa6dc42076453e96af13	refs/heads/feature/05-add_observer_pattern_bv

69a48b744fe1d5011ef1bc437907e7045562665c	refs/heads/feature/06-add_predator-entity

1cc5bfbaa744a929e38bfad3bf5e32bf021ce1ad	refs/heads/feature/07-predators_kills_bv

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

2ec4c2d34c6b052a5d99e3bfa3a2ac7d16cc280f	refs/heads/fix/03-unit_test_compiliation

4d06baa12347ac24724387f4ed24c94e4eb424f6	refs/heads/master

5dc19be958aad25b249b7fb45190b80f6f32999f	refs/heads/pre-release/iteration1

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

33863dcd20bdab078691bb470272409df3acc055	refs/heads/refactor/04-implement_strategy_pattern

5bca29e9c2ac9e682796fe49deccffdb175ed090	refs/heads/release/iteration1

a0d90722755dffa0bb40d8e7a7acae7b27f8ed3e	refs/heads/release/iteration2-prelim1

890f75ee6cead2f7c2bda56ce72f6f7c9fdb79ed	refs/heads/style

2ee97dd6c97277542a11b301d96438d652b2b997	refs/heads/tests




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 1)

[OPEN issue #18] :  Observer.h function is also called notify - change to updateState [chore]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 17)

[CLOSED issue #17] :  Predator kills bv and bv becomes ghost [enhancement]

[CLOSED issue #16] :  Add predator entity  [enhancement]

[CLOSED issue #15] :  Adding observer pattern to BV [enhancement]

[CLOSED issue #14] :  Unit test for Strategy pattern [refactor] [tests]

[CLOSED issue #13] :  Added BV sensors for other BV [enhancement]

[CLOSED issue #12] :  Implement strategy pattern for Braitenberg vehicle [refactor] 1

[CLOSED issue #11] :  Add documentation for doxygen code [docs]

[CLOSED issue #10] :  Unit test formatting for factory is not clear [refactor] [tests] 1

[CLOSED issue #9] :  Unittest C++ type exception error [bug]

[CLOSED issue #8] :  Implement factory pattern into arena [enhancement]

[CLOSED issue #7] :  Fix factory and braitenberg vehicle to be google style compliant [style]

[CLOSED issue #6] :  Implement the functionality for color of robot sensors [enhancement]

[CLOSED issue #5] :  Refactor robot collision behavior [refactor]

[CLOSED issue #4] :  Implement Robot Behaviors for Aggression, love, and cower [enhancement] 1

[CLOSED issue #3] :  Adding json object to unittest for factories  [refactor]

[CLOSED issue #2] :  AdjustEntityOverlap Function Error [bug]

[CLOSED issue #1] :  Compilation Error For Simulator [bug]






#### Documentation Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-chant077/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-chant077/cpplint/cpplint.py --root=.. *.cc *.h
arena.cc:148:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:162:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:82:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:82:  Missing space before {  [whitespace/braces] [5]
braitenberg_vehicle.cc:111:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:116:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:117:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:119:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:122:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:123:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:124:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:126:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:167:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:167:  Extra space before )  [whitespace/parens] [2]
braitenberg_vehicle.cc:168:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:241:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:241:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:244:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:244:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:247:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:247:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:250:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:250:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:259:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:259:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:262:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:262:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:265:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:265:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:268:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:268:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:278:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:278:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:281:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:281:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:284:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:284:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_vehicle.cc:287:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_vehicle.cc:287:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
graphics_arena_viewer.cc:385:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:386:  Closing ) should be moved to the previous line  [whitespace/parens] [2]
graphics_arena_viewer.cc:435:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:437:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:439:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:465:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:467:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:469:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:498:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
graphics_arena_viewer.cc:566:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:567:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:568:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:571:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.cc:572:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:573:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:577:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:578:  Missing space after ,  [whitespace/comma] [3]
graphics_arena_viewer.cc:581:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:35:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:80:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:80:  Missing space before {  [whitespace/braces] [5]
predator.cc:113:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:118:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:119:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:121:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:124:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:125:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:126:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:135:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:147:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:159:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:162:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:162:  Extra space before )  [whitespace/parens] [2]
predator.cc:163:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:172:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
aggressive.h:18:  Include the directory when naming .h files  [build/include] [4]
aggressive.h:19:  Include the directory when naming .h files  [build/include] [4]
aggressive.h:31:  You don't need a ; after a }  [readability/braces] [4]
aggressive.h:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
aggressive.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
aggressive.h:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
behaviors.h:18:  Include the directory when naming .h files  [build/include] [4]
behaviors.h:19:  Include the directory when naming .h files  [build/include] [4]
behaviors.h:30:  Do not leave a blank line after "public:"  [whitespace/blank_line] [3]
behaviors.h:32:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
behaviors.h:32:  Extra space before ( in function call  [whitespace/parens] [4]
behaviors.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
braitenberg_vehicle.h:43:  Do not leave a blank line after "public:"  [whitespace/blank_line] [3]
braitenberg_vehicle.h:44:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:46:  You don't need a ; after a }  [readability/braces] [4]
braitenberg_vehicle.h:46:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:48:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:50:  You don't need a ; after a }  [readability/braces] [4]
braitenberg_vehicle.h:50:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:52:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
braitenberg_vehicle.h:56:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
coward.h:18:  Include the directory when naming .h files  [build/include] [4]
coward.h:19:  Include the directory when naming .h files  [build/include] [4]
coward.h:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
coward.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
coward.h:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
explore.h:18:  Include the directory when naming .h files  [build/include] [4]
explore.h:19:  Include the directory when naming .h files  [build/include] [4]
explore.h:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
explore.h:33:  At least two spaces is best between code and comments  [whitespace/comments] [2]
explore.h:33:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
explore.h:33:  Should have a space between // and comment  [whitespace/comments] [4]
explore.h:33:  Missing space after ,  [whitespace/comma] [3]
explore.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
explore.h:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.h:58:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
graphics_arena_viewer.h:94:  Add #include <string> for string  [build/include_what_you_use] [4]
graphics_arena_viewer.h:76:  Add #include <vector> for vector<>  [build/include_what_you_use] [4]
love.h:18:  Include the directory when naming .h files  [build/include] [4]
love.h:19:  Include the directory when naming .h files  [build/include] [4]
love.h:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
love.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
love.h:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
none.h:7:  #ifndef header guard has wrong style, please use: SRC_NONE_H_  [build/header_guard] [5]
none.h:44:  #endif line should be "#endif  // SRC_NONE_H_"  [build/header_guard] [5]
none.h:18:  Include the directory when naming .h files  [build/include] [4]
none.h:19:  Include the directory when naming .h files  [build/include] [4]
none.h:33:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
none.h:33:  Extra space before ( in function call  [whitespace/parens] [4]
observer.h:6:  #ifndef header guard has wrong style, please use: SRC_OBSERVER_H_  [build/header_guard] [5]
observer.h:27:  #endif line should be "#endif  // SRC_OBSERVER_H_"  [build/header_guard] [5]
observer.h:12:  Should have a space between // and comment  [whitespace/comments] [4]
observer.h:19:  public: should be indented +1 space inside class Observer  [whitespace/indent] [3]
observer.h:22:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
predator.h:7:  #ifndef header guard has wrong style, please use: SRC_PREDATOR_H_  [build/header_guard] [5]
predator.h:203:  #endif line should be "#endif  // SRC_PREDATOR_H_"  [build/header_guard] [5]
predator.h:42:  Do not leave a blank line after "public:"  [whitespace/blank_line] [3]
Done processing arena.cc
Done processing braitenberg_vehicle.cc
Done processing controller.cc
Done processing factory_bv.cc
Done processing factory_food.cc
Done processing factory_light.cc
Done processing factory_predator.cc
Done processing food.cc
Done processing graphics_arena_viewer.cc
Done processing light.cc
Done processing main.cc
Done processing motion_behavior.cc
Done processing motion_behavior_differential.cc
Done processing predator.cc
Done processing rgb_color.cc
Done processing aggressive.h
Done processing arena_entity.h
Done processing arena.h
Done processing arena_immobile_entity.h
Done processing arena_mobile_entity.h
Done processing arena_viewer.h
Done processing behavior_enum.h
Done processing behaviors.h
Done processing braitenberg_vehicle.h
Done processing common.h
Done processing controller.h
Done processing coward.h
Done processing entity_type.h
Done processing explore.h
Done processing factory_bv.h
Done processing factory_entity.h
Done processing factory_food.h
Done processing factory_light.h
Done processing factory_predator.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light.h
Done processing love.h
Done processing mainpage.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing none.h
Done processing observer.h
Done processing params.h
Done processing pose.h
Done processing predator.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 134
Makefile:162: recipe for target 'check-style' failed
make[1]: *** [check-style] Error 1
make[1]: Leaving directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_02_Basic_Feedback/repo-chant077/project/src'
Makefile:8: recipe for target 'check-style' failed
make: *** [check-style] Error 2
</pre>




#### Compile Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)


#### Unit Tests


Link to full feedback: [Proj_02_Full_Feedback.md](Proj_02_Full_Feedback.md)

