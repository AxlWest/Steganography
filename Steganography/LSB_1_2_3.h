#pragma once

class ImageFile ;

class LSB_1_2_3
{
    public :

        LSB_1_2_3() ; //Constructor
        ~LSB_1_2_3() ; //Destructor

        ImageFile* proformSteganography(ImageFile* image , const char* messagePathway) ;
        void extractSteganography(ImageFile* image , const char* messageFileName) ;
} ;
