#ifndef SEVEN_SEGMENTS_H
#define SEVEN_SEGMENTS_H

#include <stdint.h>

#define DIGIT_0 0b00111111
#define DIGIT_1 0b00000110
#define DIGIT_2 0b01011011
#define DIGIT_3 0b01001111
#define DIGIT_4 0b01100110
#define DIGIT_5 0b01101101
#define DIGIT_6 0b01111101
#define DIGIT_7 0b00000111
#define DIGIT_8 0b01111111
#define DIGIT_9 0b01101111
#define DIGIT_A 0b01110111
#define DIGIT_B 0b01111100
#define DIGIT_b 0b01111100
#define DIGIT_C 0b00111001
#define DIGIT_d 0b01011110
#define DIGIT_D 0b01011110
#define DIGIT_E 0b01111001
#define DIGIT_F 0b01110001
#define DIGIT_g 0b01111101
#define DIGIT_H 0b01110110
#define DIGIT_h 0b01110100
#define DIGIT_L 0b00111000
#define DIGIT_l DIGIT_1
#define DIGIT_O DIGIT_0
#define DIGIT_o 0b01011100
#define DIGIT_r 0b01010000
#define DIGIT_W 0b00111110
#define DIGIT_w 0b00011100
#define DIGIT_sp 0b00000000
#define DIGIT_dp 0b10000000

typedef void (*seven_segments_print_fptr)(uint8_t map);
typedef void (*seven_segments_power_fptr)(uint8_t state);

struct seven_segments {
    uint8_t value;
    uint8_t dot;
    uint8_t clear;
    seven_segments_print_fptr print;
    seven_segments_power_fptr power;
};

void seven_segments_print(struct seven_segments *dev);
void seven_segments_loading(struct seven_segments *dev, uint8_t state);

#endif /* SEVEN_SEGMENTS_H */
