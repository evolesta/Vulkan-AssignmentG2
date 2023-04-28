#include "va_window.h"

namespace va {
	vaWindow::vaWindow(int w, int h, std::string title, vaCamera& cameraRef) : width{ w }, height{ h }, windowTitle{ title }, camera{ cameraRef } {
		initWindow();
	}

	void vaWindow::cleanup() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	VkExtent2D vaWindow::getExtent() {
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		VkExtent2D actualExtent = {
			static_cast<uint32_t>(width),
			static_cast<uint32_t>(height)
		};

		return actualExtent;
	}

	void vaWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
	}

	void vaWindow::handleInput() {
		// W - Going forward
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			std::cout << "Pressed the W key" << std::endl;
		}

		// S - Going backward
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			std::cout << "Pressed the S key" << std::endl;
		}

		// A - going left
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			std::cout << "Pressed the A key" << std::endl;
		}

		// D - going right
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			std::cout << "Pressed the D key" << std::endl;
		}

		
	}

	// Helper functions
	void vaWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface");
		}
	}

	void vaWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<vaWindow*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
	}

	void vaWindow::minimization() {
		int width = 0, height = 0;
		glfwGetFramebufferSize(window, &width, &height);

		while (width == 0 || height == 0) {
			glfwGetFramebufferSize(window, &width, &height);
			glfwWaitEvents();
		}
	}
}