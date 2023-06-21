# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;

	public:

    Contact();
	void defContactInfo();
	void showContactInfo();
};

#endif