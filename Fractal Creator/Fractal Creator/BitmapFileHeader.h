#pragma once

#include <cstdint>
//makes c++ align all of this in 2 byte boundaries no hidden padding
#pragma pack(2)

using namespace std;

namespace caveofprogramming {
	struct BitmapFileHeader {
		char header[2]{ 'B','M' };
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffset;
	};
}