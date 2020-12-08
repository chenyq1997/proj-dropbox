#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#define FILL1 'd'
#define FILL2 '1'
using namespace std;
const int chunk_len = 100;

void pad(char *a)
{
	string chunkname(&a[0],&a[strlen(a)]);
	const char *path_out,*path;
	ifstream infile;
	string s = "data/SampleInputForProjectII/";
	string s1=s.append(chunkname);
	path = s1.append(".txt").c_str();
	path_out = s1.c_str();
	cout<<path<<endl;
	
	string chunk;
	
	infile.open(path);
	getline(infile,chunk,'\n');
	if (chunk.length() >= chunk_len) return;
	ofstream outfile(path_out);
	
	char default_rail = FILL1;
	char default_rail2 = FILL2;
	int l = chunk.length();
	if (chunk[l-1] != default_rail)
	{
		chunk.append(chunk_len-l,default_rail);
		cout<<"has been added "<<chunk_len-l << " d"<<endl;
		cout<<chunk<<endl;
	}
	else {
		chunk.append(chunk_len-l,default_rail2);
		cout<<"has been added "<<chunk_len-l << " 1"<<endl;
		cout<<chunk<<endl;
	}
	infile.close();
	outfile<< chunk<<endl;
}
void depad(string chunkname)
{
	const char *path_out,*path;
	ifstream infile;
	string s = "data/SampleInputForProjectII/";
	string s1=s.append(chunkname);
	
	// check if there is an add file
	path = s1.append(".txt").c_str();
	path_out = s1.c_str();
	string chunk;
	infile.open(path);
	if(!infile){
		cout << "Error opening file " <<endl;
		return;
	}
	
	cout<<path<<endl;
	getline(infile,chunk,'\n');
	infile.close();
	
	ofstream outfile(path_out);
	char default_rail = FILL1;
	char default_rail2 = FILL2;
	int l = chunk.length();
	if (chunk[l-1] == default_rail)
	{
		int i=l-1;
		while (i>0){
			if (chunk[i]!=default_rail) break;
			i--;
		}
		chunk = chunk.substr(0,i+1);
		cout<<"Has been deleted " << l-i-1 << " d"<<endl;
		cout<<chunk<<endl;
	} 
	else {
		int i=l-1;
		while (i>0){
			if (chunk[i]!=default_rail2) break;
			i--;
		}
		chunk = chunk.substr(0,i+1);
		cout<<"Has been deleted " << l-i-1 << " 1"<<endl;
		cout<<chunk<<endl;
	}
	
	outfile<< chunk<<endl;
	outfile.close();
}

int main(){

	int chunk_number = 3;
	 
	string input;
	ifstream infile1,infile2;
/*	ofstream outfile("data/SampleInputForProjectII/10-chrunk.txt");
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
	char c[] = "chunk2";
	pad(c);
}