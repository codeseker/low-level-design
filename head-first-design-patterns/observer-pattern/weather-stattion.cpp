#include <bits/stdc++.h>
using namespace std;

// class WeatherData {
//     public:
//     int getTemperatur() {

//     }
//     int getHumidity() {

//     }
//     int getPressure() {

//     }

//     // This method is called automatically whenever something changes 
//     void measurementsChanged() {
//         /*
//             Naive Approach -> Get Updated Values
//         */
//        int temp = getTemperatur();
//        int humidity = getHumidity();
//        int pressure = getPressure();

//         // weatherDisplay.update(temp, humidity, pressure)
//         // statisticsDisplay.update(temp, humidity, pressure)
//         // forecastDisplay.update(temp, humidity, pressure)
//     }
// };

/*
    Correct code using Observer Pattern and also Support new Device addition
    in a scalable manner 
*/


class Observer {
public:
    virtual void update(int temp, int humidity, int pressure) = 0;
};

class DisplayDevice {
public:
    virtual void display() = 0;
};

class WeatherDisplay : public DisplayDevice, public Observer {
    int temp, humidity, pressure;

public:
    void update(int temp, int humidity, int pressure) override {
        this->temp = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    void display() override {
        cout << "Weather Display -> Temp: " << temp
             << " Humidity: " << humidity
             << " Pressure: " << pressure << endl;
    }
};

class StatisticsDisplay : public DisplayDevice, public Observer {
    int temp, humidity, pressure;

public:
    void update(int temp, int humidity, int pressure) override {
        this->temp = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    void display() override {
        cout << "Statistics Display -> Avg Temp: " << temp
             << " Humidity: " << humidity
             << " Pressure: " << pressure << endl;
    }
};

class ForecastDisplay : public DisplayDevice, public Observer {
    int temp, humidity, pressure;

public:
    void update(int temp, int humidity, int pressure) override {
        this->temp = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    void display() override {
        cout << "Forecast Display -> Temp: " << temp
             << " Humidity: " << humidity
             << " Pressure: " << pressure << endl;
    }
};

class Subject {
public:

    virtual void registerObserver(Observer* a) = 0;
    virtual void unregisterObserver(Observer* a) = 0;
    virtual void notify() = 0;
};

class WeatherData : public Subject {

    int temp;
    int humidity;
    int pressure;
    set<Observer*> observers;

public:
    int getTemperature() { return temp; }
    int getHumidity() { return humidity; }
    int getPressure() { return pressure; }

    void registerObserver(Observer* a) override {
        observers.insert(a);
    }

    void unregisterObserver(Observer* a) override {
        observers.erase(a);
    }


    void notify() override {
        int temp = getTemperature();
        int humidity = getHumidity();
        int pressure = getPressure();

        for (auto it : observers) {
            it->update(temp, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notify();
    }

    void setMeasurements(int t, int h, int p) {
        temp = t;
        humidity = h;
        pressure = p;

        measurementsChanged();
    }
};

int main() {

    WeatherData weatherStation;

    WeatherDisplay w;
    StatisticsDisplay s;
    ForecastDisplay f;

    weatherStation.registerObserver(&w);
    weatherStation.registerObserver(&s);
    weatherStation.registerObserver(&f);

    cout << "First Update\n";
    weatherStation.setMeasurements(30, 70, 1000);

    cout << "\nSecond Update\n";
    weatherStation.setMeasurements(25, 60, 990);

    return 0;
}