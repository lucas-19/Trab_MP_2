#include "romano.hpp"
using namespace std;
#include <iostream>
#define SUCCESS 1
#define FAILURE 0


int RomanToDecimal(char const * roman) {
    int i = 0;
    int integer = 0;
    int counterC = 0;
    int counterX = 0;
    while(roman[i] != '\0'){

        if(roman[i] == 'M'){
            if(roman[i - 1] == 'C'){
                if(roman[i - 2] == 'C'){
                    return 0;
                }else {
                    if(roman[i + 1] == 'M'){
                        return 0;
                    }
                    integer -= 100;
                }
            }    
            integer += 1000;
        }

        if(roman[i] == 'D') {
            if(roman[i - 1] == 'C'){
                if(roman[i - 2] == 'C'){
                    return 0;
                } else{
                    integer -= 100;
                }
            } else if(roman[i - 1] == 'D' || roman[i - 1] == 'X' || roman[i - 1] == 'I' || roman[i - 1] == 'L' || roman[i - 1] == 'V'){
                return 0;
            }
            integer += 500;
        }

        if(roman[i] == 'C' && roman[i + 1] != 'M' && roman[i + 1] != 'D'){
            if(roman[i - 1] == 'X'){
                counterC--;
                if(roman[i - 2] == 'X' || roman[i + 1] == 'X'){
                    return 0;
                } else{
                    if(roman[i + 1] == 'C'){
                        return 0;
                    }
                    integer -= 10; 
                }
            }
            counterC++;
            if(counterC > 3){
                return 0;
            }
            integer += 100;
        }

        if(roman[i] == 'L') {
            if(roman[i - 1] == 'X'){
                if(roman[i - 2] == 'X'){
                    return 0;
                } else{
                    integer -= 10;
                }
            } else if(roman[i - 1] == 'L' || roman[i - 1] == 'I' || roman[i - 1] == 'V'){
                return 0;
            }
            integer += 50;
        }

        if(roman[i] == 'X' && roman[i + 1] != 'C' && roman[i + 1] != 'L'){
            if(roman[i - 1] == 'I'){
                counterX--;
                if(roman[i - 2] == 'I' || roman[i + 1] == 'I'){
                    return 0;
                } else{
                    if(roman[i + 1] == 'X'){
                        return 0;
                    }
                    integer -= 1;

                }
            }
            counterX++;
            if(counterX > 3) {
                return 0;
            }
            integer += 10;
        }

        i++;
    }
    if(integer > 3000 || i >= 31){
        return 0;
    }
    else{
        return integer;
    }
}