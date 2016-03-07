#include "Bitmap.h"


using namespace std;

BMPHeader::BMPHeader()
{
}


BMPHeader::~BMPHeader()
{
	cout << "Press any Key to Continue\n";
	cin.get();
}


void BMPHeader::Fill(std::ifstream* k)
{
	// Get Header Information
	for (int i = 0; i < bitmapheader; i++)
	{
		HeaderData[i] = k->get();
	}

	// Get Info Header Information
	for (int i = 0; i < bitmapinfoheader; i++)
	{
		InfoHeaderData[i] = k->get();
	}
	// Temp Struct
	RGBPixel temp;

	// Padding
	int padding;

	// Get Image Information
	for (int h = 0; h < getHeight(); h++)
	{
		for (int w = 0; w < getWidth(); w++)
		{
			temp.b = (k->get());
			temp.g = (k->get());
			temp.r = (k->get());

			ImageData.push_back(temp);
		}

		if ((getWidth() * 3) % 4 == 0)
		{
			padding = 0;
		}
		else
		{
			padding = (4 - ((getWidth() * 3) % 4));
		}
		while (padding > 0)
		{
			k->get();
			padding--;
		}
	}

	// Close Input File
	k->close();
}

int BMPHeader::getImageOffset()
{
	int offset = 0;
	for (int i = 10; i < 14; i++)
	{
		offset += (int)HeaderData[i];
	}
	return offset;
}

// Return File Size(Bytes)
int BMPHeader::getSize()
{
	int out = 0;

	for (int i = 5; i > 1; i--)
	{
		out = (out << 8) | (uint8_t)HeaderData[i];
	}
	return out;
}

// Get Pixel Height of Image
int BMPHeader::getHeight()
{
	int height = 0;
	for (int i = 11; i > 7; i--)
	{
		height = (height << 8) | (uint8_t)InfoHeaderData[i];
	}
	return height;
}

// Get Pixel Width of Image
int BMPHeader::getWidth()
{
	int width = 0;
	for (int i = 7; i > 3; i--)
	{
		width = (width << 8) | (uint8_t)InfoHeaderData[i];

	}
	return width;
}
// Get Bits Per Pixel
int BMPHeader::getBitsPerPixels()
{
	int bps = 0;
	for (int i = 14; i < 16; i++)
	{
		bps += (int)InfoHeaderData[i];
	}
	return bps;
}

// Return String Representation of BMP Header
string BMPHeader::toString()
{
	string s;
	s = "Width:  \t" + std::to_string(getWidth()) + " pixels\n";
	s += "Height: \t" + std::to_string(getHeight()) + " pixels\n";
	s += "File Size:   \t" + std::to_string(getSize()) + " bytes\n";
	s += "Image Offset: \t" + std::to_string(getImageOffset()) + " bytes\n";
	s += "BitsPerPixel:\t" + std::to_string(getBitsPerPixels()) + " bits\n";
	return s;
}


// Write Pixel Data to COUT
void BMPHeader::COUTImageData()
{
	vector<RGBPixel>::iterator it = ImageData.begin();
	for (it; it != ImageData.end(); it++)
	{
		cout << (int)it->b << endl;
		cout << (int)it->g << endl;
		cout << (int)it->r << endl;
	}
}


void BMPHeader::writeBMP()
{
	ofstream ofs("bmpOut.bmp", ofstream::out | ofstream::binary);

	// Write Header
	for (int h = 0; h < bitmapheader; h++)
	{
		ofs << HeaderData[h];
	}

	// Write Info Header
	for (int i = 0; i < bitmapinfoheader; i++)
	{
		ofs << InfoHeaderData[i];
	}


	// Write Pixel Data
	int padding;
	vector<RGBPixel>::iterator it = ImageData.begin();

	for (int h = 0; h < getHeight(); h++)
	{
		for (int w = 0; w < getWidth(); w++)
		{
			ofs << (char)it->b;
			ofs << (char)it->g;
			ofs << (char)it->r;
			it++;
		}
		// Write padding if necessary

		if ((getWidth() * 3) % 4 == 0)
		{
			padding = 0;
		}
		else
		{
			padding = (4 - ((getWidth() * 3) % 4));
		}

		while (padding > 0)
		{
			ofs << (char)0;
			padding--;
		}
	}
	ofs.close();
}


void BMPHeader::inversePixel()
{
	for (int i = 0; i < (getWidth() * getHeight()); i++)
	{
		inversePixel(&ImageData[i]);
	}
}

// Takes a Pointer to Struct RGBPixel and inverses the color
void BMPHeader::inversePixel(RGBPixel* pixel)
{
	pixel->b = (255 - pixel->b);
	pixel->g = (255 - pixel->g);
	pixel->r = (255 - pixel->r);
}



