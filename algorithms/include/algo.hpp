#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"

long fibonacci(const int n)
{ 
    /*if (n <= 1) return n;*/
    if (n == 0 || n == 1) {
        return n;
    }

    long a = 0;
    long b = 1;

    for (int i = 2; i <= n; i++) {
        long temp = a + b;
        a = b;
        b = temp;
    }

    return b;
    
}

int linear_search(Array * a, const int target)
{  
    for (size_t i = 0; i < a->len; ++i) { 
        if (a->data[i] == target) {
            return static_cast<int>(i);  
        }
    }
    return -1;  // Return -1 if not found
   
}

long factorial(const int n)
{ 
    if (n == 0)
    {
        return 1;
    } else {
        return n * factorial(n - 1);
    }


}

#endif // ALGO_H_
