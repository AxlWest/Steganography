#pragma once

class ImageFile ;

class LSB_2_2_2
{
    public :

        LSB_2_2_2() ; //Constructer
        ~LSB_2_2_2() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
