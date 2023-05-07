#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdint.h>


extern float freq; //extern makes the freq variable global. static would create a static instance for each source file, each with the same name (which is confusing)
void playNote(uint, float ) ;

	
#endif
