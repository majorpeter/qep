/*
 * Qep.h
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#ifndef QEP_QEP_H_
#define QEP_QEP_H_

#include <stdint.h>

class Qep {
public:
    Qep(bool inverted = false, int32_t startPosition = 0);
    virtual ~Qep() {}

    /**
     * This method must calculate 'delta' value in implementations.
     *
     * Base class implementation simply adds delta to absPosition.
     */
    virtual void update();

    inline int32_t getDeltaValue() {
        return delta;
    }

    inline int32_t getAbsolutePosition() {
        return absPosition;
    }
protected:
    const bool inverted;
    int32_t absPosition;
    int32_t delta;
};

#endif /* QEP_QEP_H_ */
