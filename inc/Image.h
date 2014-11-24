#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

class Image
{
public:
	Image ();
	Image (int width, int height);	
	~Image ();

	// Copy constractor and Assignemt operator
	Image (const Image& src);
	Image& operator= (const Image& src);

	void swap (Image& src);
	void setPixel (int x, int y, unsigned char pixel);
	unsigned char getPixel (int x, int y) const;
	// Tests if the image data exists, and presumably valid.
	bool isValid () const { return pixels_ != 0;}	

	int width () const { return width_;} // Image width
	int height () const { return height_;} // Image height
	
	class rangeError {}; // Exception class	

private:
	// Initialize or cleanup the allocated image data
	void init ();
	void cleanup ();
	
	int width_; // Image width
	int height_; // Image height
	unsigned char * pixels_;
};

#endif // IMAGE_H