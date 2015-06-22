#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

template<class T>
T input()
{
	T value;
	std::cin >> value;
	return value;
}

template<class T>
void bogoSort(T Itr)
{
	while (!std::is_sorted(std::begin(Itr), std::end(Itr)))
	{
		std::random_shuffle(std::begin(Itr), std::end(Itr));
		for (auto Elem : Itr)
			std::cout << Elem << " ";
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> Vec;
	int num;
	std::cin >> num;

	for (int i = 0; i < num; ++i)
		Vec.push_back(input<int>());

	auto start = std::chrono::system_clock::now();

	bogoSort(Vec);

	auto end = std::chrono::system_clock::now();

	std::cout << "ˆ—ŽžŠÔF" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "msec" << std::endl;
	return 0;
}