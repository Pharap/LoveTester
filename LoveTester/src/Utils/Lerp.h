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

constexpr float lerp(float value0, float value1, float factor)
{
	return (((1 - factor) * value0) + (factor * value1));
}

constexpr double lerp(double value0, double value1, double factor)
{
	return (((1 - factor) * value0) + (factor * value1));
}

constexpr long double lerp(long double value0, long double value1, long double factor)
{
	return (((1 - factor) * value0) + (factor * value1));
}