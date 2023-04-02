#pragma once

#include "va_window.h"

#include <vector>
#include <iostream>
#include <optional>
#include <set>

namespace va {
	class vaSwapChain;

	class vaBaseDevice {
	
	public:
		vaBaseDevice(vaWindow &window, vaSwapChain &swapChainRef);

		#ifdef NDEBUG
				const bool enableValidationLayers = false;
		#else
				const bool enableValidationLayers = true;
		#endif

		struct SwapChainSupportDetails {
			VkSurfaceCapabilitiesKHR capabilities;
			std::vector<VkSurfaceFormatKHR> formats;
			std::vector<VkPresentModeKHR> presentModes;
		};
		struct QueueFamilyIndices { std::optional<uint32_t> graphicsFamily; std::optional<uint32_t> presentFamily; bool isComplete() { return graphicsFamily.has_value(); } };

		// Getters
		VkDevice device() { return _device; }
		VkPhysicalDevice physicalDevice() { return _physicalDevice; }
		VkSurfaceKHR surface() { return _surface; }
		SwapChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(_physicalDevice); }
		QueueFamilyIndices getQueueFamilies() { return findQueueFamilies(_physicalDevice); }

		void createInstance();
		void setupDebugMessenger();
		void createSurface();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createCommandPool();
		void createCommandBuffer();
		void createSyncObjects();
		void drawFrame();
		void cleanup();

	private:
		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

		const int MAX_FRAMES_IN_FLIGHT = 2;

		VkInstance _instance;
		VkDebugUtilsMessengerEXT _debugMessenger;
		VkPhysicalDevice _physicalDevice;
		VkDevice _device;
		VkQueue _graphicsQueue;
		VkQueue _presentQueue;
		VkSurfaceKHR _surface;
		VkCommandPool _commandPool;
		std::vector<VkCommandBuffer> _commandBuffers;
		std::vector<VkSemaphore> _imageAvailableSemaphores;
		std::vector<VkSemaphore> _renderFinishedSemaphores;
		std::vector<VkFence> _inFlightFences;
		uint32_t _currentFrame = 0;

		vaWindow &_window;
		vaSwapChain &swapChain;

		// Helper functions instance
		std::vector<const char*> getRequiredExtensions();

		// Helper functions validation layers
		bool checkValidationLayerSupport();
		VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator,
			VkDebugUtilsMessengerEXT* pDebugMessenger);
		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		// Helper functions physical device
		bool isDeviceSuitable(VkPhysicalDevice device);
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	};
}