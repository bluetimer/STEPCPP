//import input and output library for cin,cout and endl
#include <iostream>
//import cmath library for pow(x,y)
#include <cmath>
//import input/output manipulator for setprecision
#include <iomanip>

/*
 * uses all the classes from the library. If you dont use namespace std,
 * you will have to specify the classes you want to use one by one.
 * For example,
 * using std::cout;
 * using std::cin;
 */

using namespace std;

/*
 * the main loop will return 0 if the code is successfully complie.
 * for debugging purposes, we can return another integer values,which
 * describes different type of error.
 * For example, return 1 if file is not found.
 */

int main() {

	//create an integer variable height and weight and set it equal to 0
	//create a BMI variable using either double or float. This will return the value in decimal point.

	int weight, height = 0;
	float BMI = 0;

	// there are 2 ways to start a new line in the command window.
	// 1) use '\n' 2) use endl. I will show you how to use both methods below.

	//uses \n to start a new line
	cout << "Please enter your weight(lbs): \n";
	cin >> weight;

	//troll prevention. example using return 1 for input error. the code will be terminated immediately.

	if (weight > 1400) {
		cout << "The heaviest human being ever recorded was Jon Brower Minnoach, weighing at 1400 pounds.\n";
		cout << "If you are heavier than Jon, please call Guinness World Record. \n";
		return 1;
	}
	
	//uses endl to start a new line. 
	cout << "Please enter your height(inches): " << endl;
	cin >> height;

	if (height > 107) {
		cout << "The tallest human being ever recorded was Robert Pershing Wadlow, weighing at 8ft 11in .\n";
		cout << "If you are taller than Robert, please call Guinness World Record. \n";
		return 1;
	}

	//BMI calculation: (weight*703)/height^2;

	BMI = (weight * 703) / pow(height, 2);

	//uses if-else statement to determine BMI range and uses setprecision command to set the output to 3 significant figure.

	if (BMI < 18.5) {
		cout << "You're underweight.Your BMI is " << setprecision(3) << BMI;
	}
	else if (BMI >= 18.5 && BMI <= 23) {
		cout << "You're very healthy.Your BMI is " << setprecision(3) << BMI;
	}
	else if (BMI >= 23 && BMI <= 27.5) {
		cout << "You're overweight.Your BMI is " << setprecision(3) << BMI;
	}
	else if (BMI > 27.5) {
		cout << "You're obese.Your BMI is " << setprecision(3) << BMI;
	}


	return 0;

}
