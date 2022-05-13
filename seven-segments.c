#include "seven-segments.h"

uint8_t digit_tab[] = {
    DIGIT_0,
    DIGIT_1,
    DIGIT_2,
    DIGIT_3,
    DIGIT_4,
    DIGIT_5,
    DIGIT_6,
    DIGIT_7,
    DIGIT_8,
    DIGIT_9,
    DIGIT_A,
    DIGIT_B,
    DIGIT_C,
    DIGIT_D,
    DIGIT_E,
    DIGIT_F,
};

uint8_t alphabet[] = {
    DIGIT_A , //A
    DIGIT_b , //B
    DIGIT_C , //C
    DIGIT_d , //D
    DIGIT_E , //E
    DIGIT_F , //F
    DIGIT_g , //G
    DIGIT_h , //H
    0       , //I
    0       , //J
    0       , //K
    DIGIT_l , //L
    0       , //M
    0       , //N
    DIGIT_O , //O
    0       , //P
    0       , //Q
    DIGIT_r , //R
    0       , //S
    0       , //T
    0       , //U
    0       , //V
    DIGIT_w , //W
    0       , //X
    0       , //Y
    0       , //Z
};

uint8_t loading[] = {
    0b00100001,
    0b00000011,
    0b00000110,
    0b00001100,
    0b00011000,
    0b00110000,
};

void seven_segments_print(struct seven_segments *dev)
{
    uint8_t map = 0;
    if(dev->value <= 0x0F)
    {
        map = digit_tab[dev->value];
    }
    else if(dev->value >= 'a' && dev->value <= 'z')
    {
        map = alphabet[dev->value-'a'];
    }
    else if(dev->value >= '0' && dev->value <= '9')
    {
        map = digit_tab[dev->value-'0'];
    }

    if(dev->clear == 1)
    {
        map = 0;
        dev->clear = 0;
    }
    
    if(dev->dot)
    {
        map |= DIGIT_dp;
    }

    dev->print(map);
}

void seven_segments_loading(struct seven_segments *dev, uint8_t state)
{
    uint8_t map = 0;
    if(state < 6)
    {
        map = loading[state];
    }

    if(dev->clear == 1)
    {
        map = 0;
        dev->clear = 0;
    }

    if(dev->dot)
    {
        map |= DIGIT_dp;
    }

    dev->print(map);
}