#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	amount = 0;
	for (int i = 0; i < 8; ++i)
		contacts[i] = Contact();
}

void	PhoneBook::add_contact(Contact contact)
{
	contacts[amount % 8] = contact;
	amount++;
}

static void form_column(std::string text)
{
	if (text.length() > 10)
		std::cout << text.substr(0, 9) + ".";
	else
	{
		for (int i = 0; i < 10 - text.length(); ++i)
			std::cout << " ";
		std::cout << text;
	}
}

static void form_contact_line(Contact c, int i)
{
	form_column(std::to_string(i));
	std::cout << "|";
	form_column(c.getFirst());
	std::cout << "|";
	form_column(c.getLast());
	std::cout << "|";
	form_column(c.getNick());
	std::cout << std::endl;
}

void	PhoneBook::display_contacts(void)
{
	for (int i = 0; i < 8; ++i)
		if (contacts[i].getFirst().length() > 0)
			form_contact_line(contacts[i], i);
}

void	PhoneBook::print_contact(int i)
{
	if (i > amount)
		return;
	std::cout << contacts[i].getFirst() << std::endl << contacts[i].getLast() << std::endl << contacts[i].getNick() << std::endl << contacts[i].getNbr() << std::endl << contacts[i].getSecret() << std::endl;
}

int	PhoneBook::get_amount()
{
	return amount;
}