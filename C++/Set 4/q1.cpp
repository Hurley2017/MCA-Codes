#include <iostream>
#include <cmath>
#define pI 3.1415
using namespace std;
class Parent
{
    private:
        double iamprivate;
    protected:
        double iamprotected;
    public:
        double iampublic;
        Parent()
        {
            cout << "Parent class initialized." << endl;
        }
        void takeinp(double n)
        {
            iamprivate = n;
            iamprotected = n;
            iampublic = n;
        }
        double printPrivate()
        {
            return pI*pow(iamprivate, 2);
        }
        double printProtected()
        {
            return pI*pow(iamprotected, 2);
        }
        double printPublic()
        {
            return pI*pow(iampublic, 2);
        }
};
class Child : public Parent
{
    public:
        Child()
        {
            cout << "Child class initialized." << endl;
        }
};
double printAll(double n)
{
    return pI*pow(n,2);
}
int main()
{
    int switch1, switch2;
    double value;
    system("clear");
    cout << "Question 1: Write a C++ Program to calculate area of a circle to demonstrate the access modifier (A) public (B) private (C) protected." << endl;
    cout << "Running : " << endl;
    Parent p;
    Child c;
    cout << "Enter the radius value of the circle." << endl;
    cin >> value;
    p.takeinp(value);
    c.takeinp(value);
    outer:
    cout << "Choose access specifier.\n1) Private\n2) Protected\n3) Public\n4) Exit\nEnter Choice : ";
    cin >> switch1;
    switch (switch1)
    {
        case 1:
            inner1:
            cout << "In Private mode : " << endl;
            cout << "Choose options from below.\n1) Access from Parent class.\n2) Access from derived class.\n3) Access from main function.\n4) Exit\nEnter Choice : ";
            cin >> switch2;
            switch (switch2)
            {
                case 1:
                    cout << "Accessing from Parent class." << endl;
                    cout << p.printPrivate() << endl;
                    goto inner1;
                case 2:
                    cout << "Accessing from Derived class." << endl;
                    cout << c.printPrivate() << endl;
                    goto inner1;
                case 3:
                    cout << "Accessing from main function." << endl;
                    //cout << printAll(p.iamprivate);
                    goto inner1;
                case 4:
                    break;    
                default:
                    cout << "Incorrect Choice" << endl;
                    goto inner1;
            }
            goto outer;
        case 2:
            inner2:
            cout << "In Protected mode : " << endl;
            cout << "Choose options from below.\n1) Access from Parent class.\n2) Access from derived class.\n3) Access from main function.\n4) Exit\nEnter Choice : ";
            cin >> switch2;
            switch (switch2)
            {
                case 1:
                    cout << "Accessing from Parent class." << endl;
                    cout << p.printProtected() << endl;
                    goto inner2;
                case 2:
                    cout << "Accessing from Derived class." << endl;
                    cout << c.printProtected() << endl;
                    goto inner2;
                case 3:
                    cout << "Accessing from main function." << endl;
                    //cout << printAll(p.iamprotected);
                    goto inner2;
                case 4:
                    break;    
                default:
                    cout << "Incorrect Choice" << endl;
                    goto inner2;
            }
            goto outer;
        case 3:
            inner3:
            cout << "In Public mode : " << endl;
            cout << "Choose options from below.\n1) Access from Parent class.\n2) Access from derived class.\n3) Access from main function.\n4) Exit\nEnter Choice : ";
            cin >> switch2;
            switch (switch2)
            {
                case 1:
                    cout << "Accessing from Parent class." << endl;
                    cout << p.printPublic() << endl;
                    goto inner3;
                case 2:
                    cout << "Accessing from Derived class." << endl;
                    cout << c.printPublic() << endl;
                    goto inner3;
                case 3:
                    cout << "Accessing from main function." << endl;
                    cout << printAll(p.iampublic) << endl;
                    goto inner3;
                case 4:
                    break;    
                default:
                    cout << "Incorrect Choice" << endl;
                    goto inner3;
            }
            goto outer;
        case 4:
            break;
        default:
            cout << "Incorrect Choice!" << endl;
            goto outer;
    }
    return 0;
}