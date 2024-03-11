#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public exception{
public:
    explicit MyException(const char* message): m_message(message){}

    [[nodiscard]] const char* what() const noexcept override{
        return m_message;
    }
private:
   const char* m_message;
};

void checkValue(int value){
    if(value < 0 || value > 100){
        throw range_error("\n\nWartosc spoza zakresu!");
    }
    cout << "\n\nWartosc jest w zakresie.";
}

float division(int a, int b){
    if(b==0){
        throw MyException("\n\nNie dziel przez zero");
    }
    return (float)a/(float)b;
}

int main(){
    int x, y;
    cout << "\n\nPodaj liczby w zakresie 0-100: ";
    cin >> x >> y;
    try {
        checkValue(x);
        checkValue(y);
        cout << "\n\nWynik dzielenia to: " << division(x,y) << endl;
    } catch (const range_error& e) {
        cerr << "\n\nWyjatek: " << e.what() << endl;
    } catch (const MyException& e) {
        cerr << "\n\nWyjatek: " << e.what() << endl;
    }
    return 0;
}