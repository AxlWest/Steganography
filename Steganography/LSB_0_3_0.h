#pragma once

class ImageFile ;

class LSB_0_3_0
{
    public :

        LSB_0_3_0() ; //Constructor
        ~LSB_0_3_0() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
