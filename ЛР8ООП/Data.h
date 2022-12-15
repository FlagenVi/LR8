#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define TEST
using namespace std;
class Data
{
private:
	string FileName;
	int Lines = 0;
	int WordsCount = 0;
	int WordsFound = 0;
	vector<string> data;
	vector<string> dataFind;
	void ReadFile();
	void print_data();
	void print_dataFind();
	bool isvowel(char ch);
public:
	Data(string filename1);
	~Data();
	void find();
	string get_FileName();
	int get_Lines();
	int get_WordsCount();
	int get_WordsFound();
	void print_to_file();
};