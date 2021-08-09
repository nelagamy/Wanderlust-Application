//Nermien Elassy_900196006
//Shahd Elmahallawy_900194441
#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class User
{
private:
    
    // User will enter this whenever he/she enters the app (New feature1)
    string Name;
    string Password;
    
    // Currency exchange atrributes
    double pocketMoney;
    int Coupon;
    
    // Bus Service Integration
    int availibility[5][3]; // We assumed the size of the array
 
    //cut off
    int max;
    int min;
    int cutOff;
    int* p1;
    int* p2;
    int num;

    //Hotel Reservation System
    struct roomReservation
    {
        string type; // Single, double,etc
        int stayingNights; // 4nights, 3nights, etc
        bool payment; // By CIB bank or not
    };
    int n_rooms;
    roomReservation* rooms;

public:
    int feature;
    char Currency;
    int month;
    char Day_time;

    User(); //Constructor //Contribution work

    //Contribution work
    //login
    void setName(string name); //setter for the user's name
    string getName(); // getter for the user's name
    void setPassword(string Pass); //setter for the password
    string getPassword(); //getter for the password
    
    //Contribution work
    //Choosing the feature
    void chooseFeature(int f);

    //Shahd
    // Currency exchange functions
    void setpocketMoney(double money);
    double transferDollars();

    //Shahd
    // Coupon checker
    void setCoupon(int coupon1);
    void checkCoupon();
    
    //Shahd
    // Bus Service Integration
    int find_best_pickup();

    //Nermien
    //cut off
    void set_min(int minimum);
    void set_max(int maximum);
    void set_cutOff(int cutprice);
    int* generatePrice();
    int* filterArrays();
    int* getP2();
    int getNum();

    //Nermien
    //Hotel Reservation System
    void setRoomReservation();
    int getSingle();
    int getDouble();
    int getSuite();
    bool getPayment();
    void calculateUserTotal();

    //Nermien
    //Recommendation system
    double felxibilityScale;
    double budget;
    double adventoursness;
    double average;
    void averageScale();
    void RecommendedDestination();
    
    //Contribution work
    //Forecast (New feature3)
    void Forecast();

    //Contribution work
    // control functions (New feature2)
    void controlFeatures();
    void currencyexchange ();
    void coupon();
    void Bus_Service_Integration();
    void Cut_off();
    void Hotel_Reservation_System();
    void Recomendation_System();
};


#endif /* User_hpp */
