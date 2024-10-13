#include <iostream>
using namespace std;
class classBox
{
    // 3 variables

public:
    int width, length, height;

    // 1 member function

    int return_volume()
    {
        return width * length * height;
    }

    // constructor
    classBox(int w, int l, int h)
    {
        width = w;
        length = l;
        height = h;
    }
};
int main()
{
    classBox box2(4, 5, 6);
    cout << box2.return_volume();
}
