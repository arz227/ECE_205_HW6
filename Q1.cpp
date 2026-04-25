#include <iostream> 
#include <vector>

using namespace std;

// function to find maximum value in vector
int findMax(vector<int> myVector);

int main()
{
	char choice = 'y';   // control loop

	// loop so program can run multiple times
	while (choice == 'y' || choice == 'Y')
	{
		vector<int> myVector;   // store user input
		int number;

		cout << "Please enter a non-negative integer: " << endl;
		cin >> number;

		// keep taking input until negative number
		while (number >= 0)
		{
			myVector.push_back(number);   // add to vector

			cout << "Please enter a non-negative integer: " << endl;
			cin >> number;
		}

		// check if user entered at least one number
		if (myVector.size() > 0)
		{
			int max = findMax(myVector);   // get max value

			// create histogram bins (each bin size = 10)
			vector<int> histogram(max / 10 + 1, 0);

			// count how many numbers fall in each bin
			for (int i = 0; i < myVector.size(); i++)
			{
				// divide by 10 to find bin index
				histogram[myVector[i] / 10]++;
			}

			// display histogram
			for (int i = 0; i < histogram.size(); i++)
			{
				// show range and count
				cout << i * 10 << "-" << i * 10 + 9 << ": " << histogram[i] << endl;
			}
		}
		else
		{
			cout << "No numbers entered." << endl;
		}

		// ask user if they want to repeat
		cout << "Do you want to continue? (y/n): ";
		cin >> choice;
	}

	return 0;
}

// function to find max value
int findMax(vector<int> myVector)
{
	int max = 0;

	// loop through all elements
	for (int i = 0; i < myVector.size(); i++)
	{
		if (myVector[i] > max)
			max = myVector[i];   // update max
	}

	return max;
}
