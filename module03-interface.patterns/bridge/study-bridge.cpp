#include <iostream>

class rendering_service;

class shape {
protected:
    rendering_service &renderingService;
public:
    shape(rendering_service &renderingService) : renderingService(renderingService) {}

    virtual void draw() = 0;
};

class rendering_service {
public:
    virtual void render(const shape& s) = 0;
};

class raster_service : public rendering_service {
public:
    void render(const shape &s) override {
        std::cout << "Raster rendering shape " << typeid(s).name() << std::endl;
    }
};

class vector_service : public rendering_service {
public:
    void render(const shape &s) override {
        std::cout << "Vector rendering shape " << typeid(s).name() << std::endl;
    }
};

class circle : public shape {
    double x,y,radius;
public:
    circle(rendering_service &renderingService, double x, double y, double radius) : shape(renderingService), x(x),
                                                                                     y(y), radius(radius) {}
    void draw() override {
        renderingService.render(*this);
    }
};

class square : public shape {
    double x,y,edge;
public:
    square(rendering_service &renderingService, double x, double y, double edge) : shape(renderingService), x(x),
                                                                                     y(y), edge(edge) {}
    void draw() override {
        renderingService.render(*this);
    }
};

int main(){
    vector_service vs;
    raster_service rs;
    circle v_unit_circle{vs,0.,0.,1.};
    circle r_unit_circle{rs,0.,0.,1.};
    square v_square{vs,0.,0.,1.};
    square r_square{rs,0.,0.,1.};
    v_unit_circle.draw();
    r_unit_circle.draw();
    v_square.draw();
    r_square.draw();
    return 0;
}