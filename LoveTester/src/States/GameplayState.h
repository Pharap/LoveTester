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

// Predeclare Game
class Game;

class GameplayState
{
private:
	enum class GameplaySubState
	{
		AwaitingUsers,
		Testing,
		Result,
	};

private:
	static constexpr uint16_t fps = 60;
	static constexpr uint16_t updatesRequired = (5 * fps);

private:
	uint16_t updatesRemaining = updatesRequired;
	bool testComplete = false;

public:
	void update(Game &);
	void render(Game &);
};