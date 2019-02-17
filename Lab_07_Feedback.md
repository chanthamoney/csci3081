### Feedback for Lab 07

Run on February 17, 17:11:29 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "cpplint" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab07_style_doxy" exists.

+ Pass: Change into directory "labs/lab07_style_doxy".

+ Pass: Check that directory "docs" exists.

+ Pass: Check that file "docs/Doxyfile" exists.


#### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.


#### Google Style Compliance I

+ Fail: Cpplint checking for for Google C++ compliance

/export/scratch/cpplint-gitbot/./src/obstacle.h:8:  #ifndef header guard has wrong style, please use: SRC_OBSTACLE_H_  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/obstacle.h:43:  #endif line should be "#endif  // SRC_OBSTACLE_H_"  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/mainpage.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
/export/scratch/cpplint-gitbot/./src/mainpage.h:0:  No #ifndef header guard found, suggested CPP variable is: SRC_MAINPAGE_H_  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/robot_viewer.h:7:  #ifndef header guard has wrong style, please use: SRC_ROBOT_VIEWER_H_  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/robot_viewer.h:222:  #endif line should be "#endif  // SRC_ROBOT_VIEWER_H_"  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/robot_land.h:1:  #ifndef header guard has wrong style, please use: SRC_ROBOT_LAND_H_  [build/header_guard] [5]
/export/scratch/cpplint-gitbot/./src/robot_land.h:172:  #endif line should be "#endif  // SRC_ROBOT_LAND_H_"  [build/header_guard] [5]


#### Doxygen

+ Skip: Change into directory "docs".

  This test was not run because of an earlier failing test.

+ Skip: Generating documentation by running doxygen

  This test was not run because of an earlier failing test.

+ Skip: Check that file "../src/mainpage.h" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that file "html/classrobot__land.html" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that file "html/classObstacle.html" exists.

  This test was not run because of an earlier failing test.

