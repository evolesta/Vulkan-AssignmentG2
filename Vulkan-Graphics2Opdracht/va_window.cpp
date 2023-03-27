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
	}

	void vaWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface");
		}
	}
}