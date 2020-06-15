#include "LoveMeter.h"

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

#include <Arduboy2.h>
#include <math.h>

#include "Game.h"
#include "Images.h"
#include "Utils.h"

struct Point2
{
	uint8_t x;
	uint8_t y;
};

constexpr Point2 points[] PROGMEM
{
	{ 21, 36 }, { 35, 26 }, { 52, 20 }, { 75, 20 }, { 92, 26 }, { 106, 36 },
};

inline Point2 getMeterPoint(uint8_t value)
{
	constexpr size_t steps = getSize(points);
	constexpr uint8_t divisor = (100 / (steps - 1));

	const uint8_t quotient = (value / divisor);
	const uint8_t remainder = (value % divisor);

	const size_t index0 = quotient;
	const size_t index1 = (index0 + 1);

	const uint8_t x0 = pgm_read_byte(&points[index0].x);
	const uint8_t y0 = pgm_read_byte(&points[index0].y);
	const uint8_t x1 = pgm_read_byte(&points[index1].x);
	const uint8_t y1 = pgm_read_byte(&points[index1].y);

	const float factor = (static_cast<float>(remainder) / static_cast<float>(divisor));

	const uint8_t x = static_cast<uint8_t>(lerp(x0, x1, factor));
	const uint8_t y = static_cast<uint8_t>(lerp(y0, y1, factor));

	return { x, y };
}

constexpr uint8_t getHeartFrame(HeartState heartState)
{
	return static_cast<uint8_t>(heartState);
}

void LoveMeter::render(Arduboy2 & arduboy) const
{
	// Draw dial
	Sprites::drawOverwrite(0, 0, Images::loveMeter, 0);

	// Draw hearts
	constexpr uint8_t leftHeartX = 4;
	constexpr uint8_t leftHeartY = 8;

	constexpr uint8_t rightHeartX = (WIDTH - (leftHeartX + Images::heartWidth));
	constexpr uint8_t rightHeartY = leftHeartY;

	Sprites::drawOverwrite(leftHeartX, leftHeartY, Images::heart, getHeartFrame(this->leftHeartState));
	Sprites::drawOverwrite(rightHeartX, rightHeartY, Images::heart, getHeartFrame(this->rightHeartState));

	// Draw pointer
	constexpr Point2 startPoint { 63, 50 };

	const Point2 endPoint = getMeterPoint(this->value);

	arduboy.drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y, WHITE);
}