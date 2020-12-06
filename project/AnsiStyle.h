#pragma once

#include <iostream>
#include <string>

namespace AnsiStyle
{

	const std::string reset = "\033[0m";
	const std::string clear = "\033[2J";
	const std::string homeCursor = "\033[H";

	enum class Backcolors
	{
		DarkBlack = 40,
		DarkRed = 41,
		DarkGreen = 42,
		DarkYellow = 43,
		DarkBlue = 44,
		DarkMagenta = 45,
		DarkCyan = 46,
		DarkWhite = 47,

		Reset = 49,

		Black = 100,
		Red = 101,
		Green = 102,
		Yellow = 103,
		Blue = 104,
		Magenta = 105,
		Cyan = 106,
		White = 107,
	};

	enum class Forecolors
	{
		DarkBlack = 30,
		DarkRed = 31,
		DarkGreen = 32,
		DarkYellow = 33,
		DarkBlue = 34,
		DarkMagenta = 35,
		DarkCyan = 36,
		DarkWhite = 37,

		Reset = 39,

		Black = 90,
		Red = 91,
		Green = 92,
		Yellow = 93,
		Blue = 94,
		Magenta = 95,
		Cyan = 96,
		White = 97
	};

	enum class Decorations
	{
		Bold = 1,
		Dim = 2,
		Italic = 3,
		Underline = 4,
		Blink = 5,
		RapidBlink = 6,
		Reversed = 7,
		Conceal = 8,
		Crossed = 9
	};

	template <typename T>
	using AnsiToken = typename std::enable_if<
		std::is_same<T, AnsiStyle::Backcolors>::value || 
		std::is_same<T, AnsiStyle::Forecolors>::value ||
		std::is_same<T, AnsiStyle::Decorations>::value,
		std::ostream&>::type;

	template <typename T>
	AnsiToken<T> operator<<(std::ostream& stream, const T& color)
	{
		stream << "\033[" << static_cast<int>(color) << "m";
		return stream;
	}

	namespace CursorNavigation
	{
		enum class Direction : char
		{
			Up = 'A',
			Down = 'B',
			Right = 'C',
			Left = 'D'
		};

		std::string move(Direction direction, unsigned int step) noexcept;
	}
}