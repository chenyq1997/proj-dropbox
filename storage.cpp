// Copyright 2020 Yanqiu Chen chen1997@bu.edu
// storage.cpp: combined functions for load/list/retrieve/delete

#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <typeinfo>

// The components

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
	/*
	LoadStructures();
	if(argc == 1) cout << "Error: no command line option." << endl;
	else if(argc == 2 && !strcmp(argv[1], "-l"))
	{
		//TODO: ListFiles
		ListStorage();
	}
	else if(argc == 3 && !strcmp(argv[1], "-s"))
	{
		//TODO: Store(Load)
		LoadFile(,argv[2],);
	}
	else if(argc == 3 && !strcmp(argv[1], "-r"))
	{
		//TODO: Retrieve
		RetrieveFile(argv[2]);
	}
	else if(argc == 3 && !strcmp(argv[1], "-d"))
	{
		//TODO: Delte
		DeleteFile(argv[2]);
	}
	else
	{
		cout << "Parameter error." << endl;
	}	
	SaveStructures();
	*/
	return 0;
}