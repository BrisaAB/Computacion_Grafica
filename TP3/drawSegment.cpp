void drawSegment(paintPixelFunction paintPixel, glm::vec2 p0, glm::vec2 p1) {
	//DDA PARA RECTAS
	int difX = p1.x-p0.x;
	int difY=p1.y-p0.y;
	if(std::abs(difX)>std::abs(difY)){
		if(difX<0){
			std::swap(p0,p1);
		}
		float pendiente = (p1.y-p0.y)/(p1.x-p0.x);
		for(glm::vec2 p=p0;p.x<p1.x;++p.x){
			paintPixel(p);
			p.y+=pendiente;
		}
	}else{
		if(difY<0){
			std::swap(p0,p1);
		}
		float pendiente = (p1.x-p0.x)/(p1.y-p0.y);
		for(glm::vec2 p=p0;p.y<p1.y;++p.y){
			paintPixel(p);
			p.x+=pendiente;
		}
	}
}
