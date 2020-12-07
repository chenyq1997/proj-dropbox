// Copyright 2020 Yanqiu 'Sandro' Chen chen1997@bu.edu

/********************
dict.cpp:
Packaged dictionary structures and functions using uthash header (https://github.com/troydhanson/uthash).
*********************/

#define HashSize 256  //The expected length of Hash output (bits)
#define HashByteSize HashSize / 8

#include <string> //strcpy(), strcmp()
#include "dict.h"
#include "uthash.h"
#include "sha256.h"

using namespace std;

//The dictionary structures per uthash requirements
filename *filename_dict = NULL;
chunkname *chunkname_dict = NULL;

/**********FILENAME FUNCTIONS**********/
    
/** CONSTRUCTORS **/
filename::filename(){}
filename::filename(char actual_name[])
{
  strcpy(name, actual_name);  //Copy final hash value to chunk
}

/** DICT OPERATIONS **/
//ADD
void filename::add_to_fdict()
{
  //Using uthash macro
  HASH_ADD_STR(filename_dict, name, this);  //Input 1-3: the dictionary, the name of the key field, the pointer to the instance
}
//DELETE
void filename::delete_from_fdict()
{
  //Using uthash macro
  HASH_DEL(filename_dict, this);  
}


/**********CHUNKNAME FUNCTIONS**********/
    
/** CONSTRUCTORS **/
chunkname::chunkname(){}
chunkname::chunkname(char hashval[])
{
  strcpy(name, hashval);  //Copy final hash value to chunk 
  count = 1;  //The newly added file will have this new chunk
}

/** DICT OPERATIONS **/
//ADD
void chunkname::add_to_cdict()
{
  //Using uthash macro
  HASH_ADD_STR(chunkname_dict, name, this);  //Input 1-3: the dictionary, the name of the key field, the pointer to the instance
}
//DELETE
void chunkname::delete_from_cdict()
{
  //Using uthash macro
  HASH_DEL(chunkname_dict, this);  
}



/**********DICT QUERY/LISTING**********/
//The find and operations of two dictionaries
filename* find_filename(char query[])
{
  filename *res;
  //Using uthash macro
  HASH_FIND_STR(filename_dict, query, res);  //Input 1-3: dict, pointer to the query literal key, output pointer (NULL if not found).
  return res;
}
chunkname* find_chunkname(char query[])
{
  chunkname *res;
  //Using uthash macro
  HASH_FIND_STR(chunkname_dict, query, res);  //Input 1-3: dict, pointer to the query literal key, output pointer (NULL if not found).
  return res;  
}

//Function to list entries in alphabetical order in filename_dict
void list_aph_fdict()
{
  //Using uthash macro to sort dict
  HASH_SORT(filename_dict, aph_sort);
  //Listing the result
  filename* iter;
  int i = 1;
  for(iter = filename_dict; iter != NULL; iter = (filename*) (iter->hh.next))
    printf("%d.\t%s\n", i, iter->name);
}

//Alphabetical sort function required for sorting
int aph_sort(filename *a, filename *b)
{
  return strcmp(a->name, b->name);
}

//Function to update the item in chunkname_dict
void update_count(char query[], int newcount)
{
  chunkname *res;
  res = find_chunkname(query);
  if(res != NULL) res->count = newcount;
}

/**********WRAPPER FUNCTIONS**********/

// Take in a segment of file (in char[]), sha256 hash then return the result to be used as name of the chunk
char* sha256_segment(char input[])
{
  SHA256 sha256;
  string s = sha256(input);
  char* res = new char[HashByteSize];
  strncpy(res, s.c_str(), HashByteSize);
  return res;
}
