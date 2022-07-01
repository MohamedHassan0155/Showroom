#include<iostream>
#include<string.h>
#include"garage.h"
#include "showrooms.h"
#include<set>
#include<vector>

using namespace std;

struct ShowRoom_receipt {
    int Process_ID = 0;
    string Customer_ID;
    Date date;
    double Amount_of_money = 0;
    Car Chosen_car;
};

class customer {
public:
    string name, pass;
    vector<Service> HistoricService;

    //static string currentcustomer;

    static set<pair<string, string> > user;

    static vector<customer> Customers;

    static void registration();

    static int login();

    static void displayAll(customer &Cust);

    static void search();

    static void page();
};

class Admin {
public:
    const string admainName = "admin", id, password = "admin";

    static void GetCar(ShowRooms &X);

    static void GetService(garage &X);

    static void AddShow();

    static void AddGarage();

    static void Administration();
};
