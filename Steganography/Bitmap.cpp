#include <stdio.h>
#include <stdlib.h>
#include "Bitmap.h"
#include "ImageFile.h"

Bitmap::Bitmap(void)
{
}

Bitmap::~Bitmap(void)
{
}

ImageFile* Bitmap::bitmapFileLoader(const char* imagePathway)
{
	FILE *filePtr ;
	
	BITMAPFILEHEADER	bitmapFileHeader;		// bitmap file header
	unsigned char		*bitmapImage;			// bitmap image data
	int					imageIdx = 0;		// image index counter
	unsigned char		tempRGB;				// swap variable

	// open filename in "read binary" mode
	filePtr = fopen(imagePathway, "rb") ;

	if (filePtr == NULL)
	{
		return NULL ;
	}

	// read the bitmap file header
	fread(&bitmapFileHeader , sizeof(BITMAPFILEHEADER) , 1 , filePtr) ;
	
	// verify that this is a bitmap by checking for the universal bitmap id
	if(bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr) ;
		return NULL ;
	}

	// read the bitmap information header
	fread(&bitmapInfoHeader , sizeof(BITMAPINFOHEADER) , 1 , filePtr);

	// move file pointer to beginning of bitmap data
	fseek(filePtr , bitmapFileHeader.bfOffBits , SEEK_SET);

	// allocate enough memory for the bitmap image data
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader.biSizeImage);

	// verify memory allocation
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// read in the bitmap image data
	fread(bitmapImage, 1, bitmapInfoHeader.biSizeImage, filePtr);

	// make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(filePtr) ;
		return NULL ;
	}

	// swap the R and B values to get RGB since the bitmap color format is in BGR
	for (imageIdx = 0; imageIdx < bitmapInfoHeader.biSizeImage; imageIdx+=3)
	{
		tempRGB = bitmapImage[imageIdx] ;
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2] ;
		bitmapImage[imageIdx + 2] = tempRGB ;
	}

	// close the file and return the bitmap image data
	fclose(filePtr) ;

	ImageFile* imageFile = NULL ;
	imageFile = new ImageFile() ;

	imageFile->setHeight(bitmapInfoHeader.biHeight) ;
	imageFile->setWidth(bitmapInfoHeader.biWidth) ;
	imageFile->setImageSize(bitmapInfoHeader.biSizeImage) ;
	imageFile->setImage(bitmapImage) ;

	return imageFile ;
}

int Bitmap::bitmapFileSaver(char* fileName , int width , int height , unsigned char* imageData)
{
    FILE			 *filePtr;		// file pointer
    BITMAPFILEHEADER bitmapFileHeader;	// bitmap file header
    BITMAPINFOHEADER bitmapInfoHeader;	// bitmap info header
    int				 imageIdx;	// used for swapping RGB->BGR
    unsigned char	 tempRGB;			// used for swapping

    int add = 4 - ((width * 3)%4) ; //Work out bytes to add at end of line for line padding

    if(add == 4)
    {
        add = 0 ;
    }

    int size = ((width * 3) + add) * height ; //Calculate size of image with padding

    // open file for writing binary mode
    filePtr = fopen(fileName, "wb");
    if (!filePtr)
        return 0;

    // define the bitmap file header
    bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER);
    bitmapFileHeader.bfType = 0x4D42;
    bitmapFileHeader.bfReserved1 = 0;
    bitmapFileHeader.bfReserved2 = 0;
    bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // define the bitmap information header
    bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfoHeader.biPlanes = 1;
    bitmapInfoHeader.biBitCount = 24;						// 24-bit
    bitmapInfoHeader.biCompression = 0 ;//BI_RGB;				// no compression
    bitmapInfoHeader.biSizeImage = size ;
    bitmapInfoHeader.biXPelsPerMeter = 0;
    bitmapInfoHeader.biYPelsPerMeter = 0;
    bitmapInfoHeader.biClrUsed = 0;
    bitmapInfoHeader.biClrImportant = 0;
    bitmapInfoHeader.biWidth = width;						// bitmap width
    bitmapInfoHeader.biHeight = height;					// bitmap height

    // switch the image data from RGB to BGR
    for (imageIdx = 0; imageIdx < bitmapInfoHeader.biSizeImage; imageIdx+=3)
    {
        tempRGB = imageData[imageIdx];
        imageData[imageIdx] = imageData[imageIdx + 2];
        imageData[imageIdx + 2] = tempRGB;
    }

    // write the bitmap file header
    fwrite(&bitmapFileHeader, 1, sizeof(BITMAPFILEHEADER), filePtr);

    // write the bitmap info header
    fwrite(&bitmapInfoHeader, 1, sizeof(BITMAPINFOHEADER), filePtr);

    // write the image data
    fwrite(imageData, 1, bitmapInfoHeader.biSizeImage, filePtr);

    // close our file
    fclose(filePtr);

    return 1;
}
