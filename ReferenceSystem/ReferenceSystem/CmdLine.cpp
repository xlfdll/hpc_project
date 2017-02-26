// CBIR System (Color Histogram based)
// CSS 535 Project - Winter 2017
// Max Strange, Jeremy Albert, Longfei Xi
//
// CmdLine.cpp - command line handling functions (definition)

#include "CmdLine.h"

void ShowHelp()
{
	cout
		<< "Color Histogram CBIR System" << endl
		<< "CSS 535 Project - Winter 2017" << endl
		<< "Max Strange, Jeremy Albert, Longfei Xi" << endl
		<< endl
		<< "Usage:" << endl
		<< "\tCBIRSystem -u" << endl
		<< "OR" << endl
		<< "\tCBIRSystem (-i | -c) <reference image filename>" << endl
		<< endl
		<< "Parameters:" << endl
		<< "\t-u: create image and feature directories if they do not exist; otherwise, update all image features." << endl
		<< "OR" << endl
		<< "\t-i: use intensity color features" << endl
		<< "\t-c: use color-code color features" << endl
		<< "<reference image filename>: search all images similar to given (reference) image file in image directory" << endl
		<< endl;
}

void HandleArguments(PCTSTR *szArgument, int nArgumentCount)
{
	if (lstrcmp(TEXT("-u"), szArgument[1]) == 0)
	{
		InitializeCBIRDatabase();
	}
	else if (nArgumentCount >= 3)
	{
		CBIRMethod method;

		if (lstrcmp(TEXT("-i"), szArgument[1]) == 0)
		{
			method = CBIRMethod::Intensity;
		}
		else if (lstrcmp(TEXT("-c"), szArgument[1]) == 0)
		{
			method = CBIRMethod::ColorCode;
		}

		PerformCBIRSearch(szArgument[2], method);
	}
}