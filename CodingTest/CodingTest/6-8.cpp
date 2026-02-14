#include <iostream>
#include <string>

int main(void)
{
	std::string subject, grade;
	double credit = 0.f, changedGrade = 0.f;
	double comCredit = 0.f, comCreditMulGrade = 0.f;

	for (int i = 0; i < 20; ++i)
	{
		std::cin >> subject >> credit >> grade;

		if (grade == "A+")
			changedGrade = 4.5;
		else if (grade == "A0")
			changedGrade = 4.0;
		else if (grade == "B+")
			changedGrade = 3.5;
		else if (grade == "B0")
			changedGrade = 3.0;
		else if (grade == "C+")
			changedGrade = 2.5;
		else if (grade == "C0")
			changedGrade = 2.0;
		else if (grade == "D+")
			changedGrade = 1.5;
		else if (grade == "D0")
			changedGrade = 1.0;
		else if (grade == "F")
			changedGrade = 0.0;
		else if (grade == "P")
			continue;

		comCredit += credit;
		comCreditMulGrade += credit * changedGrade;
	}

	double result = comCreditMulGrade / comCredit;
	std::cout.precision(7);
	std::cout << result;

	return 0;
}
