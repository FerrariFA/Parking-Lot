#include "UFO.h"

UFO::UFO(float scale, float x_, float y_)
{
	anchor=Vec(0,0);

	vector <Vec> p;


	Poly Ceil(Vec(0,0),0.2,true);
	Ceil.randomColor();
	Ceil.setAnchor(anchor);

	p.clear();
	p.push_back(Vec(-0.15,0));
	p.push_back(Vec(-0.05,0));
	p.push_back(Vec(-0.02,-0.07));
	p.push_back(Vec(-0.18,-0.07));
	Poly Tail_left(p);
	Tail_left.randomColor();
	Tail_left.setAnchor(anchor);

	p.clear();
	p.push_back(Vec(0.15,0));
	p.push_back(Vec(0.05,0));
	p.push_back(Vec(0.02,-0.07));
	p.push_back(Vec(0.18,-0.07));
	Poly Tail_right(p);
	Tail_right.fillColor(Tail_left);
	Tail_right.setAnchor(anchor);

	p.clear();
	p.push_back(Vec(-0.1414,0.1414));
	p.push_back(Vec(-0.2,0.2));
	p.push_back(Vec(-0.14,0.12));
	Poly Aerial_left(p);
	Aerial_left.randomColor();
	Aerial_left.setAnchor(anchor);

	p.clear();
	p.push_back(Vec(0.1414,0.1414));
	p.push_back(Vec(0.2,0.2));
	p.push_back(Vec(0.14,0.12));
	Poly Aerial_right(p);
	Aerial_right.fillColor(Aerial_left);
	Aerial_right.setAnchor(anchor);

	elem.push_back(Ceil);
	elem.push_back(Tail_left);
	elem.push_back(Tail_right);
	elem.push_back(Aerial_left);
	elem.push_back(Aerial_right);

	zoom(scale);
	move(Vec(x_,y_));
}

void UFO::self_spin(float T)
{
	rotate(50*PI/T,anchor);//The time chump is 25ms
}

Tel::Tel(float x, float y){
    Vec p0(x,y);
    static float scale=150;
    vector <Vec> p;p.clear();
    p.push_back(Vec(15/scale,20/scale));
    p.push_back(Vec(-15/scale,20/scale));
    p.push_back(Vec(-15/scale,-20/scale));
    p.push_back(Vec(15/scale,-20/scale));

    elem.push_back(p);elem[0].randomColor();
    move(p0);
}

void Tel::random_color()  {
    elem[0].randomColor();
}
