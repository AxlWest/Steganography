#include "LSB.h"
#include "ImageFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LSB::LSB(void)
{
}

LSB::~LSB(void)
{
}

ImageFile* LSB::proformSteganography(ImageFile* image , char* messagePathway)
{
	FILE* file = NULL ;
	unsigned int k = 0 ;
	unsigned int fileSize = 0 ;
	unsigned char* textData = NULL ;
	unsigned char* imageData = NULL ;

	file = fopen(messagePathway , "rb") ;

	if(file == NULL)
	{
		return NULL ;
	}

	fseek(file , 0 , SEEK_END) ;
	fileSize = ftell(file) ;
	rewind(file) ;

	textData = (unsigned char*)malloc(fileSize) ;

	fread(textData , 1 , fileSize , file) ;

	fclose(file) ;

	imageData = image->getImage() ;

	for(int i = 0 ; i < fileSize ; i++)
	{
		if(textData[i] & 128)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 64)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 32)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 16)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 8)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 4)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 2)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;

		if(textData[i] & 1)
		{
			if(imageData[k] & 1)
			{
				//Already a 1
			}
			else
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
		else
		{
			if(imageData[k] & 1)
			{
				imageData[k] ^= 1 << 0 ;
			}
			else
			{
				//Already a 0
			}
		}

		k++ ;
	}

	/*for(int i = 0 ; i < 100 ; i++)
	{
		printf("%d\n" , imageData[i]) ;
	}*/

	image->setImage(imageData) ;

	return image ;
}

void LSB::extractSteganography(ImageFile* image , char* messageFileName)
{
	FILE* file = NULL ;
	unsigned char* textData = NULL ;
	unsigned char* imageData = NULL ;
	int k = 0 ;

	textData = 0 ;

	textData = (unsigned char*)malloc(image->getImageSize() * sizeof(unsigned char)) ;
	imageData = image->getImage() ;

	for(int i = 0 ; i < image->getImageSize() ; i++)
	{
		textData[i] = 0 ;
	}

	for(int i = 0 ; i < (image->getImageSize() /8) ; i++)
	{
		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 7 ;
		}
		else
		{
			textData[i] ^= 0 << 7 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 6 ;
		}
		else
		{
			textData[i] ^= 0 << 6 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 5 ;
		}
		else
		{
			textData[i] ^= 0 << 5 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 4 ;
		}
		else
		{
			textData[i] ^= 0 << 4 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 3 ;
		}
		else
		{
			textData[i] ^= 0 << 3 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 2 ;
		}
		else
		{
			textData[i] ^= 0 << 2 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 1 ;
		}
		else
		{
			textData[i] ^= 0 << 1 ;
		}

		k++ ;

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 0 ;
		}
		else
		{
			textData[i] ^= 0 << 0 ;
		}

		k++ ;
	}

	if(messageFileName != NULL)
	{
		file = fopen(messageFileName , "wb") ;
	}
	else
	{
		file = fopen("ExtractedMessage.txt" , "wb") ;
	}

	fwrite(textData , sizeof(unsigned char) , 100 , file) ;

	fclose(file) ;
}

bool LSB::prayItFits(unsigned int imageSize , unsigned int textSize)
{
	if((imageSize / 8) >= textSize)
	{
		return true ;
	}
	else
	{
		return false ;
	}
}