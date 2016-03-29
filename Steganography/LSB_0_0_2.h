#pragma once

class ImageFile ;

class LSB_0_0_2
{
    public :

        LSB_0_0_2() ;
        ~LSB_0_0_2() ;

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
