#include "ImageFile.h"

ImageFile::ImageFile(void)
{
}

ImageFile::~ImageFile(void)
{
}

void ImageFile::setHeight(int height)
{
	this->height = height ;
}

void ImageFile::setWidth(int width)
{
	this->width = width ;
}

void ImageFile::setImageSize(int imageSize)
{
	this->imageSize = imageSize ;
}

void ImageFile::setImage(unsigned char* image)
{
	this->image = image ;
}

int ImageFile::getHeight(void)
{
	return this->height ;
}

int ImageFile::getWidth(void)
{
	return this->width ;
}

int ImageFile::getImageSize(void)
{
	return this->imageSize ;
}

unsigned char* ImageFile::getImage(void)
{
	return this->image ;
}