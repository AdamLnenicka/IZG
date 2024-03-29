/**
 * @file
 * @brief This file contains structures and function declaration that are needed
 * for manipulation with uniforms.
 *
 * @author Tomáš Milet, imilet@fit.vutbr.cz
 * @author Adam Lněnička
 *
 * All uniform values are constants that can only be read on GPU (in shaders).
 * A uniform value does not change during drawing.
 * A uniform value can be changed from CPU side between draw calls.
 * They are useful for storing matrices, samplers and other global constants.
 */


#pragma once


#include <stdint.h>

#include <student/fwd.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief This type is used for storing location of uniform variable.
 *
 * Uniform location can be negative. In that case, uniform does not exists.
 * When uniform location is not negative, it is direct index into list of
 * uniforms.
 * \see Uniforms
 */
typedef int32_t UniformLocation;


/**
 * @brief This enums represents type of uniform value
 */
typedef enum UniformType
{
	UNIFORM_FLOAT,  ///< single 32-bit float
	UNIFORM_VEC2,   ///< two    32-bit floats
	UNIFORM_VEC3,   ///< three  32-bit floats
	UNIFORM_VEC4,   ///< four   32-bit floats
	UNIFORM_UINT,   ///< single int32_t
	UNIFORM_MAT4,   ///< matrix 4x4, base type is 32-bit float
} UniformType;


/**
 * @brief This functions reserves memory in GPU for uniform variable.
 *
 * This function usually does not exists in common graphics API (OpenGL).
 * \see uniform1f
 *
 * @param gpu  GPU handler
 * @param name name of uniform value, it has to be unique among uniform values
 * @param type type of uniform value
 */
void cpu_reserveUniform(GPU gpu, const char *name, UniformType type);

/**
 * @brief This function returns location of reserved uniform variable.
 *
 * Returned value can be negative - in that case, uniform does not exits.
 * If returned value is not negative, it is direct index into uniform list.
 * Its alternative function in OpenGL is glGetUniformLocation.
 * \see Uniforms
 *
 * @param gpu  GPU handler
 * @param name name of uniform value
 *
 * @return uniform location of uniform value with name: name
 */
UniformLocation getUniformLocation(GPU gpu, const char *name);

/**
 * @brief This function uploads single float to uniform variable in GPU memory.
 *
 * Its alternative function in OpenGL is glUniform1f
 *
 * @param gpu      GPU handler
 * @param location location of uniform value
 * @param v0 value
 */
void cpu_uniform1f(GPU gpu, UniformLocation location, float v0);

/**
 * @brief This function uploads two floats to uniform variable in GPU memory.
 *
 * Its alternative function in OpenGL is glUniform2f
 *
 * @param gpu      GPU handler
 * @param location location of uniform value
 * @param v0 first component
 * @param v1 second component
 */
void cpu_uniform2f(GPU gpu, UniformLocation location, float v0, float v1);

/**
 * @brief This function uploads three floats to uniform variable in GPU memory.
 *
 * Its alternative function in OpenGL is glUniform3f
 *
 * @param gpu      GPU handler
 * @param location location of uniform value
 * @param v0 first component
 * @param v1 second component
 * @param v2 third component
 */
void cpu_uniform3f(
	GPU gpu, UniformLocation location, float v0, float v1, float v2
);

/**
 * @brief This function uploads four floats to uniform variable in GPU memory.
 *
 * Its alternative function in OpenGL is glUniform4f
 *
 * @param gpu      GPU handler
 * @param location location of uniform value
 * @param v0 first component
 * @param v1 second component
 * @param v2 third component
 * @param v3 fourth component
 */
void cpu_uniform4f(
	GPU gpu, UniformLocation location, float v0, float v1, float v2, float v3
);

/**
 * @brief This function uploads 4x4 matrix to uniform variable in GPU memory.
 *
 * Its alternative function in OpenGL is glUniformMatrix4fv
 *
 * @param gpu      GPU handler
 * @param location location of uniform value
 * @param data     matrix stored in linear order
 */
void cpu_uniformMatrix4fv(GPU gpu, UniformLocation location, const float *data);

/**
 * @brief This function interprets uniform value as float.
 *
 * @param uniforms all uniforms
 * @param location location of uniform
 *
 * @return float
 */
const float *shader_interpretUniformAsFloat(
	Uniforms uniforms, UniformLocation location
);

/**
 * @brief This function interprets uniform value as vec2.
 *
 * @param uniforms all uniforms
 * @param location location of uniform
 *
 * @return vec2
 */
const Vec2 *shader_interpretUniformAsVec2(
	Uniforms uniforms, UniformLocation location
);

/**
 * @brief This function interprets uniform value as vec3.
 *
 * @param uniforms all uniforms
 * @param location location of uniform
 *
 * @return vec3
 */
const Vec3 *shader_interpretUniformAsVec3(
	Uniforms uniforms, UniformLocation location
);

/**
 * @brief This function interprets uniform value as vec4.
 *
 * @param uniforms all uniform
 * @param location location of uniform
 *
 * @return vec4
 */
const Vec4 *shader_interpretUniformAsVec4(
	Uniforms uniforms, UniformLocation location
);

/**
 * @brief This function interprets uniform value as Mat4.
 *
 * @param uniforms all uniforms
 * @param location location of uniform
 *
 * @return Mat4
 */
const Mat4 *shader_interpretUniformAsMat4(
	Uniforms uniforms, UniformLocation location
);


#ifdef __cplusplus
}
#endif
