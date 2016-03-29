#pragma once

class ImageFile ;

class LSB_4_4_4
{
    public :

        LSB_4_4_4() ; //Constructor
        ~LSB_4_4_4() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;

        void addEnding(ImageFile* image , int k) ;
} ;
