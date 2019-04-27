### Feedback for Proj 02

Run on April 26, 22:18:55 PM.


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

26b24826551b943cf49caa7c21cb2ccbf3b24a54	refs/heads/devel

82c0c9f1b8aea2038ad774bc03aad494d498a83d	refs/heads/docs

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

5bef7862878037d7e4d998528a8ea5937f488e8c	refs/heads/feature/03-implement_factory_pattern

5774c9bb3c0746434b6a63df26a4f4b11c5b1b9c	refs/heads/feature/04-bv_sensors_for_other_bvs

26041de679a354824169aa6dc42076453e96af13	refs/heads/feature/05-add_observer_pattern_bv

69a48b744fe1d5011ef1bc437907e7045562665c	refs/heads/feature/06-add_predator-entity

1cc5bfbaa744a929e38bfad3bf5e32bf021ce1ad	refs/heads/feature/07-predators_kills_bv

b5991806668ccd065049dff06667f5f97acf9a16	refs/heads/feature/08-bv_starves

4b87dba6bbc5a0708c397d5734a26d4d7cff4332	refs/heads/feature/09-dynamic_wheel_velocity_starving

e8e77e18f15abd4046a8d0903edcf16990e8c4de	refs/heads/feature/10-decorator_pattern_predator

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

2ec4c2d34c6b052a5d99e3bfa3a2ac7d16cc280f	refs/heads/fix/03-unit_test_compiliation

248826614f30d53c2ea421f1dcf9c2e4c8d82940	refs/heads/master

5dc19be958aad25b249b7fb45190b80f6f32999f	refs/heads/pre-release/iteration1

6d1c4ab3513b5b595ec0d11a28012c485936ee1c	refs/heads/pre-release/iteration2

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

33863dcd20bdab078691bb470272409df3acc055	refs/heads/refactor/04-implement_strategy_pattern

5bca29e9c2ac9e682796fe49deccffdb175ed090	refs/heads/release/iteration1

a67ca66e2467e75c21939da7a2a2820be5fefca2	refs/heads/release/iteration2

a0d90722755dffa0bb40d8e7a7acae7b27f8ed3e	refs/heads/release/iteration2-prelim1

083d603b24639fda4de94b873a8fb0c9dd814327	refs/heads/release/iteration2-prelim2

156e94272dba4f90bc1485e97fb76dd3141e9d76	refs/heads/style

2ee97dd6c97277542a11b301d96438d652b2b997	refs/heads/tests




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 2)

