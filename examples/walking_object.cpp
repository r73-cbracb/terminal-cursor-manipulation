#define _GETCH_FUNCTION_INCLUDES // enable the "getch()" function 
#define _NORMAL_INCLUDES		// enable the includes in the header

#include "../cursor_manipulation.h"

int main(){
	RESET_TERMINAL;					// reset terminal for calibration
	CSAVE; 							// save the position
	std::cout << "o" << std::flush; // print our character 
	
	char key_pressed = ' ';
	while((key_pressed = getch()) != '\n'){ // to get out, press "enter"
		if(key_pressed == 'w'){
			CRESTORE;
			std::cout << " " << std::flush;
			CRESTORE;

			CMOVE_UP;
			CSAVE;
			std::cout << "o" << std::flush;
		}else if(key_pressed == 'a'){
			CRESTORE;
			std::cout << " " << std::flush;
			CRESTORE;

			CMOVE_LEFT;
			CMOVE_LEFT;
			CSAVE;
			std::cout << "o" << std::flush;
		}else if(key_pressed == 's'){
			CRESTORE;
			std::cout << " " << std::flush;
			CRESTORE;

			CMOVE_DOWN;
			CSAVE;
			std::cout << "o" << std::flush;
		}else if(key_pressed == 'd'){
			CRESTORE;
			std::cout << " " << std::flush;
			CRESTORE;

			CMOVE_RIGHT;
			CSAVE;
			std::cout << "o" << std::flush;
		}
	}
	return 0;
}