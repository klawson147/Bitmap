#pragma once
#include <Windows.h>
#include <Commdlg.h>
#include <tchar.h>


class OpenFileDialog
{
public:
	OpenFileDialog(void);
	TCHAR*DefaultExtension = "bmp";
	TCHAR*FileName; // Defined as a 1 Byte Character
	TCHAR*Filter;
	int FilterIndex;
	int Flags;
	TCHAR*InitialDir;
	HWND Owner;
	TCHAR*Title = "Choose a .bmp File";

	bool ShowDialog();
};