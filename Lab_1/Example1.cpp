#include "BigInt.h"
using namespace std;


int main()
{
    string n, m;
    bool cycle = true, comp;
    int b, c;
    BigInt A, B, C;
    do
    {
        cout << "Choose the operation:\n\t1) Convert big int to int\n\t2) Big int + big int\n\t3) Big int + int\n\t4) Big int - big int" <<
            "\n\t5) Big int - int\n\t6) Big int * big int\n\t7) Big int * int\n\t8) Big int / big int\n\t9) Big int / int\n\t10) Preincrement\n\t" <<
            "11) Postincrement\n\t12) Predecrement\n\t13) Postdecrement\n\t14) Big int ? big int\n\t15) Big int ? int\n\t16) Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "A = " << A.getNum() << endl;
            c = A.TransformBigInt();
            cout << "a = " << c << endl;
            break;
        case 2:
            cout << "Enter big int number: ";
            cin >> n >> m;
            A.setNum(n);
            B.setNum(m);
            cout << "A = " << A.getNum() << endl;
            cout << "B = " << B.getNum() << endl;
            C = A + B;
            cout << "A + B = " << C.getNum() << endl;
            C += A;
            cout << "+= A = " << C.getNum() << endl;
            break;
        case 3:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "Enter int number: ";
            cin >> b;
            cout << "A = " << A.getNum() << endl;
            cout << "b = " << b << endl;
            C = A + b;
            cout << "A + b = " << C.getNum() << endl;
            C += b;
            cout << "+= b = " << C.getNum() << endl;
            break;
        case 4:
            cout << "Enter big int number: ";
            cin >> n >> m;
            A.setNum(n);
            B.setNum(m);
            cout << "A = " << A.getNum() << endl;
            cout << "B = " << B.getNum() << endl;
            C = A - B;
            cout << "A - B = " << C.getNum() << endl;
            C -= A;
            cout << "-= A = " << C.getNum() << endl;
            break;
        case 5:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "Enter int number: ";
            cin >> b;
            cout << "A = " << A.getNum() << endl;
            cout << "b = " << b << endl;
            C = A - b;
            cout << "A - b = " << C.getNum() << endl;
            C -= b;
            cout << "-= b = " << C.getNum() << endl;
            break;
        case 6:
            cout << "Enter big int number: ";
            cin >> n >> m;
            A.setNum(n);
            B.setNum(m);
            cout << "A = " << A.getNum() << endl;
            cout << "B = " << B.getNum() << endl;
            C = A * B;
            cout << "A * B = " << C.getNum() << endl;
            C *= A;
            cout << "*= A = " << C.getNum() << endl;
            break;
        case 7:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "Enter int number: ";
            cin >> b;
            cout << "A = " << A.getNum() << endl;
            cout << "b = " << b << endl;
            C = A * b;
            cout << "A * b = " << C.getNum() << endl;
            C *= b;
            cout << "*= b = " << C.getNum() << endl;
            break;
        case 8:
            cout << "Enter big int number: ";
            cin >> n >> m;
            A.setNum(n);
            B.setNum(m);
            cout << "A = " << A.getNum() << endl;
            cout << "B = " << B.getNum() << endl;
            C = A / B;
            cout << "A / B = " << C.getNum() << endl;
            C /= B;
            cout << "/= B = " << C.getNum() << endl;
            break;
        case 9:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "Enter int number: ";
            cin >> b;
            cout << "A = " << A.getNum() << endl;
            cout << "b = " << b << endl;
            C = A / b;
            cout << "A / b = " << C.getNum() << endl;
            C /= b;
            cout << "/= b = " << C.getNum() << endl;
            break;
        case 10:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "A = " << A.getNum() << endl;
            C = ++A;
            cout << "++A = " << C.getNum() << endl;
            break;
        case 11:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "A = " << A.getNum() << endl;
            C = A++;
            cout << "A++ = " << C.getNum() << endl;
            cout << "A = " << A.getNum() << endl;
            break;
        case 12:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "A = " << A.getNum() << endl;
            C = --A;
            cout << "--A = " << C.getNum() << endl;
            break;
        case 13:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "A = " << A.getNum() << endl;
            C = A--;
            cout << "A-- = " << C.getNum() << endl;
            cout << "A = " << A.getNum() << endl;
            break;
        case 14:
            cout << "Enter big int number: ";
            cin >> n >> m;
            A.setNum(n);
            B.setNum(m);
            cout << "A = " << A.getNum() << endl;
            cout << "B = " << B.getNum() << endl;
            comp = A > B;
            cout << "A > B is " << boolalpha << comp << endl;
            comp = A < B;
            cout << "A < B is " << comp << endl;
            comp = A >= B;
            cout << "A >= B is " << comp << endl;
            comp = A <= B;
            cout << "A <= B is " << comp << endl;
            break;
        case 15:
            cout << "Enter big int number: ";
            cin >> n;
            A.setNum(n);
            cout << "Enter int number: ";
            cin >> b;
            cout << "A = " << A.getNum() << endl;
            cout << "b = " << b << endl;
            comp = A > b;
            cout << "A > b is " << boolalpha << comp << endl;
            comp = A < b;
            cout << "A < b is " << comp << endl;
            comp = A >= b;
            cout << "A >= b is " << comp << endl;
            comp = A <= b;
            cout << "A <= b is " << comp << endl;
            break;
        case 16:
            cycle = false;
            break;
        default:
            cout << "There is not such operation!\n";
            break;
        }
    } while (cycle);
}
