#include "Bitmap.h"
#include "OpenFileDialog.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
	// Open File Dialog
	OpenFileDialog* openFileDialog1 = new OpenFileDialog();
	openFileDialog1->ShowDialog();
	
	// String Representation of Filename
	string filename(openFileDialog1->FileName);

	// Open BMP File
	ifstream ifs(filename, fstream::in | fstream::binary);

	// Ensure File is still Accessible
	if (!ifs.is_open())
	{
		cout << filename << " can't be opened\n";
		
	}
	// Ensure File is of type .bmp
	else if (!(filename.substr(filename.find_last_of(".") + 1) == "bmp"))
	{
		cout << filename << " is not a .bmp file\n";
	}
	else
	{
		BMPHeader header;

		// Pass File to be read
		header.Fill(&ifs);

		// Display Various Information
		cout << header.toString();

		// Inverse Pixels
		header.inversePixel();

		// Write BMP File
		header.writeBMP();
	}
	
	return 1;
}
