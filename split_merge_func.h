#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <typeinfo>

using namespace std;

char *filePathForLoad;
char *outputFilePathForLoad;
const int chunkSize = 1024;



// split a file into serveral chunks
void splitChunks(char *filePath, string chunkName, char *outputFilePath);
//merge those individual chunks into same outputFile
void mergeChunks(char *filePath, string chunkName, char *outputFilePath);