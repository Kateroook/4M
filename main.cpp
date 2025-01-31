#include <iostream>
#include <cmath>


using namespace std;

double APPROXIMATION = 0.0001;
double ROOT = 7;
double A = -3, B = -1.11051; //segment

double function (double x)
{
    double result = pow(x,2) + 5* sin(x) -1;
    return result;
}

int signum(double x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

double derivative (double x)
{
    double result = 2*x + 5*cos(x);
    return result;
}


void dichotomy(){
    cout << "Dichotomy method: \n\n";

    printf("%2s %15s %15s %15s %15s\n", "n", "a_n", "x_n", "b_n", "f(x_n)");


    double x_n;
    int i = 1;
    while (true)
    {
        x_n = (A + B) / 2.0;
        printf("%2d %15f %15f %15f %15f\n", i, A, x_n, B, function(x_n));

        if (abs(B-A) < APPROXIMATION || function(x_n) == 0)
        {
            break;
        }

        if (signum(function(x_n)) == signum(function(A)))
        {
            A = x_n;
        }
        if(signum(function(x_n)) == signum(function(B)))
        {
            B = x_n;
        }
        i++;
    }
    //Output
    cout << "\nApproximate root: " << x_n << endl;
};

void newtonModified()
{
    cout << "Modified Newton's method  \n\n";

    printf("%2s %15s %15s\n", "n", "x_n", "f(x_n)");

    double x0 = -2.23;
    double x = A;
    double derivative_of_x0 = derivative(x0);

    for (int i = 0; i < ROOT; ++i)
    {
        x -= function(x)/derivative_of_x0;
        printf("%2d %15f %15f\n", i+1, x, function(x));
    }

    //Output
    cout << "\nApproximate root: " << x << endl;
}

int main() {
    dichotomy();
    //newtonModified();
    return 0;
}
