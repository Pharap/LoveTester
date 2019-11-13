#include "SplashScreenState.h"

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

#include "../Game.h"
#include "../Images.h"
#include "../Utils.h"

void SplashScreenState::update(Game & game)
{
	auto & arduboy = game.getArduboy();

	if(arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON))
	{
		game.setGameState(GameState::TitleScreen);
		return;
	}
	
	// TODO: fix this god-awful mess
	if (blinkDelay > 0)
	{
		if (arduboy.everyXFrames(60))
		{
			--this->blinkDelay;
			if (blinkDelay == 0)
				this->blinkInvert = !this->blinkInvert;
		}
	}
	else if (arduboy.everyXFrames(2))
	{
		if (this->blinkInvert)
		{
			if (this->blinkTick > blinkTickMin)
				--this->blinkTick;
			else
			{
				const uint8_t randomVariance = (static_cast<uint8_t>(random()) % (blinkDelayVariance + 1));
				this->blinkDelay = (blinkDelayDefault + randomVariance);
			}
		}
		else
		{
			if (this->blinkTick < blinkTickMax)
				++this->blinkTick;
			else
				this->blinkInvert = !this->blinkInvert;
		}
	}
}

void SplashScreenState::render(Game & game)
{
	auto & arduboy = game.getArduboy();

	constexpr uint8_t x = calculateCentreX(Images::pharapLogoWidth);
	constexpr uint8_t y = calculateCentreY(Images::pharapLogoHeight);

	Sprites::drawOverwrite(x, y, Images::pharapLogo, 0);
	arduboy.fillRect(x + 14, y + 15, 20, this->blinkTick, WHITE);
	arduboy.fillRect(x + 14, (y + 27) - this->blinkTick, 20, this->blinkTick, WHITE);
}