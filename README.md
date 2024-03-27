Implementation of a rendering system, including the main program, CPU-side operations, rendering pipeline, and shaders.

### Files
The project consists of several source files, each serving a distinct purpose in the rendering process.
In this Documentation I will be describing files that I have worked on:

- **Main Program**: `main.c` - Contains the entry point and orchestration of the rendering process.
- **CPU-side Operations**: `CPU.C` - Implements CPU-side operations, including data loading and manipulation.
- **Rendering Pipeline**: `PIPELINE.C` - Implements the rendering pipeline responsible for transforming vertices and assembling primitives for rasterization.
- **Shaders**: `SHADER.C` - Contains implementations of vertex and fragment shaders for lighting and shading computations.

### Main Program
#### `main.c`
- **Overview**: Serves as the entry point for the rendering system. It initializes necessary resources, orchestrates the rendering process, and handles user interaction.
- - **Description**: 
  - Initializes SDL library.
  - Creates a window using SDL.
  - Sets up the rendering environment and orchestrates the rendering process.
  - Handles user input events such as keyboard and mouse interactions.
  - Supports switching between different rendering methods using keyboard shortcuts.
  - Manages the main rendering loop until the application is exited.

### CPU-side Operations
#### `CPU.C`
- **Overview**: Implements CPU-side operations such as data loading, manipulation, and preparation for rendering.
- **Functions**:
  - Functions for loading data from files or other sources.
  - Data manipulation functions for preprocessing or transforming input data.
  - Additional utilities for CPU-side operations.

### Rendering Pipeline
#### `PIPELINE.C`
- **Overview**: Implements the rendering pipeline responsible for transforming input vertices into clip-space coordinates, assembling primitives, and preparing data for rasterization.
- **Functions**:
  - `gpu_computeGLVertexID`: Computes the `gl_VertexID` from the `vertexShaderInvocation`.
  - `gpu_computeVertexAttributeDataPointer`: Computes the pointer to vertex attribute data based on the vertex index.
  - `gpu_runVertexPuller`: Runs the vertex puller to set the correct addresses for vertex attributes.
  - `gpu_runPrimitiveAssembly`: Assembles primitives by running the vertex puller and vertex shader for each vertex.

### Vertex and Fragment Shaders
#### `SHADER.C`
- **Overview**: Implements vertex and fragment shaders for lighting and shading computations using the Phong illumination model.
- **Functions**:
  - `phong_vertexShader`: Transforms input vertices into clip-space coordinates and computes output vertex attributes.
  - `phong_fragmentShader`: Computes Phong shading with specular reflection based on input fragment attributes.
- **Additional Elements**:
  - Macros and Functions for value clamping.

## CPU.C

This file contains the implementation of the CPU side for Phong shading.

### Functions

#### `phong_onInit(int32_t width, int32_t height)`

This function is called to initialize the CPU side of the Phong shading. It creates a GPU, sets the viewport size, initializes matrices, initializes light position, reserves uniform variables for matrices, camera position, and light position, creates a shader program, attaches shaders, sets attribute interpolation, creates buffers for bunny vertices and indices, configures the vertex puller, and sets up indexing.

##### Parameters
- `width`: The width of the viewport.
- `height`: The height of the viewport.

#### `phong_onExit()`

This function is called to clean up resources used by the CPU side of the Phong shading.

#### `phong_onDraw(SDL_Surface *surface)`

This function is called to perform drawing using Phong shading. It clears the depth and color buffers, activates the shader program, activates the vertex puller, sets uniform data for matrices, camera position, and light position, and draws triangles.

##### Parameters
- `surface`: Pointer to the SDL surface to draw onto.

### Todo
- Complete the initialization function (`phong_onInit`) by implementing buffer creation, shader program setup, vertex puller configuration, and uniform variable setup.
- Implement the drawing function (`phong_onDraw`) by activating the shader program, activating the vertex puller, setting uniform data, and drawing triangles.



## PIPELINE.C

This file contains the implementation of the rendering pipeline.

### Functions

#### `gpu_computeGLVertexID(const VertexIndex *const indices, const VertexShaderInvocation vertexShaderInvocation)`

This function computes the `gl_VertexID` from the `vertexShaderInvocation` and optional indexing. If indexing is not used, it returns the `vertexShaderInvocation`. If indexing is used, it retrieves the vertex index from the indices array.

#### `gpu_computeVertexAttributeDataPointer(const GPUVertexPullerHead *const head, const VertexIndex gl_VertexID)`

This function computes the pointer to the data of the specified vertex attribute based on the vertex puller head and `gl_VertexID`. It considers the enabled status of the head and calculates the precise address of the attribute data.

#### `gpu_runVertexPuller(GPUVertexPullerOutput *const output, const GPUVertexPullerConfiguration *const puller, const VertexShaderInvocation vertexShaderInvocation)`

This function runs the vertex puller, computing the addresses of vertex attributes for the specified `vertexShaderInvocation`. It iterates over enabled vertex puller heads, computes the attribute pointers, and stores them in the output structure.

#### `gpu_runPrimitiveAssembly(const GPU gpu, GPUPrimitive *const primitive, const size_t nofPrimitiveVertices, const GPUVertexPullerConfiguration *const puller, const VertexShaderInvocation baseVertexShaderInvocation, const VertexShader vertexShader)`

This function assembles primitives by running the vertex puller and vertex shader for each vertex of the primitive. It computes the `vertexShaderInvocation` for each vertex, runs the vertex puller to obtain attribute data, and runs the vertex shader to process the attributes. It populates the `primitive` structure with the resulting vertices.

### Additional Functions (Truncated)

Due to space constraints, the following functions' descriptions have been truncated:
- `gpu_runFrustumPlaneClippingOnEdge`: Performs clipping of an edge by a frustum plane.
- `gpu_writeClippedTriangle_OneVertexVisible`: Writes one triangle when only one vertex is visible.

These functions handle frustum plane clipping and triangle clipping, respectively.



## SHADER.C

This file contains the implementation of the Phong vertex and fragment shaders.

### Phong Vertex Shader

#### `phong_vertexShader(GPUVertexShaderOutput *const output, const GPUVertexShaderInput *const input, const GPU gpu)`

This function transforms input vertices into clip-space. It retrieves the view and projection matrices from the GPU's uniform variables, interprets input vertex attributes (position and normal) from the GPU, and transforms the position to clip-space using matrix multiplication. The transformed position and normal are written to the output structure.

### Phong Fragment Shader

#### `phong_fragmentShader(GPUFragmentShaderOutput *const output, const GPUFragmentShaderInput *const input, const GPU gpu)`

This function computes Phong shading with Phong specular reflection. It retrieves the camera and light positions from the GPU's uniform variables, interprets input fragment attributes (interpolated position and normal) from the GPU, and performs the following calculations:
- Diffuse color calculation based on the orientation of the surface normal.
- Diffuse and specular lighting calculations using the Phong reflection model.
- Writing the final color to the output structure.

### Additional Macros and Functions

- `CLAMPF(_x, _min, _max)`: A macro to constrain a float value within a specified range.
- `clampVec3(Vec3 *const v, const float min, const float max)`: A function to constrain a Vec3 value within a specified range.

These macros and functions assist in value clamping and are utilized within the shader implementations.

