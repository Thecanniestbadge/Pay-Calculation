// Programmer:		Thecanniestbadge
// Date:			6/05/2023
// Program Name:	Pay Calculation
// Chapter:			Decisions
// Description:		This program detemines the users pay weekly by getting their payrate and the number of hours they worked

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

int main(void)
{
	// Constant and Variable Declarations
	const double STD_HOURS = 40.0;
	const double OVERTIME_MULTIPLIER = 1.5;
	// Input variables
	double payRate		= 0.0;
	double hoursWorked	= 0.0;
	// Calculated variables
	double weeklyPay		= 0.0;
	double overtimeHours	= 0.0;
	double overtimePayRate	= 0.0;
	double overtimePay		= 0.0;
	double stdPay			= 0.0;
	// *** Your program goes here ***
	// *** INPUT ***
	// Get the pay rate 
	printf("Enter the pay rate: $");
	scanf("%lf", &payRate);
	// Get the hours worked
	printf("Enter the number of hours worked: ");
	scanf("%lf", &hoursWorked);
	printf("\n"); // blank line
	//***PROCESSING***
	// Decide if overtime or not
	// and calculate weekly pay
	if (hoursWorked <= STD_HOURS) {
		// Normal time ($/hr * hrs = pay($))
		weeklyPay = payRate * hoursWorked;
	}
	else
	{ // Overtime (time and a half for hours over 40)
		// (separating the calculation into  steps)
		// Calculate the number of overtime hours
		overtimeHours = hoursWorked - STD_HOURS;
		// Calculate the overtime pay rate
		overtimePayRate = payRate * OVERTIME_MULTIPLIER;
		// Calculate the overtime pay
		overtimePay = overtimePayRate * overtimeHours;
		// Calculate the normal ( 40 hrs.) pay
		stdPay = payRate * STD_HOURS;
		// add together the normal pay and the overtime pay 
		weeklyPay = stdPay + overtimePay;

		// Another way - single line math
		// weeklyPay = (payRate * STD_HOURS) + ((payRate * OVERTIME_MULTIPLIER) * (hoursWorked - STD_HOURS));
	}
	// *** OUTPUT ***
	// Display weekly gross pay
	printf("Pay: $%.2lf\n", weeklyPay);
	printf("\n"); // blank line
	return 0;
} // end main()
