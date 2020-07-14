#include <cmath>
#include <string>

// factory method
struct colorful_point ;
struct point {
    static point* newColorfulPolar(double radius, double theta,const std::string& color) {
        return new colorful_point{radius * cos(theta), radius * sin(theta),color};
    }
    static point newCartesian(double x, double y) {
        return {x, y};
    }

    static point newPolar(double radius, double theta) {
        return {radius * cos(theta), radius * sin(theta)};
    }

private:
    double x, y;
protected:
    point(double x, double y) : x(x), y(y) {}
};

struct colorful_point : public point {
    friend point* point::newColorfulPolar(double radius, double theta,const std::string &);
protected:
    colorful_point(double x, double y, const std::string &color) : point(x, y), color(color) {}
private:
   const std::string &color;
};

int main() {
    auto p1 = point::newCartesian(1, 2);
    auto p2 = point::newPolar(5, M_PI_4);
    auto p3 = point::newColorfulPolar(5, M_PI_4, std::string("red"));
    return 0;
}