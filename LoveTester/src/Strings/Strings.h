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

#include <avr/pgmspace.h>

namespace Strings
{
	constexpr char titleOption0[] PROGMEM = "Test";
	constexpr char titleOption1[] PROGMEM = "Credits";

	constexpr char creditsTextLine0[] PROGMEM = "Programming & Art:";
	constexpr char creditsTextLine1[] PROGMEM = "Pharap";
	constexpr char creditsTextLine2[] PROGMEM = "";
	constexpr char creditsTextLine3[] PROGMEM = "Inspired by the";
	constexpr char creditsTextLine4[] PROGMEM = "Nintendo Love Tester";
	constexpr char creditsTextLine5[] PROGMEM = "which was designed by";
	constexpr char creditsTextLine6[] PROGMEM = "Gunpei Yokoi";
	constexpr char creditsTextLine7[] PROGMEM = "(1941-1997)";

	constexpr const char * creditsText[] PROGMEM
	{
		creditsTextLine0, creditsTextLine1, creditsTextLine2, creditsTextLine3,
		creditsTextLine4, creditsTextLine5, creditsTextLine6, creditsTextLine7,
	};

}