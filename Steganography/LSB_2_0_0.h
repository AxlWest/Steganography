#pragma once

class ImageFile ;

class LSB_2_0_0
{
    public :

        LSB_2_0_0() ; //Constructor
        ~LSB_2_0_0() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;
} ;
