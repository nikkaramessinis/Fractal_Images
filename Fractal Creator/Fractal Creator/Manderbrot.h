#pragma once
namespace caveofprogramming {
	class Manderbrot
	{
	public:
		static const int MAX_ITERATIONS = 1000;
	public:
		Manderbrot();
		virtual ~Manderbrot();
		static int getIterations(double x, double y);
	};
}
