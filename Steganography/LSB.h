#pragma once

class ImageFile ;

class LSB
{
	public :

		LSB(void) ; //Constructor
		~LSB(void) ; //Destructor

		ImageFile* proformSteganography(ImageFile* image , char* messagePathway) ;
		void extractSteganography(ImageFile* image , char* messageFileName) ;

		bool prayItFits(unsigned int imageSize , unsigned int textSize) ;
} ;