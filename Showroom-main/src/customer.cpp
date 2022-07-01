#include "customer.h"
#include<set>
#include <iostream>
#include <ctime>

using namespace std;
#define Rooms ShowRooms::Rooms
#define DisplayShowRooms ShowRooms::DisplayShowRooms
#define DisplayGarage garage::DisplayGarage
#define Garages garage::Garages
set<pair<string, string> > customer::user;
vector<customer> customer::Customers;

time_t now = time(0);
tm *ltm = localtime(&now);
int year1 = 1900 + ltm->tm_year;
int month1 = 1 + ltm->tm_mon;
int today1 = ltm->tm_mday ;
int day1 = today1 + (30 * month1) + (365 * year1);

template<typename T>
void Erase(vector<T> &X, int idx) {
    if(X.empty()) return;

    swap(X[idx], X.back());
    X.pop_back();
}

void customer::registration() {
    string name, pw;
    cout << "Enter Username : ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> pw;
    system("cls");
    auto it = user.lower_bound({name, ""});
    if (it->first == name) {
        cout << "Username already exists!" << endl;
        registration();
    } else {
        customer New;
        New.name = name, New.pass = pw;
        user.insert({name, pw});
        cout << "Registration Is Successfull! " << endl;
        Customers.push_back(New);
        login();
    }
}

int customer::login() {
    int idx = 0;
    string n, p;
    cout << "Enter Username : ";
    cin >> n;
    cout << "Enter Password: ";
    cin >> p;
    system("cls");
    if (user.count({n, p})) { //O(log(N))
        for (int i = 0; i < Customers.size(); i++) { //O(N)
            if (Customers[i].name == n && Customers[i].pass == p) {
                idx = i;
                break;
            }
        }
        cout << "Your Login Is Successfull!" << endl;
    } else {
        cout << "Login error, check your username or password!" << endl;
        cout << endl;
        login();
    }

    return idx;
}

// Bassel's task
void ShowRoomReceipt(ShowRoom_receipt receipt) {
    cout << "Process ID: " << receipt.Process_ID << endl;
    cout << "Customer ID: " << receipt.Customer_ID << endl;
    cout << "Process Date: " << receipt.date.day << "/" << receipt.date.month << "/" << receipt.date.year << endl;
    cout << "Price: " << receipt.Amount_of_money << " LE\n";
    cout << "Car Model: " << receipt.Chosen_car.model << endl;
}

// etfahmo m3 b3d b2a
void customer::page() {
    Login:
    int c, plaa2;
    int x;
    cout << "|-------------------------------------------|" << endl;
    cout << "|         Welcome To The Login Page         |" << endl;
    cout << "|-------------------------------------------|" << endl << endl;
    cout << "1: Admin" << endl;
    cout << "2: Customer" << endl;
    cin >> x;
    system("cls");
    int idx = 0;
    if (x == 2) {
        cout << "1: Login" << endl;
        cout << "2: Register" << endl;
        cin >> c;
        system("cls");
        switch (c) {
            case 1:
                idx = login();
                break;
            case 2:
                registration();
                break;

            default:
                system("cls");
                cout << "Please Select From Options Given Above!" << endl;
                page();
        }
        cout << "1: Display" << endl;
        cout << "2: Search" << endl;
        cin >> plaa2;
        system("cls");
        switch (plaa2) {
            case 1:
                displayAll(Customers[idx]);
                break;
            case 2:
                search();

            default:
                break;
        }

    }
    else if (x == 1) {
        Admin admin;
        string name, pass;
        cout << "Enter Username: " << endl;
        cin >> name;
        cout << "Enter Password: " << endl;
        cin >> pass;
        system("cls");
        if (name == admin.admainName && pass == admin.password)
            Admin::Administration();
        else {
            cout << "\nLogin failed. Check your username or password!" << endl;
            cout << endl;
            goto Login;
        }
    } else {
        cout << "Please Select From Options Given Above " << endl;
        page();
    }
}


