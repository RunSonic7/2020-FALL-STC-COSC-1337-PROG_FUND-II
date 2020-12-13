#include <iostream>
#include <iomanip>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main()
{
	Address sender = Address("Juan Mireles II","123 Computer Ln", "Donna", "TX", "78537");
	Address receiver = Address("Alfred Estrada", "999 Apple Circle", "Cupertino", "CA", "11111");

	Package package = Package(sender, receiver, 2.0, 3.0);
	TwoDayPackage twoDayPackage = TwoDayPackage(sender, receiver, 2.0, 3.0, 5.00);
	OvernightPackage overnightPackage = OvernightPackage(sender, receiver, 2.0, 3.0);

	// Display Info
	cout << "\n\nFrom:\nName: " << package.getAddressSender().getName()
		<< "\nAddress: " << package.getAddressSender().getAddress()
		<< "\nCity: " << package.getAddressSender().getCity()
		<< "\nState: " << package.getAddressSender().getState()
		<< "\nZip Code: " << package.getAddressSender().getZipCode() << endl;

	cout << "\n\nTo:\nName: " << package.getAddressRecipient().getName()
		<< "\nAddress: " << package.getAddressRecipient().getAddress()
		<< "\nCity: " << package.getAddressRecipient().getCity()
		<< "\nState: " << package.getAddressRecipient().getState()
		<< "\nZip Code: " << package.getAddressRecipient().getZipCode() << endl;

	cout << fixed << setprecision(2) << "\n\nPricing Chart\n\n"
		<< "Standard Package Cost: ";

	if (package.calculateCost() > 0)
		cout << "$ " << package.calculateCost();
	else
		cout << "Unable to calculate due to invalid input.";

	cout << "\nTwo Day Package Cost: ";

	if (twoDayPackage.calculateCost() > 0)
		cout << "$ " << twoDayPackage.calculateCost();
	else
		cout << "Unable to calculate due to invalid input.";

	cout << "\nOvernight Package Cost: ";

	if (overnightPackage.calculateCost() > 0)
		cout << overnightPackage.calculateCost();
	else
		cout << "Unable to calculate due to invalid input.";

	cout << "\n\n";
	return 0;

}