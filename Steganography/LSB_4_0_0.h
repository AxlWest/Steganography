#pragma once

class ImageFile ;

class LSB_4_0_0
{
    public :

        LSB_4_0_0() ; //Constructor
        ~LSB_4_0_0() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;
} ;
