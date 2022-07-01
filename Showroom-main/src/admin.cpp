#include "customer.h"
#include "iostream"

using namespace std;
int choice;
#define Rooms ShowRooms::Rooms
#define DisplayShowRooms ShowRooms::DisplayShowRooms
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages
#define GetCar Admin::GetCar
#define GetService Admin::GetService
#define AddShow Admin::AddShow
#define AddGarage Admin::AddGarage
#define Administration Admin::Administration

template <typename T>
void Erase(vector<T> &X, int idx) {
    if(X.empty()) return;

    swap(X[idx], X.back());
    X.pop_back();
}

void Admin::GetCar(ShowRooms &X) {
    Car c;
    cout << "Enter Car model : " << endl;
    cin >> c.model;
    cout << "Enter Car Country : " << endl;
    cin >> c.make;
    cout << "Enter Car year : " << endl;
    cin >> c.year;
    cout << "Enter Car price : " << endl;
    cin >> c.price;
    cout << "Is Installment Available ? (1 / 0)" << endl;
    cin >> c.installment;
    system("cls");
    X.car.push_back(c);
}

void Admin::GetService(garage &X) {
    Service x;
    cout << "Enter Service Name : " << endl;
    cin >> x.name;
    cout << "Enter Service Price : " << endl;
    cin >> x.price;
    system("cls");
    X.service.push_back(x);
}

void Admin::AddShow() {
    ShowRooms x;
    cout << "Enter ShowRooms Name: " << endl;
    cin >> x.name;
    cout << "Enter ShowRooms Location: " << endl;
    cin >> x.location;
    cout << "Enter Phone number: " << endl;
    cin >> x.phone;
    system("cls");

    cout << "Do you want to add cars to this showroom ? (Y / N)" << endl;
    char c;
    cin >> c;

    if (c == 'Y') {
        cout << "How many cars ?" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            GetCar(x);
    }
    system("cls");

    Rooms.push_back(x);
}

