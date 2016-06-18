/*
You are a waiter at a party. There are N stacked plates. Each plate has a number written on it. You start picking up the plates from the top one by one and check whether the number written on the plate is divisible by P(a prime). The starting value of P is 2. If the number is divisible, you stack that plate separately with other P divisible plates. If not, you stack that plate separately with the other plates that are not divisible by P.

Sample Input
5 1
3 4 7 6 5

Sample Output
4
6
3
7
5
*/
#include <stack>
#include <iostream>
using namespace std;

/*
input a prime and find the next prime
http://stackoverflow.com/questions/4475996/given-prime-number-n-compute-the-next-prime
*/
static const std::size_t small_primes[] ={2,3,5,7,11,13,17,19,23,29};

static const std::size_t indices[] ={1,7,11,13,17,19,23,29};

bool is_prime(std::size_t x){
    const size_t N = sizeof(small_primes) / sizeof(small_primes[0]);
    for (std::size_t i = 3; i < N; ++i)
    {
        const std::size_t p = small_primes[i];
        const std::size_t q = x / p;
        if (q < p)
            return true;
        if (x == q * p)
            return false;
    }
    for (std::size_t i = 31; true;)
    {
        std::size_t q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 6;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 4;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 6;

        q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
        i += 2;
    }
    return true;
}

std::size_t next_prime(std::size_t n){
    const size_t L = 30;
    const size_t N = sizeof(small_primes) / sizeof(small_primes[0]);
    // If n is small enough, search in small_primes
    if (n <= small_primes[N-1])
        return *std::lower_bound(small_primes, small_primes + N, n);
    // Else n > largest small_primes
    // Start searching list of potential primes: L * k0 + indices[in]
    const size_t M = sizeof(indices) / sizeof(indices[0]);
    // Select first potential prime >= n
    //   Known a-priori n >= L
    size_t k0 = n / L;
    size_t in = std::lower_bound(indices, indices + M, n - k0 * L) - indices;
    n = L * k0 + indices[in];
    while (!is_prime(n))
    {
        if (++in == M)
        {
            ++k0;
            in = 0;
        }
        n = L * k0 + indices[in];
    }
    return n;
}


void calcStackPrimes (stack<int>& stk1, int& Q){
    int prime = 2;
    //need total of 3 stacks for algorithm
    stack<int> stk2, DivP;
    stack<int> &source = stk1, &nonDivP = stk2;
    
    for (int i=0; i<Q; ++i){
        //check the plates from the pile that were not divisible by in the last iteration.
        while(!source.empty()){
            if(source.top()%prime == 0)
                DivP.push(source.top());
            else
                nonDivP.push(source.top());
            source.pop();
        }
        //pop and print every element from DivP stack
        while(!DivP.empty()){
            cout << DivP.top() << endl;
            DivP.pop();
        }
        //swap source and nonDivP for next step
        source.swap(nonDivP);
        
        //get next prime
        prime = next_prime(prime+1);
    }
    //print the remaining elements in source
    while(!source.empty()){
        cout << source.top() << endl;
        source.pop();
    }
    return;
}


int main() {
    int N, Q;
    stack<int> plates;
    cin >> N >> Q;

    while (cin >> N){
        plates.push(N);
    }

    calcStackPrimes(plates, Q);
 
    return 0;
}
