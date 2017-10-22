/*
 * QepStm32F1Gpio.cpp
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#include "QepStm32F1Gpio.h"
#include <stm32f10x_gpio.h>
#include <stdio.h>

#define DEBUG_PRINTF(...)

QepStm32F1Gpio::QepStm32F1Gpio(GPIO_TypeDef * const portA, uint16_t pinA,
        GPIO_TypeDef * const portB, uint16_t pinB, bool inverted,
        int32_t startPosition) :
        Qep(inverted, startPosition), portA(portA), pinA(pinA), portB(portB), pinB(pinB) {
    phase = 0;
}

void QepStm32F1Gpio::init() {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;  // enable weak pull down, just in case
    GPIO_InitStruct.GPIO_Pin = pinA;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(portA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = pinB;
    GPIO_Init(portB, &GPIO_InitStruct);
}

void QepStm32F1Gpio::update() {
    /*
     * | Phase |  A |  B | (A << 1 | B) |
     * |-------|----|----|--------------|
     * | 0     | 0  | 0  | 0            |
     * | 1     | 0  | 1  | 1            |
     * | 2     | 1  | 1  | 3            |
     * | 3     | 1  | 0  | 2            |
     */
    static const int8_t phaseLut[] = {0, 1, 3, 2};
    static const uint8_t phaseCount = sizeof(phaseLut) / sizeof(phaseLut[0]);

    uint8_t a = GPIO_ReadInputDataBit(portA, pinA);
    uint8_t b = GPIO_ReadInputDataBit(portB, pinB);
    int8_t phase = phaseLut[(a << 1) | b];

    switch (phase - this->phase) {
    case 1:
        delta = inverted ? -1 : 1;
        break;
    case -1:
    case phaseCount - 1:
        delta = inverted ? 1 : -1;
        break;
    default:
        delta = 0;
        break;
    }
    this->phase = phase;

    DEBUG_PRINTF("phase=%d A=%d B=%d\n", phase, a, b);

    Qep::update();
}
