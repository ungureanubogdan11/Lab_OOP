#include <iostream>

union DummyUnion {
    int a; // 32 bits
    char c; // 8 bits
}; // 32 bits

struct DummyStruct {
    int a; // 32 bits
    char c; // 8 bits
}; // 40 bits

struct FructStruct {
    std::string nume;
    double gramaj;
};


class FructClass {

private:
    std::string nume{"no_name"};
    double gramaj{0};

public:
    FructClass(const std::string& nume, double gramaj) {
        this->nume = nume;
        this->gramaj = gramaj;

        std::cout << "constructor cu parametrii\n";
    }

    FructClass() {
        std::cout << "constructor fara parametrii\n";
    }

    FructClass& operator = (const FructClass& other) {
        this->nume = other.nume;
        this->gramaj = other.gramaj;

        return *this;
    }

    FructClass(const FructClass& fruit) {
        this->nume = fruit.nume;
        this->gramaj = fruit.gramaj;

        std::cout << "Constructor copiere\n";
    }

    void printInfo() {
        std::cout << this->nume << ' ' << this->gramaj << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, const FructClass& fruit) {
        os << fruit.nume << " " << fruit.gramaj << '\n';
        return os;
    }

    friend std::istream& operator>>(std::istream& is, FructClass& fruit) {
        is >> fruit.nume >> fruit.gramaj;
        return is;
    }

    ~FructClass() {
        std::cout << "obiectul " << nume << " a fost mancat!\n";
    }
};


int main()
{
    // DummyUnion dummy;
    // dummy.a = 97;
    // std::cout << dummy.c << '\n';
    // dummy.a = 98;
    // std::cout << dummy.a << '\n';

    FructClass fructClass1("mar", 105), fructClass2;
    fructClass1.printInfo();
    fructClass2.printInfo();

    FructClass fructClass3(fructClass1);
    fructClass3.printInfo();
    
    FructClass fructClass4;
    fructClass4.printInfo();
    fructClass4 = fructClass1;
    // fructClass4.operator=(fructClass1);  la fel ca linia de mai sus
    // fructClass4.printInfo();
    std::cout << fructClass4 << fructClass1;
    operator<<(operator<<(std::cout, fructClass4), fructClass1);

    std::cin >> fructClass1;
    std::cout << fructClass1;
    return 0;
}