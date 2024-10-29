#include <iostream>

using namespace std;

class Temperature {
private:
    double degreesKelvin,
           degreesFahrenheit,
           degreesCelsius;
public:
    //Temperature Conversions
    void setTempKelvin(double Kelvin) {
        degreesKelvin = Kelvin;
        degreesCelsius = degreesKelvin - 273.15;
        degreesFahrenheit = (degreesCelsius * 9.0 / 5.0) + 32;
    }
    double getTempKelvin() {
        return degreesKelvin;
    }
    void setTempCelsius() {

    }
    double getTempCelsius() {
        return degreesCelsius;
    }
    void setTempFahrenheit() {

    }
    double getTempFahrenheit() {
        return degreesFahrenheit;
    }
};

int main() {
    //Variable Defined
    double Kelvin;
    //Class Object Defined
    Temperature temp;
    //Temperature Entered and Set
    cout << "Please enter a temperature in degrees Kelvin:";
    cin >> Kelvin;
    temp.setTempKelvin(Kelvin);
    //Temperature Conversions Displayed
    cout << endl << temp.getTempKelvin() << " Degrees Kelvin\n"
    << temp.getTempCelsius() << " Degrees Celsius\n"
    << temp.getTempFahrenheit() << " Degrees Fahrenheit\n";

    return 0;

}
