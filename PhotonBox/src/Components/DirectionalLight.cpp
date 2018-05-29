#include "../Core/FrameBuffer.h"
#include "../Core/Systems/Lighting.h"
#include "../Core/Systems/Renderer.h"
#include "../Resources/DefaultPostShader.h"
#include "../Resources/DepthShader.h"
#include "../Resources/ForwardDirectionalLightShader.h"
#include "DirectionalLight.h"
#include "imgui\imgui.h"

DirectionalLight::DirectionalLight()
{
	Lighting::addLight(this);
	_depthShader = DepthShader::getInstance();
	_shadowMapResolution = 4096;
	lightProjection = Matrix4f::createOrthographic(-5, 5, -5, 5, 0.1, 100);

	shadowBuffer = new FrameBuffer(_shadowMapResolution, _shadowMapResolution);
	shadowBuffer->addDepthTextureAttachment("depth");
	shadowBuffer->ready();
}

void DirectionalLight::destroy()
{
	Lighting::removeLight(this);
}

Shader * DirectionalLight::getLightShader()
{
	return ForwardDirectionalLightShader::getInstance();
}

void DirectionalLight::renderShadowMap(bool captureMode)
{
	shadowBuffer->enable();
	shadowBuffer->clear();

	Renderer::render(_depthShader, captureMode);

	if(!captureMode){
		ImGui::Begin("Depth");
		ImGui::Image((void *)shadowBuffer->getAttachment("depth")->id, ImVec2(_shadowMapResolution/15, _shadowMapResolution/15));
		ImGui::End();
	}

	FrameBuffer::resetDefaultBuffer();
}
