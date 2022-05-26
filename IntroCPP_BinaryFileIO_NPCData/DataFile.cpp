#include "DataFile.h"
#include <fstream>
#include "raylib.h"
using namespace std;

Image LoadImageEx(Color* pixels, int width, int height)
{
	Image image = { 0 };
	unsigned char* fileData = (unsigned char*)pixels;
	unsigned char* dataPtr = fileData;
	unsigned int size = GetPixelDataSize(width, height, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
	image.data = RL_MALLOC(size);      // Allocate required memory in bytes
	if (image.data)
	{
		memcpy(image.data, dataPtr, size); // Copy required data to image
		image.width = width;
		image.height = height;
		image.mipmaps = 1;
		image.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
	}
	return image;
}

Color* GetImageData(Image image)
{
	return (Color*)image.data;
}

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	//Clear();
}

//void DataFile::AddRecord(string imageFilename, string name, int age)
//{
//	Image i = LoadImage(imageFilename.c_str());
//
//	Record* r = new Record;
//	r->image = i;
//	r->name = name;
//	r->age = age;
//
//	records.push_back(r);
//	recordCount++;
//}

DataFile::Record DataFile::GetRecord(int index)
{
	return record;
}

//void DataFile::Save(string filename)
//{
//	ofstream outfile(filename, ios::binary);
//
//	int recordCount = records.size();
//	outfile.write((char*)&recordCount, sizeof(int));
//
//	for (int i = 0; i < recordCount; i++)
//	{		
//		Color* imgdata = GetImageData(records[i]->image);
//				
//		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
//		int nameSize = records[i]->name.length();
//		int ageSize = sizeof(int);
//
//		outfile.write((char*)&records[i]->image.width, sizeof(int));
//		outfile.write((char*)&records[i]->image.height, sizeof(int));
//		
//		outfile.write((char*)&nameSize, sizeof(int));
//		outfile.write((char*)&ageSize, sizeof(int));
//
//		outfile.write((char*)imgdata, imageSize);
//		outfile.write((char*)records[i]->name.c_str(), nameSize);
//		outfile.write((char*)&records[i]->age, ageSize);
//
//	}
//
//	outfile.close();
//}

void DataFile::Load(string filename, unsigned int index)
{
	//Clear();

	ifstream infile(filename, ios::binary);
	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int)); //record count is 5 (in the file)
	int nameSize = 0;
	int ageSize = 0;
	int width = 0, height = 0, format = 0, imageSize = 0;

	for (int i = 0; i <= index; i++)
	{				
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		if (i == index)		// if i == index then load record
		{
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize +1];
			name[nameSize] = '\0';
			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			//Record record;
			record.image = img;
			record.name = name;
			record.age = age;
		
			//records = { record };	// no push back because no vector so replaced with record
			
			delete[] imgdata;
			delete[] name;
		}
		else // else skip record using seekg with std::ios::cur by the size of the record
		{
			infile.seekg(nameSize + ageSize + imageSize, std::ios::cur);	// size of the record is based on imageSize, nameSize and ageSize
		}
		
		//Record* r = new Record();
		//r.image = img;
		//r->name = string(name);
		//r->age = age;
		//records = { r };

	}
	infile.close();
}

//void DataFile::Clear()
//{
//	for (int i = 0; i < records.size(); i++)
//	{
//		delete records[i];
//	}
//	records.clear();
//	recordCount = 0;
//}