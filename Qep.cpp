/*
 * Qep.cpp
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#include "Qep.h"

Qep::Qep(bool inverted, int32_t startPosition) :
        inverted(inverted), absPosition(startPosition) {
    delta = 0;
}

void Qep::update() {
    absPosition += delta;
}
