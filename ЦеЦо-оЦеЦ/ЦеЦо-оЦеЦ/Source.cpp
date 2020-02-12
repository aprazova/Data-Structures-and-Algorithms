#include <iostream>
#include <string>
#include <algorithm>

int func(std::string wordOne, std::string wordTwo)
{
	int result = 0;
	if (wordOne.compare(wordTwo) == 0)
	{
		return result;
	}
	else
	{
		int lenWordOne = wordOne.length();
		int index = 0;
		int lenWordTwo = wordTwo.length();
		bool* visitedWordTwo = new bool[lenWordTwo];
		for (int i = 0;i < lenWordTwo;i++)
		{
			visitedWordTwo[i] = false;
		}
		int i = 0;
		bool temp;
		for (i; i < lenWordOne && index < lenWordTwo; i++)
		{
			temp = false;
			while (wordOne[i] > wordTwo[index] && index < lenWordTwo - 1)
			{
				index++;
			}
			if (wordOne[i] <= wordTwo[index])
			{
				visitedWordTwo[index] = true;
				int tempOne = (int)wordTwo[index] - (int)wordOne[i];
				result += tempOne;
				index++;
				temp = true;
			}
			if (temp == false)
			{
				break;
			}
		}
		index = 0;
		for (i;i < lenWordOne;i++)
		{
			while (visitedWordTwo[index] && index < lenWordTwo)
			{
				index++;
			}
			int tempOne = (int)wordTwo[index] - (int)wordOne[i];
			if (tempOne < 0)
			{
				tempOne += 26;
			}
			result += tempOne;
			index++;
		}
		return result;
	}
}

int main()
{
	int t;
	std::cin >> t;
	int* result = new int[t];
	std::string wordOne, wordTwo;

	for (size_t i = 0; i < t; i++)
	{
		std::cin >> wordOne >> wordTwo;
		std::sort(wordOne.begin(), wordOne.end());
		std::sort(wordTwo.begin(), wordTwo.end());
		result[i] = func(wordOne, wordTwo);
	}
	for (size_t i = 0; i < t; i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}