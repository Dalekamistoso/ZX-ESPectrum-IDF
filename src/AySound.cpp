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

#include "AySound.h"
#include "hardconfig.h"
#include "ESPectrum.h"
#include "ayemu.h"

// Registers
// regs[0] = finePitchChannelA;
// regs[1] = coarsePitchChannelA;
// regs[2] = finePitchChannelB;
// regs[3] = coarsePitchChannelB;
// regs[4] = finePitchChannelC;
// regs[5] = coarsePitchChannelC;
// regs[6] = noisePitch;
// regs[7] = mixer;
// regs[8] = volumeChannelA;
// regs[9] = volumeChannelB;
// regs[10] = volumeChannelC;
// regs[11] = envelopeFineDuration;
// regs[12] = envelopeCoarseDuration;
// regs[13] = envelopeShape;
// regs[14] = ioPortA;
uint8_t AySound::regs[15] = { 0xFF };

// Status
uint8_t AySound::selectedRegister = 0xFF;

void AySound::update()
{
 	ayemu_set_regs(&ESPectrum::ay, regs);
}

uint8_t AySound::getRegisterData()
{

	if (selectedRegister < 15) return regs[selectedRegister];

	return 0;

}

void AySound::selectRegister(uint8_t registerNumber)
{
	selectedRegister = registerNumber;
}

void AySound::setRegisterData(uint8_t data)
{
	
	if (selectedRegister < 15) {
		regs[selectedRegister] = data;	
    	update();
	}

}

void AySound::reset()
{

	for (int i=0;i<15;i++) regs[i] = 0xFF;

	// Vol = 0
	regs[8]=0;
	regs[9]=0;
	regs[10]=0;

	selectedRegister = 0xFF;

	update();

}
