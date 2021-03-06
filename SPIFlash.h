/* Audio Library for Teensy 3.X
 * Copyright (c) 2014, Pete (El Supremo), el_supremo@shaw.ca
 *
 * Development of this audio library was funded by PJRC.COM, LLC by sales of
 * Teensy and Audio Adaptor boards.  Please support PJRC's efforts to develop
 * open source software by purchasing Teensy or other PJRC products.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, development funding notice, and this permission
 * notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef SPIFlash_h
#define SPIFlash_h

#include <stdint.h>
#include <SPI.h>
 
void flash_read_id(unsigned char *idt);
unsigned char flash_read_status(void);
void flash_page_program(unsigned char *wp,int pn);
void flash_erase_pages_sector(int pn);
void flash_read_pages(unsigned char *rp,int pn,int n_pages);
void flash_fast_read_pages(unsigned char *rp,int pn,int n_pages);
void flash_chip_erase(boolean wait);
void flash_init(void);
void flash_hard_reset(void);
void write_pause(void);

class SPIFlash
{
public:
	void id(unsigned char *idt);

	void read(int page, unsigned char *data);
	void write(int page, const unsigned char *data);
	void erase(int partition);

private:
	uint8_t status(void);
};

#endif
