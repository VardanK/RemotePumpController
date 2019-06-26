#pragma once

class Color {
public:
	int red, green, blue;

	Color(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
};

namespace Colors {
	const Color RED = Color(255, 0, 0);
	const Color GREEN = Color(0, 255, 0);
	const Color BLUE = Color(0, 0, 255);

	const Color LIGHT_RED = Color(125, 0, 0);
	const Color LIGHT_GREEN = Color(0, 125, 0);
	const Color LIGHT_BLUE = Color(0, 0, 125);

	const Color WHITE = Color(255, 255, 255);
	const Color GRAY = Color(125, 125, 125);

	const Color IDLE = Color(125, 125, 125);
}