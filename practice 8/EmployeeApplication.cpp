#include"TaskC.h"
#include"EmployeeApplication.h"
void employeeApplication()
{
	Employee a,b;

	a.setFirstName("muneeb ");
	a.setLastName("ur rehman");
	a.setSalary(3000);

	b.setFirstName("yagomi");
	b.setLastName(" light");
	b.setSalary(30000);

	cout << a.getFirstName() << a.getLastName() << " : " << getYearlySalary(a.getSalary()) << endl;
	cout << b.getFirstName() << b.getLastName() << " : " << getYearlySalary(b.getSalary()) << endl;

	cout << "after incrementing \n";

	a.increaseSalary();
	b.increaseSalary();

	cout << a.getFirstName() << a.getLastName() << " : " << getYearlySalary(a.getSalary()) << endl;
	cout << b.getFirstName()<< b.getLastName() << " : " << getYearlySalary(b.getSalary()) << endl;

}