#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <typeinfo>
#include "split_merge_func.h"

using namespace std;

// split a file into serveral chunks
void splitChunks(char *filePath, char* chunkName, char *outputFilePath) {
    ifstream fileStream;
    // read in binary
    fileStream.open(filePath, ios::in | ios::binary);
    // fileStream.seekg(0, ios::end);
    // streampos sp=fileStream.tellg();
    //cout << "file size is " << sp << endl;
    int count;

    if (fileStream.is_open()) {
        ofstream chunk;
        // buffer to save one chunk
        char *buffer = new char[chunkSize];

        chunk.open(chunkName.c_str(), ios::out | ios:: trunc | ios:: binary);

        //fileStream.read(buffer, chunkSize);
        for(int i = 0; i < chunkSize; i++) {
            if (!fileStream.eof()) {
                fileStream >> buffer[i];
                //cout << buffer[i]<<endl;
            }
        }
        // save a fixed size to chunk file
        if (chunk.is_open()) {
            chunk.write(buffer, chunkSize);
            chunk.close();
        }

        ofstream restFileStream;
        restFileStream.open(outputFilePath, ios::out | ios:: trunc | ios:: binary);

        // find the inputfile size
        fileStream.seekg(0, ios::end);
        int fileStreamLength = fileStream.tellg();
        cout << "file size is " << fileStreamLength << endl;

        // buffer to save rest file
        char *restFileBuffer = new char[fileStreamLength];

        if (restFileStream.is_open()) {
            // save rest file into the outputFilePath
            fileStream.seekg(chunkSize, ios::beg);
            fileStream.read(restFileBuffer, fileStreamLength - chunkSize);
            restFileStream.write(restFileBuffer,fileStream.gcount());
            restFileStream.close();
        }
        delete[] buffer;
        delete[] restFileBuffer;
        fileStream.close();

        filePathForLoad = outputFilePath;
        outputFilePathForLoad = filePath;

        cout << "chunking success" << endl;
        cout << "input file: " << filePathForLoad << endl;
        cout << "output file: " << filePath << endl;
    }
    else {
        cout << "Error opening the file" << endl;
    }
}

//merge those individual chunks into same outputFile
void mergeChunks(char const *filePath, string chunkName, char const *outputFilePath) {
    ifstream chunkFileStream;
    chunkFileStream.open(chunkName.c_str(), ios::in | ios::binary);

    char *chunkBuffer = new char[chunkSize];
    chunkFileStream.read(chunkBuffer, chunkSize);

    // chunk file add to end of the inputFile
    fstream inputFileStream;
    inputFileStream.open(filePath, ios:: in | ios::out | ios:: binary | ios:: app);
    inputFileStream.write(chunkBuffer, chunkFileStream.gcount());

    //get the size of the new inputfile
    inputFileStream.seekg(0, ios::end);
    int length = inputFileStream.tellg();
    cout << length << endl;
    
    //create a buffer and output all content in the inputfile to the buffer
    char *inputBuffer = new char[length];
    inputFileStream.seekg(0, ios::beg);
    inputFileStream.read(inputBuffer, length);
    
    // write the inputfile content to the outputfile
    ofstream outputFileStream;
    outputFileStream.open(outputFilePath, ios:: out | ios:: binary);
    outputFileStream.write(inputBuffer, inputFileStream.gcount());
    
    delete[] chunkBuffer;
    delete[] inputBuffer;
    chunkFileStream.close();
    inputFileStream.close();
    outputFileStream.close();
}

//For individual testing
/*int main() {
    //splitChunks("/Users/lujie/Desktop/testchunk.txt", "project.txt", "/Users/lujie/Desktop/test_out.txt");
    mergeChunks("/Users/lujie/Desktop/testchunk.txt", "chunk.txt", "/Users/lujie/Desktop/test_out.txt");
}*/
