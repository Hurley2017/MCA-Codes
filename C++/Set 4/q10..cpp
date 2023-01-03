#include <iostream>
#include <cmath>
#define pI 3.141
using namespace std;
class Shapes
{
    public:
        double calVal(double length)
        {
            // CUBE
            return pow(length, 3);
        };
        double calVal(double height, double width, double length)
        {
            // CUBOID
            return height*width*length;
        };
        double calVal(double radius, double height)
        {
            // CYLINDER
            return height*pI*pow(radius, 2);
        };
        double calVal(double radius, bool load)
        {
            // Sphere
            return (4/3)*pI*pow(radius, 2);
        }
        double calVal(double height, double radius, bool load)
        {
            // CONE
            return (pI/3)*height*pow(radius, 2);
        }
};
int main()
{
    Shapes s;
    int sw;
    restart:
    cout << "Choose from the following : \n1) Cube\n2) Cuboid\n3) Cylinder\n 4) Sphere\n5) Cone\n6) Exit\nEnter choice : ";
    cin >> sw;
    switch(sw)
    {
        case 1:
            double length;
            cout << "For Cube" << endl;
            cout << "Enter length : ";
            cin >> length;
        case 2:
            double height, lenght, width;
            cout << "For Cuboid" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter length : ";
            cin >> lenght;
            cout << "Enter width : ";
            cin >> width;
            cout << "Answer is " << s.calVal(height, width, lenght) << endl;
        case 3:
            double height, radius;
            cout << "For Cylinder" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(radius, height) << endl;
        case 4:
            bool f;
            double radius;
            cout << "For Sphere" << endl;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(radius, f) << endl;
            goto restart;
        case 5:
            bool f;
            double height, radius;
            cout << "For Cone" << endl;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter radius : ";
            cin >> radius;
            cout << "Answer is " << s.calVal(height, radius, f) << endl;
            goto restart;
        case 6:
            break;
        default:
            cout << "Bad choice." << endl;
            goto restart;
    }
    
}