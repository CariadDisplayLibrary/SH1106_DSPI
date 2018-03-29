#include <SH1106_DSPI.h>

void SH1106_DSPI::initializeDevice() {
    _dspi->begin();
    pinMode(_cs, OUTPUT);
    digitalWrite(_cs, HIGH);
    pinMode(_dc, OUTPUT);
    digitalWrite(_dc, HIGH);
    if (_res != 255) {
        pinMode(_res, OUTPUT);
        digitalWrite(_res, HIGH);
        delay(10);
        digitalWrite(_res, LOW);
        delay(10);
        digitalWrite(_res, HIGH);
    }
    initDevice();
}

void SH1106_DSPI::command(uint8_t c) {
    digitalWrite(_dc, LOW);
    digitalWrite(_cs, LOW);
    _dspi->transfer(c);
    digitalWrite(_cs, HIGH);
}

void SH1106_DSPI::command(uint8_t c, uint8_t p) {
    digitalWrite(_dc, LOW);
    digitalWrite(_cs, LOW);
    _dspi->transfer(c);
    _dspi->transfer(p);
    digitalWrite(_cs, HIGH);
}

void SH1106_DSPI::data(uint8_t d) {
    digitalWrite(_dc, HIGH);
    digitalWrite(_cs, LOW);
    _dspi->transfer(d);
    digitalWrite(_cs, HIGH);
}

void SH1106_DSPI::data(uint8_t *d, uint32_t l) {
    digitalWrite(_dc, HIGH);
    digitalWrite(_cs, LOW);
    for (uint32_t i = 0; i < l; i++) {
        _dspi->transfer(d[i]);
    }
    digitalWrite(_cs, HIGH);
}


