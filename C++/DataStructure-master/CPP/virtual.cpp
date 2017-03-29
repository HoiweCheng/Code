#include <iostream>
using namespace std;

class Polygon
{
    protected:
        int width, height;
    public:
        void set_values(int a, int b)
        {
            width = a;
            height = b;
        }
        virtual int area()
        {
            return 0;
        }
        virtual void test()
        {
            cout << "base" << endl;
        }
};

class Rectangle: public Polygon
{
    public:
        int area()
        {
            return width * height;
        }
        void test()
        {
            cout << "rectangle" << endl;
        }
};

class Triangle: public Polygon
{
    public:
        int area()
        {
            return width * height / 2;
        }
        void test()
        {
            cout << "triangle" << endl;
        }
};

int main()
{
    //example of polymorphism in C++
    Rectangle rect;
    Triangle trgl;
    Polygon *ppoly1 = &rect;
    Polygon *ppoly2 = &trgl;
    ppoly1 -> set_values(4,5);
    ppoly2 -> set_values(4,5);
    cout << rect.area() << endl;//20
    cout << trgl.area() << endl;//10
    //power of virtual function
    //we we use the object of base class Polygon rather than Rectangle or
    //Triangle to call function area(), it can still know which area() to
    //call
    cout << ppoly1->area() << endl;
    cout << ppoly2->area() << endl;
   

    Polygon poly;
    Polygon *ppoly3 = &poly;
    cout << ppoly3->area() << endl;

    cout << "function call test() " << endl;
    ppoly3->test();
    ppoly1->test();
    ppoly2->test();
    return 0;
}
