#pragma once

class ImageFile ;

class LSB_0_0_3
{
    public :

        LSB_0_0_3() ; //Constructor
        ~LSB_0_0_3() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
