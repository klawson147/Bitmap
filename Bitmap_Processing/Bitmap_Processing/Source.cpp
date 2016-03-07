#include "Bitmap.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;


int main()
{
	int messageID = MessageBox(NULL, (LPCWSTR)L"Hello", (LPCWSTR)L"World", MB_OK);
	cout << messageID << endl;
	// Open BMP File
	ifstream ifs("bmp3000.bmp", fstream::in | fstream::binary);
	BMPHeader header;

	// Pass File to be read
	header.Fill(&ifs);

	// Display Various Information
	cout << header.toString();
	
	// Inverse Pixels
	header.inversePixel();

	// Write BMP File
	header.writeBMP();

	return 1;
}

