#ifndef IO_Bitmap_h
#define IO_Bitmap_h




namespace Aurora {
	namespace IO {
		class Bitmap
		{
			Bitmap();
			virtual ~Bitmap();
			Bitmap(const Bitmap &value);
			Bitmap(Bitmap &&value);
			Bitmap &operator=(Bitmap && value);
			Bitmap& operator=(const Bitmap& value);
		};
	};
};
#endif