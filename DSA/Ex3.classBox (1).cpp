#include<iostream>
using namespace std;

class classBox
{
    public: 
    double width;
    double lenght;
    double height;
    double dia;

    void info()
    {
        cout << "Enter the width: ";
        cin >> width;
        cout << "Enter the Lenght: ";
        cin >> lenght;
        cout << "Enter the height: ";
        cin >> height;
    }

    double diameter(float width, float lenght, float height)
    {
        dia = width * lenght * height;
        cout << "box has a dimension of (" << width << "," << lenght << "," << height << ")" << endl;
        cout << "The box has a diameter of " << dia << endl;

    }

};

int main() 
{   
    classBox box1;
    box1.info();
    box1.diameter();
    

}