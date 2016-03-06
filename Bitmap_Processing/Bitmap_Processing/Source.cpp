#include "Bitmap.h"
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	ifstream ifs("bmp3000.bmp", fstream::in | fstream::binary);

	BMPHeader header;

	header.Fill(&ifs);
	ifs.close();

	cout << header.toString();
	//header.COUTImageData();

	header.writeBMP();

	cout << endl;

	return 1;
}

