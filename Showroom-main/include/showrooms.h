#include<vector>
#include<iostream>

using namespace std;

struct Car {
    string year;
    int price;
    string make, model;
    int installment;
    int deadline = 0;
};

class ShowRooms {
public:
    string name;
    string location;
    string phone;
    vector<Car> car;

    void Display();

    static void DisplayShowRooms(int turn);

    static vector<ShowRooms> Rooms;
};
