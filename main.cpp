#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Arrays for number names
const vector<string> below_20 = {
	"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

const vector<string> tens = {
	"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

const vector<string> thousands = {
	"", "Thousand", "Million", "Billion", "Trillion"
};

string convertLessThanThousand(int num);

// Function to convert a number to English form
string numberToWords(int num) {
	if (num == 0) return "Zero";

	string result = "";

	int thousandIndex = 0;

	while (num > 0) {
		if (num % 1000 != 0) {
			string part = convertLessThanThousand(num % 1000);
			if (!result.empty()) {
				result = part + " " + thousands[thousandIndex] + " " + result;
			} else {
				result = part + " " + thousands[thousandIndex];
			}
		}
		num /= 1000;
		thousandIndex++;
	}

	return result;
}

// Helper function to convert numbers less than 1000
string convertLessThanThousand(int num) {
	string result = "";

	if (num >= 100) {
		result += below_20[num / 100] + " Hundred ";
		num %= 100;
	}

	if (num >= 20) {
		result += tens[num / 10] + " ";
		num %= 10;
	}

	if (num > 0) {
		result += below_20[num] + " ";
	}

	return result;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <number>" << endl;
		return 1;
	}

	stringstream ss(argv[1]);
	int num;
	ss >> num;

	if (!ss || num < 0) {
		cout << "Please provide a valid positive integer." << endl;
		return 1;
	}

	string result = numberToWords(num);
	cout << result << endl;

	return 0;
}