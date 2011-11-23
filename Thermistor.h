/*
 * 2011 Eberhard Rensch, Pleasant Software
 *
 * Based on parts of the Makerbot firmware
 * Copyright 2010 by Adam Mayer	 <adam@makerbot.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef THERMISTOR_HH_
#define THERMISTOR_HH_

#include <stdint.h>

#define THERM_TABLE_SIZE 20
#define SAMPLE_COUNT 4

struct ThermTableEntry {
	int16_t adc;
	int16_t celsius;
} __attribute__ ((packed));

class Thermistor {
private:
        uint16_t current_temp;
	uint8_t analog_pin; // index of analog pin
	const static int ADC_RANGE = 1024;
	int16_t sample_buffer[SAMPLE_COUNT];
	uint8_t next_sample;
	const uint8_t table_index;

public:
	Thermistor(uint8_t analog_pin, uint8_t table_index);

        int16_t getTemperature() const { return current_temp; }

	// True if update initiated, false otherwise
	bool update();
};

#endif //THERMISTOR_H
