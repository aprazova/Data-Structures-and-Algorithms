#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
	std::vector<std::string> vec;
	std::unordered_map<std::string, int> result;
	std::string letter;
	for (int i = 0;i < 2;i++)
	{
		std::getline(cin, letter);
		int len = letter.length();
		std::string word;
		for (int j = 0;j < len;j++)
		{
			if (letter[j] == ' ')
			{
				vec.push_back(word);
				result[word] = 0;
				word = "\0";
			}
			else
			{
				word += letter[j];
			}
		}
		if (word[word.length() - 1] != ' ')
		{
			vec.push_back(word);
			result[word] = 0;
			word = "\0";
		}
	}
	for (int i = 0;i < vec.size();i++)
	{
		result[vec[i]]++;
	}
	std::sort(vec.begin(), vec.end());
	for (int i = 0;i < vec.size();i++)
	{

		if (result[vec[i]] == 1)
		{
			std::cout << vec[i] << "\n";
		}
	}
	return 0;
}
