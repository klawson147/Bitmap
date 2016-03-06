#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>

struct RGBPixel
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

class BMPHeader
{
private:
	static const int bitmapheader = 14;
	char HeaderData[bitmapheader];

	static const int bitmapinfoheader = 40;
	char InfoHeaderData[bitmapinfoheader];

	int widthPadding;

	std::vector<RGBPixel> ImageData;
public:
	BMPHeader();
	~BMPHeader();

	void Fill(std::ifstream*);

	int getSize();
	int getImageOffset();
	int getHeight();
	int getWidth();
	int getBitsPerPixels();

	void writeBMP();

	void inversePixel();
	void inversePixel(RGBPixel*);

	void COUTImageData();

	std::string toString();


};

