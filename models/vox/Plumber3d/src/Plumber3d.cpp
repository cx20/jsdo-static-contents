// File : Plumber3d.cpp
// Comple : cl Plumber3d.cpp /EHsc (for Visual C++ 2019)

#include <string>
#include <vector>
#include <map> 
#include <iostream>
#include <fstream>

using namespace std;

#ifndef BYTE
	#define BYTE unsigned char
#endif

string dataSet[9][16][16] = {
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","BK","BK","BK","BG","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","BG","BG","BG" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BR","BG","BK","BK","BK","BK","BK","BK","BK","RD","RD","RD" },
    { "BK","BK","BK","BK","BR","BG","BK","BK","BK","BK","BK","BR","RD","RD","RD","RD" },
    { "BK","BK","BK","BK","BR","BR","BK","BK","BK","BK","BR","BR","BR","BR","RD","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BL","BL","RD","RD","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BL","RD","RD","RD","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BG","BG","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BG","BG","BG","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BR","BG","BG","BG","BR","BG","BG","BK","BK" },
    { "BK","BK","BK","BK","BR","BR","BG","BG","BG","BG","BR","BR","BR","BR","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BG","BG","BG","BG","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","BL","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","BL","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","BL","BL","BL","BL","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BL","RD","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BL","BL","BL","BL","BR","BR" },
    { "BK","BK","BK","BK","BK","BK","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BG","BG","BR","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BG","BG","BG","BR","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BR","BG","BG","BG","BR","BG","BG","BG","BK" },
    { "BK","BK","BK","BK","BR","BR","BG","BG","BG","BG","BR","BR","BR","BR","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BG","BG","BG","BG","BG","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","BL","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","BL","RD","RD","RD","BK","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","BL","BL","BL","BL","BL","BK","BK","BR" },
    { "BK","BK","BK","BK","BK","BL","RD","BL","BL","BL","BL","BL","YL","BK","BR","BR" },
    { "BK","BK","BK","BR","BK","BL","BL","BL","BL","BL","BL","BL","BL","BK","BR","BR" },
    { "BK","BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BL","BK","BR","BR" },
    { "BK","BR","BR","BR","BK","BK","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BR","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BG","BG","BR","BG","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BG","BG","BG","BR","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BR","BG","BG","BG","BR","BG","BG","BG","BK" },
    { "BK","BK","BK","BK","BR","BR","BG","BG","BG","BG","BR","BR","BR","BR","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BG","BG","BG","BG","BG","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BL","RD","BL","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BL","RD","RD","BL","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BL","RD","RD","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BL","RD","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BK","BK","BR","BK","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BR","BK","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BG","BG","BR","BG","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BG","BG","BG","BR","BG","BG","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BR","BG","BG","BG","BR","BG","BG","BG","BK" },
    { "BK","BK","BK","BK","BR","BR","BG","BG","BG","BG","BR","BR","BR","BR","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BG","BG","BG","BG","BG","BG","BG","BK","BK","BK" },
    { "BK","BK","RD","RD","RD","RD","RD","BL","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","RD","RD","RD","RD","RD","RD","RD","BL","RD","RD","BK","BK","BK","BK","BK" },
    { "BG","BG","RD","RD","RD","RD","RD","RD","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BG","BG","BG","BK","BK","BK","RD","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BG","BK","BR","BK","BK","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK" },
    { "BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BR","BK","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","RD","RD","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BG","BG","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BG","BG","BG","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BR","BR","BG","BG","BG","BR","BG","BG","BK","BK" },
    { "BK","BK","BK","BK","BR","BR","BG","BG","BG","BG","BR","BR","BR","BR","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BG","BG","BG","BG","BG","BG","BK","BK","BK" },
    { "BK","BK","RD","RD","RD","RD","RD","BL","RD","RD","BK","BK","BK","BK","BK","BK" },
    { "BK","RD","RD","RD","RD","RD","RD","RD","BL","RD","BK","BK","BK","BK","BK","BK" },
    { "BG","BG","RD","RD","RD","RD","RD","RD","BL","BL","BK","BK","BK","BK","BK","BK" },
    { "BG","BG","BG","BK","BK","BK","RD","BL","BL","YL","BK","BK","BK","BK","BK","BK" },
    { "BK","BG","BK","BR","BK","BK","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BR","BR","BR","BL","BL","BL","BL","BL","BL","BL","BK","BK","BK","BK","BK" },
    { "BK","BR","BK","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK","BK","BK" }
},
{
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","RD","RD","RD","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","RD","RD","RD","RD","RD","RD","RD","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BR","BR","BR","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BG","BK","BK","BK","BK","BK","BR","BK","BK","BK","BK" },
    { "BK","BK","BK","BK","BR","BR","BK","BK","BK","BK","BR","BR","BR","BK","BK","BK" },
    { "BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","RD","RD","RD","RD","RD","BL","BK","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","RD","RD","RD","RD","RD","RD","RD","BL","BK","BK","BK","BK","BK","BK","BK" },
    { "BG","BG","RD","RD","RD","RD","RD","RD","BL","BK","BK","BK","BK","BK","BK","BK" },
    { "BG","BG","BG","BK","BK","BK","BK","BL","BL","BK","BK","BK","BK","BK","BK","BK" },
    { "BK","BG","BK","BR","BK","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK" },
    { "BK","BK","BR","BR","BR","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK" },
    { "BK","BR","BR","BR","BK","BK","BL","BL","BL","BL","BK","BK","BK","BK","BK","BK" },
    { "BK","BR","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK","BK" }
}
};

