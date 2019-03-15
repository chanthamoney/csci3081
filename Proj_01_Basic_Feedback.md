### Feedback for Proj 01

Run on March 15, 16:19:58 PM.


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


#### Git Usage

+ Pass: Check git commit history
Commits found=137

+ Pass: Run git ls-remote gather all branches in repo

e37dc80873c520959b92a3fb8ca64efe84320bd0	refs/heads/devel

c708c903d3e24901756e5a0e2f25993f1e6daee4	refs/heads/docs

8e3a5bfb231c7d4afb305f7c2339cd6e3ea10c88	refs/heads/feature/01-add_robot_behaviors

1ef71ec3f2adafb831dcf9c686b013de6e3b03d4	refs/heads/feature/02-add_color_sensor_for_robot

5bef7862878037d7e4d998528a8ea5937f488e8c	refs/heads/feature/03-implement_factory_pattern

d5bd187ee73715e9cab54f52f780158b0468f33c	refs/heads/fix/01-compilation-errors

3cf8b8d837f15174e697560e3716cbeb0922e720	refs/heads/fix/01-entity_pass_through_entity

2ec4c2d34c6b052a5d99e3bfa3a2ac7d16cc280f	refs/heads/fix/03-unit_test_compiliation

086be64bc967c5a38e247c7a3ca7c0ad8d718138	refs/heads/master

1b3ebd50426b265ad53f46c40a112dae613a0814	refs/heads/refactor/01-adding-json-object

c3c21c56c0ce281df73641979d47865c588200d7	refs/heads/refactor/02-update_robot_collision_behavior

edfbb5fb594e1ca9316aa6e89a26ab41c187d400	refs/heads/style

9a0a5ef6762dcd749ed48d1bf2832cac8eee5d26	refs/heads/tests




#### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

[OPEN issue #] : 





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 11)

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

+ Pass: Check that file "docs/uml_design.pdf" exists.


Link to full feedback: [Proj_01_Full_Feedback.md](Proj_01_Full_Feedback.md)


#### Style Tests

+ Fail: Ensuring code follows style guide.

<pre>cd src; make check-style
make[1]: Entering directory '/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-chant077/project/src'
==== Checking style is correct ====
/class/grades/Spring-2019/csci3081/student-repos/Proj_01_Basic_Feedback/repo-chant077/cpplint/cpplint.py --root=.. *.cc *.h
factory_bv.h:59:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
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
Done processing mainpage.h
Done processing motion_behavior_differential.h
Done processing motion_behavior.h
Done processing params.h
Done processing pose.h
Done processing rgb_color.h
Done processing wheel_velocity.h
Total errors found: 1
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

