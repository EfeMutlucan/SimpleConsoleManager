#include <iostream>
#include <string>
#include <iomanip>

// Username and Password

const std::string correctUsername = "admin";
const std::string correctPassword = "admin1234";

// Login Function

bool login() {

	std::string username;
	std::string password;

	while (true) {

		std::cout << "Enter your username: ";
		std::cin >> username;
		std::cout << "Enter your password: ";
		std::cin >> password;


		if (username == correctUsername && password == correctPassword) {
			return true;
		}
		else if (username != correctUsername && password == correctPassword) {
			std::cout << "Incorrect username. Please try again...\n";
		}
		else if (username == correctUsername && password != correctPassword) {
			std::cout << "Incorrect password. Please try again...\n";
		}
		else {
			std::cout << "Incorrect username and password. Please try again.\n";
		}
	}
}

// Calculator Function

void calculator() {

	char op;

	double num1, num2;

	std::cout << "CALCULATOR\n";
	std::cout << "Choose your operations (+, -, *, /): ";
	std::cin >> op;
	std::cout << "First number: ";
	std::cin >> num1;
	std::cout << "Second number: ";
	std::cin >> num2;

	switch (op) {

	case '+':
		std::cout << "Result: " << num1 + num2 << std::endl;
		break;
	case '-':
		std::cout << "Result: " << num1 - num2 << std::endl;
		break;
	case '*':
		std::cout << "Result: " << num1 * num2 << std::endl;
		break;
	case '/':
		if (num2 != 0) {
			std::cout << "Result: " << num1 / num2 << std::endl;
		}
		else {
			std::cout << "Error: Division by zero!" << std::endl;
		}
		break;
	default:
		std::cout << "Invalid Operation!" << std::endl;

	}
}

// Function to calculate the first day of the month

int getFirstDayOfMonth(int year, int month) {
	int day = 1;
	int y = year - (14 - month) / 12;
	int m = month + 12 * ((14 - month) / 12) - 2;
	int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;

}

// Function to calculate the number of days in a month 

int getDaysInMonth(int year, int month) {
	if (month == 2) {
		//	Check for leap year in February
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 29;
		}
		else {
			return 28;
		}

	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

// Calendar Function

void printCalendar(int year, int month) {
	const std::string months[] = { "January","February","March","April","May","June",
									"July","August","September","October","November","December" };
	const std::string daysOfWeek[] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };

	std::cout << "\n     " << months[month - 1] << " " << year << "\n";
	for (const auto& day : daysOfWeek) {
		std::cout << std::setw(4) << day;
	}
	std::cout << "\n";

	int firstDay = getFirstDayOfMonth(year, month);
	int daysInMonth = getDaysInMonth(year, month);

	int day = 1;
	for (int i = 0; i < firstDay; i++) {
		std::cout << std::setw(4) << "";
	}
	for (int i = firstDay; i < 7; i++) {
		std::cout << std::setw(4) << day++;
	}
	std::cout << "\n";
	while (day <= daysInMonth) {
		for (int i = 0; i < 7 && day <= daysInMonth; i++) {
			std::cout << std::setw(4) << day++;
		}
		std::cout << "\n";
	}
}

// Menu Function

void showMenu() {

	int choice;

	do {

		std::cout << "\nMENU\n";
		std::cout << "1.Calendar\n";
		std::cout << "2.Calculator\n";
		std::cout << "3.Exit\n";
		std::cout << "Your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			int year, month;
			std::cout << "Enter year: ";
			std::cin >> year;
			std::cout << "Enter month: ";
			std::cin >> month;
			printCalendar(year, month);
			break;
		}
		case 2:
			calculator();
			break;
		case 3:
			std::cout << "Exiting...\n";
			exit(0);
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 3);


}

// Main Function

int main() {

	std::cout << "WELCOME!\n";

	// User Login
	if (login()) {

		// Display Menu
		showMenu();
	}

	return 0;
}