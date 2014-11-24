#include "Image.h"

void Image::cleanup ()
{
	// Put the object back into its original, null state.
	delete [] pixels_;
	width_ = 0;
	height_ = 0;
	pixels_ = 0;
}

void Image::init ()
{
	// All memory allocation passes through this function.
	if (width_ > 0 && height_ > 0)
	pixels_ = new unsigned char [width_ * height_];
}

Image::Image (const Image& src) : width_ (0), height_ (0), pixels_ (0)
{
	if (src.isValid()) 
	{
		width_ = src.width ();
		height_ = src.height ();
		init ();
		memcpy (pixels_, src.pixels_, width_ * height_);
	}
}

// Image& Image::operator= (const Image& src)
// {
// 	if (&src != this) 
// 	{
// 		// Delete any existing data and recreate the source image
// 		cleanup ();
// 		width_ = src.width ();
// 		height_ = src.height ();
// 		init ();
// 		memcpy (pixels_, src.pixels_, width_ * height_);
// 	}
// 	return *this;
// }

template<class T> void swap (T& a, T& b)
{
	T copy(a);
	a = b;
	b = copy;
}

void Image::swap (Image& src)
{
	::swap (width_, src.width_);
	::swap (height_, src.height_);
	::swap (pixels_, src.pixels_);
}

Image& Image::operator= (const Image& src)
{
	Image temp (src);
	swap (temp);
	return *this;
}

void Image::setPixel (int x, int y, unsigned char pixel)
{
	if (x < 0 || y < 0 || x >= width_ || y >= height_ || !isValid())
		throw rangeError ();
	unsigned char* p = pixels_ + y*width_ + x;
	*p = pixel;
}

unsigned char Image::getPixel (int x, int y) const
{
	if (x < 0 || y < 0 || x >= width_ || y >= height_ || !isValid())
		throw rangeError ();
	// Image data is stored a row at a time.
	unsigned char* p = pixels_ + y*width_ + x;
	return *p;
}