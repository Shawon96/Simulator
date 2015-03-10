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
			std::shared_ptr<Aurora::Renderer::PrimitiveRestart> primitiveRestart;
			bool depthMask;
			std::shared_ptr<FacetCulling> facetCulling;
			ProgramPointSize programPointSize;
			RasterizationMode rasterizationMode;
			std::shared_ptr<ScissorTest> scissorTest;
			std::shared_ptr<StencilTest> stencilTest;
			std::shared_ptr<DepthTest> depthTest;
			std::shared_ptr<DepthRange> depthRange;
			std::shared_ptr<Blending> blending;
			std::shared_ptr<ColorMask> colorMask;
		public:
			RenderState()
			{
				primitiveRestart = std::make_shared<Aurora::Renderer::PrimitiveRestart>();
				facetCulling = std::make_shared<Aurora::Renderer::FacetCulling>();
				programPointSize = ProgramPointSize::Disabled;
				rasterizationMode = RasterizationMode::Fill;
				scissorTest = std::make_shared<Aurora::Renderer::ScissorTest>();
				stencilTest = std::make_shared<Aurora::Renderer::StencilTest>();
				depthTest = std::make_shared<Aurora::Renderer::DepthTest>();
				depthRange = std::make_shared<Aurora::Renderer::DepthRange>();
				blending = std::make_shared<Aurora::Renderer::Blending>();
				colorMask = std::make_shared<Aurora::Renderer::ColorMask>(true, true, true, true);
				depthMask = true;
			}

			std::shared_ptr<Aurora::Renderer::PrimitiveRestart> PrimitiveRestart() const {
				return primitiveRestart;
			}
			template<typename T>
			void PrimitiveRestart(T &&value) {
				primitiveRestart = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::FacetCulling> FacetCulling() const {
				return facetCulling;
			}
			template<typename T>
			void FacetCulling(T &&value) {
				facetCulling = std::forward<T>(value);
			}

			Aurora::Renderer::ProgramPointSize ProgramPointSize() const {
				return programPointSize;
			}
			template<typename T>
			void ProgramPointSize(T &&value) {
				programPointSize = std::forward<T>(value);
			}

			Aurora::Renderer::RasterizationMode RasterizationMode() const {
				return rasterizationMode;
			}
			template<typename T>
			void RasterizationMode(T &&value) {
				rasterizationMode = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::ScissorTest> ScissorTest() const {
				return scissorTest;
			}
			template<typename T>
			void ScissorTest(T &&value) {
				scissorTest = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::StencilTest> StencilTest() const {
				return stencilTest;
			}
			template<typename T>
			void StencilTest(T &&value) {
				stencilTest = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::DepthTest> DepthTest() const {
				return depthTest;
			}
			template<typename T>
			void DepthTest(T &&value) {
				depthTest = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::DepthRange> DepthRange() const {
				return depthRange;
			}
			template<typename T>
			void DepthRange(T &&value) {
				depthRange = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::Blending> Blending() const {
				return blending;
			}
			template<typename T>
			void Blending(T &&value) {
				blending = std::forward<T>(value);
			}

			std::shared_ptr<Aurora::Renderer::ColorMask> ColorMask() const {
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
#endif