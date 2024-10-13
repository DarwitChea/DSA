#include<iostream>
using namespace std;

class classBox
{
    public: 
    double width;
    double lenght;
    double height;
    double dia;

    classBox(double w, double l,double h) 
    {
        width = w;
        lenght = l;
        height = h;
    }

    double diameter()
    {
        dia = width * lenght * height;

        return dia;
    }
};

int main() 
{   
    double width, lenght, height,dia;
    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the Lenght: ";
    cin >> lenght;
    cout << "Enter the height: ";
    cin >> height;
  
    classBox box1(width,lenght,height);
    cout << "box has a dimension of (" << width << "," << lenght << "," << height << ")" << endl;
    cout << "The box has a diameter of " << box1.diameter() << endl;
}