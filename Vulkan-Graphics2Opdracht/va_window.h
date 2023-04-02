#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace va {

	class vaWindow {

	public:
		vaWindow(int w, int h, std::string title);
		
		// Getters
		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent();
		bool getFramebufferResized() { return framebufferResized; }
		void resetFramebufferResized() { framebufferResized = false; }

		void cleanup();

		// Helper functions
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		void minimization();

	private:
		void initWindow();

		const int width;
		const int height;
		std::string windowTitle;
		GLFWwindow *window;
		bool framebufferResized = false;
	};
}