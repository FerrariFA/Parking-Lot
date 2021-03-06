#include "Field.h"

Field::Field() {
    Line door({Vec(-0.95, -0.5), Vec(-0.75, -0.5)});
    door.fillColor(1,0,0);
    door.setAnchor(Vec(-0.75, -0.5));
    lines.push_back(door);

    Line wall({Vec(-0.75, -0.5), Vec(-0.75, -0.3), Vec(0.99, -0.3), Vec(0.99, 0.99), Vec(-0.99, 0.99), Vec(-0.99, -0.99)});
    wall.fillColor(0, 0, 0);
    lines.push_back(wall);

    for (int i = 0; i < 6; ++i){
        Line down( {Vec(-0.75+i*0.3, -0.3), Vec(-0.75+i*0.3, -0.05)} );
        down.fillColor(0,0,0);
        lines.push_back(down);

        Line up( {Vec(-0.75+i*0.3, 0.75), Vec(-0.75+i*0.3, 0.99)} );
        up.fillColor(0,0,0);
        lines.push_back(up);
    }

    Poly barrier({Vec(-0.7,0.3), Vec(0.6,0.3), Vec(0.6,0.4), Vec(-0.7,0.4)});
    barrier.randomColor();
    elem.push_back(barrier);

}

void Field::draw() {
    for (int i = 0; i < lines.size(); ++i){
        lines[i].draw();
    }
    for (int i = 0; i < elem.size(); ++i){
        elem[i].draw();
    }
}

void Field::open() {
    ++status;
    lines[0].rotate(-PI/2/90);
}

void Field::close() {
    --status;
    lines[0].rotate(PI/2/90);
}

int Field::getStatus() {
    return status;
}
