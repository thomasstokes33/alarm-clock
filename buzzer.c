#include "buzzer.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdint.h>


void playNote(uint gpio, float frequency) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    
    uint pwmSlice = pwm_gpio_to_slice_num(gpio);

    float divider = 1.0f;
    uint32_t sys_clk_freq = clock_get_hz(clk_sys);
    uint32_t wrap_value = sys_clk_freq / (divider * frequency);
    while (wrap_value > 65535) {
        divider *= 2.0f;
        wrap_value = sys_clk_freq / (divider * frequency);
    }

    pwm_set_clkdiv(pwmSlice, divider);

    pwm_set_wrap(pwmSlice, wrap_value);

    uint32_t dutyCycle = wrap_value / 2;
    pwm_set_chan_level(pwmSlice, PWM_CHAN_A, dutyCycle);

    pwm_set_enabled(pwmSlice, true);
    busy_wait_ms(500);
    pwm_set_enabled(pwmSlice,false);
}