void customer::displayAll(customer &Cust) {
    int plaa;
    Display:
    cout << "1: Buy/Rent Car" << endl;
    cout << "2: Services" << endl;
    cout << "3: Service History" << endl;
    cout << "4: Logout" << endl;
    cout << "Enter Your Choice : " << endl;
    cin >> plaa;
    system("cls");
    if (plaa == 1) {
        system("cls");
        int idx1, idx2;
        DisplayShowRooms(1);
        cout << "-------------------------------------" << endl;
        cout << "Enter index of both showroom and car." << endl;
        cout << "Showroom index : " << endl;
        cin >> idx1;
        cout << "Car index : " << endl;
        cin >> idx2;
        system("cls");
        cout << "1: Buy" << endl;
        cout << "2: Rent" << endl;
        int choose;
        cin >> choose;
        system("cls");

        ShowRoom_receipt receipt;
        receipt.Process_ID++;
        receipt.Customer_ID = Cust.name;
        receipt.date.day = today1;
        receipt.date.month = month1;
        receipt.date.year = year1;

        if (choose == 1) {
            cout << "Do you want to book it for a specific time? (y/n)" << endl;
            char c;
            cin >> c;
            if (c == 'y') {
                receipt.Amount_of_money += Rooms[idx1].car[idx2].price;
                receipt.Chosen_car.model = Rooms[idx1].car[idx2].model;

                int days;
                cout << "For How Many Days?" << endl;
                cin >> days;
                cout << "Your car has been booked until " << today1 + days << "/" << month1 << "/" << year1 << endl;
                cout << "Do You Want Show Your Receipt? (y/n)" << endl;
                cin >> c;

                if (c == 'y')
                    ShowRoomReceipt(receipt);

                cout << "Congrats, Purchase Completed!" << endl;
                Erase(Rooms[idx1].car, idx2);
                return;
            } else {
                receipt.Amount_of_money += Rooms[idx1].car[idx2].price;
                receipt.Chosen_car.model = Rooms[idx1].car[idx2].model;
                cout << "Do You Want Show Your Receipt? (y/n)" << endl;
                cin >> c;

                if (c == 'y')
                    ShowRoomReceipt(receipt);

                cout << "Congrats, Purchase Completed!" << endl;
                Erase(Rooms[idx1].car, idx2);
                return;
            }
        }
        if (choose == 2) {
            int days;
            cout << "How Many Days?\n" << "One Day Is Equal To 0.1% Of The Total Value Of The Car" << endl;
            cin >> days;
            // 1 day = 1% price of car, 1 day = 0.01 * price of car
            // 5 days = 5 * (0.01 * price)
            receipt.Amount_of_money = days * (Rooms[idx1].car[idx2].price * 0.01);
            receipt.Chosen_car.model = Rooms[idx1].car[idx2].model;
            // 13/3 , today = 13 + (3 * 30)
            Rooms[idx1].car[idx2].deadline = day1 + days;

//            // today = 29, rent = 10 day -> deadline = 39 (this is wrong)
//            // if(deadline > 30) deadline = deadline - 30
//            // now deadline = 9 (this is correct)
//            if (Rooms[idx1].car[idx2].deadline > 30)
//                Rooms[idx1].car[idx2].deadline -= 30;

            char c;
            cout << "Do You Want Show Your Receipt? (y/n)" << endl;
            cin >> c;
            if (c == 'y')
                ShowRoomReceipt(receipt);

            cout << "Enjoy Your Time!" << endl;
            return;
        }

    }
    else if (plaa == 2) {
        system("cls");
        //DisplayGarage(1 to show garage with services, Customer name, Customer Service History)
        DisplayGarage(Cust.name, Cust.HistoricService);
    }
    else if (plaa == 3) {
        system("cls");
        for (auto u : Cust.HistoricService) {
            cout << "-Service Name : " << u.name << endl;
            cout << "-Service Price : " << u.price << endl;
            cout << u.date.day << '/' << u.date.month << '/' << u.date.year << endl;
        }
    }
    else if (plaa == 4) {
        system("cls");
        page();
    }
    else {
        system("cls");
        cout << "Please Enter From Options Given Above";
        goto Display;
    }
}

void customer::search() {
    int yournum;
    cout << "1: Car " << endl;
    cout << "2: Showroom " << endl;
    cout << "3: Garage " << endl;
    cout << "4: Service " << endl;
    cout << "Enter Your Choice :" << endl;
    cin >> yournum;
    system("cls");
    string name, model;
    bool found;
    switch (yournum) {
        case 1:
            cout << "Enter car name and model." << endl;
            cout << "Car Name : " << endl;
            cin >> name;
            cout << "Car Model :" << endl;
            cin >> model;
            system("cls");
            for (auto u : Rooms)
                for (auto v : u.car)
                    if (v.model == name && v.year == model) {
                        cout << "Showroom name : " << u.name << endl;
                        cout << "Showroom location : " << u.location << endl;
                        cout << "Car price : " << v.price << endl;
                        cout << "Installment state : " << v.installment << endl;
                        if (day1 < v.deadline && v.deadline != 0)
                            cout << "Car state : Not Available" << endl;
                        else
                            cout << "Car state : Available" << endl;
                        found = true;
                    }

            if (!found)
                cout << "Car not found!" << endl;

            break;

        case 2:
            cout << "Enter showroom name : " << endl;
            cin >> name;
            system("cls");
            for (auto u : Rooms) {
                if (u.name == name) {
                    cout << "Showroom location : " << u.location << endl;
                    cout << "Showroom Phone number : " << u.phone << endl;
                    u.Display();
                    found = true;
                }
            }

            if (!found) cout << "Showroom not found!" << endl;

            break;
        case 3:
            cout << "Enter garage name : " << endl;
            cin >> name;
            system("cls");
            for (auto u : Garages) {
                if (u.name == name) {
                    cout << "Garage location : " << u.location << endl;
                    cout << "Garage Phone number : " << u.phone << endl;
                    u.Display_garage();
                    found = true;
                }
            }

            if (!found) cout << "Garage not found!" << endl;

            break;
        case 4:
            cout << "Enter service name : " << endl;
            cin >> name;
            system("cls");
            for (auto u : Garages) {
                for (auto v : u.service) {
                    if (v.name == name) {
                        cout << "Garage name : " << u.name << endl;
                        cout << "Garage location : " << u.location << endl;
                        cout << "Service price : " << v.price << endl;
                        found = true;
                    }
                }
            }

            if (!found) cout << "Service not found!" << endl;

            break;
        default:
            break;
    }
}