vector<BYTE> colorPalette = {
	0xFC, 0xFC, 0xFC, 0xFF, 0xFC, 0xFC, 0xCC, 0xFF, 0xFC, 0xFC, 0x98, 0xFF, 0xFC, 0xFC, 0x64, 0xFF,
	0xFC, 0xFC, 0x30, 0xFF, 0xFC, 0xFC, 0x00, 0xFF, 0xFC, 0xCC, 0xFC, 0xFF, 0xFC, 0xCC, 0xCC, 0xFF,
	0xFC, 0xCC, 0x98, 0xFF, 0xFC, 0xCC, 0x64, 0xFF, 0xFC, 0xCC, 0x30, 0xFF, 0xFC, 0xCC, 0x00, 0xFF,
	0xFC, 0x98, 0xFC, 0xFF, 0xFC, 0x98, 0xCC, 0xFF, 0xFC, 0x98, 0x98, 0xFF, 0xFC, 0x98, 0x64, 0xFF,
	0xFC, 0x98, 0x30, 0xFF, 0xFC, 0x98, 0x00, 0xFF, 0xFC, 0x64, 0xFC, 0xFF, 0xFC, 0x64, 0xCC, 0xFF,
	0xFC, 0x64, 0x98, 0xFF, 0xFC, 0x64, 0x64, 0xFF, 0xFC, 0x64, 0x30, 0xFF, 0xFC, 0x64, 0x00, 0xFF,
	0xFC, 0x30, 0xFC, 0xFF, 0xFC, 0x30, 0xCC, 0xFF, 0xFC, 0x30, 0x98, 0xFF, 0xFC, 0x30, 0x64, 0xFF,
	0xFC, 0x30, 0x30, 0xFF, 0xFC, 0x30, 0x00, 0xFF, 0xFC, 0x00, 0xFC, 0xFF, 0xFC, 0x00, 0xCC, 0xFF,
	0xFC, 0x00, 0x98, 0xFF, 0xFC, 0x00, 0x64, 0xFF, 0xFC, 0x00, 0x30, 0xFF, 0xFC, 0x00, 0x00, 0xFF,
	0xCC, 0xFC, 0xFC, 0xFF, 0xCC, 0xFC, 0xCC, 0xFF, 0xCC, 0xFC, 0x98, 0xFF, 0xCC, 0xFC, 0x64, 0xFF,
	0xCC, 0xFC, 0x30, 0xFF, 0xCC, 0xFC, 0x00, 0xFF, 0xCC, 0xCC, 0xFC, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF,
	0xCC, 0xCC, 0x98, 0xFF, 0xCC, 0xCC, 0x64, 0xFF, 0xCC, 0xCC, 0x30, 0xFF, 0xCC, 0xCC, 0x00, 0xFF,
	0xCC, 0x98, 0xFC, 0xFF, 0xCC, 0x98, 0xCC, 0xFF, 0xCC, 0x98, 0x98, 0xFF, 0xCC, 0x98, 0x64, 0xFF,
	0xCC, 0x98, 0x30, 0xFF, 0xCC, 0x98, 0x00, 0xFF, 0xCC, 0x64, 0xFC, 0xFF, 0xCC, 0x64, 0xCC, 0xFF,
	0xCC, 0x64, 0x98, 0xFF, 0xCC, 0x64, 0x64, 0xFF, 0xCC, 0x64, 0x30, 0xFF, 0xCC, 0x64, 0x00, 0xFF,
	0xCC, 0x30, 0xFC, 0xFF, 0xCC, 0x30, 0xCC, 0xFF, 0xCC, 0x30, 0x98, 0xFF, 0xCC, 0x30, 0x64, 0xFF,
	0xCC, 0x30, 0x30, 0xFF, 0xCC, 0x30, 0x00, 0xFF, 0xCC, 0x00, 0xFC, 0xFF, 0xCC, 0x00, 0xCC, 0xFF,
	0xCC, 0x00, 0x98, 0xFF, 0xCC, 0x00, 0x64, 0xFF, 0xCC, 0x00, 0x30, 0xFF, 0xCC, 0x00, 0x00, 0xFF,
	0x98, 0xFC, 0xFC, 0xFF, 0x98, 0xFC, 0xCC, 0xFF, 0x98, 0xFC, 0x98, 0xFF, 0x98, 0xFC, 0x64, 0xFF,
	0x98, 0xFC, 0x30, 0xFF, 0x98, 0xFC, 0x00, 0xFF, 0x98, 0xCC, 0xFC, 0xFF, 0x98, 0xCC, 0xCC, 0xFF,
	0x98, 0xCC, 0x98, 0xFF, 0x98, 0xCC, 0x64, 0xFF, 0x98, 0xCC, 0x30, 0xFF, 0x98, 0xCC, 0x00, 0xFF,
	0x98, 0x98, 0xFC, 0xFF, 0x98, 0x98, 0xCC, 0xFF, 0x98, 0x98, 0x98, 0xFF, 0x98, 0x98, 0x64, 0xFF,
	0x98, 0x98, 0x30, 0xFF, 0x98, 0x98, 0x00, 0xFF, 0x98, 0x64, 0xFC, 0xFF, 0x98, 0x64, 0xCC, 0xFF,
	0x98, 0x64, 0x98, 0xFF, 0x98, 0x64, 0x64, 0xFF, 0x98, 0x64, 0x30, 0xFF, 0x98, 0x64, 0x00, 0xFF,
	0x98, 0x30, 0xFC, 0xFF, 0x98, 0x30, 0xCC, 0xFF, 0x98, 0x30, 0x98, 0xFF, 0x98, 0x30, 0x64, 0xFF,
	0x98, 0x30, 0x30, 0xFF, 0x98, 0x30, 0x00, 0xFF, 0x98, 0x00, 0xFC, 0xFF, 0x98, 0x00, 0xCC, 0xFF,
	0x98, 0x00, 0x98, 0xFF, 0x98, 0x00, 0x64, 0xFF, 0x98, 0x00, 0x30, 0xFF, 0x98, 0x00, 0x00, 0xFF,
	0x64, 0xFC, 0xFC, 0xFF, 0x64, 0xFC, 0xCC, 0xFF, 0x64, 0xFC, 0x98, 0xFF, 0x64, 0xFC, 0x64, 0xFF,
	0x64, 0xFC, 0x30, 0xFF, 0x64, 0xFC, 0x00, 0xFF, 0x64, 0xCC, 0xFC, 0xFF, 0x64, 0xCC, 0xCC, 0xFF,
	0x64, 0xCC, 0x98, 0xFF, 0x64, 0xCC, 0x64, 0xFF, 0x64, 0xCC, 0x30, 0xFF, 0x64, 0xCC, 0x00, 0xFF,
	0x64, 0x98, 0xFC, 0xFF, 0x64, 0x98, 0xCC, 0xFF, 0x64, 0x98, 0x98, 0xFF, 0x64, 0x98, 0x64, 0xFF,
	0x64, 0x98, 0x30, 0xFF, 0x64, 0x98, 0x00, 0xFF, 0x64, 0x64, 0xFC, 0xFF, 0x64, 0x64, 0xCC, 0xFF,
	0x64, 0x64, 0x98, 0xFF, 0x64, 0x64, 0x64, 0xFF, 0x64, 0x64, 0x30, 0xFF, 0x64, 0x64, 0x00, 0xFF,
	0x64, 0x30, 0xFC, 0xFF, 0x64, 0x30, 0xCC, 0xFF, 0x64, 0x30, 0x98, 0xFF, 0x64, 0x30, 0x64, 0xFF,
	0x64, 0x30, 0x30, 0xFF, 0x64, 0x30, 0x00, 0xFF, 0x64, 0x00, 0xFC, 0xFF, 0x64, 0x00, 0xCC, 0xFF,
	0x64, 0x00, 0x98, 0xFF, 0x64, 0x00, 0x64, 0xFF, 0x64, 0x00, 0x30, 0xFF, 0x64, 0x00, 0x00, 0xFF,
	0x30, 0xFC, 0xFC, 0xFF, 0x30, 0xFC, 0xCC, 0xFF, 0x30, 0xFC, 0x98, 0xFF, 0x30, 0xFC, 0x64, 0xFF,
	0x30, 0xFC, 0x30, 0xFF, 0x30, 0xFC, 0x00, 0xFF, 0x30, 0xCC, 0xFC, 0xFF, 0x30, 0xCC, 0xCC, 0xFF,
	0x30, 0xCC, 0x98, 0xFF, 0x30, 0xCC, 0x64, 0xFF, 0x30, 0xCC, 0x30, 0xFF, 0x30, 0xCC, 0x00, 0xFF,
	0x30, 0x98, 0xFC, 0xFF, 0x30, 0x98, 0xCC, 0xFF, 0x30, 0x98, 0x98, 0xFF, 0x30, 0x98, 0x64, 0xFF,
	0x30, 0x98, 0x30, 0xFF, 0x30, 0x98, 0x00, 0xFF, 0x30, 0x64, 0xFC, 0xFF, 0x30, 0x64, 0xCC, 0xFF,
	0x30, 0x64, 0x98, 0xFF, 0x30, 0x64, 0x64, 0xFF, 0x30, 0x64, 0x30, 0xFF, 0x30, 0x64, 0x00, 0xFF,
	0x30, 0x30, 0xFC, 0xFF, 0x30, 0x30, 0xCC, 0xFF, 0x30, 0x30, 0x98, 0xFF, 0x30, 0x30, 0x64, 0xFF,
	0x30, 0x30, 0x30, 0xFF, 0x30, 0x30, 0x00, 0xFF, 0x30, 0x00, 0xFC, 0xFF, 0x30, 0x00, 0xCC, 0xFF,
	0x30, 0x00, 0x98, 0xFF, 0x30, 0x00, 0x64, 0xFF, 0x30, 0x00, 0x30, 0xFF, 0x30, 0x00, 0x00, 0xFF,
	0x00, 0xFC, 0xFC, 0xFF, 0x00, 0xFC, 0xCC, 0xFF, 0x00, 0xFC, 0x98, 0xFF, 0x00, 0xFC, 0x64, 0xFF,
	0x00, 0xFC, 0x30, 0xFF, 0x00, 0xFC, 0x00, 0xFF, 0x00, 0xCC, 0xFC, 0xFF, 0x00, 0xCC, 0xCC, 0xFF,
	0x00, 0xCC, 0x98, 0xFF, 0x00, 0xCC, 0x64, 0xFF, 0x00, 0xCC, 0x30, 0xFF, 0x00, 0xCC, 0x00, 0xFF,
	0x00, 0x98, 0xFC, 0xFF, 0x00, 0x98, 0xCC, 0xFF, 0x00, 0x98, 0x98, 0xFF, 0x00, 0x98, 0x64, 0xFF,
	0x00, 0x98, 0x30, 0xFF, 0x00, 0x98, 0x00, 0xFF, 0x00, 0x64, 0xFC, 0xFF, 0x00, 0x64, 0xCC, 0xFF,
	0x00, 0x64, 0x98, 0xFF, 0x00, 0x64, 0x64, 0xFF, 0x00, 0x64, 0x30, 0xFF, 0x00, 0x64, 0x00, 0xFF,
	0x00, 0x30, 0xFC, 0xFF, 0x00, 0x30, 0xCC, 0xFF, 0x00, 0x30, 0x98, 0xFF, 0x00, 0x30, 0x64, 0xFF,
	0x00, 0x30, 0x30, 0xFF, 0x00, 0x30, 0x00, 0xFF, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0xCC, 0xFF,
	0x00, 0x00, 0x98, 0xFF, 0x00, 0x00, 0x64, 0xFF, 0x00, 0x00, 0x30, 0xFF, 0xEC, 0x00, 0x00, 0xFF,
	0xDC, 0x00, 0x00, 0xFF, 0xB8, 0x00, 0x00, 0xFF, 0xA8, 0x00, 0x00, 0xFF, 0x88, 0x00, 0x00, 0xFF,
	0x74, 0x00, 0x00, 0xFF, 0x54, 0x00, 0x00, 0xFF, 0x44, 0x00, 0x00, 0xFF, 0x20, 0x00, 0x00, 0xFF,
	0x10, 0x00, 0x00, 0xFF, 0x00, 0xEC, 0x00, 0xFF, 0x00, 0xDC, 0x00, 0xFF, 0x00, 0xB8, 0x00, 0xFF,
	0x00, 0xA8, 0x00, 0xFF, 0x00, 0x88, 0x00, 0xFF, 0x00, 0x74, 0x00, 0xFF, 0x00, 0x54, 0x00, 0xFF,
	0x00, 0x44, 0x00, 0xFF, 0x00, 0x20, 0x00, 0xFF, 0x00, 0x10, 0x00, 0xFF, 0x00, 0x00, 0xEC, 0xFF,
	0x00, 0x00, 0xDC, 0xFF, 0x00, 0x00, 0xB8, 0xFF, 0x00, 0x00, 0xA8, 0xFF, 0x00, 0x00, 0x88, 0xFF,
	0x00, 0x00, 0x74, 0xFF, 0x00, 0x00, 0x54, 0xFF, 0x00, 0x00, 0x44, 0xFF, 0x00, 0x00, 0x20, 0xFF,
	0x00, 0x00, 0x10, 0xFF, 0xEC, 0xEC, 0xEC, 0xFF, 0xDC, 0xDC, 0xDC, 0xFF, 0xB8, 0xB8, 0xB8, 0xFF,
	0xA8, 0xA8, 0xA8, 0xFF, 0x88, 0x88, 0x88, 0xFF, 0x74, 0x74, 0x74, 0xFF, 0x54, 0x54, 0x54, 0xFF,
	0x44, 0x44, 0x44, 0xFF, 0x20, 0x20, 0x20, 0xFF, 0x10, 0x10, 0x10, 0xFF, 0x00, 0x00, 0x00, 0xFF
};


