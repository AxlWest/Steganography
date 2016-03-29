#pragma once

class ImageFile ;

class LSB_0_0_1
{
    public :

        LSB_0_0_1() ; //Constructor
        ~LSB_0_0_1() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
