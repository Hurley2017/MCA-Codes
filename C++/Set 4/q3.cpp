#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
class Number_List
{
    private:
        int i, j, limit, sizearr, *arr;
    public:
        Number_List(int n)
        {
            limit = n;
        }
        void createArr()
        {
            cout << "Enter size of the array : ";
            cin >> sizearr;
            arr = (int *)malloc(sizearr*sizeof(int));
            for(i = 0; i<sizearr; i++)
            {
                *(arr+i) = rand()%limit;
            }
        }
        void sortArr()
        {
            for(i = 0; i<sizearr-1; i++)
            {
                for(j = i; j<sizearr; j++)
                {
                    if(*(arr+i) > *(arr + j))
                    {
                        int temp = *(arr + i);
                        *(arr + i) = *(arr + j);
                        *(arr + j) = temp;
                    }
                }
            }
        }
        int voidMin()
        {
            int min = INT_MAX;
            for(i = 0; i<sizearr; i++)
            {
                if(min > *(arr + i))
                {
                    min = *(arr + i);
                }
            }
            return min;
        }
        int voidMax()
        {
            int max = INT_MIN;
            for(i = 0; i<sizearr; i++)
            {
                if(max > *(arr + i))
                {
                    max = *(arr + i);
                }
            }
            return max;
        }
};