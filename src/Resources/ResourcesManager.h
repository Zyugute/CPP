#pragma once

#include <string>
#include <memory>
#include <map>

namespace Renderer
{
	class ShaderProgram;
}

class ResouceMnager {
public:
	ResouceMnager(const std::string& executablePath);
	~ResouceMnager() = default;

	ResouceMnager(const ResouceMnager&) = delete;
	ResouceMnager& operator=(const ResouceMnager&) = delete;
	ResouceMnager& operator=(ResouceMnager&&) = delete;
	ResouceMnager(ResouceMnager&&) = delete;

	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

private:

	std::string getFileString(const std::string& relativeFilePath) const;

	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramMap;
	ShaderProgramMap m_shaderPrograms;

	std::string m_path;
};