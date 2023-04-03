#pragma once

#include "va_baseDevice.h"
#include <glm/glm.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <array>

namespace va {
	class vaSwapChain;

	class vaGraphicsPipeline {
	public:
		vaGraphicsPipeline(vaBaseDevice &deviceRef, vaSwapChain &swapchainRef);

		void createGraphicsPipeline();
		void createVertexBuffer();
		void createIndexBuffer();
		void cleanup();

		// Getters
		VkPipeline graphicsPipeline() { return _graphicsPipeline; }
		VkBuffer vertexBuffer() { return _vertexBuffer; }
		VkBuffer indexBuffer() { return _indexBuffer; }
		uint32_t verticesSize() { return vertices.size(); }
		uint32_t indicesSize() { return indices.size(); }

	private:
		// Variables
		vaBaseDevice &device;
		vaSwapChain &swapchain;
		VkPipelineLayout _pipelineLayout;
		VkPipeline _graphicsPipeline;
		VkBuffer _vertexBuffer;
		VkDeviceMemory _vertexBufferMemory;
		VkBuffer _indexBuffer;
		VkDeviceMemory _indexBufferMemory;

		// Vertex input
		struct Vertex {
			glm::vec2 pos;
			glm::vec3 color;

			static VkVertexInputBindingDescription getBindingDescription() {
				VkVertexInputBindingDescription bindingDescription{};
				bindingDescription.binding = 0;
				bindingDescription.stride = sizeof(Vertex);
				bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

				return bindingDescription;
			}

			static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
				std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};
				attributeDescriptions[0].binding = 0;
				attributeDescriptions[0].location = 0;
				attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
				attributeDescriptions[0].offset = offsetof(Vertex, pos);

				attributeDescriptions[1].binding = 0;
				attributeDescriptions[1].location = 1;
				attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
				attributeDescriptions[1].offset = offsetof(Vertex, color);

				return attributeDescriptions;
			}
		};
		const std::vector<Vertex> vertices = {
			{{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
			{{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
			{{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
			{{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
		};
		const std::vector<uint16_t> indices = {
			0, 1, 2, 2, 3,  0
		};

		// Helper functions
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
		uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	};
}