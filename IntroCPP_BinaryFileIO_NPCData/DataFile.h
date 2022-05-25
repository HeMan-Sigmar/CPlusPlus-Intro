#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;

	};

private:
	int recordCount;
	//vector<Record*> records;	// delete this vector. Load only the required record 
	Record record;

public:
	DataFile();
	~DataFile();
	//void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);
	Record records{ nullptr };
	int GetRecordCount() { return recordCount; };

	//void Save(string filename);
	void Load(string filename, unsigned int index);

private:
	//void Clear();

};

