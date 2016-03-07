#include "Bitmap.h"
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	// Open BMP File
	ifstream ifs("bmp3000.bmp", fstream::in | fstream::binary);
	BMPHeader header;

	// Pass File to be read
	header.Fill(&ifs);

	// Display Various Information
	cout << header.toString();
	
	// Write BMP File
	header.writeBMP();

	return 1;
}

