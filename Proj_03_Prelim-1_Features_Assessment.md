### Partial Assessment for Project Iteration 03 - Prelim-1_Features (Graded By: Lakshya Goel)

#### Total score: _6_ / _8_

Run on May 14, 18:02:03 PM.


#### Prelim1 Release Branch

+ Pass: Checkout prelim 1 branch.




#### System Files and Lab Directory Structure

+ Pass: Copy directory "Files for Dependencies".



+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Copy directory "Files for Testing".



+ Pass: Change into directory "project".

+ Pass: Checkout regrade branch.



+ Pass: Change into directory "tests-i".

+ Pass: Check that make compiles.



+ Pass: Change into directory "..".

+ Pass: Check that file "./build/bin/tests-i" exists.


#### Functionality- Decoration Alone

+  _1_ / _1_ : Pass: Decorates Once - Gets through first decoration without a seg fault (scenes/pred_decorate_1.json)



+  _1_ / _1_ : Pass: Decorates Twice - Gets through second decoration without a seg fault (scenes/pred_decorate_2.json)



+  _1_ / _1_ : Pass: Decorates Thrice - Gets through third decoration without a seg fault (scenes/pred_decorate_3.json)



+  _1_ / _1_ : Pass: Starves - Dies after 3rd decoration (scenes/pred_starve.json)




#### Functionality - Consuming BV

+  _0_ / _1_ : Fail: Movement Towards BV - Does it move towards BV as a Predator or Decorated as BV? (scenes/pred_move_towards_bv.json)
    fails to run the test executable: InteractiveTest.ArenaViewerTest.
arg  1 = scenes/pred_move_towards_bv.json
arg  2 = 160
arg  3 = 1.5
arg  4 = 0
Note: Google Test filter = InteractiveTest.ArenaViewerTest
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from InteractiveTest
[ RUN      ] InteractiveTest.ArenaViewerTest

return code: -11



+  _0_ / _1_ : Fail: Undecorates - Does it undecorate after consuming BV? (scenes/pred_undecorates.json)
    fails to run the test executable: InteractiveTest.ArenaViewerTest.
arg  1 = scenes/pred_undecorates.json
arg  2 = 160
arg  3 = 3
arg  4 = 0
Note: Google Test filter = InteractiveTest.ArenaViewerTest
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from InteractiveTest
[ RUN      ] InteractiveTest.ArenaViewerTest

return code: -11




#### Functionality - Decorator Behavior

+  _2_ / _2_ : Pass: Moves as a BV when decorated as BV. (scenes/pred_bv_decorator.json)




#### Regrade Process

You may create json config files that prove that your functionality works in the "regrade/iteration3-prelim1" branch under the "project/scenes" folder.  Use the names for the scene files above.  Submit a new regrade request and we will re-run with your new files and a description of how to test.


#### Possible Areas of Failure

 * Cannot turn off mobility of entity (i.e. cannot call entity->set_is_moving(...)).
 * Program expects a BV to exist.
 * The BV must be the first entity in the config.
 * Simulation timing is handled outside of the arena_->AdvanceTime(1.0).
 * Segfault when a predator consumes.

#### Total score: _6_ / _8_

