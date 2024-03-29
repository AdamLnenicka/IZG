/**
 * @file
 * @brief This file contains forward declarations and constants.
 *
 * @author Tomáš Milet, imilet@fit.vutbr.cz
 * @author Adam Lněnička
 */


#pragma once


#include <stdint.h>
#include <stdlib.h>


/**
 * @brief maximal number of vertex attribute components
 */
#define MAX_NUMBER_OF_ATTRIBUTE_COMPONENTS 4

/**
 * @brief maximal number of attributes
 */
#define MAX_ATTRIBUTES 4

/**
 * @brief number of channels per color
 */
#define CHANNELS_PER_COLOR 4

/**
 * @brief pi constant
 */
#define MY_PI 3.14159265359f

/**
 * @brief number of vertices per triangle
 */
#define VERTICES_PER_TRIANGLE 3

/**
 * @brief number of edges per triangle
 */
#define EDGES_PER_TRIANGLE 3

/**
 * @brief number of weights per 2D barycentric coordinates
 */
#define WEIGHTS_PER_BARYCENTRICS 3

/**
 * @brief coord of a pixel center
 */
#define PIXEL_CENTER .5f

/**
 * @brief This value represents maximal number of triangles that can be created
 * by clipping of single input triangle.
 * This value is overestimated.
 */
#define MAX_CLIPPED_TRIANGLES 64


struct GPUPrimitive;                  // forward declaration
struct GPUTriangle;                   // forward declaration
struct GPUTriangleList;               // forward declaration
struct Vec2;                          // forward declaration
struct Vec3;                          // forward declaration
struct Vec4;                          // forward declaration
struct Mat4;                          // forward declaration
struct GPUVertexPullerConfiguration;  // forward declaration
struct GPUVertexShaderOutput;         // forward declaration
struct GPUVertexShaderInput;          // forward declaration
struct GPUFragmentShaderOutput;       // forward declaration
struct GPUFragmentShaderInput;        // forward declaration
struct GPUFragmentAttributes;         // forward declaration
struct GPUVertexPullerHead;           // forward declaration
struct GPUVertexIndexing;             // forward declaration
struct GPUVertexPullerOutput;         // forward declaration


typedef struct GPUPrimitive GPUPrimitive;                       ///< shortcut
typedef struct GPUTriangle GPUTriangle;                         ///< shortcut
typedef struct GPUTriangleList GPUTriangleList;                 ///< shortcut
typedef struct Vec2 Vec2;                                       ///< shortcut
typedef struct Vec3 Vec3;                                       ///< shortcut
typedef struct Vec4 Vec4;                                       ///< shortcut
typedef struct Mat4 Mat4;                                       ///< shortcut
typedef struct GPUVertexPullerConfiguration
	GPUVertexPullerConfiguration;                               ///< shortcut
typedef struct GPUVertexShaderInput GPUVertexShaderInput;       ///< shortcut
typedef struct GPUVertexShaderOutput GPUVertexShaderOutput;     ///< shortcut
typedef struct GPUFragmentShaderInput GPUFragmentShaderInput;   ///< shortcut
typedef struct GPUFragmentShaderOutput GPUFragmentShaderOutput; ///< shortcut
typedef struct GPUFragmentAttributes GPUFragmentAttributes;     ///< shortcut
typedef struct GPUVertexPullerHead GPUVertexPullerHead;         ///< shortcut
typedef struct GPUVertexIndexing GPUVertexIndexing;             ///< shortcut
typedef struct GPUVertexPullerOutput GPUVertexPullerOutput;     ///< shortcut


/**
 * @brief A instance of this type stores handle to GPU object.
 *
 * Every object on GPU is represented by unsigned integer value - id/name.
 * CPU side can manipulate GPU object by these ids.
 */
typedef size_t ObjectID;

/**
 * @brief Type for storing buffer handle.
 */
typedef ObjectID BufferID;

/**
 * @brief This type represents vertex puller handle - index to vertex puller
 * configuration.
 */
typedef ObjectID VertexPullerID;

/**
 * @brief This type represents shader program id.
 *
 * A program is collection of shaders (vertex shader, fragment shader, ...).
 * This id points to one program on GPU.
 */
typedef ObjectID ProgramID;

/**
 * @brief Instance of this type contains index to vertex.
 */
typedef size_t VertexIndex;

/**
 * @brief This type represents attribute index.
 */
typedef size_t AttribIndex;

/**
 * @brief A instance of this type stores GPU handle.
 *
 * Every function call that is not directly on GPU and sets state on GPU has
 * this handler as first parameter.
 */
typedef void *GPU;

/**
 * @brief A instance of this type stores handle to all uniforms.
 */
typedef const void *Uniforms;

/**
 * @brief A instance of this type represents id of vertex shader invocation.
 */
typedef size_t VertexShaderInvocation;

/**
 * @brief This type represents callback (function pointer) to vertex shader.
 */
typedef void (*VertexShader)(
	GPUVertexShaderOutput *, const GPUVertexShaderInput *, GPU
);

/**
 * @brief This type represents callback (function pointer) to fragment shader.
 */
typedef void (*FragmentShader)(
	GPUFragmentShaderOutput *, const GPUFragmentShaderInput *, GPU
);

/**
 * @brief A instance of this type represents handle to all vertex attributes of
 * input vertex of vertex shader.
 */
typedef const void *GPUVertexShaderInputVertexAttributes;

/**
 * @brief A instance of this type represents handle to all vertex attributes of
 * output vertex of vertex shader.
 */
typedef void *GPUVertexShaderOutputVertexAttributes;

/**
 * @brief This type represents data for single attribute.
 */
typedef uint8_t
	AttributeData[sizeof(float) * MAX_NUMBER_OF_ATTRIBUTE_COMPONENTS];
