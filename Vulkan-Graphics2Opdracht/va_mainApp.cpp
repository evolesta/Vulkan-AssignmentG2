#include "va_mainApp.h"

namespace va {

	// public
	void vaMainApp::run() {
		initVulkan();
		mainLoop();
		cleanup();
	}

	// private
	void vaMainApp::initVulkan() {
		vaBaseDevice.createInstance();
		vaBaseDevice.setupDebugMessenger();
		vaBaseDevice.createSurface();
		vaBaseDevice.pickPhysicalDevice();
		vaBaseDevice.createLogicalDevice();
		vaSwapChain.createSwapChain();
		vaSwapChain.createImageViews();
		vaSwapChain.createRenderPass();
		vaGraphicsPipeline.createGraphicsPipeline();
		vaSwapChain.createFramebuffers();
		vaBaseDevice.createCommandPool();
		vaBaseDevice.createCommandBuffer();
	}

	void vaMainApp::mainLoop() {
		// Main loop to keep the GLFW window open
		while (!vaWindow.shouldClose()) {
			glfwPollEvents();
		}
	}

	void vaMainApp::cleanup() {
		vaGraphicsPipeline.cleanup();
		vaSwapChain.cleanup();
		vaBaseDevice.cleanup();
		vaWindow.cleanup();
	}
}