#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool Settingsmap(int& x, int& y, int& varrange) {
    //--MAP--
    cout << "--Map--" << endl;
    cout << "(width)x=:";
    cin >> x;
    cout << "(height)y=:";
    cin >> y;
    cout << "(radius of variables)varrange=:";
    cin >> varrange;
    if ((x != 0) and (y != 0) and (varrange != 0)) {
        return true;
    } else {
        return false;
    }  
}

bool ReadDefaultMapValues(int& x, int& y, int& varrange) {
    ifstream file("default.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open default.txt file!" << endl;
        return false;
    }
    
    string line;
    bool inMapSection = false;
    
    while (getline(file, line)) {
        // Проверяем начало секции Map
        if (line.find("--Map--") != string::npos) {
            inMapSection = true;
            continue;
        }
        
        // Проверяем конец секции Map
        if (line.find("----") != string::npos && inMapSection) {
            break;
        }
        
        // Если мы в секции Map, читаем значения
        if (inMapSection) {
            if (line.find("x=") != string::npos) {
                x = stoi(line.substr(line.find("=") + 1));
            } else if (line.find("y=") != string::npos) {
                y = stoi(line.substr(line.find("=") + 1));
            } else if (line.find("varrange=") != string::npos) {
                varrange = stoi(line.substr(line.find("=") + 1));
            }
        }
    }
    
    file.close();
    return (x != 0 && y != 0 && varrange != 0);
}

int main() {
    bool debugging = true;
    int x = 0, y = 0, varrange = 0;
    int defx = 111, defy = 111, defvarrange = 2;
    cout << "Hello I app for fast create game." << endl;

    if(debugging) {
        cout << "Let's start with the basic setup." << endl;
        
        char choice;
        cout << "Use default map data? (y/n): ";
        cin >> choice;
        
        if(choice == 'y' || choice == 'Y') {
            // Чтение данных по умолчанию из файла
            if(ReadDefaultMapValues(x, y, varrange)) {
                cout << "Using default values from file: x=" << x << ", y=" << y << ", varrange=" << varrange << endl;
            } else {
                cout << "Error reading default values! Using fallback defaults." << endl;
                x = defx;
                y = defy;
                varrange = defvarrange;
            }
        } else {
            // Запрос пользовательских значений
            if(Settingsmap(x, y, varrange)) {
                cout << "Custom values set." << endl;
            } else {
                cout << "Invalid values! Using defaults from file." << endl;
                if(!ReadDefaultMapValues(x, y, varrange)) {
                    cout << "Error reading default values! Using fallback defaults." << endl;
                    x = defx;
                    y = defy;
                    varrange = defvarrange;
                }
            }
        }
        
        cout << "Final values: x=" << x << " y=" << y << " varrange=" << varrange << endl;
    }
    else {
        //main.cpp
    }
    return 0;
}
