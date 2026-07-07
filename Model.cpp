#include "Model.h" 
Model::Model(const char* file) {
	std::string text = get_file_contents(file);
	JSON = json::parse(text);
	Model::file = file;
	data = getData();
}

std::vector<unsigned char> Model::getData() {
	std::string bytesText;
	std::string uri = JSON["buffers"][0]["uri"];
	std::string fileStr = std::string(file);
	std::string fileDirectory = fileStr.substr(0, fileStr.find_last_of('/') + 1);
	bytesText = get_file_contents((fileDirectory + uri).c_str());
	std::vector<unsigned char> data(bytesText.begin(), bytesText.end());
	return data;
}

std::vector<float> Model::getFloats(json accessor) {
	return {};
}

std::vector<GLuint> Model::getIndices(json accessor) {
	return {};
}

std::vector<glm::vec2> Model::groupFloatsVec2(std::vector<float> floatVec) {
	return {};
}

std::vector<glm::vec3> groupFloatsVec3(std::vector<float> floatVec) {
	return {};
}

std::vector<glm::vec4> groupFloatsVec4(std::vector<float> floatVec) {
	return {};
}

std::vector<Vertex> Model::assembleVertices(std::vector<glm::vec3> positions, std::vector<glm::vec3> normals, std::vector<glm::vec2> texUVs){
	return {};
}