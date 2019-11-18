#ifndef MAIN_H
#define MAIN_H

#include "mserial.h"
#include "get_rssi.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct {
	uint8_t head1;
	uint8_t head2;
	uint8_t head3;
	uint8_t type;
	uint16_t data;
}data_frame;

void frame_set(data_frame* src, uint8_t head1,uint8_t head2,uint8_t head3,uint8_t type,uint16_t data);

#endif

