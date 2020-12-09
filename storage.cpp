// Copyright 2020 Yanqiu Chen chen1997@bu.edu
// storage.cpp: combined functions for load/list/retrieve/delete

#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <typeinfo>

// The components
#include "dict.h"
#include "split_merge_func.h"
#include "pad.h"
#include "op.h"

using namespace std;


/*
Usage:
"storage -l": listing the stored files
"storage -s $FILENAME": store the file into the file system
"storage -r $FILENAME": retrieve the file from the file system
"storage -d $FILENAME": delete the file from the file system
*/
int main(int argc, char** argv)
{
	if(argc == 1) cout << "Please enter a command line option." << endl;
	else if(argc == 2 && !strcmp(argv[1], "-l"))
	{
		//TODO: ListFiles
	}
	else if(argc == 3 && !strcmp(argv[1], "-s"))
	{
		//TODO: Store(Load)
	}
	else if(argc == 3 && !strcmp(argv[1], "-r"))
	{
		//TODO: Retrieve
	}
	else if(argc == 3 && !strcmp(argv[1], "-d"))
	{
		//TODO: Delte
	}
	else
	{
		cout << "Parameter error." << endl;
	}	
	return 0;
}