int getColorIndex1(const char* colorName);
void addChunkName(vector<BYTE>& byteArray, const char* chunkName);
void addIntValue(vector<BYTE>& byteArray, int value);
void addModelData(vector<BYTE>& byteArray);
void addByteArray(vector<BYTE>& byteArray, const vector<BYTE>& byteArray2);

int main( int argc, char* argv[] ) {
	string strFileName = "Plumber3d.vox";
	ofstream file;

	file.open(strFileName.c_str(), ios::out|ios::binary|ios::trunc);
	if (!file) {
	   return 1;
	}

	// File Spec: MagicaVoxel .vox File Format
	// https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox.txt

	vector<BYTE> modelByteArray;
	addModelData(modelByteArray);

	int paletteCount = colorPalette.size() / 4;
	int paletteChunkSize = paletteCount * 4;
	int voxelCount = modelByteArray.size() / 4;
	int voxelChunkSize = voxelCount * 4 + 4;
	int modelSizeX = 16;
	int modelSizeY = 16;
	int modelSizeZ = 16;
	int modelChunkSize = 12;
	int childrenChunkSize = (4 + 8 + modelChunkSize) + (4 + 8 + voxelChunkSize) + (4 + 8 + paletteChunkSize);
	int version = 150;
	
	vector<BYTE> byteArray;
	addChunkName(byteArray, "VOX ");
	addIntValue(byteArray, version);
	
	addChunkName(byteArray, "MAIN");
	addIntValue(byteArray, 0);
	addIntValue(byteArray, childrenChunkSize);
	
	addChunkName(byteArray, "SIZE");
	addIntValue(byteArray, modelChunkSize);
	addIntValue(byteArray, 0);
	addIntValue(byteArray, modelSizeX);
	addIntValue(byteArray, modelSizeY);
	addIntValue(byteArray, modelSizeZ);
	
	addChunkName(byteArray, "XYZI");
	addIntValue(byteArray, voxelChunkSize);
	addIntValue(byteArray, 0);
	addIntValue(byteArray, voxelCount);
	addByteArray(byteArray, modelByteArray);
	
	addChunkName(byteArray, "RGBA");
	addIntValue(byteArray, paletteChunkSize);
	addIntValue(byteArray, 0);
	addByteArray(byteArray, colorPalette);

	file.write((char*)&byteArray[0], byteArray.size());

	return 0;
}

