#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Vector to store prime numbers
	vector<long long> primes;
	// Generate prime numbers up to 100,000
	for (long long i = 2; i <= 100000; i++) // O(10^5)
	{
		bool is_prime = true;
		// Check if 'i' is a prime number
		for (long long j = 2; j * j <= i; j++) // O(sqrt(10^5)) = O(10^2)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		// If 'i' is prime, add it to the list of primes
		if (is_prime)
			primes.push_back(i);
	}
	// Total complexity for generating primes: O(10^5 * 10^2) = O(10^7)

	int t;
	cin >> t;

	while (t--) // O(3000)
	{
		long long d;
		cin >> d;

		long long p = -1;
		// Find the smallest prime >= (1 + d)
		for (long long i = 0; i < primes.size(); i++) // O(9000)
		{
			if (primes[i] >= (1 + d))
			{
				p = primes[i];
				break;
			}
		}
		long long q = -1;
		// Find the smallest prime >= (p + d)
		for (long long i = 0; i < primes.size(); i++) // O(9000)
		{
			if (primes[i] >= (p + d))
			{
				q = primes[i];
				break;
			}
		}

		// Calculate the smallest number 'a' with at least 4 divisors
		long long a = min(1LL * p * p * p, 1LL * p * q);
		cout << a << endl;
	}
}

// Time Complexity (TC): O(10^7) + O(3000 * 9000) = O(10^7) + O(3 * 10^7) = O(10^7)
// Space Complexity (SC): O(10^4)
