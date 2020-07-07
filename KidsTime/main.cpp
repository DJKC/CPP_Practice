#include<iostream>
#include <cctype>

using namespace std;

void getTime(string whichTime, int& hours, int& minutes, bool& isAM);
//Function gets the time.
//Parameter whichTime indicates current or future time.
//Paramter hours is the hours component for the time.
//Paramter minutes is the minutes component for the time.
//Parameter isAm indicates if it is AM or PM.

int timeDifference(int hoursNow, int minutesNow, int isAM_now, int hoursFuture, int minutesFuture, bool isAM_future);
//Function calculates the difference is 2 times given.
//  No current provisions for entering a given date or going backwards in time have been made.
//Parameters in order are hours, minute, A.M. indictor for the present time and
//  then the hours, minute, A.M. indictor for the future time.

int main(){//declarations
    int hoursNow, hoursFuture, minutesNow, minutesFuture;
    bool isAM_now, isAM_future; //for the am or pm
    
    cout << "Time machine introduction goes here.\n";
    
    getTime("CURRENT", hoursNow, minutesNow, isAM_now);
    getTime("FUTURE", hoursFuture, minutesFuture, isAM_future);
    
    int difference = timeDifference(hoursNow, minutesNow,isAM_now, hoursFuture, minutesFuture, isAM_future);
 
    cout << "The difference between " << hoursNow  << ":" << minutesNow << (isAM_now ? " A.M." : " P.M.")
         << " and " << hoursFuture  << ":" << minutesFuture << (isAM_future ? " A.M." : " P.M.") << " is " << difference << " minutes.\n";
    
    return 0;
}

void getTime(string whichTime, int& hours, int& minutes, bool& isAM){
    char answer;
    
    do{
        cout << "Please enter the " << whichTime << " time as directed below.\n\n";
        
        do{
            cout << "What hour is it?\n"
                 << "Hour #: ";
            cin >> hours;
        }while((hours < 1) || (hours > 12));

        do{
            cout << "What are the minutes for this hour?\n"
                 << "Minute #: ";
            cin >> minutes;
        }while((minutes < 0) || (minutes > 59));

        cout << "\nPlease enter the number that shows the correct time.\n"
             << "0) " << hours << ":" << minutes << " P.M.\n"
             << "1) " << hours << ":" << minutes << " A.M.\n"
             << "0 or 1: ";
        cin >> isAM;

        cout << "\nYour time is " << hours << ":" << minutes << (isAM ? " A.M." : " P.M.") << "\n"
             << "Is this correct?\n"
             << "Y / N: ";
        cin >> answer;
        
        cout << "\t\t-----\n\n";
    }while(tolower(answer) == 'n');
    
    return;
}

int timeDifference(int hoursNow, int minutesNow, int isAM_now, int hoursFuture, int minutesFuture, bool isAM_future) {
int totalMinutesFuture, totalMinutesNow;

/*
Scenario #1, P.M. -> A.M.
    Calculate 11:59 P.M. minus present time
    Calculate future time minus minus 12:00 A.M.
    Add values and 1 minute to account for 11:59 P.M. to 12:00 A.M..
    
Scenario #2, P.M. -> P.M.
    If future hour > present hour
        Calculate future time minus current time
    Else present hour > future hour
        Calculate difference of now time minus future time.
        Subtract 24 hours from that.

Scenario #3, A.M. -> P.M.
    Calculate 11:59 A.M. minus present time
    Calculate future time minus minus 12:00 P.M.
    Add values and 1 minute to account for 11:59 A.M. to 12:00 P.M..

Scenario #4, A.M. -> A.M.
    If future hour > present hour
        Calculate future time minus current time
    Else present hour > future hour
        Calculate difference of now time minus future time.
        Subtract 24 hours from that.
*/
    
    return totalMinutesFuture - totalMinutesNow;
}