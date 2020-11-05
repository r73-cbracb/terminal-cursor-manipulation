#define _GETCH_FUNCTION_INCLUDES    // for "getch()" function
#define _NORMAL_INCLUDES            // for <iostream>

#include "cursor_manipulation.h"



//SOME FUNCTIONS THE Don't do anything but print
// __func__ --> returns the function name its currently at
void open_file(){
    std::cout << __func__ << std::endl;
}
void help(){
    std::cout << __func__ << std::endl;
}
void exit(){
    std::cout << __func__ << std::endl;
}
////////////////////////////////////////////
int cycle_menu(const short start_y, const short start_x, const short max_line){
    
    int current_option = start_y;
    char key_pressed = ' ';
    while((key_pressed = getch()) != '\n'){
        if(key_pressed == 'w'){
            if(current_option > start_y){
                CMOVE_AT(12, current_option);
                std::cout << ' ';
                CMOVE_AT(12, --current_option);
                std::cout << 'X';
                std::cout.flush();
            }
        }else if(key_pressed == 's'){
            if(current_option < max_line ){
                CMOVE_AT(12, current_option);
                std::cout << ' ';
                CMOVE_AT(12, ++current_option);
                std::cout << 'X';
                std::cout.flush();
            }
        }
    }
    // Go to the last line
    CMOVE_AT(1,5);
    return current_option;
}
void menu(){
    // the start_y is '2' because 'X' is located at the 2nd line in the
    // terminal
    
    // the start_x is '12' because 'X' is located at the 12th string of the
    // string literal "Open File:[X]"

    // max_line is '4' because, that is the maximum value the 'X' can cycle
    int start_y = 2, start_x = 12, max_line = 4;
    std::cout << "File Reader (Excel):" << std::endl;
    std::cout << "Open File:[X]" << std::endl;
    std::cout << "Help:     [ ]" << std::endl;
    std::cout << "Exit:     [ ]" << std::endl;
    
    int user_option = cycle_menu(start_y, start_x, max_line);
    
    switch (user_option)
    {
    case 2:
        open_file();
        break;
    case 3:
        help();
        break;
    case 4:
        exit();
        break;    
    default:
        break;
    }
}

int main(){
    RESET_TERMINAL; // mandatory
    menu();    
    return 0;
}