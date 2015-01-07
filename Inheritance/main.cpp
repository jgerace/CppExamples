#include <iostream>

using namespace std;

class Shape
{
    private:
        int z;

    public:
        int x;
        int y;

        Shape() {};
        Shape(int xVal, int yVal)
          :x(xVal), y(yVal) // example of initializer list
          {}

        int getX() {return x;}
        void setX(int xVal) {x = xVal;}

        int getY() {return y;}
        void setY(int yVal) {y = yVal;}
};

class Rectangle : public Shape // "public" indicates that it will only inherit public members
{
    public:
        Rectangle(): Shape() {};
        Rectangle(int xVal, int yVal)
        :Shape(xVal, yVal) // how to call a parent constructor in initialization list
        {}

        int area();
};

int Rectangle::area() // example of defining a method outside of the class
{
    return x * y;
}

class Triangle : public Shape
{
    private:
        Triangle(); // prevents callers from instantiating without arguments;

    public:
        Triangle(int xVal, int yVal)
        :Shape(xVal, yVal)
        {}

        int area() {return x * y / 2;} // example of defining a method inside a class
};

int main(int argc, char *argv[])
{
    Rectangle r;
    r.setX(5);
    r.setY(4);
    cout << "Dimensions of rectangle: " << r.getX() << " by " << r.getY() << endl;
    cout << "Area of rectangle: " << r.area() << endl;

    Triangle t(4, 6);
    cout << "Area of triangle: " << t.area() << endl;

    return 0;
}
