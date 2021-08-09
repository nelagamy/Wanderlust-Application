//Nermien Elassy_900196006
//Shahd Elmahallawy_900194441
#include "User.hpp"
using namespace std;
int main()
{
    User user1;
    //Signin
    string name;
    string pass;
    cout << "Please, enter your name: " << endl;
    cin >> name;
    user1.setName(name);
    cout << "Please, enter your password: " << endl;
    cin >> pass;
    user1.setPassword(pass);
    
    //choose feature
    int feature;
    do {
        cout << "Please, enter the number of the feature you want to use: " << endl;
        cout << "1 for Currency exchange" << endl;
        cout << "2 for entering your Coupon" << endl;
        cout << "3 for Bus Service Integration" << endl;
        cout << "4 for Filtering Search Results of hotels" << endl;
        cout << "5 for Hotel Reservation System" << endl;
        cout << "6 for Recommendation system" << endl;
        cout << "7 for the forecast news "<<endl;
        cin >> feature;
        user1.chooseFeature(feature);
        user1.controlFeatures();
        cout << "Enter 0 if you want to return to the main menu or any other number if you want to exit: " << endl;
        cin >> feature;

    } while (feature == 0);
    cout<<"Thank you for using Wanderlust! Waiting for your feedback :) "<<endl;
    return 0;
}

