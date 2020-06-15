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

#include <stdint.h>

#include "HeartState.h"

class Arduboy2;

class LoveMeter
{
private:
	uint8_t value;

public:
	HeartState leftHeartState;
	HeartState rightHeartState;

	uint8_t getValue() const
	{
		return this->value;
	}

	void setValue(uint8_t value)
	{
		this->value = (value % 100);
	}

	void adjustBy(int value)
	{
		const int result = (this->value + value);
		this->value = (result < 0) ? (100 + (result % 100)) : (result % 100);
	}

	void render(Arduboy2 &) const;
};