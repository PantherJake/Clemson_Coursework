/*
lab03b.c
Jacob Vickio
CPSC 1010-200, CPSC 1011-003
Lab 3 - Part 3 BONUS

This program's purpose is to take input about the users hourly rate for pay from work and hours per week worked. From here the program will calculate the total deductions and all the different taxes that will be taken from the paycheck, and display the users net pay.

Academic Honesty Declaration:
The following code represents my own work and I have neither received nor given assistance that violates the collaboration policy posted with this assignment. I have not copied or modified code from any other source other than the lab assignment, course textbook, or course lecture slides. Any unauthorized collaboration or use of materials not permitted will be subjected to academic integrity policies of Clemson University and CPSC 1010/1011. I acknowledge that this lab assignment is based upon an assignment created at Clemson University and that any posting or publishing of this code is prohibited unless I receive written permisison from Clemson University.
*/

#include <stdio.h>

main() 
{
double hoursPerWeek;
double hourlyPay;
double grossPay;
double netPay;
double totalDeductions;
double federalTax;
double stateTax;
double ficaTax;
double medicareTax;

printf("Hours per Week:\t\t ");
scanf("%lf", &hoursPerWeek);

printf("Hourly Pay:\t\t$");
scanf("%lf", &hourlyPay);

grossPay = hoursPerWeek * hourlyPay;

federalTax = grossPay * 0.10;
stateTax = grossPay * 0.014;
ficaTax = grossPay * 0.062;
medicareTax = grossPay * 0.0145;

totalDeductions = federalTax + stateTax + ficaTax + medicareTax;

netPay = grossPay - totalDeductions;

printf("Gross Pay:\t\t $%.2lf\n", grossPay);
printf("Net Pay:\t\t $%.2lf\n\n", netPay);

printf("Deductions\n");
printf("Federal:\t\t $%.2lf\n", federalTax);
printf("State:\t\t\t $%.2lf\n", stateTax);
printf("FICA:\t\t\t $%.2lf\n", ficaTax);
printf("Medicare:\t\t $%.2lf\n", medicareTax);


return 0;
}
