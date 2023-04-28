#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include "va_camera.h"
#include "va_baseDevice.h"
#include "va_graphicsPipeline.h"
#include "va_swapChain.h"
#include <cassert>
#include <limits>

namespace va {
	vaCamera::vaCamera(vaBaseDevice& deviceRef, vaGraphicsPipeline& gpRef, vaSwapChain& swapChainRef) : device{ deviceRef }, graphicsPipeline{ gpRef }, swapChain{swapChainRef} {};

	// Main functions

	// Helper functions
	void vaCamera::updateView(glm::vec3 position, glm::vec3 target, glm::vec3 up) {
		_view = glm::lookAt(position, target, up);
	}

	void vaCamera::updateProjection(float aspectRatio) {
		_projection = glm::perspective(glm::radians(_camera.fov), aspectRatio, _camera.nearClip, _camera.farClip);
	}
}