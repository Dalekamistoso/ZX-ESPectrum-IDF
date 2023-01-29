///////////////////////////////////////////////////////////////////////////////
//
// ZX-ESPectrum - ZX Spectrum emulator for ESP32
//
// Copyright (c) 2020, 2021 David Crespo [dcrespo3d]
// https://github.com/dcrespo3d/ZX-ESPectrum-Wiimote
//
// Based on previous work by Ramón Martinez, Jorge Fuertes and many others
// https://github.com/rampa069/ZX-ESPectrum
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#include "MemESP.h"
#include <stddef.h>

uint8_t* MemESP::rom[4];

uint8_t* MemESP::ram0 = NULL;
uint8_t* MemESP::ram1 = NULL;
uint8_t* MemESP::ram2 = NULL;
uint8_t* MemESP::ram3 = NULL;
uint8_t* MemESP::ram4 = NULL;
uint8_t* MemESP::ram5 = NULL;
uint8_t* MemESP::ram6 = NULL;
uint8_t* MemESP::ram7 = NULL;
uint8_t* MemESP::ram[8];

volatile uint8_t MemESP::bankLatch = 0;
volatile uint8_t MemESP::videoLatch = 0;
volatile uint8_t MemESP::romLatch = 0;
volatile uint8_t MemESP::pagingLock = 0;
uint8_t MemESP::modeSP3 = 0;
uint8_t MemESP::romSP3 = 0;
uint8_t MemESP::romInUse = 0;

