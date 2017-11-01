#include <BMP_Handler.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int width, height;
	unsigned char* bitmapData;
	bitmapData = BMP_Handler::loadBMP("Arrow.bmp", width, height);
	BMP_Handler::saveBMP("Arrow1.bmp", bitmapData, width, height);
	system("pause");
	return 0;
}