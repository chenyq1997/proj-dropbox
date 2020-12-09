#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <typeinfo>

using namespace std;

// split a file into serveral chunks
void splitChunks(char const *filePath, string chunkName, char const *outputFilePath);
//merge those individual chunks into same outputFile
void mergeChunks(char const *filePath, string chunkName, char const *outputFilePath);