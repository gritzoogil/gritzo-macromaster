#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

// Numeric Input Validation

double InputValidation(const std::string& prompt) {
	double value;
	while (true) {
		std::cout << prompt;
		if (!(std::cin >> value)) {
			std::cout << "Invalid input. Please enter a valid number \n \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		else if (cin.fail()) {
			cout << "Invalid input. Please only enter a valid input. \n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (value < 0) {
			std::cout << "Invalid input. Please enter non-negative values \n \n";
		}
		else {
			break;
		}

	}
	return value;
}

int OneTwoThree(const std::string& prompt) {
	int ScndValue;
	while (true) {
		if (!(cin >> ScndValue)) {
			cout << "Invalid input. Please enter a number.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (ScndValue < 1 || ScndValue > 3) {
			cout << "Invalid input. Please only choose from 1, 2, 3.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	return ScndValue;
}



int main() {
	int activityLevel, height;
	char sex;
	double weight, age;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Welcome to MacroMaster: Your Ultimate Food Macro Guide!\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	// Physical Profile
	cout << "\nFirst of all, we need your physical profile so that we can give the macros that are the perfect fit for you!\n\n";
	// Input Age
	age = InputValidation("Enter your age (example: 18): ");
	// Input Sex
	while (true) {
		cout << "Enter your sex (m/f): ";

		if (!(cin >> sex)) {
			cout << "Invalid input. Please only choose from m/f.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (sex != 'm' && sex != 'f' && sex != 'M' && sex != 'F') {
			cout << "Invalid input. Please only choose from m/f.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}

	// Height and Weight Input
	height = InputValidation("Enter your height in CM (example: 170): ");
	weight = InputValidation("Enter your weight in KG (example: 67): ");

	// BMR Calculation
	double bmr;

	if (sex == 'm' || sex == 'M') {
		bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
	}
	else if (sex == 'f' || sex == 'F') {
		bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
	}
	else {
		cout << "Error. Please input properly. :)";
	}
	system("cls");

	// Input Activity Level
	cout << "Good! Now we need your activity level.\n\n";
	cout << "1) Sedentary (little to no exercise)\n";
	cout << "2) Lightly active (light exercise/sports 1-3 days a week)\n";
	cout << "3) Moderately active (moderate exercise/sports 3-5 days a week)\n";
	cout << "4) Very active (hard exercise/sports 6-7 days a week)\n";
	cout << "5) Extra active (very hard exercise and a physical job)\n\n";
	while (true) {
		cout << "Choose your activity level (1, 2, 3, 4, 5): ";

		if (!(cin >> activityLevel)) {
			cout << "Invalid input. Please enter a number.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (activityLevel < 1 || activityLevel > 5) {
			cout << "Invalid input. Please only choose from 1, 2, 3, 4, 5.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	system("cls");

	// Calculate maintenance caloires based on activity level
	double maintenanceCal;
	switch (activityLevel) {
	case 1:
		maintenanceCal = bmr * 1.2;
		break;
	case 2:
		maintenanceCal = bmr * 1.375;
		break;
	case 3:
		maintenanceCal = bmr * 1.55;
		break;
	case 4:
		maintenanceCal = bmr * 1.725;
		break;
	case 5:
		maintenanceCal = bmr * 1.9;
		break;
	}

	// Input Fitness Goal
	int fitnessGoal;
	cout << "Nice! Now we're going to ask you, what is your fitness goal?\n\n";
	cout << "1) Lose weight\n";
	cout << "2) Maintain weight\n";
	cout << "3) Gain weight\n\n";

	fitnessGoal = OneTwoThree("Choose your fitness goal(1, 2, 3): ");

	system("cls");

	// Final calories calculation based on fitness goal
	double deficitCal, surplusCal, finalCal;
	switch (fitnessGoal) {
	case 1: // Weight Loss
		// Ask user within slow or fast progress
		int weightLossProgression;
		cout << "What is your desired progression to lose weight?\n\n";
		cout << "1) Lose " << weight * 0.005 << "kg per week (Slow: Recommended for people who can't stick to a diet.)\n";
		cout << "2) Lose " << weight * 0.01 << "kg per week (Fast: Recommended for people who can stick to a diet.)\n";
		cout << "3) Custom\n\n";

		weightLossProgression = OneTwoThree("Choose your desired progression (1, 2, 3) :");

		double lossPerWeek, customLossPerWeek;
		switch (weightLossProgression) {

		case 1: // Slow
			lossPerWeek = weight * 0.005;
			deficitCal = maintenanceCal - (lossPerWeek * 500);
			finalCal = deficitCal;
			break;
		case 2: // Fast
			lossPerWeek = weight * 0.01;
			deficitCal = maintenanceCal - (lossPerWeek * 500);
			finalCal = deficitCal;
			break;
		case 3: // Custom
			system("cls");
			cout << "Enter your custom desired weight loss per week in percent. Always add two decimal places. (Example: 2.00): ";
			cin >> customLossPerWeek;
			lossPerWeek = weight * customLossPerWeek / 100;
			deficitCal = maintenanceCal - (lossPerWeek * 500);
			finalCal = deficitCal;
			break;
		}
		break;

	case 2: // Maintenance 
		finalCal = maintenanceCal;
		break;

	case 3: // Weight Gain
		// Ask user within slow or fast progress
		int weightGainProgression;
		cout << "What is your desired progression to gain weight?\n\n";
		cout << "1) Gain " << weight * 0.0025 << "kg per week (Slow: Recommended for people who can't stick to a diet.)\n";
		cout << "2) Gain " << weight * 0.005 << "kg per week (Fast: Recommended for people who can stick to a diet.)\n";
		cout << "3) Custom\n\n";

		weightGainProgression = OneTwoThree("Choose your desired progression (1, 2, 3): ");

		double gainPerWeek, customGainPerWeek;
		switch (weightGainProgression) {
		case 1: // Slow
			gainPerWeek = weight * 0.0025;
			surplusCal = maintenanceCal + (gainPerWeek * 500);
			finalCal = surplusCal;
			break;
		case 2: // Fast
			gainPerWeek = weight * 0.005;
			surplusCal = maintenanceCal + (gainPerWeek * 500);
			finalCal = surplusCal;
			break;
		case 3: // Custom
			system("cls");
			cout << "Enter your custom desired weight gain per week in percent. Always add two decimal places. (Example: 2.00): ";
			cin >> customGainPerWeek;
			gainPerWeek = weight * customGainPerWeek / 100;
			surplusCal = maintenanceCal + (gainPerWeek * 500);
			finalCal = surplusCal;
			break;
		}
		break;
	}
	system("cls");

	// Display profile, bmr, maintenance calories
	cout << "~~~~~~~~~PROFILE~~~~~~~~~\n";
	cout << "Age: " << age << endl;
	cout << "Sex: " << sex << endl;
	cout << "Weight: " << weight << "kg" << endl;
	cout << "Height: " << height << "cm" << endl;
	cout << "Basal Metabolic Rate (BMR): " << bmr << " Cal/day" << endl;
	cout << "Maintenance Calories: " << maintenanceCal << " Cal/day" << endl << endl;

	// Display calories
	cout << "~~~~~~~~~TARGET CALORIES AND MACROS~~~~~~~~~\n";
	cout << "\n";
	cout << "This is your daily calories to achieve your goal: " << finalCal << " Cal/day\n";

	// Calculate macros
	int protein, fat, carb;
	cout << "Here are the perfect macros for you and your goal:\n";
	switch (fitnessGoal) {
	case 1: // Weight Loss &

	case 2: // Mintenance
		protein = weight * 2.20462;
		fat = weight * 2.20462 * 0.3;
		carb = (finalCal - (protein * 4) - (fat * 9)) / 4;
		break;

	case 3: // Weight Gain
		protein = weight * 2.20462 * 0.8;
		fat = weight * 2.20462 * 0.3;
		carb = (finalCal - (protein * 4) - (fat * 9)) / 4;
		break;
	}

	// Display Macros
	cout << "Protein: " << protein << "g\n";
	cout << "Fats: " << fat << "g\n";
	cout << "Carbs: " << carb << "g\n";

	// Check if calories is below bmr 
	if (finalCal < bmr) {
		cout << "\n";
		cout << "NOTE: \n";
		cout << "Because your target calories is lower than your BMR, we recommend bumping up your activity levels so that your target calories can get higher.\n\n";
	}

	// Ask the user if they want the explanation
	char explanation;
	while (true) {
		cout << "\n";
		cout << "Do you want to see the explanation? (y/n): ";

		if (!(cin >> explanation)) {
			cout << "Invalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (explanation != 'y' && explanation != 'n' && explanation != 'Y' && explanation != 'N') {
			cout << "Invalid input. Please only choose from y, n.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}


	switch (explanation) {
	case 'y': // yes explanation
	case 'Y':
		switch (fitnessGoal) {
		case 1:

		case 2:
			system("cls");
			cout << "Protein: " << protein << 'g' << endl; // Explanation for protein
			cout << "This is 1g/lb of bodyweight. This primarily aims to preserve muscle mass while reducing body fat. When someone is cutting, they are typically in a caloric deficit, consuming fewer calories than their body requires for maintenance. During this phase, there's a risk of losing not just fat but also muscle mass.\n\n";
			cout << "Fats: " << fat << 'g' << endl; // Explanation for fats
			cout << "This is 0.3g/lb of bodyweight. Adequate fat intake is crucial for the production and regulation of hormones within the body. Hormones are chemical messengers that control various bodily functions, including metabolism, growth, mood, reproduction, and more. Fats play a significant role in hormone production and regulation.\n\n";
			cout << "Carbs: " << carb << 'g' << endl; // Explanation for carbs
			cout << "This is the rest of your calories. Adequate carbohydrate intake is important for Recovery and Glycogen Replenishment, Muscle Building and Performance. It is also protein sparing and also causes insulin response.\n\n";

			// Check if calories is below bmr 

			if (finalCal < bmr) {
				cout << "\n";
				cout << "NOTE: \n";
				cout << "Because your target calories is lower than your BMR, we recommend bumping up your activity levels so that your target calories can get higher.\n\n";
			}
			break;

		case 3:
			system("cls");
			cout << "Protein: " << protein << 'g' << endl; // Explanation for protein
			cout << "This is 0.8g/lb of bodyweight. Consuming 0.8 grams of protein per pound of body weight is important when bulking as it supports muscle growth, repair, and a positive nitrogen balance, crucial for recovery and maintaining muscle mass during a caloric surplus.\n\n";
			cout << "Fats: " << fat << 'g' << endl; // Explanation for fats
			cout << "This is 0.3g/lb of bodyweight. Adequate fat intake is crucial for the production and regulation of hormones within the body. Hormones are chemical messengers that control various bodily functions, including metabolism, growth, mood, reproduction, and more. Fats play a significant role in hormone production and regulation.\n\n";
			cout << "Carbs: " << carb << 'g' << endl; // Explanation for carbs
			cout << "This is the rest of your calories. Adequate carbohydrate intake is important for Recovery and Glycogen Replenishment, Muscle Building and Performance. It is also protein sparing and causes insulin response.\n\n";
			// Check if calories is below bmr 
			if (finalCal < bmr) {
				cout << "\n";
				cout << "NOTE: \n";
				cout << "Because your target calories is lower than your BMR, we recommend bumping up your activity levels so that your target calories can get higher.\n\n";
			}
			break;
		}
	case 'n': // no explanation
	case 'N':
		break;
	}

	// Asks the user if they want to exit
	cout << "Press any key to exit the program.\n";

	_getch();
	return 0;
}