[OPEN issue #23] :  Factory pattern reads in CSV [enhancement]

[OPEN issue #22] :  Add decorator pattern for predator [enhancement] 1





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 21)

[CLOSED issue #21] :  Calculate wheel velocity of BV based on dynamically weighted combos [enhancement]

[CLOSED issue #20] :  Make bv starve if no food after 600 iterations [enhancement]

[CLOSED issue #19] :  Make google style compliant for iteration 2 prelim 2 [chore]

[CLOSED issue #18] :  Observer.h function is also called notify - change to updateState [chore]

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
arena.cc:40:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
arena.cc:205:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:206:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:211:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
arena.cc:212:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:102:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:135:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:136:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
braitenberg_vehicle.cc:149:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:152:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:153:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_vehicle.cc:153:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
braitenberg_vehicle.cc:154:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:181:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:300:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
braitenberg_vehicle.cc:313:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.cc:330:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_vehicle.cc:331:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:63:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:66:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
predator.cc:66:  Mismatching spaces inside () in if  [whitespace/parens] [5]
predator.cc:69:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
predator.cc:106:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:106:  At least two spaces is best between code and comments  [whitespace/comments] [2]
predator.cc:107:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.cc:134:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:144:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
predator.cc:164:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:164:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:168:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:168:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:172:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:172:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:250:  Should have a space between // and comment  [whitespace/comments] [4]
predator.cc:251:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:262:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
predator.cc:264:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
predator.cc:269:  At least two spaces is best between code and comments  [whitespace/comments] [2]
predator.cc:270:  Missing space before ( in while(  [whitespace/parens] [5]
predator.cc:272:  At least two spaces is best between code and comments  [whitespace/comments] [2]
predator.cc:272:  Should have a space between // and comment  [whitespace/comments] [4]
predator.cc:273:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:277:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:281:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:281:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:285:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:285:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:289:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:293:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:293:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:297:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:297:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:302:  Missing space before ( in if(  [whitespace/parens] [5]
predator.cc:306:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
predator.cc:306:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
predator.cc:306:  Missing space before {  [whitespace/braces] [5]
arena_entity.h:220:  #endif line should be "#endif  // SRC_ARENA_ENTITY_H_"  [build/header_guard] [5]
arena_entity.h:51:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
arena_entity.h:51:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
arena_entity.h:52:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
arena_entity.h:52:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
braitenberg_decorator.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
braitenberg_decorator.h:2:  #ifndef header guard has wrong style, please use: SRC_BRAITENBERG_DECORATOR_H_  [build/header_guard] [5]
braitenberg_decorator.h:177:  #endif line should be "#endif  // SRC_BRAITENBERG_DECORATOR_H_"  [build/header_guard] [5]
braitenberg_decorator.h:17:  public: should be indented +1 space inside class BvDecorator  [whitespace/indent] [3]
braitenberg_decorator.h:19:  Single-parameter constructors should be marked explicit.  [runtime/explicit] [5]
braitenberg_decorator.h:48:  Mismatching spaces inside () in if  [whitespace/parens] [5]
braitenberg_decorator.h:51:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_decorator.h:51:  Missing space before {  [whitespace/braces] [5]
braitenberg_decorator.h:55:  Missing space before ( in if(  [whitespace/parens] [5]
braitenberg_decorator.h:67:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:68:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:70:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:71:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:73:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:74:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:75:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:76:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:77:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:78:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:79:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:80:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:138:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_decorator.h:138:  At least two spaces is best between code and comments  [whitespace/comments] [2]
braitenberg_decorator.h:138:  Missing username in TODO; it should look like "// TODO(my_username): Stuff."  [readability/todo] [2]
braitenberg_decorator.h:140:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
braitenberg_decorator.h:152:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_decorator.h:152:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_decorator.h:155:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_decorator.h:155:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_decorator.h:158:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_decorator.h:158:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_decorator.h:161:  An else should appear on the same line as the preceding }  [whitespace/newline] [4]
braitenberg_decorator.h:161:  If an else has a brace on one side, it should have it on both  [readability/braces] [5]
braitenberg_decorator.h:168:  private: should be indented +1 space inside class BvDecorator  [whitespace/indent] [3]
braitenberg_decorator.h:173:  Closing brace should be aligned with beginning of class BvDecorator  [whitespace/indent] [3]
braitenberg_vehicle.h:113:  Extra space after ( in function call  [whitespace/parens] [4]
braitenberg_vehicle.h:133:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.h:134:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.h:135:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.h:136:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.h:137:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
braitenberg_vehicle.h:138:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
food_decorator.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
food_decorator.h:1:  #ifndef header guard has wrong style, please use: SRC_FOOD_DECORATOR_H_  [build/header_guard] [5]
food_decorator.h:64:  #endif line should be "#endif  // SRC_FOOD_DECORATOR_H_"  [build/header_guard] [5]
food_decorator.h:16:  public: should be indented +1 space inside class FoodDecorator  [whitespace/indent] [3]
food_decorator.h:18:  Single-parameter constructors should be marked explicit.  [runtime/explicit] [5]
food_decorator.h:47:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:48:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:49:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:50:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:51:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:52:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:53:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:54:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:55:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
food_decorator.h:58:  private: should be indented +1 space inside class FoodDecorator  [whitespace/indent] [3]
food_decorator.h:60:  Closing brace should be aligned with beginning of class FoodDecorator  [whitespace/indent] [3]
light_decorator.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
light_decorator.h:1:  #ifndef header guard has wrong style, please use: SRC_LIGHT_DECORATOR_H_  [build/header_guard] [5]
light_decorator.h:75:  #endif line should be "#endif  // SRC_LIGHT_DECORATOR_H_"  [build/header_guard] [5]
light_decorator.h:16:  public: should be indented +1 space inside class LightDecorator  [whitespace/indent] [3]
light_decorator.h:18:  Single-parameter constructors should be marked explicit.  [runtime/explicit] [5]
light_decorator.h:46:  Missing space before {  [whitespace/braces] [5]
light_decorator.h:69:  private: should be indented +1 space inside class LightDecorator  [whitespace/indent] [3]
light_decorator.h:71:  Closing brace should be aligned with beginning of class LightDecorator  [whitespace/indent] [3]
predator.h:183:  You don't need a ; after a }  [readability/braces] [4]
predator.h:185:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.h:185:  You don't need a ; after a }  [readability/braces] [4]
predator.h:187:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.h:187:  You don't need a ; after a }  [readability/braces] [4]
predator.h:190:  You don't need a ; after a }  [readability/braces] [4]
predator.h:191:  You don't need a ; after a }  [readability/braces] [4]
predator.h:200:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.h:214:  private: should be indented +1 space inside class Predator  [whitespace/indent] [3]
predator.h:222:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
predator.h:274:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
predator.h:281:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
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
Done processing braitenberg_decorator.h
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
Done processing food_decorator.h
Done processing food.h
Done processing graphics_arena_viewer.h
Done processing light_decorator.h
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
Total errors found: 139
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

