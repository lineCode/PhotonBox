# PhotonBox
A modern OpenGL Game-Engine with focus on PBR

## Project Goal
The PhotonBox Engine aims to be an open source resource for people interested in graphics and system architecture. The goal is to create a clean and readable codebase, whilst still maintaining good performance and a high graphical fidelity. An Editor is currently not planned as I am still exploring the possibilities for state based GUI solutions.

## Rendering 
- Deferred/Forward Rendering
- Point lights, Directional lights, Spot lights
- SkyBox/Enviroment Mapping
- Parallax cubeMap correction
- Cook Torrance BRDF shader
  - Albedo Map
  - Normal Map
  - Roughness Map
  - Metallic Map
  - Ambient Occclusion Map
  - Emission Map
- Dynamic Irradiance & Specular-Convolution generation
- Post Processing List
  - Eye adaptation
  - Bloom
  - Tone mapping
  - SSAO
  - SSReflections
  - Temporal anti aliasing
- Transparent/Cutout rendering
- Shadow mapping
- Contact shadows
- Volumetric Fog
- Text rendering

## Systems
- Component system
- Scene system
- Generic Materials
- Lightprobe volumes
- Resource caching
- Async resource loading
- Shader hot reload
- PhysX 3.4 partial integration
- ImGui integration

## Media
Interiour
![screenshot_1](https://user-images.githubusercontent.com/7956606/35122763-2d3a2934-fca0-11e7-8f38-552fcc106b7e.png)

Automotive
![screenshot 2](https://user-images.githubusercontent.com/7956606/43651128-d3b01440-9741-11e8-9224-c5bded3dedce.png)


## Project Setup
### For Windows
Generate the visual studio project files, by doubleclicking on `generate_project_win.bat` inside the `Tools` directory.

### For Linux
Install needed dependencies by executing `sudo apt install make mesa-common-dev mesa-utils xorg-dev libglu1-mesa-dev freeglut3-dev`.
Then generate the codelite project files, by executing the script with `./generate_project_linux.sh` inside the `Tools` directory.

### For Mac (Can't test :S)
Generate the xcode project files, by executing the script with `./generate_project_mac.sh` inside the `Tools` directory.

## Roadmap
### RENDERING
- Instanced rendering
- Deferred decals
- GTAO
- Anisotropic filtering

### GENERAL
- Resource management and pooling
- Precompile shader
- Abstraction layer over OpenGL
- Precompiled headers
- Switch to dynamic library compilation
- Decoupling asset conversion from engine
- Doxygen integration for documentation

### OPTIMIZATION
- Frustum culling
- Uniform buffer
- SIMD math