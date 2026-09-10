#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<char, int> MakeDNAMap(std::string input) {

	std::map<char, int> map;

	for (size_t i = 0; i < input.length(); i++)
	{
		bool cantInsert = false;
		if (map.find(input[i]) != map.end()) {
			cantInsert = true;
		}

		if (!cantInsert) {
			map.insert({ input[i], 1 });
		}
		else
		{
			map[input[i]]++;
		}

	}

	return map;
}

std::vector<char> getMapkeys(std::map<char, int> input) {
	std::vector<char> keys;
	for (auto person : input) {
		keys.push_back(person.first);
	}
	return keys;
}	

int HammingDistanceCal(std::string seq1, std::string seq2) {

	int count = 0;

	for (size_t i = 0; i < seq1.length(); i++)
	{
		if (seq1[i] != seq2[i]) {
			count++;
		}
	}
	return count;	
}

int main()
{

	std::map<char, int> DAN1 = MakeDNAMap("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");

	
	for (auto person : DAN1) {
		std::cout << person.first << " : " << person.second << "\n";
	}

		
	int hammingDistance = HammingDistanceCal("GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT");

	std::cout << "The number of differences between the two DNA sequences is: " << hammingDistance << "\n";


}

