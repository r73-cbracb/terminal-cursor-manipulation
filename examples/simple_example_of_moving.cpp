#define _NORMAL_INCLUDES
#include "../cursor_manipulation.h"


// for "usleep()" function
#include "unistd.h"
#define SLEEP usleep(1000000) // delete a zero if it's too slow for you

int main(){
	RESET_TERMINAL;
	// starts at (1,1)
	std::cout << "A" << std::flush;
	
	CMOVE_AT(2,2);
	CSAVE;	// Save (2,2)
	SLEEP;
	std::cout << "B" << std::flush;
	
	CMOVE_AT(3,3);
	SLEEP;
	std::cout << "C" << std::flush;
	
	CMOVE_AT(4,4);
	SLEEP;
	std::cout << "D" << std::flush;
	
	CMOVE_AT(5,5);
	SLEEP;
	std::cout << "E" << std::flush;

	// go back to the saved position
	CRESTORE;
	SLEEP;
	std::cout << "F" << std::flush;


	return 0;
}