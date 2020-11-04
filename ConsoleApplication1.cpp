#include <iostream>

using namespace std;

int main()
{
	const unsigned int max = 1000;

	int numbers[max];
	int number;

	bool stop = false;

	string fun;

	int tab_size = 0;
	while (!stop)
	{
		cin >> fun;		

		if (fun == "A") {
			cin >> number;
			if (tab_size < max) {
				numbers[tab_size] = number;
				tab_size++;
			}
			else {
				cout << "FULL\n";
			}
		}
		else if (fun == "E") {
			int sum = 0;

			for (int x = 0; x < tab_size; x++) {
				sum += numbers[x];
			}

			double average = float(sum) / float(tab_size);
			cout << average << endl;

		}
		else if (fun == "P") {
			int indexs[max] = {};
			int new_numbers[max] = {};
			bool repeat[max] = {};
			
			int i = 0;
			for (int x = 0; x < tab_size; x++) {
				int counter = 0;
				int check = 0;
				while (counter < tab_size) {
					if (numbers[x] == numbers[tab_size - 1 - counter]) {
						check++;
					}
					counter++;
				}

				if (check < 2) {
					new_numbers[i] = numbers[x];
					i++;
				}
				else if (!repeat[numbers[x]]) {
					new_numbers[i] = numbers[x];
					i++;
					repeat[numbers[x]] = true;
				}
			}

			for (int x = 0; x < i; x++) {
				cout << new_numbers[x] << " ";	
			}

			cout << endl;
		}
		else if (fun == "M") {		
			int sums[max];
			int index_of_sum[max];

			int sums_i = 0;
			int sum;
			int greatest_sum;
			int greatest_sum_index;
			

			for (int i = 0; i < tab_size; i++) {
				if (tab_size > 1) {
					if (i > 0 && i < tab_size - 1) {
						sum = numbers[i - 1] + numbers[i + 1];
						sums[sums_i] = sum;
						index_of_sum[sums_i] = i;
						sums_i++;
					}
					else if (tab_size - 1 == i) {
						break;
					}
				}				
			}

			greatest_sum = int(*max_element(sums, sums + sums_i));

			for (int i = 0; i < sums_i; i++) {
				if (sums[i] == greatest_sum) {
					greatest_sum_index = index_of_sum[i];
				}

			}
			cout << greatest_sum_index << endl;
		}
		else if (fun == "Q") {
			stop = true;
		}
	}

	return 0;
}
