
#ifndef NUMBER_TO_NESORA_HPP
#define NUMBER_TO_NESORA_HPP

#include <string>
#include <stdio.h>

inline std::string number_to_Nesora(int input) {
	std::string out;

	if (input == 0)return "zero";
	if (input / abs(input) == -1)out += "mainasu";
	std::string num = std::to_string(input);

	for (size_t i = 0;i < num.size();i++) {
		int nowketasu = num.size() - i - 1;
		switch (num[i]) {
		case '0':
			break;
		case '1':
			if (nowketasu % 4 == 0)
				out += "iti";
			else if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		case '2':
			out += "ni";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		case '3':
			out += "sann";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "byaku";
			else if (nowketasu % 4 == 3)
				out += "zenn";
			break;
		case '4':
			out += "yonn";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		case '5':
			out += "go";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		case '6':
			if (nowketasu % 4 == 0)
				out += "roku";
			if (nowketasu % 4 == 1)
				out += "rokuzyuu";
			else if (nowketasu % 4 == 2)
				out += "ro,pyaku";
			else if (nowketasu % 4 == 3)
				out += "rokusenn";
			break;
		case '7':
			out += "nana";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		case '8':
			if (nowketasu % 4 == 0)
				out += "hati";
			if (nowketasu % 4 == 1)
				out += "hatizyuu";
			else if (nowketasu % 4 == 2)
				out += "ha,pyaku";
			else if (nowketasu % 4 == 3)
				out += "ha,senn";
			break;
		case '9':
			out += "kyuu";
			if (nowketasu % 4 == 1)
				out += "zyuu";
			else if (nowketasu % 4 == 2)
				out += "hyaku";
			else if (nowketasu % 4 == 3)
				out += "senn";
			break;
		}

		if (nowketasu % 4 == 0) {
			if(nowketasu / 4 == 1)
				out += "mann";
			else if (nowketasu / 4 == 2)
				out += "oku";
			else if (nowketasu / 4 == 3)
				out += "tyou";
			else if (nowketasu / 4 == 4)
				out += "kei";
			else if (nowketasu / 4 == 5)
				out += "gai";
			else if (nowketasu / 4 == 6)
				out += "zyo";
			else if (nowketasu / 4 == 7)
				out += "zyou";
			else if (nowketasu / 4 == 8)
				out += "kou";
			else if (nowketasu / 4 == 9)
				out += "kann";
		}
	}

	return out;
}


inline std::string number_to_Nesora(float input, int digits = 5) {
	std::string out;

	if (input == (float)0.0)return "zero";
	if (input / abs(input) == -1)out += "mainasu";
	if (input >= (float)1.0)out += number_to_Nesora((int)input);
	else out += "rei";

	out += "tenn";
	std::string num = std::to_string(input - (float)(int)input);

	for (size_t i = 0;i < num.size() and i < digits;i++) {
		switch (num[i + 2]) {
		case '0':
			out += "zero";
			break;
		case '1':
			out += "iti";
			break;
		case '2':
			out += "nii";
			break;
		case '3':
			out += "sann";
			break;
		case '4':
			out += "yonn";
			break;
		case '5':
			out += "goo";
			break;
		case '6':
			out += "roku";
			break;
		case '7':
			out += "nana";
			break;
		case '8':
			out += "hati";
			break;
		case '9':
			out += "kyuu";
			break;
		}
	}

	return out;
}


inline std::string number_to_Nesora(std::string input) {



}


inline std::string normalization_to_Nesora(std::string input) {
	return "";
}



#endif//NUMBER_TO_NESORA_HPP
