#include "va_window.h"

namespace va {
	vaWindow::vaWindow(int w, int h, std::string title) : width{ w }, height{ h }, windowTitle{ title } {
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