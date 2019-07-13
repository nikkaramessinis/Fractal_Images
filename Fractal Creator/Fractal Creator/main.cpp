#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Manderbrot.h"
#include "Bitmap.h"
#include "tbb/parallel_for.h"
using namespace caveofprogramming;
using namespace std;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;


	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	unique_ptr<int[]>histogram(new int[Manderbrot::MAX_ITERATIONS]());
	unique_ptr<int[]>fractal(new int[WIDTH*HEIGHT]());

	tbb::parallel_for(0,HEIGHT,[&](int y) 
	{
		for (int x = 0; x < WIDTH; x++) 
		{
			double xFractal=(x-WIDTH/2-200)*2.0/ HEIGHT;
			double yFractal = (y - HEIGHT / 2)*2.0/HEIGHT;
			
			int iterations = Manderbrot::getIterations(xFractal,yFractal);

			fractal[y*WIDTH+x]=iterations;
			if(iterations!=Manderbrot::MAX_ITERATIONS)
			histogram[iterations]++;
		}
		//cout << y << endl;
	});
	//cout << endl;
	int total = 0;
	for (int i = 0; i < Manderbrot::MAX_ITERATIONS; i++) 
	{
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++) 
	{
		for (int x = 0; x < WIDTH; x++) 
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;
			int iterations = fractal[y*WIDTH + x];

			//uint8_t color = (uint8_t)(256 * (double)iterations / Manderbrot::MAX_ITERATIONS);
			if (iterations != Manderbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++)
				{
					hue += ((double)histogram[i]) / total;
				}

				green = pow(255, hue);
			}
			bitmap.setPixel(x, y, red, green, blue);

		}
	}
	//cout << min << "," << max << endl;
	bitmap.write("test.bmp");
	return 0;
}