void drawCurve(paintPixelFunction paintPixel, curveEvalFunction evalCurve) {
	float t=0;
	glm::vec2 pAnterior=evalCurve(0).p;
	float tAnterior=0;
	while(t<=1){
		float coorX=evalCurve(t).p.x;
		float coorY=evalCurve(t).p.y;
		
		if(glm::vec2(round(pAnterior.x),round(pAnterior.y)) != glm::vec2(round(coorX),round(coorY))){
			paintPixel(glm::vec2(round(coorX),round(coorY)));
		}
		/*
		if(std::abs(round(coorX) - round(pAnterior.x)) > 1){
			if(evalCurve(t).d.x>0){
				paintPixel(glm::vec2(round(coorX)-1,round(coorY)));
			}else{
				paintPixel(glm::vec2(round(coorX)+1,round(coorY)));
			}
		}else if (std::abs(round(coorY) - round(pAnterior.y)) > 1 ){
			if(evalCurve(t).d.y>0){
				paintPixel(glm::vec2(round(coorX),round(coorY)-1));
			}else{
				paintPixel(glm::vec2(round(coorX),round(coorY)+1));
			}
		}*/
		//Forma con rectas
		
		if(std::abs(round(coorX) - round(pAnterior.x)) > 1){
			std::cout<<"aaaaa"<<std::endl;
			paintPixel(evalCurve(tAnterior+(0.5/(std::fabs(evalCurve(t).d.x)))).p);
		}else if(std::abs(redon(coorY) - round(pAnterior.y)) > 1){
			std::cout<<"bbbbb"<<std::endl;
			paintPixel(evalCurve(tAnterior+(0.5/(std::fabs(evalCurve(t).d.y)))).p);
		}
		tAnterior = t;
		if(std::fabs(evalCurve(t).d.x)>std::fabs(evalCurve(t).d.y)){
			t+=1/(std::fabs(evalCurve(t).d.x));
		}else{
			t+=1/(std::fabs(evalCurve(t).d.y));
		}
		
		pAnterior = glm::vec2(coorX,coorY);
		
	}
}
