#include <iostream>

#include "Bitmap.h"
using namespace caveofprogramming;
using namespace std;

int main() {
	int const WIDTH = 600;
	int const HEIGHT = 800;
	Bitmap bitmap(WIDTH,HEIGHT);
	for (int y = 0; y < 800; y++) {
		for (int x = 0; x < 600; x++) {
			bitmap.setPixel(x, y, 255, 0, 0);
		}
	}
	bitmap.write("test.bmp");
	//while (1);
	return 0;
}