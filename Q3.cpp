#include <iostream> 
#include <vector>

using namespace std;

// function to find prime numbers using sieve algorithm
void SieveOfEratosthenes(int n);

int main() 
{
	char choice = 'y';   // controls repeating the program

	// loop so program keeps running
	while (choice == 'y' || choice == 'Y')
	{
		int n;

		cout << "Enter a number to see the primes lower than it: ";
		cin >> n;
		cout << endl;


		// INPUT VALIDATION
		
		// if user enters negative or small number,
		// program will keep asking until valid input
		while (n <= 2)
		{
			cout << "Wrong number, try again." << endl;

			cout << "Enter a number to see the primes lower than it: ";
			cin >> n;
			cout << endl;
		}

		// call sieve function after valid input
		SieveOfEratosthenes(n);

		// ask user if they want to repeat
		cout << "Do you want to continue? (y/n): ";
		cin >> choice;
	}

	return 0;
}


// SIEVE OF ERATOSTHENES FUNCTION

void SieveOfEratosthenes(int n) 
{
	// create vector of size n
	// all values initially set to TRUE (assume prime)
	vector<bool> primes(n, true);

	// 0 and 1 are NOT prime numbers
	primes[0] = false;
	primes[1] = false;

	// loop from 2 up to sqrt(n)
	// i * i < n avoids unnecessary checks
	for (int i = 2; i * i < n; i++)
	{
		// if current number is still marked as prime
		if (primes[i])
		{
			// mark all multiples of i as NOT prime
			// start from i*i (smaller multiples already handled)
			for (int j = i * i; j < n; j = j + i)
			{
				primes[j] = false;
			}
		}
	}

	
	// DISPLAY PRIME NUMBERS
	
	cout << "Prime numbers lower than " << n << ":" << endl;

	for (int i = 2; i < n; i++)
	{
		// print only numbers still marked true
		if (primes[i])
			cout << i << endl;
	}
}
