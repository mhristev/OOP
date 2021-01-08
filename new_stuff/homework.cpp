#include <iostream>
#include <iomanip>
#include <map>

using namespace std;


class DateTime{
    public:
    int seconds;
    int minutes;
    int hours;
    int days;
    int months;
    int years;

    DateTime () {
        this->seconds = Start.seconds + 0;
        this->minutes = Start.minutes + 0;
        this->hours = Start.hours + 0;
        this->days = Start.days + 0;
        this->months = Start.months + 0;
        this->years = Start.years + 0;
    }

    DateTime (int sec, int min, int hour, int day, int month, int year) {
        this->seconds = Start.seconds + sec;
        this->minutes = Start.minutes + min;
        this->hours = Start.hours + hour;
        this->days = Start.days + day;
        this->months = Start.months + month;
        this->years =Start.years + year;
    }

    DateTime (const DateTime& source) {
        this->seconds = source.seconds;
        this->minutes = source.minutes;
        this->hours = source.hours;
        this->days = source.days;
        this->months = source.months;
        this->years = source.years;

        cout << "Copy constructor called" << endl;
    }
    const static DateTime Start;

    friend ostream& operator<< (ostream& out, const DateTime& source);

    bool operator ==(map <char,int>& date) {
        if(date['d'] == this->days && date['m'] == this->months && date['y'] == this->years){
            return true;
        }else
        {
            return false;
        }
        
    }

    bool operator !=(const DateTime& source) {
        if(this->seconds != source.seconds || 
           this->minutes != source.minutes || 
           this->hours != source.hours || 
           this->days != source.days || 
           this->months != source.months || 
           this->years != source.years) {
            return true;
        } else {
            return false;
        }
    }

    bool operator >(const DateTime& source){
        if(this->seconds > source.seconds || 
           this->minutes > source.minutes || 
           this->hours > source.hours || 
           this->days > source.days || 
           this->months > source.months || 
           this->years > source.years) {
            return true;
        } else {
            return false;
        }
    } 



};

const DateTime DateTime :: Start = DateTime(0, 0, 0, 0, 0, 1900);

ostream& operator<< (ostream& out, const DateTime& source) {
    out << "Date:" << source.years << "-" 
    << std::setw(2) << setfill('0') << source.months << "-" 
    << std::setw(2) << setfill('0') << source.days << " " 
    << std::setw(2) << setfill('0') << source.hours << ":" 
    << std::setw(2) << setfill('0')<< source.minutes << ":" 
    << std::setw(2) << setfill('0')<< source.seconds;
    return out;
}



int main() {

    DateTime mydate(10, 20, 10, 7, 5, 120);
    DateTime mydate2(10, 20, 10, 7, 5, 100);

    map<char, int> date;
    date['d'] = 7;
    date['m'] = 5;
    date['y'] = 2000;

    
    
    if (mydate2 == date) 
        cout << "true" << endl;
    else
        cout << "not true" << endl;
    //cout << mydate << endl;

}