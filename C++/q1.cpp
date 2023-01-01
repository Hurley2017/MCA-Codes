#include <iostream>
#include <cmath>
#define pI 3.1415
using namespace std;
class Circle
{
    private:
        float pri_rad;
    protected:
        float pro_rad;
    public:
        float pub_rad;
    void getpriVal()
    {
        cout << "Getting input for private variable.\n";
        cin >> pri_rad;
    }
    void getproVal()
    {
        cout << "Getting input for protected variable.\n";
        cin >> pro_rad;
    }
    void getpubVal()
    {
        cout << "Getting input for public variable.\n";
        cin >> pub_rad;
    }
    double calcpriArea()
    {
        return pI*pow(pri_rad, 2);
    }
    double calcproArea()
    {
        return pI*pow(pro_rad, 2);
    }
    double calcpubArea()
    {
        return pI*pow(pub_rad, 2);
    }
    double general(float fromMain)
    {
        return pI*pow(fromMain, 2);
    }
};
int main()
{
    Circle ob;
    //finish in class[lab]
    return 0;
}