int getColorIndex(const char* colorName) {
	map<string, int> keyValue;
	keyValue["BK"] = 52;  // black
	keyValue["BG"] = 8;   // beige
	keyValue["BR"] = 96;  // brown
	keyValue["RD"] = 216; // red
	keyValue["YL"] = 5;   // yellow
	keyValue["GN"] = 232; // green
	keyValue["WT"] = 196; // water
	keyValue["BL"] = 211; // blue
	keyValue["PR"] = 104; // purple
	
	return keyValue[colorName];
}

void addChunkName(vector<BYTE>& byteArray, const char* chunkName) {
	for ( int i = 0; i < strlen(chunkName); i++ ) {
		byteArray.push_back(chunkName[i]);
	}
}

void addIntValue(vector<BYTE>& byteArray, int value) {
	BYTE byte4[4] = {};
	memcpy((BYTE*)&byte4, (BYTE*)&value, sizeof(byte4));
	for ( int i = 0; i < sizeof(byte4); i++ ) {
		byteArray.push_back(byte4[i]);
	}
}

void addModelData(vector<BYTE>& byteArray) {
	for ( int z = 0; z < 9; z++ ) {
		for ( int y = 0; y < 16; y++ ) {
			for ( int x = 0; x < 16; x++ ) {
				string colorName = dataSet[z][y][x];
				if ( colorName != "BK" ) {
					BYTE colorIndex = (BYTE)getColorIndex(colorName.c_str());
					byteArray.push_back( x );
					byteArray.push_back( 15 - z - 4);
					byteArray.push_back( 15 - y );
					byteArray.push_back( colorIndex );
				}
			}
		}
	}
}

void addByteArray(vector<BYTE>& byteArray, const vector<BYTE>& byteArray2) {
	byteArray.insert(byteArray.end(), byteArray2.begin(), byteArray2.end());
}