#pragma once

//#include <windows.h>

//Alows this to work on linux
#define BYTE  unsigned char
#define DWORD  unsigned int
#define LONG  int
#define UINT  unsigned int
#define WORD  unsigned short int

#define LPSTR  char*


#pragma pack(1)
typedef struct tagBITMAPFILEHEADER {
  WORD    bfType;
  DWORD   bfSize;
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

#pragma pack()

typedef struct tagBITMAPINFOHEADER{
  DWORD  biSize;
  LONG   biWidth;
  LONG   biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

#define BITMAP_ID 0x4D42

class ImageFile ;

class Bitmap
{
	private :

		unsigned char* bitmapData ;

		BITMAPINFOHEADER bitmapInfoHeader ;

	public :

		Bitmap(void) ; //Constructor
		~Bitmap(void) ; //Destructor
		
		ImageFile* bitmapFileLoader(const char* imagePathway) ; //Loads the bitmap file
        int bitmapFileSaver(char* fileName , int width , int height , unsigned char* imageData) ; //Saves the bitmap file
} ;
