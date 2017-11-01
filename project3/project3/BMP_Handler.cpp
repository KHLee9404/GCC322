#include "BMP_Handler.h"
#include "Bitmap.h"
#include <fstream>

using namespace std;


unsigned char* BMP_Handler::loadBMP(const char *filename, int &width, int &height){
	ifstream fin;

	fin.open(filename, ios::binary);

	unsigned char header[14] = "";	

	fin.seekg(0,ios::end);
	int length = fin.tellg();	
	fin.seekg(0,ios::beg);
	
	fin.read((char*)header,sizeof(header));		
	
	int offset=*(int*)&header[10];		

	unsigned char dib[54 - 14] = "";

	if(offset == 54){
		fin.read((char*)dib,sizeof(dib));
	}
	
	width=*(int*)&dib[4];
	height=*(int*)&dib[8];
	
	int padding = 4 - ((3*width)%4)== 0 ? 0 : 4 - ((3 * width) % 4);
	int size = (height * ((width * 3) + padding));

	unsigned char *bmp = new unsigned char[size];	
	fin.read((char*)bmp,sizeof(char)*size);
	fin.close();
	return bmp;
}

void BMP_Handler::saveBMP(const char* filename, const unsigned char* bmp, int width, int height) {
	DIB dib;		
	ofstream fout;
	fout.open(filename, ios::binary | ios::trunc);	

	dib.width = width;
	dib.heigth = height;
	int padding = 4-((3*width)%4)==0?0:4-((3*width)%4);
	int size = (height*((width * 3) + padding));
	dib.sizeBMP = size;
	dib.data.filesize = dib.data.offset + size;
	fout.write(reinterpret_cast<char*>(&dib), sizeof(dib));
	for (int i = 0; i < size; i++) {
		fout << bmp[i];
	}
	fout.close();
}