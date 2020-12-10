#include <stdio.h>	//remove(1)
#include <iostream>
#include "dict.h"
#include "split_merge_func.h"
#include "pad.h"
#include "sha256.h"


void LoadFile(char *fileName, char  *filePath, char  *outputFilePath) {
    SHA256 sha256;
    Chunk *head = NULL;
    Chunk *first = NULL;
    int leftLength;
    char* chunkName;

    ifstream fileStream;
    // read in binary
    fileStream.open(filePath, ios::in | ios::binary);

    //find the length of input file
    fileStream.seekg(0, ios::end);
    leftLength = fileStream.tellg();


    filePathForLoad = filePath;
    outputFilePathForLoad = outputFilePath;


    filename *file_name = new filename(fileName);
    file_name->add_to_fdict();

    while(leftLength > chunkSize) {
        //
        splitChunks(filePathForLoad, chunkName, outputFilePathForLoad);
        // False
        if (!find_chunkname(chunkName)) {
            // create a chunkname pointer
            chunkname *chunkNamePtr = new chunkname(chunkName);
            chunkNamePtr->add_to_cdict();
        }
        else {
            count_up(chunkName);
        }

        Chunk *chunk = new Chunk();
        //chunk -> name = chunkName;
        strncpy(chunk->name, chunkName, HashByteSize);

        if (head == NULL) {
            file_name -> first = chunk;
            
        }
        else {
            head -> next = chunk;
        }

        head = chunk;
    }

    if(leftLength < chunkSize) {
        pad(filePathForLoad);
        file_name->padded = 1;
    }

    // hash the left file data
    ifstream restFileStream;
    restFileStream.open(filePathForLoad, ios::in | ios::binary);
    //create a buffer
    char *buffer = new char[leftLength];
    restFileStream.read(buffer, leftLength);

    char *hash_rest = sha256_segment(buffer);

    if (!find_chunkname(hash_rest)) {
            // create a chunkname pointer
            chunkname *chunkNameRestPtr = new chunkname(hash_rest);
            chunkNameRestPtr->add_to_cdict();
        }
        else {
            count_up(chunkName);
        }

        Chunk *chunk_rest = new Chunk();
        //chunk -> name = chunkName;
        strncpy(chunk_rest->name, hash_rest, HashByteSize);
        head->next = chunk_rest;

}

void ListStorage()
{
	list_aph_fdict();
}

void RetrieveFile(char* input)
{
	//Find in dict
	filename* res = find_filename(input);
	if(res == NULL) cout << "File not found in master storage.\n" << endl;
	else
	{
		Chunk* cptr;
		cptr = res->first;
		while(cptr->next != NULL)
		{

		}		
	}	
}

void DeleteFile(char* input)
{
	//Find in dict
	filename* res = find_filename(input);
	if(res == NULL) cout << "File not found in master storage.\n" << endl;
	else
	{
		Chunk* cptr;
		cptr = res->first;
		while(cptr != NULL)
		{
			count_down(cptr->name);
			if(find_chunkname(cptr->name)->count == 0)
			{
				if(remove(cptr->name) == 0) continue;
				else cout << "Error: chunk data removal unsuccessful." << endl;
				find_chunkname(cptr->name)->delete_from_cdict();
			}
			cptr = cptr->next;
		}
		res->delete_from_fdict();
		//free(res);
		cout << "Successfully deleted " << input << " from master storage." << endl;
	}
}



