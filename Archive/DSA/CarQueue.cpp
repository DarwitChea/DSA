
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car
{
    int id;
    string make;
    string model;
    string type;
    int year;
    int price;
};

void displayCars(vector<Car> cars)
{
    for (Car car : cars)
    {

        cout << "ID: " << car.id << endl;
        cout << "Make: " << car.make << endl;
        cout << "Model: " << car.model << endl;
        cout << "Type: " << car.type << endl;
        cout << "Year: " << car.year << endl;
        cout << "Price: $" << car.price << endl;
        cout << endl;
    }
}

int main()
{
    vector<Car> cars = {
        {1, "Toyota", "Camry", "sedan", 2015, 9800},
        {2, "Ford", "Escape", "crossover", 2015, 15900},
        {3, "Honda", "Civic", "sedan", 2016, 10200},
        {4, "Volkswagen", "Golf", "compact", 2014, 8800},
        {5, "Toyota", "RAV4", "crossover", 2016, 12800}};

    // Write an algorithm to display the data above
    displayCars(cars);

    // We import the new 2 cars to our shop
    cars.push_back({6, "Toyota", "4Runner", "suv", 2015, 16900});
    cars.push_back({7, "Honda", "CR-V", "crossover", 2016, 17900});
    cout << "The Cars after add to the store: " << endl;
    displayCars(cars);

    // Remove sold cars from inventory
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].id == 3 || cars[i].id == 7)
        {
            cars.erase(cars.begin() + i);
        }
    }

    // Now two cars were sold out with IDs of 3 and 7.
    cout << "The Cars after Sold out from the Store: " << endl;
    displayCars(cars);

    // asks to see if any car in model Camry is available cars in shop.

    string searchModel = "Camry";
    cout << endl
         << "Cars with model " << searchModel << ":" << endl;
    for (Car car : cars)
    {
        if (car.model == searchModel)
        {
            cout << "ID: " << car.id << endl;
            cout << "Make: " << car.make << endl;
            cout << "Model: " << car.model << endl;
            cout << "Type: " << car.type << endl;
            cout << "Year: " << car.year << endl;
            cout << "Price: $" << car.price << endl;
            cout << endl;
        }
    }

    // is the most expensive and lowest price of car.
    int maxPrice = 0;
    int minPrice = 17900;
    Car mostExpensiveCar;
    Car lowestPricedCar;
    for (Car car : cars)
    {
        if (car.price > maxPrice)
        {
            maxPrice = car.price;
            mostExpensiveCar = car;
        }
        if (car.price < minPrice)
        {
            minPrice = car.price;
            lowestPricedCar = car;
        }
    }
    cout << endl
         << "Most expensive car:" << endl;

    cout << "ID: " << mostExpensiveCar.id << endl;
    cout << "Make: " << mostExpensiveCar.make << endl;
    cout << "Model: " << mostExpensiveCar.model << endl;
    cout << "Type: " << mostExpensiveCar.type << endl;
    cout << "Year: " << mostExpensiveCar.year << endl;
    cout << "Price: $" << mostExpensiveCar.price << endl;
    cout << endl
         << "Lowest priced car:" << endl;
    cout << "ID: " << lowestPricedCar.id << endl;
    cout << "Make: " << lowestPricedCar.make << endl;
    cout << "Model: " << lowestPricedCar.model << endl;
    cout << "Type: " << lowestPricedCar.type << endl;
    cout << "Year: " << lowestPricedCar.year << endl;
    cout << "Price: $" << lowestPricedCar.price << endl;
    return 0;
}
