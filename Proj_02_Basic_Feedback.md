### Feedback for Proj 02

Run on April 14, 21:45:00 PM.


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

cffa5fdc961323d081a37ce0fd1215726d3bf3fe	refs/heads/devel

2ee4cba73676d59a59c3c4615e30330746aa4f33	refs/heads/docs

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

5bef7862878037d7e4d998528a8ea5937f488e8c	refs/heads/feature/03-implement_factory_pattern

5774c9bb3c0746434b6a63df26a4f4b11c5b1b9c	refs/heads/feature/04-bv_sensors_for_other_bvs

26041de679a354824169aa6dc42076453e96af13	refs/heads/feature/05-add_observer_pattern_bv

69a48b744fe1d5011ef1bc437907e7045562665c	refs/heads/feature/06-add_predator-entity

1cc5bfbaa744a929e38bfad3bf5e32bf021ce1ad	refs/heads/feature/07-predators_kills_bv

b5991806668ccd065049dff06667f5f97acf9a16	refs/heads/feature/08-bv_starves

4b87dba6bbc5a0708c397d5734a26d4d7cff4332	refs/heads/feature/09-dynamic_wheel_velocity_starving

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

2ec4c2d34c6b052a5d99e3bfa3a2ac7d16cc280f	refs/heads/fix/03-unit_test_compiliation

2479320bf2b2ad709ada39b661d8af5dfe93b84b	refs/heads/master

5dc19be958aad25b249b7fb45190b80f6f32999f	refs/heads/pre-release/iteration1

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

33863dcd20bdab078691bb470272409df3acc055	refs/heads/refactor/04-implement_strategy_pattern

5bca29e9c2ac9e682796fe49deccffdb175ed090	refs/heads/release/iteration1

a0d90722755dffa0bb40d8e7a7acae7b27f8ed3e	refs/heads/release/iteration2-prelim1

083d603b24639fda4de94b873a8fb0c9dd814327	refs/heads/release/iteration2-prelim2

156e94272dba4f90bc1485e97fb76dd3141e9d76	refs/heads/style

2ee97dd6c97277542a11b301d96438d652b2b997	refs/heads/tests




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

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
arena.cc:56:  Add #include <utility> for make_pair  [build/include_what_you_use] [4]
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
Total errors found: 1
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

