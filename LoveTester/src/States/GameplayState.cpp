#include "GameplayState.h"

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

constexpr int16_t getVariance(uint16_t value)
{
	return ((value & 0x08) != 0) ? -(value & 0x07) : (value & 0x07);
}

void GameplayState::update(Game & game)
{
	// Get arduboy
	auto & arduboy = game.getArduboy();

	// Return to titlescreen if B pressed
	if(arduboy.justPressed(B_BUTTON))
		game.setGameState(GameState::TitleScreen);

	if(this->testComplete)
	{
		// Reset if A pressed
		if(arduboy.justPressed(A_BUTTON))
			testComplete = false;
	}
	else
	{
		// Get love meter
		auto & loveMeter = game.getLoveMeter();

		// Check if users are present
		const bool isPersonAPresent = arduboy.pressed(LEFT_BUTTON);
		const bool isPersonBPresent = arduboy.pressed(RIGHT_BUTTON);
	
		// Update heart states
		loveMeter.leftHeartState = (isPersonAPresent) ? HeartState::Full : HeartState::Empty;
		loveMeter.rightHeartState = (isPersonBPresent) ? HeartState::Full : HeartState::Empty;

		if(isPersonAPresent && isPersonBPresent)
		{
			// Accumulate ADC noise
			auto & adcReader = game.getADCReader();
			const uint16_t adcValue = adcReader.read();
			const int16_t variance = getVariance(adcValue);

			// Update love meter
			loveMeter.adjustBy(variance);

			// If updates remaining
			if(this->updatesRemaining > 0)
			{
				// Count down
				--this->updatesRemaining;
			}
			else
			{
				// Test complete
				this->testComplete = true;
			}
		}
		else
		{
			// Set love meter value
			loveMeter.setValue(50);
			
			// Reset counter
			this->updatesRemaining = updatesRequired;
		}
	}
}

void GameplayState::render(Game & game)
{
	// Draw love meter
	auto & loveMeter = game.getLoveMeter();
	auto & arduboy = game.getArduboy();
	loveMeter.render(arduboy);
}