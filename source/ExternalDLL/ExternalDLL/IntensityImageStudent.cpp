#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	int size = other.getWidth() * other.getHeight();
	for (int i = 0; i < size; i++) {
		pixelStorage.push_back(other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	// Resize the vector according to the new width and height 
	pixelStorage.resize(width*height);
}

IntensityImageStudent::~IntensityImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	// Clear the current pixel storage
	pixelStorage.clear();
	// resize the vector according to the new width and height
	pixelStorage.resize(width*height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
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

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	// Calculate the i value on bases of x,y coordinates 
	int i = y * IntensityImage::getWidth() + x;
	setPixel(i, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	// write pixel info into pixel storage
	pixelStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	// first calculate i value on bases of x,y coordinates the get value form pixelstorage
	int i = y * IntensityImage::getWidth() + x;
	return getPixel(i);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	// Get pixel from pixelstorage
	return pixelStorage[i];;
}