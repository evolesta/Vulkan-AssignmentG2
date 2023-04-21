#pragma once

#include <tiny_obj_loader.h>
#include <glm/gtx/hash.hpp>

#include <array>
#include <unordered_map>
#include "va_baseDevice.h"

namespace va {

	class vaGraphicsPipeline;

	class vaModel {
	public:
		vaModel(vaGraphicsPipeline &graphicsPipelineRef);

		// Vertex input
		struct Vertex {
			glm::vec3 pos;
			glm::vec3 color;
			glm::vec2 texCoord;

			static VkVertexInputBindingDescription getBindingDescription() {
				VkVertexInputBindingDescription bindingDescription{};
				bindingDescription.binding = 0;
				bindingDescription.stride = sizeof(Vertex);
				bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

				return bindingDescription;
			}

			static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
				std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};
				attributeDescriptions[0].binding = 0;
				attributeDescriptions[0].location = 0;
				attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
				attributeDescriptions[0].offset = offsetof(Vertex, pos);

				attributeDescriptions[1].binding = 0;
				attributeDescriptions[1].location = 1;
				attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
				attributeDescriptions[1].offset = offsetof(Vertex, color);

				attributeDescriptions[2].binding = 0;
				attributeDescriptions[2].location = 2;
				attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
				attributeDescriptions[2].offset = offsetof(Vertex, texCoord);


				return attributeDescriptions;
			}

			bool operator==(const Vertex& other) const {
				return pos == other.pos && color == other.color && texCoord == other.texCoord;
			}
		};

		// Main functions
		void loadModel();
		
		// Getters
		uint32_t verticesSize() { return _vertices.size(); }
		uint32_t indicesSize() { return _indices.size(); }
		std::vector<Vertex> vertices() { return _vertices; }
		std::vector<uint32_t> indices() { return _indices; }

		std::string MODEL_PATH() { return _MODEL_PATH; }
		std::string TEXTURE_PATH() { return _TEXTURE_PATH; }

	private:
		std::string _MODEL_PATH = "models/viking_room.obj";
		std::string _TEXTURE_PATH = "textures/viking_room.png";

		vaGraphicsPipeline &graphicsPipeline;
		std::vector<Vertex> _vertices;
		std::vector<uint32_t> _indices;
	};
}