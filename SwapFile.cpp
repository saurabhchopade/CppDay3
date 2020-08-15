#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void readWrite(string, string);
void swap(string, string);

int main () {
	const string file1 = "first.txt";
	const string file2 = "second.txt";
	fstream fileStream;

   fileStream.open(file1, ios::out | ios::trunc);
   if(fileStream.is_open()) {
   	cout << "File " << file1 << " is opened " << endl;
      fileStream << "Hello" << endl;
      fileStream << "I am content of first file" << endl;
      fileStream.close();
  	}

   fileStream.open(file2, ios:: out | ios:: trunc);
   if(fileStream.is_open()) {
      cout << "File " << file2 << " is opened " << endl;
      fileStream << "Hello" << endl;
      fileStream << "I am content of second file" << endl;
      fileStream.close();
   }

	swap(file1,file2);
}

void swap(string file1, string file2) {
	readWrite(file1, "temp.txt");
   readWrite(file2, file1);
   readWrite("temp.txt", file2);
   remove("temp.txt");
}

void readWrite(string file1, string file2) {
	string line;
   fstream fileStream(file1, ios::in);
   if(fileStream.is_open()) {
   	cout << "File is opened for reading" << endl;

   	fstream fileStream2;
      fileStream2.open(file2, ios::out | ios::trunc);

     	while (getline(fileStream, line)) {
 	  		if(fileStream2.is_open()) {
      		fileStream2 << line << endl;
   		}
     	}
     	fileStream2.close();
     	fileStream.close();
 	}
}
