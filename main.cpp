#include <iostream>
#include <iomanip>
#include <cmath>

int factorial(int l)
{
    int result = 1;
    for(int i=1; i<(l+1); ++i)
    {
        result*=i;
    }
    return result;
}

int main() {
    int k;
    double x;
    double coss = 1, eps = 1, sl=1;
    int l=1;
    bool f=1;
    std::cout << "Enter x: " << std::endl;
    std::cin >> x;
    std::cout << "Enter k: " << std::endl;
    std::cin >> k;

    for (int i=0; i<(k+1); i++) { //подсчёт эпсилон
        eps= eps/10;
    }
    std::cout << "eps = " <<eps << std::endl;
    std::cout << std::endl;

    while (x<=0)
        x+=360;
    while (x>=360)
        x-=360;

    if ((x > 90) && (x <= 180)){
        x=180-x;
        f=0;
    }
    else {
        if ((x > 180) && (x <= 270)) {
            x = x - 180;
            f=0;
        }
        else {
            if ((x > 270) && (x <= 360)) {
                x = 360 - x;
            }
        }
    }

    x=x*M_PI/180; //перевод в радианы

    while (eps < sl)
    {
        sl=pow(x, 2*l);
        sl= sl/factorial(2*l);
        if( l%2 == 1)
        {
            coss= coss - sl;
        }
        else
        {
            coss = coss + sl;
        }
        l++;
    }

    if (f==1) {
        std::cout << std::setprecision(k + 1) << "using formula: " << coss << std::endl;
        std::cout << std::setprecision(k + 1) << "using cos() function: " << cos(x);
    }
    else{
        std::cout << std::setprecision(k + 1) << "using formula: -" << coss << std::endl;
        std::cout << std::setprecision(k + 1) << "using cos() function: -" << cos(x);
    }
    return 0;
}
