#include<vector>
#include <iostream>
#include <ctime>
#include "garage.h"

using namespace std;
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages
vector<garage> garage::Garages;

time_t now3 = time(0);
tm *ltm3 = localtime(&now3);
int year3 = 1900 + ltm3->tm_year;
int month3 = 1 + ltm3->tm_mon;
int today3 = ltm3->tm_mday;
// Fathy's task
int counter = 0;

void garage::Display_garage() {
    int idx = 0;
    for (auto u : service) {
        cout << "--Service Name : " << u.name << endl;
        cout << "--Service Price : " << u.price << endl;
        cout << "--Service Index : " << idx++ << endl;
        cout << "-------------------------------- " << endl;
    }
    cout << endl;
}

void GarageReceipt(Garage_receipt receipt) {
    cout << "Process ID: " << receipt.Process_ID << endl;
    cout << "Customer ID: " << receipt.Customer_ID << endl;
    cout << "Process Date: " << receipt.date.day << "/" << receipt.date.month << "/" << receipt.date.year << endl;
    cout << "Price: " << receipt.Amount_of_money << " LE" << endl;
    cout << "Service Name: " << receipt.servicename << endl;
}

// For customers only
void DisplayGarage(string name, vector<Service> &service) {
    int idx = 0;
    for (auto u : Garages) {
        cout << "Garage Name : " << u.name << endl;
        cout << "Garage Location : " << u.location << endl;
        cout << "Garage Phone Number : " << u.phone << endl;
        cout << "Garage Queue Line : " << u.cnt.size() << endl;
        cout << "Garage Index : " << idx++ << endl;
        if (!u.service.empty()) {
            cout << "-Services :" << endl;
            u.Display_garage();
        }
    }
    cout << "Do you want to make an appointment in a certain garage ? (y/n)" << endl;
    char x;
    cin >> x;
    if (x == 'y') {
        cout << "Enter The Index Of The Garage: " << endl;
        int ans1, ans2;
        cin >> ans1;
        cout << "Enter The Index Of The Service: " << endl;
        cin >> ans2;
        system("cls");
        Garage_receipt receipt = {++counter, name, {today3, month3, year3},
                                  Garages[ans1].service[ans2].price,
                                  Garages[ans1].service[ans2].name};
        Garages[ans1].service[ans2].date = {today3, month3, year3};
        service.push_back(Garages[ans1].service[ans2]);
        cout << "Do You Want Show Your Receipt? (y/n)" << endl;
        char c;
        cin >> c;
        if (c == 'y') {
            GarageReceipt(receipt);
            cout << endl;
        }
        // cnt.insert(1)
        // cnt.insert(1)
        // cnt.insert(2)
        // cnt.insert(1)
        // cnt.size() -> 2
        // we use set to remove duplicates
        Garages[ans1].cnt.insert(name);
        cout << Garages[ans1].cnt.size() << " In The Queue" << endl;
        return;
    } else {
        cout << "Ok!" << endl;
    }
}

// For admin only
void DisplayGarage() {
    int idx = 0;
    for (auto u : Garages) {
        cout << "Garage Name : " << u.name << endl;
        cout << "Garage Location : " << u.location << endl;
        cout << "Garage Phone Number : " << u.phone << endl;
        cout << "Garage Queue Line : " << u.cnt.size() << endl;
        cout << "Garage Index : " << idx++ << endl;
        if (!u.service.empty())
            cout << "-Services :" << endl;
        u.Display_garage();
    }
}
