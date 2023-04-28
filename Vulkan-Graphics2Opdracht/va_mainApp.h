#pragma once

#include "va_window.h"
#include "va_baseDevice.h"
#include "va_swapChain.h"
#include "va_graphicsPipeline.h"
#include "va_model.h"
#include "va_camera.h"

#include <vector>

namespace va {

	class vaMainApp {
	public: 
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		vaWindow vaWindow{ WIDTH, HEIGHT, "Vulkan Assignment render", vaCamera };
		vaBaseDevice vaBaseDevice{vaWindow, vaSwapChain, vaGraphicsPipeline};
		vaSwapChain vaSwapChain{ vaBaseDevice, vaWindow, vaGraphicsPipeline, vaModel };
		vaGraphicsPipeline vaGraphicsPipeline{ vaBaseDevice, vaSwapChain, vaModel, vaCamera };
		vaModel vaModel{ vaGraphicsPipeline };
		vaCamera vaCamera{ vaBaseDevice, vaGraphicsPipeline, vaSwapChain };

		void initVulkan();
		void mainLoop();
		void cleanup();
	};
}