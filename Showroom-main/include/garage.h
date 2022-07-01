#include<vector>
#include<iostream>
#include<string>
#include<set>

using namespace std;
struct Date {
    int day, month, year;
};
struct Service {
    string name;
    int price;
    Date date;
};
struct Garage_receipt {
    int Process_ID = 0;
    string Customer_ID;
    Date date;
    int Amount_of_money = 0;
    string servicename;
};

class garage {
public:
    set<string> cnt;
    string name;
    string location;
    string phone;
    vector<Service> service;

    void Display_garage();

    static void DisplayGarage(string name, vector<Service>& service);

    static void DisplayGarage();

    static vector<garage> Garages;
};
