#include "LSB_0_1_0.h"
#include "ImageFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LSB_0_1_0::LSB_0_1_0()
{

}

LSB_0_1_0::~LSB_0_1_0()
{

}

ImageFile* LSB_0_1_0::proformSteganography(ImageFile* image , const char *messagePathway)
{
    FILE* file = NULL ;
    unsigned int k = 1 ;
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


    for(int i = 0 ; i < fileSize ; i++) //Each loop hides 3 letters in 24 LSB's
    {
        if(textData[i] & 128) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 64) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 32) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 16) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 8) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 4) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 2) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)

        if(textData[i] & 1) //Is the first Bit a 1
        {
            if(imageData[k] & 1) //Green byte LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //Red byte LSB is a 0
            {
                imageData[k] ^= 1 << 0 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 1) //Red byte LSB is a 1
            {
                imageData[k] ^= 1 << 0 ;
            }
            else //Red byte is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next byte (Blue)
        k++ ; //Next byte (Red)
        k++ ; //Next byte (Green)
    }

    this->addEnding(image , k) ;

    image->setImage(imageData) ;

    return image ;
}

void LSB_0_1_0::extractSteganography(ImageFile* image , const char *messageFileName)
{
    FILE* file = NULL ;
    unsigned char* textData = NULL ;
    unsigned char* imageData = NULL ;
    int k = 1 ;
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
        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 7 ;
        }
        else
        {
            textData[i] ^= 0 << 7 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 6 ;
        }
        else
        {
            textData[i] ^= 0 << 6 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 5 ;
        }
        else
        {
            textData[i] ^= 0 << 5 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 4 ;
        }
        else
        {
            textData[i] ^= 0 << 4 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 3 ;
        }
        else
        {
            textData[i] ^= 0 << 3 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 2 ;
        }
        else
        {
            textData[i] ^= 0 << 2 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 1 ;
        }
        else
        {
            textData[i] ^= 0 << 1 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

        if(k > imageSize)
        {
            break ;
        }

        if(imageData[k] & 1) //Green LSB
        {
            textData[i] |= 1 << 0 ;
        }
        else
        {
            textData[i] ^= 0 << 0 ;
        }

        k++ ; //Next RGB byte (Blue)
        k++ ; //Next RGB byte (Red)
        k++ ; //Next RGB byte (Green)

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

void LSB_0_1_0::addEnding(ImageFile *image , int k)
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

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the <
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the E
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the N
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the D
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)
    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the !
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the >
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    //Store the =
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    k++ ; //Next RGB byte (Blue)
    k++ ; //Next RGB byte (Red)
    k++ ; //Next RGB byte (Green)
}
