#include <iostream>
#include "canvas.h"

const char* bool_to_char(const bool& v) {
	return v ? "*" : " ";
}

int main() {
	microlife::canvas<bool> cav(10, 10, false);
	for (int i = 0; i < cav.width(); i++) {
		for (int j = 0; j < cav.height(); j++) {
			if (i == j)
				cav(i, j) = true;
		}
	}
	cav.print(std::cout, bool_to_char);
}