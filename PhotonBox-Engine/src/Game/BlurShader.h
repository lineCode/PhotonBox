#ifndef BLUR_SHADER_H
#define BLUR_SHADER_H

#include "../Resources/Shader.h"
#include "../Resources/Vertex.h"

class BlurShader : public Shader {
public:
	BlurShader(const std::string& fileName) { init(fileName); }

	void addUniforms() override {
		addUniform("aspectRatio");
		addUniform("offset");
	}

	void addAttributes() override {
		addAttribut("position", Vertex::AttibLocation::POSITION);
	}
};

#endif // BLUR_SHADER_H