#include <iostream>
#include <limits>
#include "cyclicqueue.h"

using namespace std;

int input(){
    int tmp;
    cin >> tmp;
    while(cin.fail()) {
        cout << "Enter a number/:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> tmp;
    }
    return tmp;
}
void test(){ 
        CyclicQueue queue(5);
        queue.print();
        CyclicQueue test = (queue + 0);
        test.print();
        std::cout << "1) test = queue - 1;" << std::endl;
        test = queue - 1;
        test.print();
        queue.print();
        std::cout << "2) test = queue / 2;" << std::endl;
        test = queue / 2;
        test.print();
        queue.print();
        std::cout << "3) test = queue++;" << std::endl;
        test = queue++;
        test.print();
        queue.print();
        std::cout << "4) test = queue--;" << std::endl;
        test = queue--;
        test.print();
        queue.print();
        std::cout << "5) test = ++queue;" << std::endl;
        test = ++queue;
        test.print();
        queue.print();
        std::cout << "6) test = --queue;" << std::endl;
        test = --queue;
        test.print();
        queue.print();

        std::cout << "7) queue = test;" << std::endl;
        queue = test;
        test.print();
        queue.print();
        std::cout << "8) test = queue;" << std::endl;
        test = queue;
        test.print();
        queue.print();

        std::cout << "9) int _int = queue[0];" << std::endl;
        int _int = queue[0];
        std::cout << _int << std::endl;
        test.print();
        queue.print();

        bool res;
        std::cout << "10) queue == queue" << std::endl;
        res = queue == queue;
        cout << res << endl;

        std::cout << "11) test == queue" << std::endl;
        res = test == queue;
        cout << res << endl;

        std::cout << "12) queue >= test;" << std::endl;
        res = queue >= test;
        cout << res << endl;

        std::cout << "13) queue <= test;" << std::endl;
        res = queue <= test;
        cout << res << endl;

        std::cout << "14) test < queue;" << std::endl;
        res = test < queue;
        cout << res << endl;

        std::cout << "15) test > queue;" << std::endl;
        res = test > queue;
        cout << res << endl;

        std::cout << "16) queue != queue;" << std::endl;
        res = queue != queue;
        cout << res << endl;

        std::cout << "17) 5 >= queue;" << std::endl;
        res = 5 >= queue;
        cout << res << endl;

        std::cout << "18) queue <= queue;" << std::endl;
        res = queue <= queue;
        cout << res << endl;

        std::cout << "19) queue < queue;" << std::endl;
        res = queue < queue;
        cout << res << endl;

        std::cout << "20) queue > queue;" << std::endl;
        res = queue > queue;
        cout << res << endl;

        std::cout << "21) queue != queue;" << std::endl;
        res = queue != queue;
        cout << res << endl;
}

void help() {
    cout << "0 - Add new number to queues" << endl;
    cout << "1 - Pop a number from queues" << endl;
    cout << "2 - Increase all numbers"     << endl;
    cout << "3 - Decrease all numbers"     << endl;
    cout << "4 - Reset queues"             << endl;
    cout << "5 - Run the tests"            << endl;
    cout << "6 - Quit the program"         << endl;
}
int run(){
    cout << "You a running Lab2 program" << endl;
    cout << "Enter a CyclicQueue size: " << endl << endl;
    int size = input();
    help();
    CyclicQueue a(size);
    CyclicQueue b(size);
    while (true) {
        int in;
        
        cout << "> ";
        in = input();
        try {
            switch (in) {
            case 0: 
                b = ++a;
                b.print();
                a.print();
                break;
            case 1: 
                b = --a;
                b.print();
                a.print();
                break;
            case 2: 
                b = a++;
                b.print();
                a.print();
                break;
            case 3: 
                b = a--;
                b.print();
                a.print();
                break;
            case 4: 
                b = CyclicQueue(size);
                a = CyclicQueue(size);
                b.print();
                a.print();
                break;
            case 5:
                test(); break;
            case 6:
                return 0;
            default:
                help();
            }
        } catch (string ex) {
            cout << ex << endl;
        }
    }
}


int main()
{
    run();
    return 0;
}
