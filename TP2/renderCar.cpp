void renderCar(const Car &car, const std::vector<Part> &parts) {
	const Part &axis = parts[0], &body = parts[1], &wheel = parts[2],
	           &fwing = parts[3], &rwing = parts[4], &helmet = parts[5];
	
	/// @todo: armar la matriz de transformación de cada parte para construir el auto
	
	
	if (body.show or play) {
		renderPart(car,body.models, 
				   glm::mat4( 	1.0, 0.0, 0.0, 0.0,
								0.0, 1.0, 0.0, 0.0,
								0.0, 0.0, 1.0, 0.0,
								0.0, 0.18, 0.0, 1.0 ));
	}
	
	if (wheel.show or play) {
		renderPart(car,wheel.models, 
				   rotate(
						  rotate(glm::mat4( 	0.15, 	0.0, 	0.0, 	0.0,
								0.0, 	0.15, 	0.0, 	0.0,
								0.0, 	0.0, 	-0.15, 	0.0,
								0.5, 	0.15, 	0.31, 	1.0 ),car.rang1,glm::vec3(0,1,0))
															,car.rang2,glm::vec3(0,0,1))); 
		renderPart(car,wheel.models, 
				   rotate(
						rotate(glm::mat4( 	0.15, 	0.0, 	0.0, 	0.0,
								0.0, 	0.15, 	0.0, 	0.0,
								0.0, 	0.0, 	0.15, 	0.0,
								0.5, 	0.15, 	-0.31, 	1.0 ),-car.rang1,glm::vec3(0,1,0))
															,-car.rang2,glm::vec3(0,0,1))); 
		renderPart(car,wheel.models, 
				   rotate(glm::mat4( 	0.15, 	0.0, 	0.0, 	0.0,
								0.0, 	0.15, 	0.0, 	0.0,
								0.0, 	0.0, 	-0.15,	0.0,
								-0.91, 	0.15, 	0.31, 	1.0 ),car.rang2,glm::vec3(0,0,1)));
		renderPart(car,wheel.models, 
				   rotate(glm::mat4( 	0.15, 	0.0, 	0.0, 	0.0,
								0.0, 	0.15, 	0.0, 	0.0,
								0.0, 	0.0,  	0.15, 	0.0,
								-0.91, 	0.15, 	-0.31, 	1.0 ),-car.rang2,glm::vec3(0,0,1)));
	}
	
	if (fwing.show or play) {
		renderPart(car,fwing.models, 
				   glm::mat4( 	0, 		0, 		0.33, 	0.0,
								0, 		0.33, 	0.0, 	0.0,
								-0.33, 	0.0,  	0	, 	0.0,
								0.80, 	0.13, 	0.0, 	1.0 ));
	}

	if (rwing.show or play) {
		float scl = 0.30f;
		renderPart(car,rwing.models, 
				   glm::mat4( 	0.0, 	0.0, 	0.33, 	0.0,
								0.0, 	0.33, 	0.0, 	0.0,
								-0.33, 	0.0,  	0.0, 	0.0,
								-0.9, 	0.38, 	0.0, 	1.0 ));
	}
	
	if (helmet.show or play) {
		renderPart(car,helmet.models, 
				   glm::mat4( 	0.0, 0.0, 0.1, 0.0,
								0.0, 0.1, 0.0, 0.0,
								-0.1, 0.0, 0.0, 0.0,
								0.0, 0.3, 0.0, 1.0 ));
	}

	if (axis.show and (not play)) renderPart(car,axis.models,glm::mat4(1.f));
}
