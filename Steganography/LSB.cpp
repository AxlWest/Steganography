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

ImageFile* LSB::proformSteganography(ImageFile* image , const char *messagePathway)
{
	FILE* file = NULL ;
    int i = 0 ;
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

    for(i ; i < fileSize ; i++) //Each loop hides one letter in 8 LSB's
	{
        if(textData[i] & 128) //Is the first Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 64) //Is the second Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 32) //Is the third Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 16) //Is the forth Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 8) //Is the fith Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 4) //Is the sixth Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 2) //Is the seventh Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte

        if(textData[i] & 1) //Is the eighth Bit a 1
		{
            if(imageData[k] & 1) //RGB LSB is also a 1
			{
                //Already a 1 do nothing
			}
            else //RGB LSB is a 0
			{
				imageData[k] ^= 1 << 0 ;
			}
		}
        else //Bit is a 0
		{
            if(imageData[k] & 1) //RGB LSB is a 1
			{
				imageData[k] ^= 1 << 0 ;
			}
            else //RGB LSB is also a 0
			{
                //Already a 0 do nothing
			}
		}

        k++ ; //Next RGB byte
	}

    this->addEnding(image , k);

	image->setImage(imageData) ;

	return image ;
}

void LSB::extractSteganography(ImageFile* image , const char *messageFileName)
{
	FILE* file = NULL ;
	unsigned char* textData = NULL ;
	unsigned char* imageData = NULL ;
	int k = 0 ;
    int end = 0 ;
    unsigned int imageSize = 0 ;

    imageSize = image->getImageSize() ;

    textData = (unsigned char*)malloc(imageSize * sizeof(unsigned char)) ;
	imageData = image->getImage() ;

    for(int i = 0 ; i < imageSize ; i++) //Initilize the text data to 0
	{
		textData[i] = 0 ;
	}

    for(int i = 0 ; i < (imageSize / 3) ; i++) //Each loop makes one char from 8 LSB's
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

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 6 ;
		}
		else
		{
			textData[i] ^= 0 << 6 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 5 ;
		}
		else
		{
			textData[i] ^= 0 << 5 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 4 ;
		}
		else
		{
			textData[i] ^= 0 << 4 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 3 ;
		}
		else
		{
			textData[i] ^= 0 << 3 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 2 ;
		}
		else
		{
			textData[i] ^= 0 << 2 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 1 ;
		}
		else
		{
			textData[i] ^= 0 << 1 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

		if(imageData[k] & 1)
		{
			textData[i] |= 1 << 0 ;
		}
		else
		{
			textData[i] ^= 0 << 0 ;
		}

		k++ ;

        if(k > imageSize)
        {
            break ;
        }

        if(textData[i] == '=' || textData[i] == '<' || textData[i] == 'E' || textData[i] == 'N' || textData[i] == 'D' || textData[i] == '!' || textData[i] == '>')
        {
            end++ ;
        }
        else
        {
            end = 0 ;
        }

        if(end == 8)
        {
            break ;
        }
	}

	if(messageFileName != NULL)
	{
		file = fopen(messageFileName , "wb") ;
	}
	else
	{
		file = fopen("ExtractedMessage.txt" , "wb") ;
	}

    fwrite(textData , sizeof(unsigned char) , image->getImageSize() , file) ;

	fclose(file) ;
}

void LSB::addEnding(ImageFile *image , int k)
{
    //=<END!>=

    unsigned char* imageData = NULL ;

    imageData = image->getImage() ;

    //Store the =
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    //Store the <
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    //Store the E
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    //Store the N
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    //Store the D
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    //Store the !
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    //Store the >
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    //Store the =
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ;

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ;
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
