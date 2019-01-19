#include <iostream>

#include "Bitmap.h"
using namespace caveofprogramming;
using namespace std;

int main() {
	Bitmap bitmap(800,600);
	bitmap.write("test.bmp");
	while (1);
	return 0;
}