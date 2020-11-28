/**
 * NOTE: put semicolon at the end each time you use this macros
**/

#ifndef _CURSOR_MANIPULATION_H
#define _CURSOR_MANIPULATION_H

// For Implentation of "getch()" function in linux
// this automatically defines _GETCH_FUNCTION, so you don't need to redefine it
#ifdef _GETCH_FUNCTION_INCLUDES
#define _GETCH_FUNCTION_
#include <unistd.h>
#include <termios.h>
#endif // _GETCH_FUNCTION_INCLUDES

// Basic Terminal Stuffs
#define CLEAR_SCREEN 	std::cout << "\033[2J"
#define RESET_CURSOR 	std::cout << "\033[1;1H"
#define RESET_TERMINAL	CLEAR_SCREEN; RESET_CURSOR

// Moving Manipulation
#define CMOVE_AT(x,y) 			std::cout << "\033[" << y << ";" << x << "H"
#define CMOVE_AT_PRINT(x,y,ch) 	std::cout << "\033[" << y << ";" << x << "H"; \
							   	std::cout << ch << std::flush

// Manual Moving Manipulation
#define CMOVE_UP		std::cout << "\033[1A"
#define CMOVE_DOWN		std::cout << "\033[1B"
#define CMOVE_RIGHT		std::cout << "\033[1C"
#define CMOVE_LEFT		std::cout << "\033[1D"

// Manual Moving Manipulation 'x' times
#define CMOVE_UP_T(x)		std::cout << "\033[" << x << "A"
#define CMOVE_DOWN_T(x)		std::cout << "\033[" << x << "B"
#define CMOVE_RIGHT_T(x)	std::cout << "\033[" << x << "C"
#define CMOVE_LEFT_T(x)		std::cout << "\033[" << x << "D"

// Save Cursor Position
#define CSAVE 		std::cout << "\033[s"
#define CRESTORE 	std::cout << "\033[u"

#ifdef _C_ADDON_MANIP
#define COUT_FLUSH std::cout.flush()
#endif //_C_ADDON_MANIP

#ifdef _GETCH_FUNCTION_
// NOTE: ONLY FOR LINUX
// NOTE: you need to define the _GETCH_FUNCTION_INCLUDES or manually includes
// the 2 library needed.

// return the pressed character of the user
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}
#endif // _GETCH_FUNCTION_

#endif // _CURSOR_MANIPULATION_H