void Admin::Administration() {
    Start:
    cout << "1 : Add" << endl;
    cout << "2 : Update" << endl;
    cout << "3 : Delete" << endl;
    cout << "4 : Exit" << endl;
    cin >> choice;
    system("cls");

    if (choice == 1) {
        cout << "1 : Showroom" << endl;
        cout << "2 : Garage" << endl;
        cout << "3 : Car" << endl;
        cout << "4 : Service" << endl;

        cin >> choice;
        system("cls");


        if (choice == 1) AddShow();
        if (choice == 2) AddGarage();
        if (choice == 3) {
            // 0 to show only showrooms without cars
            DisplayShowRooms(0);
            cout << "Please enter the index of showroom you wish to add car to : " << endl;
            cin >> choice;
            system("cls");
            GetCar(Rooms[choice]);
        }
        if (choice == 4) {
            DisplayGarage();
            cout << "Please enter the index of the garage you wish to add service to : " << endl;
            cin >> choice;
            system("cls");


            GetService(Garages[choice]);
        }
        goto Start;
    }
    if (choice == 2) {
        cout << "1 : Showroom" << endl;
        cout << "2 : Garage" << endl;
        cout << "3 : Car" << endl;
        cout << "4 : Service" << endl;
        cin >> choice;
        system("cls");

        if (choice == 1) {
            int idx;
            DisplayShowRooms(0);
            cout << "Please enter the index of the showroom : " << endl;
            cin >> idx;
            system("cls");

            cout << "Choose the index of the attribute to change." << endl;
            cout << "1 : Name" << endl;
            cout << "2 : location" << endl;
            cout << "3 : Phone Number" << endl;
            cin >> choice;
            system("cls");

            if (choice == 1) {
                cout << "Enter showroom new name : " << endl;
                string name;
                cin >> name;
                Rooms[idx].name = name;
            }
            if (choice == 2) {
                cout << "Enter showroom new location : " << endl;
                string location;
                cin >> location;
                Rooms[idx].location = location;
            }
            if (choice == 3) {
                cout << "Enter showroom new phone no. : " << endl;
                string number;
                cin >> number;
                Rooms[idx].phone = number;
            }
        }
        if (choice == 2) {
            int idx;
            DisplayGarage();
            cout << "Please enter the index of the garage : " << endl;
            cin >> idx;
            system("cls");

            cout << "Choose the index of the attribute to change." << endl;
            cout << "1 : Name" << endl;
            cout << "2 : location" << endl;
            cout << "3 : Phone Number" << endl;
            cin >> choice;
            system("cls");


            if (choice == 1) {
                cout << "Enter garage new name : " << endl;
                string name;
                cin >> name;
                Garages[idx].name = name;
            }
            if (choice == 2) {
                cout << "Enter garage new location : " << endl;
                string location;
                cin >> location;
                Garages[idx].location = location;
            }
            if (choice == 3) {
                cout << "Enter garage new phone no. : " << endl;
                string number;
                cin >> number;
                Garages[idx].phone = number;
            }
        }
        if (choice == 3) {
            int idx1, idx2;
            DisplayShowRooms(1);
            cout << "Enter the index of the showroom : " << endl;
            cin >> idx1;
            cout << "Enter the index of the car : " << endl;
            cin >> idx2;
            system("cls");


            cout << "1 : Price" << endl;
            cout << "2 : Year" << endl;
            cout << "3 : Country" << endl;
            cout << "4 : Model" << endl;
            cout << "5 : Installment State" << endl;
            cout << "Choose the index of the attribute to change : " << endl;
            cin >> choice;


            if (choice == 1) {
                cout << "Enter new car price : " << endl;
                int price;
                cin >> price;
                Rooms[idx1].car[idx2].price = price;
            }
            if (choice == 2) {
                cout << "Enter new car year : " << endl;
                string year;
                cin >> year;
                Rooms[idx1].car[idx2].year = year;
            }
            if (choice == 3) {
                cout << "Enter new car country : " << endl;
                string country;
                cin >> country;
                Rooms[idx1].car[idx2].make = country;
            }
            if (choice == 4) {
                cout << "Enter new car model : " << endl;
                string model;
                cin >> model;
                Rooms[idx1].car[idx2].model = model;
            }
            if (choice == 5) {
                cout << "Enter new car installment state : " << endl;
                int inst;
                cin >> inst;
                Rooms[idx1].car[idx2].installment = inst;
            }
        }
        if (choice == 4) {
            int idx1, idx2;
            DisplayGarage();
            cout << "Enter the index of the garage : " << endl;
            cin >> idx1;
            cout << "Enter the index of the service : " << endl;
            cin >> idx2;
            system("cls");


            cout << "Choose the index of the attribute to change : " << endl;
            cout << "1 : Name" << endl;
            cout << "2 : Price" << endl;
            cin >> choice;
            system("cls");


            if (choice == 1) {
                cout << "Enter new service name : " << endl;
                string name;
                cin >> name;
                Garages[idx1].service[idx2].name = name;
            }
            if (choice == 2) {
                cout << "Enter new service price : " << endl;
                int price;
                cin >> price;
                Garages[idx1].service[idx2].price = price;
            }
        }
        goto Start;
    }
    if (choice == 3) {
        cout << "1 : Showroom" << endl;
        cout << "2 : Garage" << endl;
        cout << "3 : Car" << endl;
        cout << "4 : Service" << endl;

        cin >> choice;
        system("cls");


        if (choice == 1) {
            int idx;
            DisplayShowRooms(0);
            cout << "Enter the index of the showroom : " << endl;
            cin >> idx;

            Erase(Rooms, idx);
        }
        if (choice == 2) {
            int idx;
            DisplayGarage();
            cout << "Enter the index of the garage : " << endl;
            cin >> idx;

            Erase(Garages, idx);
        }
        if (choice == 3) {
            int idx1, idx2;
            DisplayShowRooms(1);
            cout << "Enter the index of the showroom : " << endl;
            cin >> idx1;
            cout << "Enter the index of the car : " << endl;
            cin >> idx2;

            Erase(Rooms[idx1].car, idx2);
        }
        if (choice == 4) {
            int idx1, idx2;
            DisplayGarage();
            cout << "Enter the index of the garage : " << endl;
            cin >> idx1;
            cout << "Enter the index the service : " << endl;
            cin >> idx2;

            Erase(Garages[idx1].service, idx2);
        }
        goto Start;
    }
    if (choice == 4) {
        return;
    }
}

void AddGarage() {
    garage x;
    cout << "Enter garage name : " << endl;
    cin >> x.name;
    cout << "Enter garage location : " << endl;
    cin >> x.location;
    cout << "Enter garage phone number : " << endl;
    cin >> x.phone;

    cout << "Do you want to add services to this garage ? (Y / N)" << endl;
    char c;
    cin >> c;
    if (c == 'Y') {
        cout << "How many services ? " << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            GetService(x);
    }
    system("cls");
    Garages.push_back(x);
}