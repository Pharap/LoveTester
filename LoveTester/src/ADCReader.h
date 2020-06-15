#pragma once

//
// Copyright (C) 2019-2020 Pharap (@Pharap)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// For analogRead
#include <Arduino.h>

// For power_adc_enable() and power_adc_disable()
#include <avr/power.h>

template< int pinValue >
struct ADCReader
{
	static constexpr int pin = pinValue;

	uint16_t read() const
	{
		return analogRead(pin);
	}

	void enable()
	{
		power_adc_enable();
	}

	void disable()
	{
		power_adc_disable();
	}
};