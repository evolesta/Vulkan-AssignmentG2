#pragma once

#include "va_baseDevice.h"

#include <vector>
#include <iostream>
#include <algorithm>

namespace va {
	class vaGraphicsPipeline;

	class vaSwapChain {
	public:
		vaSwapChain(vaBaseDevice &deviceRef, vaWindow &windowRef, vaGraphicsPipeline &graphicsPipelineRef);

		void createSwapChain();
		void createImageViews();
		void createRenderPass();
		void createFramebuffers();
		void cleanup();

		// Public helper functions
		void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

		// Getters
		VkRenderPass renderPass() { return _renderPass; }
		VkSwapchainKHR swapChain() { return _swapChain; }

	private:
		// Variables
		vaBaseDevice &device;
		vaWindow &window;
		vaGraphicsPipeline &graphicsPipeline;

		VkSwapchainKHR _swapChain;
		std::vector<VkImage> _swapChainImages;
		VkFormat _swapChainImageFormat;
		VkExtent2D _swapChainExtent;
		VkRenderPass _renderPass;
		std::vector<VkImageView> _swapChainImageViews;
		std::vector<VkFramebuffer> _swapChainFramebuffers;

		// Helper functions
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	};
}