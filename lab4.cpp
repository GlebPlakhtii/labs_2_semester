#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>

#include <string>

using namespace std;


class Circle {
protected:
    double *center;
    double radius;


public:
    Circle(double x = 0, double y = 0, double radius = 0) {
        this->center = new double[2];
        this->center[0] = x;
        this->center[1] = y;

        this->radius = radius;
    }

    Circle(const Circle &other) {
        this->center = new double[2];
        this->center[0] = other.center[0];
        this->center[1] = other.center[1];
        this->radius = other.radius;

    }

    ~Circle() {
        delete[] this->center;

    }

    double square() {
        return M_PI * pow(this->radius, 2);
    }

    double length() {
        return M_PI * 2 * this->radius;
    }

    void change_circle(double x, double y, double radius) {
        this->center[0] = x;
        this->center[1] = y;

        this->radius = radius;
    }

    void print_info() {
        cout << "radius : " << this->radius << "\ncenter : ( " << this->center[0] << " , " << this->center[1] << " )\n";
    }

    bool is_larger_area(double area) {
        return this->square() > area;
    }


};

class ColorCircle : public Circle {
    string color;
public:

    ColorCircle(double x=0, double y=0, double radius=0, string color = "") : Circle(x, y, radius) {
        this->color = color;
    }

    void print_info() {
        cout << "radius : " << this->radius << "\ncenter : ( " << this->center[0] << " , " << this->center[1]
             << " )\ncolor : " << this->color << endl;
    }


    ColorCircle operator=(const ColorCircle &other) {
        this->~ColorCircle();
        this->center = new double[2];
        this->center[0] = other.center[0];
        this->center[1] = other.center[1];
        this->radius = other.radius;
        this->color = other.color;


    }


    double operator+(const ColorCircle &other) {
        return (pow(this->radius, 2) + pow(other.radius, 2)) * M_PI;

    }

    friend ostream &operator<<(ostream &os, ColorCircle &c);

    friend istream &operator>>(istream &is, ColorCircle &c);


};

ostream &operator<<(ostream &os, ColorCircle &c) {
    os << "radius : " << c.radius << "\ncenter : ( " << c.center[0] << " , " << c.center[1]
       << " )\ncolor : " << c.color << endl;
    return os;
}

istream &operator>>(istream &is, ColorCircle &c) {
    is >> c.center[0] >> c.center[1] >> c.radius >> c.color;
    return is;
}


int main() {
    ColorCircle c;
    cout<<"enter : double x ,double y ,double radius ,strings color :"<<endl;
    cin >> c;
    cout << c << endl;


    return 0;
}