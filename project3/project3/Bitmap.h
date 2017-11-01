#pragma once

struct Data{
	unsigned short signature;
	unsigned int filesize;
	unsigned int unused;
	unsigned int offset;
	Data() : signature(0x4d42), filesize(0), unused(0x0000), offset(54){ }
};

struct DIB{
	Data data;
	unsigned int headerSize;
	unsigned int width;
	unsigned int heigth;
	unsigned short colorPlane;
	unsigned short bitsPerPixel;
	unsigned int compression;
	unsigned int sizeBMP;
	unsigned int widthPerMeter;
	unsigned int heigthPerMeter;
	unsigned int colorPalette;
	unsigned int importantColors;
	
	DIB();
};

DIB::DIB(){
	data = Data();
	headerSize = 40;
	width = 0;
	heigth = 0;
	colorPlane = 1;
	bitsPerPixel = 24;
	compression = 3;
	sizeBMP = 0;
	widthPerMeter = 0;
	heigthPerMeter = 0;
	colorPalette = 0;
	importantColors = 0;
}
