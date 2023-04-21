#pragma once

#include "va_baseDevice.h"

#include <stb_image.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <chrono>

namespace va {
	class vaSwapChain;
	class vaModel;

	class vaGraphicsPipeline {
	public:
		vaGraphicsPipeline(vaBaseDevice &deviceRef, vaSwapChain &swapchainRef, vaModel &modelRef);

		struct UniformBufferObject {
			alignas(16) glm::mat4 model;
			alignas(16) glm::mat4 view;
			alignas(16) glm::mat4 proj;
		};

		void createGraphicsPipeline();
		void createVertexBuffer();
		void createIndexBuffer();
		void createUniformBuffers();
		void createDescriptorSetLayout();
		void createDescriptorPool();
		void createDescriptorSets();
		void createTextureImage();
		void createTextureImageView();
		void createTextureSampler();
		void createDepthResources();
		void cleanup();

		// Getters
		VkPipeline graphicsPipeline() { return _graphicsPipeline; }
		VkBuffer vertexBuffer() { return _vertexBuffer; }
		VkBuffer indexBuffer() { return _indexBuffer; }
		VkPipelineLayout pipelineLayout() { return _pipelineLayout; }
		VkDescriptorSet& descriptorSet(uint32_t index) { return _descriptorSets[index]; }
		VkImageView depthImageView() { return _depthImageView; }

		// Helper functions
		void updateUniformBuffer(uint32_t currentImage);
		VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
		VkFormat findDepthFormat();

	private:
		// Variables
		vaBaseDevice &device;
		vaSwapChain &swapchain;
		vaModel &model;
		VkDescriptorSetLayout _descriptorSetLayout;
		VkPipelineLayout _pipelineLayout;
		VkPipeline _graphicsPipeline;
		VkBuffer _vertexBuffer;
		VkDeviceMemory _vertexBufferMemory;
		VkBuffer _indexBuffer;
		VkDeviceMemory _indexBufferMemory;
		VkDescriptorPool _descriptorPool;
		std::vector<VkDescriptorSet> _descriptorSets;
		uint32_t _mipLevels;
		VkImage _textureImage;
		VkDeviceMemory _textureImageMemory;
		VkImageView _textureImageView;
		VkSampler _textureSampler;	
		VkImage _depthImage;
		VkDeviceMemory _depthImageMemory;
		VkImageView _depthImageView;

		std::vector<VkBuffer> _uniformBuffers;
		std::vector<VkDeviceMemory> _uniformBuffersMemory;
		std::vector<void*> _uniformBuffersMapped;

		// Helper functions
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
		uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
		VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		bool hasStencilComponent(VkFormat format);
		void generateMipmaps(VkImage image, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
};
}