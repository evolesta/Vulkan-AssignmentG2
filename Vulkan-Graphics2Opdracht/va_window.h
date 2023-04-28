#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace va {

	class vaCamera;
	class vaWindow {

	public:
		vaWindow(int w, int h, std::string title, vaCamera &cameraRef);
		
		// Getters
		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent();
		bool getFramebufferResized() { return framebufferResized; }
		void resetFramebufferResized() { framebufferResized = false; }

		// Main functions
		void initWindow();
		void handleInput();
		void cleanup();

		// Helper functions
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		void minimization();

	private:
		const int width;
		const int height;
		std::string windowTitle;
		GLFWwindow *window;
		bool framebufferResized = false;

		vaCamera &camera;
	};
}