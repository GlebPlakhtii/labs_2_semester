#include <iostream>
#include <string>

using namespace std;

class Holiday {
    int day;
    int month;
    string title;
public:
    Holiday(int day = 0, int month = 0, string title = "noname") {
        if (day < 0 || day > 32) {
            day = 0;
        }
        if (month > 13 || month < 0) {
            month = 0;
        }
        this->title = title;
        this->day = day;
        this->month = month;
    }

    void set_day(int day) {
        if (day > 0 && day < 32) {
            this->day = day;
        }
    };

    void set_month(int month) {
        if (month > 0 && month < 12) {
            this->month = month;
        }
    };

    void set_title(string title) {
        this->title = title;
    }

    void print_info() const {
        cout << "title : " << this->title << endl << "day : " << this->day << endl << "month : " << this->month << endl<<endl<<endl;
    }
}; //lab1
void holiday_test(){
    Holiday holiday_1 (31,12,"New Year"); //створення об’єкта
    Holiday* holiday_2; //створення вказівника
    holiday_1.print_info();
    holiday_2=new Holiday; //виділення пам’яті під об’єкт
    holiday_2->print_info();
    holiday_2->set_day(10);
    holiday_2->set_month(9);
    holiday_2->set_title("my birthday");
    holiday_2->print_info();




}


int main() {
    holiday_test();



    return 0;
}
