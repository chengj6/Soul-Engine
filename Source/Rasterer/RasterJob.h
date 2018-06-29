#pragma once

#include <map>
#include <string>
#include <vector>
#include "Shader.h"
#include "Core/Utility/Types.h"
#include <string>
#include <variant>

#include <glm/glm.hpp>

typedef std::variant<
	int,
	float,
	double,
	bool,
	uint,
	glm::mat4,
	glm::vec3,
	glm::uvec3,
	glm::vec4,
	glm::uvec4,
	glm::vec2,
	glm::uvec2
> RasterVariant;

/* A raster job. */
class RasterJob {

public:

	RasterJob();
	~RasterJob();

	/*
	 *    Array indexer operator.
	 *    @param	i	Zero-based index of the.
	 *    @return	The indexed value.
	 */

	int const& operator [](std::string i) const;

	/*
	 *    Array indexer operator.
	 *    @param	i	Zero-based index of the.
	 *    @return	The indexed value.
	 */

	int& operator [](std::string i);

	/*
	 *    Attach shaders.
	 *    @param	parameter1	The first parameter.
	 */

	virtual void AttachShaders(const std::vector<Shader*>&) = 0;

	/*
	 *    Registers the uniform described by std::string.
	 *    @param	std::string	The standard string.
	 */

	virtual void RegisterUniform(std::string) = 0;

	/*
	 *    Sets an uniform.
	 *    @param	std::string	The standard string.
	 *    @param	parameter2 	The second parameter.
	 */

	virtual void SetUniform(std::string, RasterVariant) = 0;

	/*
	 *    Uploads a geometry.
	 *    @param [in,out]	parameter1	If non-null, the first parameter.
	 *    @param 		 	parameter2	The second parameter.
	 *    @param [in,out]	parameter3	If non-null, the third parameter.
	 *    @param 		 	parameter4	The fourth parameter.
	 */

	virtual void UploadGeometry(float*, uint, uint*, uint) = 0;

	/* Draws this object. */
	virtual void Draw() = 0;

protected:

	std::map<std::string, int> shaderUniforms;
	std::vector<Shader*> shaders;

private:

};