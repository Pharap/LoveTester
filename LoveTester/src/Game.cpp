#include "Game.h"

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

void Game::setup()
{
	arduboy.begin();
	arduboy.initRandomSeed();
	adcReader.enable();
}

void Game::loop()
{
	if(!this->arduboy.nextFrame())
		return;

	this->arduboy.pollButtons();

	this->arduboy.clear();

	switch(this->gameState)
	{
		case GameState::SplashScreen:
			this->splashScreenState.update(*this);
			this->splashScreenState.render(*this);
			break;
		case GameState::TitleScreen:
			this->titleScreenState.update(*this);
			this->titleScreenState.render(*this);
			break;
		case GameState::Credits:
			this->creditsState.update(*this);
			this->creditsState.render(*this);
			break;
		case GameState::Gameplay:
			this->gameplayState.update(*this);
			this->gameplayState.render(*this);
			break;
	}

	this->arduboy.display();
}