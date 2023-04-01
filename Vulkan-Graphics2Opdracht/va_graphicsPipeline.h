#pragma once

#include "va_baseDevice.h"

#include <iostream>
#include <vector>
#include <fstream>

namespace va {
	class vaSwapChain;

	class vaGraphicsPipeline {
	public:
		vaGraphicsPipeline(vaBaseDevice &deviceRef, vaSwapChain &swapchainRef);

		void createGraphicsPipeline();
		void cleanup();

		// Getters
		VkPipeline graphicsPipeline() { return _graphicsPipeline; }

	private:
		// Variables
		vaBaseDevice &device;
		vaSwapChain &swapchain;
		VkPipelineLayout _pipelineLayout;
		VkPipeline _graphicsPipeline;

		// Helper functions
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
	};
}