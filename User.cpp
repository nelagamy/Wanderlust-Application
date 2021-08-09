//Nermien Elassy_900196006
//Shahd Elmahallawy_900194441
#include "User.hpp"
#include<fstream>
#include<cmath>
#include<string>

//constructor
User::User()
{
    //login
    Name= "";
    Password= "";
    //coupon code
    pocketMoney=0.0;
    Coupon = 0;
    //Bus Serviece Integration
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            availibility[i][j] = rand() % 60;
        }
    }
    //cut off
    max=0;
    min=0;
    cutOff=0;
    feature = 0;
    Currency= ' ';

    //Hotel Reservation system
    n_rooms = -1;
   
    //Recommendation System
    felxibilityScale = 0.0;
    budget = 0.0;
    adventoursness = 0.0;
    average = 0.0;
    
    //forecast
    month=0;
    Day_time =' ';
}

void User::setName(string name)
{
    Name = name;
}
string User::getName()
{
    return Name;
}

void User::setPassword(string Pass)
{
    Password = Pass;
}

string User::getPassword()
{
    return Password;
}

//Choosing the feature
void User::chooseFeature(int f)
{
    feature = f;
}

// Currency exchange functions
void User::setpocketMoney(double money)
{
    pocketMoney = money;
}
double User::transferDollars()
{
    double amount = 0; //result
    cout << " please enter the type of cuurency you want to convert your money into ( P OR F OR Y where P is pounds, F is Franc and Y is Yen" << endl;
    cin >> Currency;
    if (Currency == 'P')
    {
        amount = pocketMoney * 0.75;
    }
    else if (Currency == 'F')
    {
        amount = pocketMoney * 0.84;
    }
    else if (Currency == 'Y')
    {
        amount = pocketMoney * 105.95;
    }
    return amount;
}

// Coupon checker
void User::setCoupon(int coupon1)
{
    Coupon = coupon1;
}
void User::checkCoupon()
{
    int counter33 = 0; //for counting last two digits
    int counter6= 0; //for counting digits
    int temp;
    int tempCoupon = Coupon;
    do
    {
        while (Coupon != 0)
        {
            Coupon = Coupon / 10;
            counter6++;
        }
        for (int i = 0; i < 2; i++)
        {
            temp = tempCoupon % 10;
            Coupon = tempCoupon / 10;
            if (temp == 3)
            {
                counter33++;
            }
        }
        if (counter33 == 2 && counter6 == 6)
        {
            cout << "Congratulations! You got special offers and discounts on your reservations." << endl;
        }
        else
        {
            cout << "Invalid code " << endl;
            cout << "Please either renter your code or enter -1" << endl;
            cin >> Coupon;
            setCoupon(Coupon);
        }
    } while (counter6 != 6 && counter33 != 2 && Coupon != -1);
}

// Bus Service Integration
int User :: find_best_pickup()
{
    int min_array[5];
    for (int i = 0; i < 5; i++)
    {
        if (availibility[i][0] < availibility[i][1])
        {
            if (availibility[i][0] < availibility[i][2])
                min_array[i] = availibility[i][0];
            else min_array[i] = availibility[i][2];
        }
        else
        {
            if (availibility[i][1] < availibility[i][2])
                min_array[i] = availibility[i][1];
            else min_array[i] = availibility[i][2];
        }
    }
    int best_point = 0;
    int sooner = min_array[0];
    for (int i = 0; i < 5; i++)
    {
        if (sooner > min_array[i])
        {
            sooner = min_array[i];
            best_point = i + 1;
        }
    }
    return best_point;
}

//Cutoff
void User::set_max(int maximum)
{
    max = maximum;
}
void User::set_min(int minimum)
{
    min = minimum;
}
void User::set_cutOff(int cutPrice)
{
    cutOff = cutPrice;
}
int* User::getP2()
{
    return p2;
}
int User::getNum()
{
    return num;
}
int* User::generatePrice()
{
    int price[40];

    for (int i = 0; i < 40; i++)
    {
        price[i] = min + rand() % (max - min);
    }
    p1 = price;
    return p1;
}
int* User::filterArrays()
{
    int* filter;
    int endValue = 0;
    for (int i = 0; i < 40; i++)
    {
        if (p1[i] <= cutOff)
        {
            endValue++;
        }
    }
    filter = new int[endValue];

    for (int j = 0; j < endValue; j++)
    {
        if (p1[j] <= cutOff)
        {
            filter[j] = p1[j];
        }
    }
    num = endValue;
    p2 = filter;
    return p2;
}

