#ifndef Renderer_RenderState_ColorMask_h
#define Renderer_RenderState_ColorMask_h

#include <string>
namespace Aurora {
	namespace Renderer {
		namespace RenderState {

			class ColorMask
			{
			private:
				bool red;
				bool green;
				bool blue;
				bool alpha;

			public:
				ColorMask(bool red, bool green, bool blue, bool alpha)
				{
					red = red;
					green = green;
					blue = blue;
					alpha = alpha;
				}
				virtual ~ColorMask() = default;

				bool Alpha() const {
					return alpha;
				}
				template<typename T>
				void Alpha(T &&value) {


					alpha = std::forward<T>(value);
				}

				bool Blue() const {
					return blue;
				}
				template<typename T>
				void Blue(T &&value) {


					blue = std::forward<T>(value);
				}

				bool Red() const {
					return red;
				}
				template<typename T>
				void Red(T &&value) {


					red = std::forward<T>(value);
				}

				bool Green() const {
					return green;
				}
				template<typename T>
				void Green(T &&value) {


					green = std::forward<T>(value);
				}

				bool Equals(const ColorMask &other)
				{
					return
						red == other.red &&
						green == other.green &&
						blue == other.blue &&
						alpha == other.alpha;
				}

				bool operator ==(const ColorMask &right)
				{
					return this->Equals(right);
				}

				bool operator !=(const ColorMask &right)
				{
					return !this->Equals(right);
				}

				std::string ToString()
				{
					return("Red:" + std::to_string(this->red) + " Green:" + std::to_string(this->green) + " Blue:" + std::to_string(this->blue) + " Alpha:" + std::to_string(this->alpha));
				}

				int GetHashCode()
				{
					std::hash<bool> boolHash;
					return boolHash(this->red) ^ boolHash(this->green) ^ boolHash(this->blue) ^ boolHash(this->alpha);
				}

			};
		};
	};
};
#endif