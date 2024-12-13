#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void display() const override {
        std::cout << "Circle: Radius = " << radius
                  << ", Area = " << area() 
                  << ", Perimeter = " << perimeter() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        std::cout << "Rectangle: Width = " << width
                  << ", Height = " << height
                  << ", Area = " << area() 
                  << ", Perimeter = " << perimeter() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = perimeter() / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void display() const override {
        std::cout << "Triangle: Side1 = " << a
                  << ", Side2 = " << b
                  << ", Side3 = " << c
                  << ", Area = " << area() 
                  << ", Perimeter = " << perimeter() << std::endl;
    }
};

class ShapeManager {
private:
    std::vector<Shape*> shapes;

public:
    ~ShapeManager() {
        for (auto shape : shapes) {
            delete shape;
        }
    }

    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void displayAllShapes() const {
        for (auto it = shapes.begin(); it != shapes.end(); ++it) {
            (*it)->display();
        }
    }
};

int main() {
    ShapeManager manager;

    manager.addShape(new Circle(5.0));
    manager.addShape(new Rectangle(4.0, 6.0));
    manager.addShape(new Triangle(3.0, 4.0, 5.0));

    std::cout << "All Shapes:\n";
    manager.displayAllShapes();

    return 0;
}