//Hotel Reservation System
void User::setRoomReservation()
{
    for (int i = 0; i < n_rooms; i++)
    {
        do {
            cout << "Please enter the type of your room: Single or Double or Suite " << endl;
            cin >> rooms[i].type;
        } while (!(rooms[i].type == "Single" || rooms[i].type == "Double" || rooms[i].type == "Suite"));
        do {

            cout << "Please enter the number of nights you will spend in it " << endl;
            cin >> rooms[i].stayingNights;
        } while (rooms[i].stayingNights < 0);

        do {
            cout << "Please enter whether you will pay via CIB bank or not . 1 if yes 0 if no" << endl;
            cin >> rooms[i].payment;
        } while (!(rooms[i].payment == 0 || rooms[i].payment == 1));
    }
    
}
int User::getSingle()
{
    int counterSingle = 0;
    for (int i = 0; i < n_rooms; i++)
    {
        if (rooms[i].type == "Single")
        {
            counterSingle+=rooms[i].stayingNights;
        }
    }
    return counterSingle;
}
int User::getDouble()
{
    int counterDouble = 0;
    for (int i = 0; i < n_rooms; i++)
    {
        if (rooms[i].type == "Double")
        {
            counterDouble+=rooms[i].stayingNights;
        }
    }
    return counterDouble;
}
int User::getSuite()
{
    int countersuite = 0;
    for (int i = 0; i < n_rooms; i++)
    {
        if (rooms[i].type == "Suite")
        {
            countersuite+=rooms[i].stayingNights;
        }
    }
    return countersuite;
}
bool User::getPayment()
{
    bool Payment = false;
    int counterPayment = 0;
    for (int i = 0; i < n_rooms; i++)
    {
        if (rooms[i].payment == true)
        {
            counterPayment++;
        }
    }
    if (counterPayment == n_rooms)
    {
        Payment = true;
    }
    else
    {
        Payment = false;
    }
    return Payment;
}
void User::calculateUserTotal()
{
    int Single = 3000;
    int Double = 4500;
    int suite = 6000;
    int total = 0;
    bool CIB = getPayment();
    if (!CIB)
    {
        total = (getSingle() * Single + getDouble() * Double + getSuite()*suite);
    }
    else
    {
        total = (getSingle() * Single + getDouble() * Double + getSuite()*suite) * 0.97;

    }
    cout << " Your bill is " << total << "LE " << endl;
}

//Recomedation System
void User::averageScale()
{
    average = (felxibilityScale + adventoursness + budget) / 3;
}
void User::RecommendedDestination()
{
    string item1;
    double item2;
    string item3;
    double item4;
    string item5;
    double item6;
    double result2;
    double result4;
    double result6;

    ifstream StreamReader;
    ofstream StreamWriter;
    StreamReader.open("/Users/aucuser/Desktop/Final submission/Final submission/Test.txt");
    if (!StreamReader.is_open())
    {
        cout<<"Hard"<<endl;
    }
    StreamWriter.open("/Users/aucuser/Desktop/Final submission/Final submission/high.txt");
    StreamWriter << "Your recommended destination(s) are " << endl;
    while (!StreamReader.eof())
    {
        StreamReader >> item1 >> item2 >> item3 >> item4 >> item5 >> item6;
        result2 = average - item2;
        result4 = average - item4;
        result6 = average - item6;
        if (abs(result2) == 0.5)
        {
            StreamWriter << item1 << endl;
        }
        if (abs(result4) == 0.5)
        {
            StreamWriter << item3 << endl;
        }
        if (abs(result6) == 0.5)
        {
            StreamWriter << item5 << endl;
        }
      
    }
    StreamReader.close();
    StreamWriter.close();
}
//New feature1
void User::Forecast()
{
    cout<<"Please enter the current month "<<endl;
    cin>>month;
    cout<<"Please enter the current day time "<<endl;
    cin>>Day_time;
    if (month<=9 && month>=3)
    {
        if (Day_time == 'D')
        {
            cout<<"Today is hot and we do not expect raining "<<endl;
        }
    }
    else
    {
            cout<<"Today is cold and it may rain "<<endl;
    }
}
//New feature2
void User::currencyexchange ()
{

    double money;
    cout << "Enter your pocket money: " << endl;
    cin >> money;
    setpocketMoney(money);
    double dollars = transferDollars();
    cout << "Your pocket money in the new currency= " << dollars << endl;
}
void User::coupon()
{
    int c;
    cout << "Enter your copoun code: " << endl;
    cin >> c;
    setCoupon(c);
    checkCoupon();
}
void User::Bus_Service_Integration()
{

    cout << "The the best possible pickup point is point: " << find_best_pickup()<< endl;
}
void User::Cut_off()
{
    int maxValue;
    int minValue;
    int cutOffValue;
    int* temp_P;
    cout << "Enter the max price you may pay: " << endl;
    cin >> maxValue;
    set_max(maxValue);
    cout << "Enter the minimum price you may pay: " << endl;
    cin >> minValue;
    set_min(minValue);
    cout << "Enter the cut off price you want: " << endl;
    cin >> cutOffValue;
    set_cutOff(cutOffValue);
    generatePrice();
    filterArrays();
    temp_P = getP2();
    for (int i = 0; i < getNum(); i++)
    {
        cout << temp_P[i] << endl;
    }
}
void User::Hotel_Reservation_System()
{

    cout << "Please, enter the number of rooms you want to reserve: " << endl;
    cin>> n_rooms;
    rooms = new roomReservation[n_rooms];
    setRoomReservation();
    calculateUserTotal();
}

void User::Recomendation_System()
{

    cout << "Please enter your flexibility scale from 1 to 5: " << endl;
    cin >> felxibilityScale;
    cout << "Please enter your adventurenouss scale from 1 to 5: " << endl;
    cin >> adventoursness;
    cout << "Please enter your budget scale from 1 to 5: " << endl;
    cin >> budget;
    averageScale();
    RecommendedDestination();
}
void User::controlFeatures()
{
    if (feature == 1)
    {
        currencyexchange();

    }
    else if (feature == 2)
    {
        coupon();
    }
    else if (feature == 3)
    {
        Bus_Service_Integration();
    }
    else if (feature == 4)
    {
        Cut_off();
    }
    else if (feature == 5)
    {
        Hotel_Reservation_System();
    }
    else if (feature == 6)
    {
        Recomendation_System();
    }
    else if (feature == 7)
    {
        Forecast();
    }
}

