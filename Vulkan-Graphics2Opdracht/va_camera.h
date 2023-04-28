#pragma once

#include <glm/glm.hpp>

namespace va {
	class vaBaseDevice;
	class vaGraphicsPipeline;
	class vaSwapChain;
	class vaCamera {

	public:
		vaCamera(vaBaseDevice &deviceRef, vaGraphicsPipeline &gpRef, vaSwapChain &swapChainRef);

		// Camera structure
		struct Camera {
			glm::vec3 position; // position of the camera
			glm::vec3 target; // position of the camera is looking at
			glm::vec3 up; // up vector of the camera
			float fov; // Field of view of the camera
			float aspectRatio; // Aspect ratio of the screen
			float nearClip; // Distance to the near clip plane
			float farClip; // Distance to the far clip plane
		};

		// Getters
		glm::mat4 getView() { return _view; }

		// Helper function
		void updateView(glm::vec3 position, glm::vec3 target, glm::vec3 up);
		void updateProjection(float aspectRation);

	private:
		// variables
		glm::mat4 _projection;
		glm::mat4 _view;
		Camera _camera;

		vaBaseDevice &device;
		vaGraphicsPipeline &graphicsPipeline;
		vaSwapChain &swapChain;
	};
}