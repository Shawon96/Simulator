#ifndef Renderer_RenderState_StencilTest_h
#define Renderer_RenderState_StencilTest_h

#include "StencilTestFace.h"

namespace Aurora {
	namespace Renderer {
		namespace RenderState {
			class StencilTest
			{
			private:
				bool enabled;
				std::shared_ptr<StencilTestFace> frontFace;
				std::shared_ptr<StencilTestFace> backFace;
			public:
				StencilTest()
				{
					enabled = false;
					frontFace = std::make_shared<StencilTestFace>();
					backFace = std::make_shared<StencilTestFace>();
				}

				virtual ~StencilTest() = default;
				StencilTest(const StencilTest &value) : enabled(value.Enabled()), frontFace(value.FrontFace()), backFace(value.BackFace())
				{

				}
				StencilTest(StencilTest &&value) : enabled(value.Enabled()), frontFace(std::move(value.FrontFace())), backFace(std::move(value.BackFace()))
				{
					value.BackFace(nullptr);
					value.FrontFace(nullptr);
				}
				StencilTest &operator=(StencilTest && value)
				{
					if (this == &value)
						return *this;

					this->enabled = value.Enabled();

					this->frontFace = std::move(value.FrontFace());
					this->backFace = std::move(value.BackFace());
					
					value.BackFace(nullptr);
					value.FrontFace(nullptr);

					return *this;
				}
				StencilTest& operator=(const StencilTest& value)
				{
					if (this == &value)
						return *this;

					this->enabled = value.Enabled();

					this->frontFace = value.FrontFace();
					this->backFace = value.BackFace();

					return *this;
				}

				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}

				std::shared_ptr<StencilTestFace> FrontFace() const {
					return frontFace;
				}
				template<typename T>
				void FrontFace(T &&value) {
					frontFace = std::forward<T>(value);
				}

				std::shared_ptr<StencilTestFace> BackFace() const {
					return backFace;
				}
				template<typename T>
				void BackFace(T &&value) {
					backFace = std::forward<T>(value);
				}
			};
		};
	};
};
#endif