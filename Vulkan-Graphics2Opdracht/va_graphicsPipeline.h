#pragma once

#include "va_window.h"
#include "va_baseDevice.h"
#include "va_swapChain.h"

#include <iostream>
#include <vector>
#include <fstream>

namespace va {

	class vaGraphicsPipeline {
	public:
		vaGraphicsPipeline(vaBaseDevice &deviceRef, vaSwapChain &swapchainRef);

		void createRenderPass();
		void createGraphicsPipeline();
		void cleanup();

	private:
		// Variables
		vaBaseDevice &device;
		vaSwapChain &swapchain;
		VkRenderPass _renderPass;
		VkPipelineLayout _pipelineLayout;
		VkPipeline _graphicsPipeline;

		// Helper functions
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
	};
}