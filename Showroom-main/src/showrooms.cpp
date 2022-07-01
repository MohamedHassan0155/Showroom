#include"showrooms.h"
#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

time_t now2 = time(0);
tm *ltm2 = localtime(&now2);
int year2 = 1900 + ltm2->tm_year;
int month2 = 1 + ltm2->tm_mon;
int today2 = ltm2->tm_mday;
vector<ShowRooms> ShowRooms::Rooms;

// Bassel's task
void ShowRooms::Display() {
    int idx = 0;
    for (auto u : car) {
        int day = today2 + (30 * month2) + (365 * year2);
        if (day < u.deadline && u.deadline != 0) continue;
        cout << "--Car Model : " << u.model << endl;
        cout << "--Car Make : " << u.make << endl;
        cout << "--Car Price : " << u.price << endl;
        cout << "--Car Index : " << idx++ << endl;
        cout << "-------------------------------- " << endl;
    }
}

void ShowRooms::DisplayShowRooms(int turn) {
    int idx = 0;
    for (auto u : Rooms) {
        cout << "Showroom Name : " << u.name << endl;
        cout << "Showroom Location : " << u.location << endl;
        cout << "Showroom Phone Number : " << u.phone << endl;
        cout << "Showroom Index : " << idx++ << endl << endl;
        if (turn) {
            cout << "-Cars : " << endl;
            u.Display();
            cout << endl;
        }
    }
}
