#include <iostream>
#include <vector>
using namespace std;

struct stats {
	size_t copy_count = 0;
	size_t compare_count = 0;
};

stats bubble_sort(vector<int>& data);
stats shell_sort(vector<int>& data);
stats comb_sort(vector<int>& data);

stats bubble_sort(vector<int>& data) {
	stats result;
	for (size_t i = 0; i < data.size() - 1; i++)
		for (size_t j = 0; j < data.size() - 1 - i; j++)
		{
			result.compare_count++;
			if (data[j] > data[j + 1])
			{
				result.copy_count++;
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	return result;
}
stats shell_sort(vector<int>& data) {
	stats result;
	for (int step = data.size() / 2; step > 0; step /= 2) {
		for (int i = step; i < data.size(); i++) {
			for (int j = i - step; j >= 0 && data[j] > data[j + step]; j -= step) {
				result.compare_count++;
				if (data[j] < data[j + step]) {
					result.copy_count++;
					int buf = data[j];
					data[j] = data[j + step];
					data[j + step] = buf;
				}
			}
		}
	}
	return result;
}
stats comb_sort(vector<int>& data) {
	stats result;
	double factor = 1.2473309; // фактор уменьшения
	int step = data.size() - 1; // шаг сортировки

	//Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
	while (step >= 1)
	{
		for (int i = 0; i + step < data.size(); i++)
		{
			result.compare_count++;
			if (data[i] > data[i + step])
			{
				result.copy_count++;
				int buf = data[i];
				data[i] = data[i + step];
				data[i + step] = buf;
			}
		}
		step /= factor;
	}
	return result;
}

int main() {

	
	return 0;
}