#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

char charselector(int num, int offset){
	return static_cast<char>(rand() % num + offset);
}

std::string discerntype(int passtype, int length){
	std::string password = "";
	if (passtype == 1){
		for (int i = 0; i < length; ++i){
			int lettercase = rand() % 2;
			if (lettercase == 0)
				password += charselector(26, 65);
			else
				password += charselector(26, 97);
		}
	}
	else if (passtype == 2){
		for (int i = 0; i < length; ++i){
			password += charselector(10, 48);
		}
	}
	else if (passtype == 3){
		for (int i = 0; i < length; ++i){
			int choice = rand() % 2;
			if (choice == 0){
				int lettercase = rand() % 2;
				if (lettercase == 0)
					password += charselector(26, 65);
				else
					password += charselector(26, 97);
			}
			else{
				password += charselector(10, 48);
			}
		}
	}
	else if (passtype == 4){
		for (int i = 0; i < length; ++i){
			password += charselector(15, 33);
		}
	}
	else{
		for (int i = 0; i < length; ++i){
			password += charselector(93, 33);
		}
	}
	return password;
}

void generate(int passtype, int length){
	std::string pass = discerntype(passtype, length);
	std::cout << "Generated Password: " << pass << std::endl;
}

int main(){
	srand(time(NULL));
	int passtype, length;
	bool valid = false;
	while (!valid){
		std::cout << "Password Generator \n" << "\nChoose Your Password Type:\n";
		std::cout << "1) Alphabetic Password \n2) Numeric Password \n3) Alpha-Numeric \n4) Symbolic Password \n5) Combination of Above" << std::endl;
		std::cin >> passtype;
		if (passtype == -1){
			std::cout << "Thanks for using Password Generator" << std::endl;
			return 0;
		}
		if (passtype < 1 || passtype > 5){
			std::cout << "Invalid Option, try again (or -1 to quit)." << std::endl;
		}
		else{
			valid = true;
		}
	}
	valid = false;
	while (!valid){
		std::cout << "Please Enter Desired Password Length (25 max): ";
		std::cin >> length;
		std::cout << std::endl;
		if (length == -1){
			std::cout << "Thanks for using Password Generator" << std::endl;
			return 0;
		}
		if (length < 1 || length > 25){
			std::cout << "Invalid Option, try again (or -1 to quit)." << std::endl;
		}
		else{
			valid = true;
		}
	}
	generate(passtype, length);

	return 0;
}