#ifndef _SH1106_DSPI_H
#define _SH1106_DSPI_H

#include <SH1106.h>

#include <DSPI.h>

class SH1106_DSPI : public SH1106 {
    private:
        DSPI *_dspi;
        uint8_t _cs;
        uint8_t _dc;
        uint8_t _res;

    public:
        SH1106_DSPI(DSPI &dspi, uint8_t cs, uint8_t dc, uint8_t res = 255) :
            _dspi(&dspi), _cs(cs), _dc(dc), _res(res), SH1106() {}
        SH1106_DSPI(DSPI *dspi, uint8_t cs, uint8_t dc, uint8_t res = 255) :
            _dspi(dspi), _cs(cs), _dc(dc), _res(res), SH1106() {}


        void command(uint8_t c);
        void command(uint8_t c, uint8_t p);
        void data(uint8_t d);
        void data(uint8_t *d, uint32_t l);

        void initializeDevice();

};
#endif
