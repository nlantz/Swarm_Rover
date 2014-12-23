#ifndef COM_MANAGER_INT_h
#define COM_MANAGER_INT_h

#include "Arduino.h"

#define TOPBIT 0x80000000 //mask for transmit 

// Pulse parms are *50-100 for the Mark and *50+100 for the space
// First MARK is the one after the long gap
// pulse parameters in usec
#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1600
#define NEC_ZERO_SPACE	560

#define MARK  0 //defines mark for IR transmit RX (active low)
#define SPACE 1 //definws space for IR transmit TX (active low)




#endif
