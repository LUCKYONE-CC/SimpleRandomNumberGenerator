#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

int GenerateRandom(long, int);

int main()
{
	cout << "Please move your mouse around the screen to generate a random number after you typed in the length.\n";
	cout << "Please enter the desired length of the randomly generated number: ";

	int size = 0;

	cin >> size;

	long seed = 0;

	auto start = chrono::high_resolution_clock::now();
	auto duration = chrono::seconds(5);

	while (chrono::high_resolution_clock::now() - start < duration) {
		POINT MousePoint;
		if (GetCursorPos(&MousePoint)) {

			seed += MousePoint.x;
			seed -= MousePoint.y;
			cout << seed << endl;
		}
	}

	int random = GenerateRandom(seed, size);

	cout << "The random number is: " << random << endl;

	return 0;
}

int GenerateRandom(long seed, int size)
{
	return (seed * 3 + 7) % size;
}