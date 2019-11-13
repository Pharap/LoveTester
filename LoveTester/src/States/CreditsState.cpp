#include "CreditsState.h"

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
#include "../Utils.h"
#include "../Strings.h"

void CreditsState::update(Game & game)
{
	auto & arduboy = game.getArduboy();

	if(arduboy.justPressed(B_BUTTON))
		game.setGameState(GameState::TitleScreen);
}

void CreditsState::render(Game & game)
{
	auto & arduboy = game.getArduboy();

	// TODO: Make this prettier
	for(size_t index = 0; index < getSize(Strings::creditsText); ++index)
		arduboy.println(readFlashStringPointer(&Strings::creditsText[index]));
}