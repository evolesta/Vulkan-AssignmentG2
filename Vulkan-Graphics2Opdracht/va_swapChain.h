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
		void cleanup();

	private:
		// Variables
		vaBaseDevice &device;
		vaWindow &window;

		VkSwapchainKHR _swapChain;

		// Helper functions
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	};
}