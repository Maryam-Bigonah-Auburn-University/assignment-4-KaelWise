#include <iostream>
#include <cstdlib> // for exit()
#include <cctype>  // for tolower()

using namespace std;

class Month {
public:
    int month;

    Month() {
        month = 1;
    }
    Month(int monthNumber) {
        month = monthNumber;
    }
    Month (char c1, char c2, char c3) {
        if ((c1 == 'j') && (c2 == 'a') && (c3 == 'n')) {
            month = 1;
        }
        if ((c1 == 'f') && (c2 == 'e') && (c3 == 'b')) {
            month = 2;
        }
        if ((c1 == 'm') && (c2 == 'a') && (c3 == 'r')) {
            month = 3;
        }
        if ((c1 == 'a') && (c2 == 'p') && (c3 == 'r')) {
            month = 4;
        }
        if ((c1 == 'm') && (c2 == 'a') && (c3 == 'y')) {
            month = 5;
        }
        if ((c1 == 'j') && (c2 == 'u') && (c3 == 'n')) {
            month = 6;
        }
        if ((c1 == 'j') && (c2 == 'u') && (c3 == 'l')) {
            month = 7;
        }
        if ((c1 == 'a') && (c2 == 'u') && (c3 == 'g')) {
            month = 8;
        }
        if ((c1 == 's') && (c2 == 'e') && (c3 == 'p')) {
            month = 9;
        }
        if ((c1 == 'o') && (c2 == 'c') && (c3 == 't')) {
            month = 10;
        }
        if ((c1 == 'n') && (c2 == 'o') && (c3 == 'v')) {
            month = 11;
        }
        if ((c1 == 'd') && (c2 == 'e') && (c3 == 'c')) {
            month = 12;
        }
    }
    void input () {
        cout << endl << "Month number :";
        cin >> month;
        while (month < 1 || month > 12) {
            cout << endl << "Invalid month number. Chose a value between 1 and 12.";
            cin >> month;
        }
    }
    void inputMonthLetter(istream& in) {
        char letter[4];
        cout << endl << "Enter the first three letters of the month:";
        in >> letter;
        Month (letter[0], letter[1], letter[2]);
        
    }
    int getMonth () {
        return month;
    }

    void outputMonthName(ostream& out) {
        const char* monthNames[] = {"The month is January", "The month is February",
            "The month is March", "The month is April", "The month is May",
            "The month is June","July", "The month is August", "The month is September",
            "The month is October", "The month is November", "The month is December"};
        out << monthNames[month - 1];
    }

    Month nextMonth () {
        int m = ((month % 12 ) +1);
        return Month (m);
    }
};

int main () {
    Month m1, m3;

    m1.input();
    m1.outputMonthName(cout);

    m3=m1.nextMonth();
    cout << endl << "The next month is:" << m3.getMonth();

    Month m2, m4;
    m2.inputMonthLetter(cin);
    m2.outputMonthName(cout);

    m4 = m2.nextMonth();
    cout << endl << "The next month is:" << m4.getMonth();
    return 0;
}
