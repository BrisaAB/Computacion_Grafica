Pesos calcularPesos(glm::vec3 x0, glm::vec3 x1, glm::vec3 x2, glm::vec3 &x) {
	/*el peso de un punto para cierto vertice se calculaba como (a1*at)/(at*at)*/
	//Calculo areas
	glm::vec3 atotal = cross(x0-x2,x1-x2);
	glm::vec3 area0 = cross(x2-x,x1-x);
	glm::vec3 area1 = cross(x0-x,x2-x);
	glm::vec3 area2 = cross(x1-x,x0-x);
	
	//Calculo pesos
	float peso0 = (dot(area0,atotal)/dot(atotal,atotal));
	float peso1 = (dot(area1,atotal)/dot(atotal,atotal));
	float peso2 = (dot(area2,atotal)/dot(atotal,atotal));
  
	return {peso0,peso1,peso2};
}
