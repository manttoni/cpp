#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		amount;

	public:
		PhoneBook();
		void add_contact(Contact contact);
		void display_contacts();
		void print_contact(int i);
		int get_amount();
};

#endif