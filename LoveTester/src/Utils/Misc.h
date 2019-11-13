#pragma once

//
// Copyright (C) 2019 Pharap (@Pharap)
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

template< typename Type >
constexpr Type absoluteDifference(Type value0, Type value1)
{
	return (value0 < value1) ? (value1 - value0) : (value0 - value1);
}

template< typename Type >
constexpr Type integerRound(Type value)
{
	return (((value % 2) == 0) ? value : value + 1);
}

template< typename Type >
constexpr Type divideBy2Rounded(Type value)
{
	return (integerRound(value) / 2);
}

template< typename Type >
constexpr Type calculateCentre(Type largerDimension, Type dimension)
{
	return (divideBy2Rounded(largerDimension) - divideBy2Rounded(dimension));
}

#include <Arduboy2.h>

constexpr uint8_t screenWidth = WIDTH;
constexpr uint8_t screenHeight = HEIGHT;

constexpr int16_t calculateCentreX(uint8_t width)
{
	return calculateCentre(screenWidth, width);
}

constexpr int16_t calculateCentreY(uint8_t height)
{
	return calculateCentre(screenHeight, height);
}