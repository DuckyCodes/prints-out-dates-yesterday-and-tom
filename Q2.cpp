
#include <iostream>
using namespace std;
//Design a class called Date
class Date
{
protected:
    // store a date in three integers: month, day, and year
    int month;
    int day;
    int year;
public:
    // accessor and mutator functions
    int gMonth() const;
    int gDay() const;
    int gYear() const;

    void sMonth(const int);
    void sDay(const int);
    void sYear(const int);

    string monthName(const int);
    void input();

    /*three output member functions (named output1, output2, and output3*/
    //12/25/2014
    void output1() const;
    //December 25, 2014
    void output2();
    //25 December 2014
    void output3();

    /*Define a member function named Increment to display the next day.
Define a member function named Decrement to display the previous day*/
    void increment();
    void decrement();
    //default constructor that sets the date to January 1, 2000
    Date();
    
    Date(const int &, const int &, const int&);
 
};
// accessor and mutator functions
 int Date:: gMonth() const
 {
     return this-> month;
 }
 int Date:: gDay() const
 {
     return this->day;
 }
 int Date:: gYear() const
 {
     return this->year;
 }

void Date:: sMonth(const int x)
{
     this->month = x;
}
void Date:: sDay(const int x)
{
    this->day = x;
}
void Date:: sYear(const int x)
{
    this->year = x;
}

void Date:: input()
{
    /*Input Validation: In your input function ask for month first, do not accept values for the month
greater than 12 or less than 1. Do not accept values for the day less than 1 or greater than the
number of days in the month.*/

    cout << "input amount the month" << endl;
    while (true)
    {
        
        cin >> month;
        if (month < 1 || month > 12)
        {
            cout << "input a proper month" << endl;
            continue;
        }
        else
            break;

    }
    
    /*Number of days in January, March, May, July, August, October, and December: 31
Number of days in April, June, September, October: 30
Number of days in February: 28 (no need to consider leap years in your program)*/

    cout << "input days of the month" << endl;
    while (true)
    {
        
        cin >> day;
       
        if (((day > 28) && (month == 2))|| ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))||day>31)
        {
            cout << "input a proper day for that month" << endl;
            continue;
        }
        else
            break;

    }


    cout << "input year" << endl;
    cin >> year;
}
string Date::monthName(const int x)
{
    /*Number of days in January, March, May, July, August, October, and December: 31
Number of days in April, June, September, October: 30
Number of days in February: 28 (no need to consider leap years in your program)*/
    string name;
    if (x == 1)
        name = "January";
    if(x == 2)
        name = "February";
    if (x == 3)
        name = "March";
    if (x == 4)
        name = "April";
    if (x == 5)
        name = "May";
    if (x == 6)
        name = "June";
    if (x == 7)
        name = "July";
    if (x == 8)
        name = "August";
    if (x == 9)
        name = "September";
    if (x == 10)
        name = "October";
    if (x == 11)
        name = "November";
    if (x == 12)
        name = "December";

    return name;
}
/*three output member functions (named output1, output2, and output3*/
//12/25/2014
void Date:: output1() const
{
    cout << "today" << endl;
    cout << month << "/" << day << "/" << year << endl;
}
//December 25, 2014
void Date:: output2()
{
    cout << monthName(month)<<" " << day<<", " << year << endl;;
}


//25 December 2014
void Date:: output3()
{
    cout << day<<" " << monthName(month)<<" " << year << endl;;
}

void Date::increment()
{
    /*• When a date is set to the last day of the month and incremented, it should become the first
day of the following month.
• When a date is set to December 31 and incremented, it should become January 1 of the
following year.*/
    int tday = day;
    int tMonth = month;
    int tYear = year;
    cout << "next day " << endl;
    if ((month == 4 || month == 6 || month == 9 || month == 11))
    {
        if (day < 30) 
        {
            tday++;
        }
        else
        {
            tMonth++;
            tday = 1;
        }
    }
    if ((month == 2))
    {
        if (day < 28)
        {
            tday++;
        }
        else
        {
            tMonth++;
            tday = 1;
        }
    }
    if ( month == 1 || month == 3 || month == 5 || month == 7||month == 8 || month == 10)
    {
        if (day < 31)
        {
            tday++;
        }
        else
        {
            tMonth++;
            tday = 1;
        }
    }
    if (month == 12)
    {
        if (day == 31)
        {
            tMonth = 1;
            tday = 31;
            tYear++;
        }
        else
        {
            tday++;
        }
    }
    cout << tMonth << "/" << tday << "/" << tYear << endl;;
    cout << monthName(tMonth) << " " << tday << ", " << tYear << endl;
    cout << tday << " " << monthName(tMonth) << " " << tYear << endl;
}
void Date::decrement()
{
/*• When a day is set to the first day of the month and decremented, it should become
the last day of the previous month.
• When a date is set to January 1 and decremented, it should become December 31 of
the previous year.*/
    int tday = day;
    int tMonth = month;
    int tYear = year;
    cout << "Prvious day " << endl;
    if ((month == 2||month == 4 || month == 6 || month == 9 || month == 11))
    {
        if (day > 1)
        {
            tday--;
        }
        else
        {
            tMonth--;
            tday = 31;
        }
    }
    if ( month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 1)
        {
            tday--;
        }
        else
        {
            tMonth--;
            tday = 30;
        }
    }
    if (month == 3)
    {
        if (day < 1)
        {
            tday--;
        }
        else
        {
            tMonth--;
            tday = 28;
            
        }
    }
    if (month == 1)
    {
        if (day == 1)
        {
            tMonth = 12;
            tday = 31;
            tYear--;
        }
        else
        {
            tday--;
        }
    }
    cout << tMonth << "/" << tday << "/" << tYear << endl;;
    cout << monthName(tMonth)<<" " << tday <<", " << tYear << endl;
    cout << tday<<" " << monthName(tMonth) << " " << tYear << endl;
}

//default constructor that sets the date to January 1, 2000
 Date::Date()
 {
     month = 1;
     day = 1;
     year = 2000;
 }

 Date::Date(const int& a, const int& b, const int& c)
 {
     month = a;
     day = b;
     year = c;
 }
int main()
{
    Date x(12, 25, 2014);
    x.output1();
    x.output2();
    x.output3();

    x.increment();
    x.decrement();
    
    Date y(1,2,3);
    y.input();
    y.output1();
    y.output2();
    y.output3();

    y.increment();
    y.decrement();

}

/*

Demonstrate the class’s capabilities in a simple program.
Number of days in January, March, May, July, August, October, and December: 31
Number of days in April, June, September, October: 30
Number of days in February: 28 (no need to consider leap years in your program)
Save the program as Q2.cpp*/
