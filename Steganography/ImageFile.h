class ImageFile
{
	private:

		unsigned char* image ;
		int width ;
		int height ;
		int imageSize ;

	public :

		ImageFile(void) ; //Constructor
		~ImageFile(void) ; //destructor

		void setWidth(int width) ;
		void setHeight(int height) ;
		void setImageSize(int imageSize) ;
		void setImage(unsigned char* image) ;

		int getWidth(void) ;
		int getHeight(void) ;
		int getImageSize(void) ;
		unsigned char* getImage(void) ;
} ;