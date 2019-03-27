#include "StudentPreProcessing.h"
#include "ImageFactory.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	//Creating the output image
	IntensityImage * output = ImageFactory::newIntensityImage(image.getWidth(),image.getHeight());
	//Calculating the size of the entire picture
	int size = image.getHeight() * image.getWidth();
	//Calculating the intensity value for eacht pixel 
	for (int i = 0;i < size;i++) {
		//get rgb values
		auto RGBPix = image.getPixel(i); 
		// Calculating intensity value on bases of luminance.
		int newIntensity = static_cast<int>(0.3*RGBPix.r + 0.59*RGBPix.g + 0.11*RGBPix.b);
		// Set the intensity value for the output image
		output->setPixel(i, newIntensity);
	}
	return output;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}