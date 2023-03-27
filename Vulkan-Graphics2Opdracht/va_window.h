#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace va {

	class vaWindow {

	public:
		vaWindow(int w, int h, std::string title);
		
		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent();

		void cleanup();

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		void initWindow();

		const int width;
		const int height;
		std::string windowTitle;
		GLFWwindow *window;
	};
}