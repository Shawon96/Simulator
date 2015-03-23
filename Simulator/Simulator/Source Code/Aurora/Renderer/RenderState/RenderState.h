#ifndef Renderer_RenderState_RenderState_h
#define Renderer_RenderState_RenderState_h

#include "Blending.h"
#include "ColorMask.h"
#include "DepthTest.h"
#include "DepthRange.h"
#include "FacetCulling.h"
#include "PrimitiveRestart.h"
#include "ScissorTest.h"
#include "StencilTest.h"
#include <memory>

namespace Aurora {
	namespace Renderer {
		namespace RenderState {

			enum class ProgramPointSize
			{
				Enabled,
				Disabled
			};

			enum class RasterizationMode
			{
				Point,
				Line,
				Fill
			};

			class RenderState
			{
			private:
				std::shared_ptr<Aurora::Renderer::RenderState::PrimitiveRestart> primitiveRestart;
				bool depthMask;
				std::shared_ptr<Aurora::Renderer::RenderState::FacetCulling> facetCulling;
				ProgramPointSize programPointSize;
				RasterizationMode rasterizationMode;
				std::shared_ptr<Aurora::Renderer::RenderState::ScissorTest> scissorTest;
				std::shared_ptr<Aurora::Renderer::RenderState::StencilTest> stencilTest;
				std::shared_ptr<Aurora::Renderer::RenderState::DepthTest> depthTest;
				std::shared_ptr<Aurora::Renderer::RenderState::DepthRange> depthRange;
				std::shared_ptr<Aurora::Renderer::RenderState::Blending> blending;
				std::shared_ptr<Aurora::Renderer::RenderState::ColorMask> colorMask;
			public:
				RenderState()
				{
					primitiveRestart = std::make_shared<Aurora::Renderer::RenderState::PrimitiveRestart>();
					facetCulling = std::make_shared<Aurora::Renderer::RenderState::FacetCulling>();
					programPointSize = ProgramPointSize::Disabled;
					rasterizationMode = RasterizationMode::Fill;
					scissorTest = std::make_shared<Aurora::Renderer::RenderState::ScissorTest>();
					stencilTest = std::make_shared<Aurora::Renderer::RenderState::StencilTest>();
					depthTest = std::make_shared<Aurora::Renderer::RenderState::DepthTest>();
					depthRange = std::make_shared<Aurora::Renderer::RenderState::DepthRange>();
					blending = std::make_shared<Aurora::Renderer::RenderState::Blending>();
					colorMask = std::make_shared<Aurora::Renderer::RenderState::ColorMask>(true, true, true, true);
					depthMask = true;
				}

				virtual ~RenderState() = default;

				RenderState(const RenderState &value) : primitiveRestart(value.PrimitiveRestart()), 
														facetCulling(value.FacetCulling()), 
														programPointSize(value.ProgramPointSize()), 
														rasterizationMode(value.RasterizationMode()), 
														scissorTest(value.ScissorTest()), 
														stencilTest(value.StencilTest()), 
														depthTest(value.DepthTest()), 
														depthRange(value.DepthRange()), 
														blending(value.Blending()), 
														colorMask(value.ColorMask()), 
														depthMask(value.DepthMask())
				{

				}
				RenderState(RenderState &&value) : primitiveRestart(std::move(value.PrimitiveRestart())),
					facetCulling(std::move(value.FacetCulling())),
					programPointSize(std::move(value.ProgramPointSize())),
					rasterizationMode(std::move(value.RasterizationMode())),
					scissorTest(std::move(value.ScissorTest())),
					stencilTest(std::move(value.StencilTest())),
					depthTest(std::move(value.DepthTest())),
					depthRange(std::move(value.DepthRange())),
					blending(std::move(value.Blending())),
					colorMask(std::move(value.ColorMask())),
					depthMask(std::move(value.DepthMask()))
				{

				}
				RenderState &operator=(RenderState && value)
				{
					if (this == &value)
						return *this;

					primitiveRestart = std::move(value.PrimitiveRestart());
					facetCulling = std::move(value.FacetCulling());
					scissorTest = std::move(value.ScissorTest());
					stencilTest = std::move(value.StencilTest());
					depthTest = std::move(value.DepthTest());
					depthRange = std::move(value.DepthRange());
					blending = std::move(value.Blending());
					colorMask = std::move(value.ColorMask());

					depthMask = value.DepthMask();
					programPointSize = value.ProgramPointSize();
					rasterizationMode = value.RasterizationMode();

					value.PrimitiveRestart(nullptr);
					value.FacetCulling(nullptr);
					value.ScissorTest(nullptr);
					value.StencilTest(nullptr);
					value.DepthTest(nullptr);
					value.DepthRange(nullptr);
					value.Blending(nullptr);
					value.ColorMask(nullptr);

					return *this;
				}
				RenderState& operator=(const RenderState& value)
				{
					if (this == &value)
						return *this;

					primitiveRestart = value.PrimitiveRestart();
					facetCulling = value.FacetCulling();
					programPointSize = value.ProgramPointSize();
					rasterizationMode = value.RasterizationMode();
					scissorTest = value.ScissorTest();
					stencilTest = value.StencilTest();
					depthTest = value.DepthTest();
					depthRange = value.DepthRange();
					blending = value.Blending();
					colorMask = value.ColorMask();
					depthMask = value.DepthMask();

					return *this;
				}

				std::shared_ptr<Aurora::Renderer::RenderState::PrimitiveRestart> PrimitiveRestart() const {
					return primitiveRestart;
				}
				template<typename T>
				void PrimitiveRestart(T &&value) {
					primitiveRestart = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::FacetCulling> FacetCulling() const {
					return facetCulling;
				}
				template<typename T>
				void FacetCulling(T &&value) {
					facetCulling = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::ProgramPointSize ProgramPointSize() const {
					return programPointSize;
				}
				template<typename T>
				void ProgramPointSize(T &&value) {
					programPointSize = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::RasterizationMode RasterizationMode() const {
					return rasterizationMode;
				}
				template<typename T>
				void RasterizationMode(T &&value) {
					rasterizationMode = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::ScissorTest> ScissorTest() const {
					return scissorTest;
				}
				template<typename T>
				void ScissorTest(T &&value) {
					scissorTest = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::StencilTest> StencilTest() const {
					return stencilTest;
				}
				template<typename T>
				void StencilTest(T &&value) {
					stencilTest = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::DepthTest> DepthTest() const {
					return depthTest;
				}
				template<typename T>
				void DepthTest(T &&value) {
					depthTest = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::DepthRange> DepthRange() const {
					return depthRange;
				}
				template<typename T>
				void DepthRange(T &&value) {
					depthRange = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::Blending> Blending() const {
					return blending;
				}
				template<typename T>
				void Blending(T &&value) {
					blending = std::forward<T>(value);
				}

				std::shared_ptr<Aurora::Renderer::RenderState::ColorMask> ColorMask() const {
					return colorMask;
				}
				template<typename T>
				void ColorMask(T &&value) {
					colorMask = std::forward<T>(value);
				}

				bool DepthMask() const {
					return depthMask;
				}
				template<typename T>
				void DepthMask(T &&value) {
					depthMask = std::forward<T>(value);
				}




			};
		};
	};
};
#endif