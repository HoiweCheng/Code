#include <iostream>
using namespace std;

//class with pure virtual function is an abstract base class, abstract base
//class cannot be used to instantiate objects, i.e. Polygon poly;(invalid)
//It can be used to create pointer to it, i.e. Polygon *ppoly1;

//pure virtual vs. virtual
//pure virtual就像c#中的 abstract,它制定规则,if you inheritate it, you have to
//implement the pure virtual functions in it.
//virtual is like interface in C#, if you inheritate it, you can override the
//virtual functions defined in it and achieve dynamic polymorphism while
//running
//different mechanism and idea, both support polymorphism in C++

class Polygon
{
    protected:
        int width, height;
    public:
        Polygon(){}
        Polygon(int a, int b): width(a), height(b){}
        void set_values(int a, int b)
        {
            width = a;
            height = b;
        }
        virtual int area() = 0; //pure virtual function
        void printarea()
        {
            cout << this->area() << endl;
        }
};

class Rectangle: public Polygon
{
    public:
        Rectangle(){}
        Rectangle(int a, int b) : Polygon(a,b){} //inheritate constructor from
//base class Polygon
        int area()
        {
            return width * height;
        }
};

class Triangle: public Polygon
{
    public:
        Triangle(){}
        Triangle(int a, int b): Polygon(a,b){} //inheritate
        int area()
        {
            return width * height / 2;
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
    cout << "-----seperator------------" << endl;
    //power of virtual function
    //we we use the object of base class Polygon rather than Rectangle or
    //Triangle to call function area(), it can still know which area() to
    //call
    //cout << ppoly1->area() << endl;
   // cout << ppoly2->area() << endl;
     ppoly1->printarea();
     ppoly2->printarea();
    
   // Polygon poly; //invalid instantiation for abstract base class Polygon
   
    //test constructor and inheritance from base class
     Polygon *p1 = new Rectangle(4,5);
     Polygon *p2 = new Triangle(4,5);
     p1->printarea();
     p2->printarea();
     delete p1;
     delete p2;
     p1 = NULL;
     p2 = NULL;
    return 0;
}
