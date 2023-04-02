#pragma once

#include "va_window.h"
#include "va_baseDevice.h"
#include "va_swapChain.h"
#include "va_graphicsPipeline.h"

#include <vector>

namespace va {

	class vaMainApp {
	public: 
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		vaWindow vaWindow{ WIDTH, HEIGHT, "Vulkan Assignment render" };
		vaBaseDevice vaBaseDevice{vaWindow, vaSwapChain};
		vaSwapChain vaSwapChain{ vaBaseDevice, vaWindow, vaGraphicsPipeline };
		vaGraphicsPipeline vaGraphicsPipeline{ vaBaseDevice, vaSwapChain };

		void initVulkan();
		void mainLoop();
		void cleanup();
	};
}