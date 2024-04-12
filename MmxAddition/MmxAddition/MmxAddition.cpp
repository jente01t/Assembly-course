

#include <iostream>
#include "MmxVal.h"

enum MmxAddOp : unsigned int {
	paddb,		// packed byte addition with wraparound 
	paddsb,		// packed byte addition with signed saturation
	paddusb,	// packed byte addition with unsiged saturation
	paddw,		// packed word addition with wraparound
	paddsw,		// packed word addition with signed saturation
	paddusw,	// packed word addition with unsigned saturation
	paddd,		// packed doubleword addition with wraparound
};

extern "C" MmxVal MmxAdd(MmxVal a, MmxVal b, MmxAddOp op);

int main()
{
    std::cout << "Hello World!\n";
}

