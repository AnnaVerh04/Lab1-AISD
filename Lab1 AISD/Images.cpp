#include <iostream>
#include "images.h"
#include <random>
using namespace std;

int main()
{
    int size_x, size_y;
    cout << "Enter the dimensions of the field" << endl;
    cout << "a: ";
    cin >> size_x;
    cout << "b: ";
    cin >> size_y;
    Image<bool> a(size_x, size_y, false);
    double x, y, r;
    cout << "Enter the coordinates and radius" << endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "r: ";
    cin >> r;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                a(i, j) = 1;
            }
        }
    }
    cout << a;
   
    
    
   /* Image<bool> a(3, 2, true);
    Image<bool> b(3, 2, true);

    try {
        Image<bool> c = a + b;
        cout << "a:\n" << a << "\nb:\n" << b << "\na+b:\n" << c;
    }
    catch (image_exception) {
        cout << "Incorrect sizes";
        return 0;
    }*/
}
