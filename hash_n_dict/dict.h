// Copyright 2020 Yanqiu 'Sandro' Chen chen1997@bu.edu

/********************
dict.h:
Packaged dictionary structures and functions using uthash header (https://github.com/troydhanson/uthash).
*********************/
#pragma once
#define HashSize 256  //The expected length of Hash output (bits)
#define HashByteSize HashSize / 8

#include <string> //strcpy(), strcmp()
#include "uthash.h"

using namespace std;

class Chunk
{
  public:
    char name[HashByteSize];
    Chunk * next;
};

class chunkname
{
  public:
    char name[HashByteSize];  //Key - name of chunk == hash value of the chunk
    int count;  //Count of the files which includes this chunk
    UT_hash_handle hh;  //Per the format of uthash
    
    /** CONSTRUCTORS **/
    chunkname();
    chunkname(char hashval[]);

    
    /** DICT OPERATIONS **/
    //ADD
    void add_to_cdict();

    //DELETE
    void delete_from_cdict();

};

class filename
{
  public:
    char name[256]; //Key - name of the input file (256B is most File System's max file name length)
    Chunk * first;
    int padded; //Indicates whether the last chunk is padded
    UT_hash_handle hh;  //Per the format of uthash
    
    /** CONSTRUCTORS **/
    filename();
    filename(char actual_name[]);

    
    /** DICT OPERATIONS **/
    //ADD
    void add_to_fdict();

    //DELETE
    void delete_from_fdict();
};

/*The dictionary structures per uthash requirements
filename *filename_dict = NULL;
chunkname *chunkname_dict = NULL;*/

//The find and operations of two dictionaries
filename* find_filename(char query[]);
chunkname* find_chunkname(char query[]);
//Function to list entries in alphabetical order in filename_dict
void list_aph_fdict();
//Alphabetical sort function required for sorting
int aph_sort(filename *a, filename *b);
//Function to increase the item in chunkname_dict
void count_up(char query[]);
//Function to decrease the item in chunkname_dict
void count_down(char query[]);

/**********WRAPPER FUNCTIONS**********/

// Take in a segment of file (in char[]), sha256 hash then return the result to be used as name of the chunk
char* sha256_segment(char input[]);
