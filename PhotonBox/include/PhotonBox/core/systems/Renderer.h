#ifndef RENDERER_H
#define RENDERER_H

class CubeMap;
class FrameBuffer;
class TransparentShader;
class GShader;
class TransparentMeshRenderer;
class DeferredShader;
class Material;
class AABB;

#include <vector>

#include "PhotonBox/resources/ForwardAmbientLightShader.h"
#include "PhotonBox/resources/ForwardDirectionalLightShader.h"
#include "PhotonBox/resources/ForwardPointLightShader.h"
#include "PhotonBox/resources/ForwardSpotLightShader.h"
#include "PhotonBox/resources/SkyBox.h"

enum RenderType
{
	opaque, cutout, transparent
};

class Renderer
{
public:
	static const int MAX_DEBUG = 4;
	static const int SHADOW_MAP_RESOLUTION = 4096;

	static int getDebugMode() { return _debugMode; }
	static void setDebug(int debugMode);
	static void addToRenderQueue(ObjectRenderer *renderer, RenderType type);
	static void removeFromRenderQueue(ObjectRenderer *renderer);
	static void setSkyBox(CubeMap* cubeMap);
	static SkyBox* getSkyBox() { return &_skyBox; }
	static void printList();
	static void setClearColor(Vector3f color);
	static Vector3f getClearColor() { return _clearColor; }
	static void addDrawCall();
	static int getDrawCalls() { return _drawCalls; }
	static FrameBuffer* getMainFrameBuffer() { return _mainFrameBuffer; }
	static FrameBuffer* getGBuffer() { return _gBuffer; }
	static FrameBuffer* getDebugBuffer() { return _gizmoBuffer; }
	static FrameBuffer* getShadowBuffer() { return _shadowBuffer; }

	void init(float superSampling = 1);
	void start();
	void reset();
	void prePass();
	void clearDrawCalls();

	static void renderDeferred();
	static void renderForward();
	static void renderTransparents();
	static void renderShadows();
	static void captureScene(LightMap* lightmap = nullptr);
	
	void renderGizmos();
	void destroy();
private:
	static int _drawCalls;
	static void clearTransparentQueue();
	static void updateTransparentQueue();
	static SkyBox _skyBox;
	static FrameBuffer* _mainFrameBuffer;
	static FrameBuffer* _gBuffer;
	static FrameBuffer*	_gizmoBuffer;
	static FrameBuffer* _shadowBuffer;
	static int _debugMode;
	static std::vector<ObjectRenderer*> _renderListOpaque;
	static std::vector<ObjectRenderer*> _renderListTransparent;
	static Vector3f _clearColor;

	static std::map<float, TransparentMeshRenderer*> _renderQueueTransparent;

	static ForwardAmbientLightShader* _ambientLightShader;
	static ForwardDirectionalLightShader* _directionalLightShader;
	static ForwardPointLightShader* _pointLightShader;
	static ForwardSpotLightShader* _spotLightShader;
	static TransparentShader* _transparentBaseShader;
	static DeferredShader* _deferredShader;
	static DepthShader* _depthShader;
	static Material* _deferredMaterial;
};

#endif // RENDERER_H
