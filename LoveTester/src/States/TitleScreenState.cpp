#include "TitleScreenState.h"

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

#include "../Game.h"
#include "../Utils.h"
#include "../Strings.h"
#include "../Images.h"

struct Option
{
	GameState gameState;
	const char * text;
};

constexpr Option options[] PROGMEM
{
	{ GameState::Gameplay, Strings::titleOption0 },
	{ GameState::Credits, Strings::titleOption1 },
};

constexpr size_t firstOptionIndex = 0;
constexpr size_t lastOptionIndex = (getSize(options) - 1);

void TitleScreenState::update(Game & game)
{
	auto & arduboy = game.getArduboy();

	if(arduboy.justPressed(UP_BUTTON))
		if(this->optionIndex > firstOptionIndex)
			--this->optionIndex;

	if(arduboy.justPressed(DOWN_BUTTON))
		if(this->optionIndex < lastOptionIndex)
			++this->optionIndex;

	if(arduboy.justPressed(A_BUTTON))
	{
		const GameState gameState = static_cast<GameState>(pgm_read_byte(&options[this->optionIndex].gameState));
		game.setGameState(gameState);
	}
}

void TitleScreenState::render(Game & game)
{
	auto & arduboy = game.getArduboy();

	// Draw title
	constexpr uint8_t titleX = calculateCentreX(Images::titleWidth);
	constexpr uint8_t titleY = 8;

	Sprites::drawOverwrite(titleX, titleY, Images::title, 0);

	// Print options
	constexpr uint8_t fontHeight = 8;
	constexpr uint8_t fontWidth = 6;

	constexpr uint8_t prefixSize = 2;
	constexpr uint8_t optionWidth = (((getSize(Strings::titleOption1) - 1) + prefixSize) * fontWidth);

	constexpr uint8_t selectionX = calculateCentre<int>(WIDTH, optionWidth);
	constexpr uint8_t selectionY = (titleY + Images::titleHeight + 8);

	for(size_t index = 0; index < getSize(options); ++index)
	{
		const uint8_t yOffset = (index * fontHeight);
		arduboy.setCursor(selectionX, selectionY + yOffset);
		
		const FlashStringHelper prefix = (index == this->optionIndex) ? F("> ") : F("  ");
		arduboy.print(prefix);

		const FlashStringHelper text = readFlashStringPointer(&options[index].text);
		arduboy.print(text);
	}
}