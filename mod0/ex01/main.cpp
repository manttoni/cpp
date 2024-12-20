#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact input_new_contact()
{
	std::cout << "Input contact information. Empty input cancels.\n";
	std::string info[5] = {"", "", "", "", ""};
	std::string fields[] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	for (int i = 0; i < 5; ++i)
	{
		std::cout << fields[i];
		if (!std::getline(std::cin, info[i]) || info[i] == "")
			return Contact();
	}
	return (Contact(info[0], info[1], info[2], info[3], info[4]));
}

void search_contacts(PhoneBook &book)
{
	std::string input;
	int index;
	book.display_contacts();
	std::cout << "Select index: ";
	if (!std::getline(std::cin, input))
		return;
	try
	{
		index = std::stoi(input);
		if (index < 0 || index > 7 || index > book.get_amount() - 1)
		{
			std::cout << "Index out of bounds.\n";
			return;
		}
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Not a number.\n";
		return;
	}
	book.print_contact(index);
}

int main(void)
{
	PhoneBook book;
	std::string input;

	while (std::cin)
	{
		std::cout << "Give a command: ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			Contact c = input_new_contact();
			if (c.getFirst().length() > 0)
				book.add_contact(c);
		}
		else if (input == "SEARCH")
			search_contacts(book);
		else
			std::cout << "Invalid command\n";
	}

	return 0;
}
