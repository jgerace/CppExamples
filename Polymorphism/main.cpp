#include <cstdlib>
#include <iostream>

using namespace std;

class Shape
{
      protected:
      int x;
      int y;
      
      public:
      Shape(int xVal, int yVal)
        :x(xVal), y(yVal) // example of initializer list
      {}
      
      int getX() {return x;}
      void setX(int xVal) {x = xVal;}
      
      virtual int getArea() { return 0; };
};

class Rectangle: public Shape
{
      public:
      Rectangle(int xVal, int yVal)
        :Shape(xVal, yVal)
      {}
        
      int getArea() { return x * y;}
};

class Triangle: public Shape
{
      public:
      Triangle(int xVal, int yVal)
        :Shape(xVal, yVal)
      {}
      
      int getArea() { return x * y / 2;}
};

int main(int argc, char *argv[])
{
    Rectangle r(2, 4);
    Triangle t(4, 6);
    
    Shape *s = &r; // s doesn't care what type it has, it'll use the ACTUAL type of the object
    
    cerr << "Area of rectangle: " << s->getArea() << endl;
    
    s = &t;
    
    cerr << "Area of triangle: " << s->getArea() << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
