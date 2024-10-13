#include<iostream>
#include<vector>

using namespace std;

class Car{
    int iD;
    string make;
    string model;
    string type;
    int year;
    int price;
};

// Write Algorithm to display the data above

void display(vector<Car> cars){
    for(int i = 0; i < cars.size(); i++) {

    }
}

int main() {
    vector<Car> cars = {
        {1, "Toyota", "Camry", "sedan", 2015, 9800},
        {2, "Ford", "Escape", "crossover", 2015, 15900},
        {3, "Honda", "Civic", "sedan", 2016, 10200},
        {4, "Volkswagen", "Golf", "compact", 2014, 8800},
        {5, "Toyota", "RAV4", "crossover", 2016, 12800}};
}
