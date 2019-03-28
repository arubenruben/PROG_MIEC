#include <iostream>
#include <cmath>

using namespace std;


int main(){


    int n;
    int multiplo=0;
    int shutdown=0;

    for (int k = 2; k <= 1000; k++)
    {
        shutdown=0;

        for (int i = 2; i <= sqrt(k); i++)
        {
            multiplo = 0;

            for (int j = 1; multiplo < k; j++)
            {

                multiplo = i * j;

                if (multiplo == k)
                {
                    shutdown = 1;
                    break;
                }
            }

            if (shutdown == 1)
            {
                break;
            }
        }

        if (shutdown == 0)
        {
            cout << k << " ";
        }
    }
    return 0;
}
