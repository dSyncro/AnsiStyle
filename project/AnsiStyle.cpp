#include "AnsiStyle.h"
#include <sstream>

std::string AnsiStyle::CursorNavigation::move(AnsiStyle::CursorNavigation::Direction direction, unsigned int step) noexcept
{
	std::string s = "\033[" + std::to_string(step) + static_cast<char>(direction);
	return s;
}