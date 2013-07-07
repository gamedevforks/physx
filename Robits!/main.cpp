#include <iostream>

#include "Graphics.h"
#include "Settings.h"
#include "Model.h"
#include "Player.h"

int main(){
	Graphics graphics;

	Player player;

	graphics.setPlayer(&player);

	Model * dragon = graphics.loadModel("sponza.obj");
	dragon->setScale(glm::vec3(0.001, 0.001, 0.001));

	/*Model * monkey = graphics.loadModel("monkey.obj");
	monkey->setRotation(glm::vec3(3.14/2, 0, 0));
	monkey->setPosition(glm::vec3(2, 0, 0));
	monkey->setScale(glm::vec3(0.8, 0.8, 0.8));
	//this one is CW
	/*Model * teapot = graphics.loadModel("teapot.obj");
	teapot->setPosition(glm::vec3(0, 0, 2));
	teapot->setScale(glm::vec3(0.01, 0.01, 0.01));
	teapot->setRotation(glm::vec3(3.14/2, 0, 0));*/
	double lastTime = 0.0;

	while( graphics.isOpen() ){
		double currentTime = glfwGetTime();
		float deltaTime = float(currentTime - lastTime);
		lastTime = currentTime;
		if(deltaTime > 1/60.f)
			deltaTime = 1/60.f;
		graphics.update(deltaTime);
	}
}