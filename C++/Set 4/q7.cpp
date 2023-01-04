#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;
class String
{
    private:
        int i, size;
        char *in;
    public:
        String()
        {
            i = 0;
        }
        String(char *in)
        {
            i = 0;
            size = strlen(in);
            this->in = (char *)malloc(size*sizeof(char));
            while(i<size)
            {
                *(this->in + i) = *(in + i);
            }
        }
        void dispStr()
        {
            fputs(in, stdout);
        }
        void join(String a)
        {
            this->in = (char*)realloc(this->in, (a.size+size)*sizeof(char));
            while(i < a.size)
            {
                *(this->in + i + size) = *(a.in + i);
                i++;
            }
        }    
};
int main()
{
    String one("My name is "), two("Tusher Mondal");
    one.dispStr();
    two.dispStr();
    one.join(two);
    one.dispStr();
    return 0;
} 