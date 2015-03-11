#include "Bitmap.h"

namespace Aurora {
	namespace IO {


		Bitmap::Bitmap()
		{

		}

		Bitmap::Bitmap(const Bitmap &value)
		{

		}

		Bitmap::Bitmap(Bitmap &&value)
		{

		}

		Bitmap::~Bitmap()
		{

		}

		Bitmap & Bitmap::operator=(Bitmap && value)
		{
			if (this == &value)
				return *this;

			return *this;
		}

		Bitmap& Bitmap::operator=(const Bitmap& value)
		{
			if (this == &value)
				return *this;

			return *this;
		}

	};
};