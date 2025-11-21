
    #include <iostream>
using namespace std;

class Time {
private:
    int hours, mins, secs;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        mins = m;
        secs = s;
    }

    void set_date(int h, int m, int s) {
        hours = h;
        mins = m;
        secs = s;
    }

    void display() {
        cout << "Time: " << hours << ":" << mins << ":" << secs << endl;
    }

    Time operator+(Time &obj) {
        Time temp;

        temp.hours = hours + obj.hours;
        temp.mins = mins + obj.mins; // Fixed typo: `mins =` to `temp.mins =`
        temp.secs = secs + obj.secs; // Fixed typo: `sesc` to `secs`

        return temp;
    }

    Time operator=(Time &obj) { // Fixed typo: `opreator` to `operator`
        hours = obj.hours;
        mins = obj.mins; // Fixed typo: `min` to `mins`
        secs = obj.secs; // Fixed typo: `sec` to `secs`

        return *this; // Return the current object for assignment operator
    }

    bool operator<(Time &obj) {
        if (hours < obj.hours) {
            return true;
        } else if (hours == obj.hours) {
            if (mins < obj.mins) {
                return true;
            } else if (mins == obj.mins) {
                return secs < obj.secs; // Fixed logic: Corrected nested conditions
            }
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, Time &obj);
};

ostream &operator<<(ostream &os, Time &obj) { // Fixed typos in friend function declaration
    os << "Time: " << obj.hours << ":" << obj.mins << ":" << obj.secs;
    return os;
}

int main() {
    Time t1(12, 56, 30);
    Time t2(1, 34, 34);

    Time t3 = t1 + t2;
    t3.display(); // Fixed typo: `dipslay` to `display`

    if (t1 < t2) {
        cout << "The time 1 is earlier than time 2." << endl;
    } else {
        cout << "The time t2 is earlier than time 1." << endl; // Fixed typo: `<,` to `<<`
    }

    cout << "The time object is: " << t1 << endl;
    cout << "The time 2 object is: " << t2 << endl; // Fixed typo: `t1` to `t2`

    return 0;
}
