#include<iostream>
#include<string>
#include<sstream>
#include<vector>

std::vector<std::string> readInput(int& numbPomps) {
	std::cin >> numbPomps;
	std::cin.ignore();

	std::vector<std::string> datas(numbPomps);
	for (std::string& data : datas) {
		getline(std::cin, data);
	}

	return datas;
}

void printIndex(const std::vector<std::string>& amountsAndDistances, int numbPomps) {
	int distanceToGo = 0;
	int counter = 0;
	int idx = 0;
	int currPompAmount = 0;
	int nextPompDistance = 0;
	while (counter != numbPomps)
	{
		std::istringstream istr(amountsAndDistances[idx]);
		istr >> currPompAmount;
		istr >> nextPompDistance;
		distanceToGo += currPompAmount - nextPompDistance;
		//std::cout << "distanceToGo: " << distanceToGo << std::endl;
		if (distanceToGo < 0) {
			distanceToGo = 0;
			counter = 0;
		}
		else {
			counter++;
		}
		idx++;
		if (idx == numbPomps)
		{
			idx = 0;
		}
		//std::cout << "counter: " << counter << std::endl;
		//std::cout << "idx: " << idx << std::endl;
	}
	std::cout << idx << std::endl;
}

int main() {
	int numbPomps = 0;
	std::vector<std::string> amountsAndDistances = readInput(numbPomps);
	printIndex(amountsAndDistances, numbPomps);

	return 0;
}