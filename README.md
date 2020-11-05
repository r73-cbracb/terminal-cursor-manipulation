# terminal-cursor-manipulation
A header for cursor manipulation using ANSI escape sequence for c/c++ programming language.

## Features

### Basic Stuffs
- **CLEAR_SCREEN**            --> clear the screen
- **RESET_CURSOR**            --> reset the cursor to (1,1) in the terminal
- **RESET_TERMINAL**          --> Call the CLEAR_SCREEN then RESET_CURSOR

### Moving Functions
- **CMOVE_UP**                --> Move Up by 1
- **CMOVE_DOWN**              --> Move Down by 1
- **CMOVE_RIGHT**             --> Move Right by 1
- **CMOVE_LEFT**              --> Move LEFT by 1
- **CMOVE_UP_T(x)**	          --> Move Up by x times
- **CMOVE_DOWN_T(x)**         --> Move Down by x times
- **CMOVE_RIGHT_T(x)**        --> Move Right by x times
- **CMOVE_LEFT_T(x)**         --> Move Left by x times

- **CSAVE** 	                --> Save current cursor position
- **CRESTORE**                --> Restore the saved position
- **CMOVE_AT(x,y)** 		      --> Move cursor at **(x,y)** in the terminal
- **CMOVE_AT_PRINT(x,y,ch)**  --> Move the cursor at **(x,y)** then print 'ch'

### Add-ons
- **gethc()** --> returns the pressed character of the user without the need of pressing the enter key
