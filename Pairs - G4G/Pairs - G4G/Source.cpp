#include <iostream>
#include <algorithm>

int func(int* array, int n)
{
	int index = n - 1;
	int result = 0;
	for (index; index > 0;index -= 2)
	{
		if (array[index - 1] > 1)
		{
			result += (array[index] * array[index - 1]);
		}
		else
		{
			break;
		}
	}
	if (array[index] > 1)
	{
		result += array[index];
		index--;
	}
	while (index >= 0 && array[index] == 1)
	{
		result += array[index];
		index--;
	}
	int k = 1;
	for (k; k <= index && array[k] < 0; k += 2)
	{
		result += (array[k] * array[k - 1]);
	}
	if (k - 1 == index)
	{
		result += array[k - 1];
	}
	return result;
}

int main()
{
	int t, n;
	std::cin >> t;
	int* result = new int[t];
	for (size_t i = 0; i < t; i++)
	{
		std::cin >> n;
		int* array = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> array[j];
		}
		std::sort(array, array + n);
		result[i] = func(array, n);
	}
	for (size_t i = 0; i < t; i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}