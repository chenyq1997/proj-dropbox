#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "pad.h"

using namespace std;

void pad(char *a);
void depad(char *a);
int main(){

	char c[] = "chunk3";
	pad(c);
	depad(c);
	return 0;
}
/*	
	int chunk_number = 3;
 	
	string input;
	ifstream infile1,infile2;
	ofstream outfile("data/SampleInputForProjectII/10-chrunk.txt");
	infile1.open("data/SampleInputForProjectII/10-01.txt");
	getline(infile1,input, '\0');
	int l = input.length();
	int i = 0;
	cout << l <<endl;
	while (i<=l)
	{
		string s=input.substr(i,100);
		i+=100;
		outfile<<s<<endl;
	}
	infile1.close();

	string chunkname;
	int i = 1;
	while(i<=chunk_number){
		chunkname = "chunk";
		ostringstream c;
		c<<i;
		chunkname.append(c.str());
		cout<<chunkname<<endl;
		pad(chunkname);
		cout<<endl;
		i++;
	}
	i=1;
	cout<<endl<<"depad"<<endl;
	while(i<=chunk_number){
		chunkname = "chunk";
		ostringstream c;
		c<<i;
		chunkname.append(c.str());
		cout<<chunkname<<endl;
		depad(chunkname);
		cout<<endl;
		i++;
	}
*/	