#include <bits/stdc++.h>
using namespace std;

class PayRoll {
public:
    virtual double Money() =0;
    virtual ~PayRoll() {

    }
};

class Sales {
private:
    double sales;
public:
    Sales() {
        sales = 0;
    }

    void Setsales(double sales) {
        this->sales = sales;
    }

    double Getsales() const {
        return sales;
    }

    double Bonus() const {
        return sales * .02;
    }
};

class Employee : public PayRoll {
protected:
    string name;
    int id;
    Sales sales;
public:
    void SetName(const string& name) {
        this->name = name;
    }

    string GetName() const {
        return name;
    }

    void SetId(int id) {
        this->id = id;
    }

    int GetId() const {
        return id;
    }

    void SetSales(const Sales& s) {
        this->sales = s;
    }

    Sales GetSales() const {
        return sales;
    }
};

class Hourly_Employee : public Employee {
private:
    int hours;
    int salary_hour;
public:
    Hourly_Employee() {
        hours = 0;
        salary_hour = 0;
    }

    void SetSalary(int hours, int salary_hour) {
        this->hours = hours;
        this->salary_hour = salary_hour;
    }

    double Salary() const {
        double salary = hours * salary_hour;
        return salary;
    }

    double Money() override {
        return Salary() + sales.Bonus();
    }
};

class Based_Employee : public Employee {
private:
    int based_salary;
public:
    void SetBasedSalary(int based_salary) {
        this->based_salary = based_salary;
    }

    int GetBasedSalary() const {
        return based_salary;
    }

    double Salary() const {
        return based_salary;
    }

    double Money() override {
        return based_salary + sales.Bonus();
    }
};

class Invoices : public PayRoll {
private:
    int num_food;
    int price_food;
public:
    void SetNumFood(int num_food) {
        this->num_food = num_food;
    }

    int GetNumFood() const {
        return num_food;
    }

    void SetPriceFood(int price_food) {
        this->price_food = price_food;
    }

    int GetPriceFood() const {
        return price_food;
    }

    double Money() override {
        return num_food * price_food;
    }
};

double process(PayRoll* pay_roll) {
    double x=pay_roll->Money();
    return x;
}

class Pay {
private:
    vector<PayRoll*>pay_rolls_;
public:

    void pay(PayRoll* pay_roll) {
        pay_rolls_.push_back(pay_roll);
    }

};


int main() {



    return 0;
}
