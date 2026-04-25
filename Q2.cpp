#include <iostream>
#include <vector>

using namespace std;

// remove duplicate characters
vector<char> deleteRepeatedChars(vector<char> myVector);

// sort in descending order
vector<char> selectionSort(vector<char> myVector);

int main()
{
	char choice = 'y';   // loop control

	// loop so program keeps running
	while (choice == 'y' || choice == 'Y')
	{
		vector<char> myVector;   // store characters
		char input;

		cout << "Please enter a char, enter 0 to quit: " << endl;
		cin >> input;

		// input characters until '0'
		while (input != '0')
		{
			myVector.push_back(input);   // add char to vector

			cout << "Please enter a char, enter 0 to quit: " << endl;
			cin >> input;
		}

		// remove duplicates
		myVector = deleteRepeatedChars(myVector);

		// sort in descending order (z to a)
		myVector = selectionSort(myVector);

		cout << "Array with repeated char's removed and inversed:" << endl;

		// display final result
		for (int i = 0; i < myVector.size(); i++)
			cout << myVector[i] << endl;

		// ask user to continue
		cout << "Do you want to continue? (y/n): ";
		cin >> choice;
	}

	return 0;
}

// function to remove duplicates
vector<char> deleteRepeatedChars(vector<char> myVector)
{
	// outer loop selects each element
	for (int i = 0; i < myVector.size(); i++)
	{
		// compare with next elements
		for (int j = i + 1; j < myVector.size(); j++)
		{
			if (myVector[i] == myVector[j])   // duplicate found
			{
				// shift all elements left
				for (int k = j; k < myVector.size() - 1; k++)
					myVector[k] = myVector[k + 1];

				// reduce size of vector
				myVector.resize(myVector.size() - 1);

				j--;   // stay at same index to recheck
			}
		}
	}

	return myVector;
}

// selection sort (descending)
vector<char> selectionSort(vector<char> myVector)
{
	int maxIndex;
	char temp;

	// move boundary one by one
	for (int i = 0; i < myVector.size() - 1; i++)
	{
		maxIndex = i;   // assume current index is max

		// find max element
		for (int j = i + 1; j < myVector.size(); j++)
		{
			if (myVector[j] > myVector[maxIndex])
				maxIndex = j;
		}

		// swap current with max
		temp = myVector[i];
		myVector[i] = myVector[maxIndex];
		myVector[maxIndex] = temp;
	}

	return myVector;
}
