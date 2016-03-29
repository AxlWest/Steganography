#include "LSB_4_4_4.h"
#include "ImageFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LSB_4_4_4::LSB_4_4_4()
{
}

LSB_4_4_4::~LSB_4_4_4()
{
}

ImageFile* LSB_4_4_4::proformSteganography(ImageFile* image , const char *messagePathway)
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

    for(int i = 0 ; i < fileSize ; i++) //Each loop hides one letter in 8 LSB's
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

        if(textData[i] & 64) //Is the second Bit a 1
        {
            if(imageData[k] & 2) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 1 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 2) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 1 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 32) //Is the third Bit a 1
        {
            if(imageData[k] & 4) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 2 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 4) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 2 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 16) //Is the forth Bit a 1
        {
            if(imageData[k] & 8) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 3 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 8) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 3 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next RGB byte

        if(textData[i] & 8) //Is the first Bit a 1
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

        if(textData[i] & 4) //Is the second Bit a 1
        {
            if(imageData[k] & 2) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 1 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 2) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 1 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 2) //Is the third Bit a 1
        {
            if(imageData[k] & 4) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 2 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 4) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 2 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 1) //Is the forth Bit a 1
        {
            if(imageData[k] & 8) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 3 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 8) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 3 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(i < (image->getImageSize() /8)) //Check to see if all the data has been retrived
        {
            i++ ; //Increment the loop counter by 1 (Start retreving data from the next RGB set)
        }
        else //There is no more data left to be retrived
        {
            break ; //Break out of the loop
        }

        k++ ; //Next RGB byte

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

        if(textData[i] & 64) //Is the second Bit a 1
        {
            if(imageData[k] & 2) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 1 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 2) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 1 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 32) //Is the third Bit a 1
        {
            if(imageData[k] & 4) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 2 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 4) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 2 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 16) //Is the forth Bit a 1
        {
            if(imageData[k] & 8) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 3 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 8) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 3 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next RGB byte

        if(textData[i] & 8) //Is the first Bit a 1
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

        if(textData[i] & 4) //Is the second Bit a 1
        {
            if(imageData[k] & 2) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 1 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 2) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 1 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 2) //Is the third Bit a 1
        {
            if(imageData[k] & 4) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 2 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 4) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 2 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        if(textData[i] & 1) //Is the forth Bit a 1
        {
            if(imageData[k] & 8) //RGB LSB is also a 1
            {
                //Already a 1 do nothing
            }
            else //RGB LSB is a 0
            {
                imageData[k] ^= 1 << 3 ;
            }
        }
        else //Bit is a 0
        {
            if(imageData[k] & 8) //RGB LSB is a 1
            {
                imageData[k] ^= 1 << 3 ;
            }
            else //RGB LSB is also a 0
            {
                //Already a 0 do nothing
            }
        }

        k++ ; //Next RGB byte
    }

    this->addEnding(image , k) ;

    image->setImage(imageData) ;

    return image ;
}

void LSB_4_4_4::extractSteganography(ImageFile* image , const char *messageFileName)
{
    FILE* file = NULL ;
    unsigned char* textData = NULL ;
    unsigned char* imageData = NULL ;
    int k = 0 ;
    int end = 0 ;

    textData = 0 ;

    textData = (unsigned char*)malloc(image->getImageSize() * sizeof(unsigned char)) ;
    imageData = image->getImage() ;

    for(int i = 0 ; i < image->getImageSize() ; i++) //Initilize the text data to 0
    {
        textData[i] = 0 ;
    }

    for(int i = 0 ; i < (image->getImageSize() /8) ; i++) //Each loop makes one char from 8 LSB's
    {
        if(imageData[k] & 1)
        {
            textData[i] |= 1 << 7 ;
        }
        else
        {
            textData[i] ^= 0 << 7 ;
        }

        if(imageData[k] & 2)
        {
            textData[i] |= 1 << 6 ;
        }
        else
        {
            textData[i] ^= 0 << 6 ;
        }

        if(imageData[k] & 4)
        {
            textData[i] |= 1 << 5 ;
        }
        else
        {
            textData[i] ^= 0 << 5 ;
        }

        if(imageData[k] & 8)
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

        if(imageData[k] & 2)
        {
            textData[i] |= 1 << 2 ;
        }
        else
        {
            textData[i] ^= 0 << 2 ;
        }

        if(imageData[k] & 4)
        {
            textData[i] |= 1 << 1 ;
        }
        else
        {
            textData[i] ^= 0 << 1 ;
        }

        if(imageData[k] & 8)
        {
            textData[i] |= 1 << 0 ;
        }
        else
        {
            textData[i] ^= 0 << 0 ;
        }

        k++ ;

        if(i < (image->getImageSize() /8)) //Check to see if all the data has been retrived
        {
            i++ ; //Increment the loop counter by 1 (Start retreving data from the next RGB set)
        }
        else //There is no more data left to be retrived
        {
            break ; //Break out of the loop
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

        if(imageData[k] & 1)
        {
            textData[i] |= 1 << 7 ;
        }
        else
        {
            textData[i] ^= 0 << 7 ;
        }

        if(imageData[k] & 2)
        {
            textData[i] |= 1 << 6 ;
        }
        else
        {
            textData[i] ^= 0 << 6 ;
        }

        if(imageData[k] & 4)
        {
            textData[i] |= 1 << 5 ;
        }
        else
        {
            textData[i] ^= 0 << 5 ;
        }

        if(imageData[k] & 8)
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

        if(imageData[k] & 2)
        {
            textData[i] |= 1 << 2 ;
        }
        else
        {
            textData[i] ^= 0 << 2 ;
        }

        if(imageData[k] & 4)
        {
            textData[i] |= 1 << 1 ;
        }
        else
        {
            textData[i] ^= 0 << 1 ;
        }

        if(imageData[k] & 8)
        {
            textData[i] |= 1 << 0 ;
        }
        else
        {
            textData[i] ^= 0 << 0 ;
        }

        k++ ;

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

void LSB_4_4_4::addEnding(ImageFile *image , int k)
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

    if(imageData[k] & 2)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }


    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    //Store the <
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    //Store the E
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    //Store the N
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    //Store the D
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    //Store the !
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 22)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    //Store the >
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        imageData[k] ^= 1 << 3 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    k++ ; //Next byte

    //Store the =
    if(imageData[k] & 1)
    {
        imageData[k] ^= 1 << 0 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 2)
    {
        imageData[k] ^= 1 << 1 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 4)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 2 ;
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte

    if(imageData[k] & 1)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 0 ;
    }

    if(imageData[k] & 2)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 1 ;
    }

    if(imageData[k] & 4)
    {
        imageData[k] ^= 1 << 2 ;
    }
    else //RGB LSB is a 0
    {
        //Already a 0 do nothing
    }

    if(imageData[k] & 8)
    {
        //Already a 1 do nothing
    }
    else //RGB LSB is a 0
    {
        imageData[k] ^= 1 << 3 ;
    }

    k++ ; //Next byte
}
