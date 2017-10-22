/*
 * QepStm32F1Gpio.h
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#ifndef QEP_QEPSTM32F1GPIO_H_
#define QEP_QEPSTM32F1GPIO_H_

#include "Qep.h"
#include <stm32f10x.h>

class QepStm32F1Gpio: public Qep {
public:
    QepStm32F1Gpio(GPIO_TypeDef * const portA, uint16_t pinA,
            GPIO_TypeDef * const portB, uint16_t pinB, bool inverted = false,
            int32_t startPosition = 0);
    virtual ~QepStm32F1Gpio() {}

    virtual void init();
    virtual void update();
private:
    GPIO_TypeDef * const portA;
    const uint16_t pinA;
    GPIO_TypeDef * const portB;
    const uint16_t pinB;
    int8_t phase;
};

#endif /* QEP_QEPSTM32F1GPIO_H_ */
