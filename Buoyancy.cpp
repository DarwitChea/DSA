#include <iostream>
#include <cmath>
using namespace std;

double fb, v, r, w, y;

void Buoyancy(int fb, int w)
{
    if (fb >= w)
    {
        cout << "The object will float.";
    }
    else
    {
        cout << "The object will sink";
    }
}

int main()
{
    y = 62.4;
    w = 2090;
    r = 2;
    v = ((4 * 3.141 * (r * r * r)) / 3);

    fb = v * y;
    Buoyancy(fb, w);
}