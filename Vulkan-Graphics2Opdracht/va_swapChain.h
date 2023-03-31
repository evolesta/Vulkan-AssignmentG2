#pragma once

#include "va_window.h"
#include "va_baseDevice.h"

#include <vector>
#include <iostream>
#include <algorithm>

namespace va {

	class vaSwapChain {
	public:
		vaSwapChain(vaBaseDevice &deviceRef, vaWindow &windowRef);

		void createSwapChain();
		void createImageViews();
		void cleanup();

		// Getters
		VkFormat swapChainImageFormat() { return _swapChainImageFormat; }

	private:
		// Variables
		vaBaseDevice &device;
		vaWindow &window;

		VkSwapchainKHR _swapChain;
		std::vector<VkImage> _swapChainImages;
		VkFormat _swapChainImageFormat;
		VkExtent2D _swapChainExtent;
		std::vector<VkImageView> _swapChainImageViews;

		// Helper functions
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	};
}