#include <iostream>
#include <iomanip>

using namespace std;
//Class created
class GasPump {
private:
    double amountDispensed,
           amountCharged,
           costPerGallon;

public:
    double getAmountDispensed() { return amountDispensed; }
    double getAmountCharged() { return amountCharged; }
    double getCostPerGallon() { return costPerGallon; }
    void setCostPerGallon(double cpg) { costPerGallon = cpg; }
    //Calculates Dispensed Gas
    void dispense(int seconds) {
        const double dispense = 0.10;
        amountDispensed = dispense * seconds;
        amountCharged = amountDispensed * costPerGallon;
    }

};

int main() {
    //Define variables
    double cpg = 0.0, totalCost = 0.0, totalDispensed = 0.0;
    int seconds;
    //Define Class Object
    GasPump pump;
    string program;
    //Program that inputs cost per gallon and amount dispensed
    //and also has an operator end condition to shut down the pump
    //and display total operation values
    while (program != "End") {
        cout << "Enter cost per gallon:";
        cin >> cpg;
        if (cpg < 0) {
            cerr << "Cost per gallon must positive" << endl;
        }
        pump.setCostPerGallon(cpg);

        cout << "Enter duration to dispense in seconds:";
        cin >> seconds;
        if (seconds < 0) {
            cerr << "Duration must be positive" << endl;
        }
        pump.dispense(seconds);

        cout << endl << fixed << setprecision(2)
        << pump.getAmountDispensed() << " Gallons Dispensed \n"
        << "$" << pump.getCostPerGallon() << " Per Gallon\n"
        << "$" << pump.getAmountCharged() << " Fill Up Cost\n\n";

        totalCost += pump.getAmountCharged();
        totalDispensed += pump.getAmountDispensed();

        cout << "Enter a value to continue:";
        cin >> program;
        cout << endl;
    }
    //Total Value of Dispensed Gas and Cost throughout the operation
    cout << "$" << totalCost << " Total Cost" << endl
    << totalDispensed << " Total Gallons Dispensed";

    return 0;
}
