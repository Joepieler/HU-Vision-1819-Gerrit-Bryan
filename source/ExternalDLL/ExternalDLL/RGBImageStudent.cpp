#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	int size = other.getWidth() * other.getHeight();
	for (int i = 0; i < size; i++) {
		pixelStorage.push_back(other.getPixel(i));
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	// Resize the vector according to the new width and height 
	pixelStorage.resize(width*height);
}

RGBImageStudent::~RGBImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	// Clear the current pixel storage
	pixelStorage.clear();
	// resize the vector according to the new width and height
	pixelStorage.resize(width*height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	// Calculate the size of the entiere picture
	int size = other.getWidth()*other.getHeight();
	// Clear current storage and resize it
	pixelStorage.clear();
	pixelStorage.resize(size);
	// fill new pixel storage with values from other picture.
	for (int i = 0; i < size; i++) {
		pixelStorage.push_back(other.getPixel(i));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	// Calculate the i value on bases of x,y coordinates 
	int i = y*RGBImage::getWidth() + x;
	setPixel(i,pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	// write pixel info into pixel storage
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	// first calculate i value on bases of x,y coordinates the get value form pixelstorage
	int i = y * RGBImage::getWidth() + x;
	return getPixel(i);
}

RGB RGBImageStudent::getPixel(int i) const {
	// Get pixel from pixelstorage
	return pixelStorage[i];
}