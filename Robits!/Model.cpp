#include "Model.h"
#include <glm/gtx/quaternion.hpp>

//THE ORDER IS TRANSLATE, ROTATE, SCALE
//TRANSLATE TO ORIGIN BEFORE APPLYING ANYTHING

const glm::mat4 & Model::getModelMatrix() const{
	return matrix;
}
//CCW AND IN RADIANS
void Model::setRotation(glm::vec3 & rot){
	rotation = glm::quat(rot);
	change();
}

void Model::setScale(glm::vec3 & scal){
	scayle = scal;
	change();
}

void Model::setPosition(glm::vec3 & pos){
	position = pos;
	change();
}

void Model::change(){
	matrix = glm::mat4(1.0);
	matrix = glm::translate(matrix, position) *glm::toMat4(rotation);
	matrix = glm::scale(matrix, scayle);
}