#ifndef SET_EXCEPTIONS_H_INCLUDED
#define SET_EXCEPTIONS_H_INCLUDED

#include <exception>
#include <string>

class set_base_exception : public std::exception
{
public:
	virtual const char* what()
	{
		return message;
	}

	explicit set_base_exception();

	explicit set_base_exception(const char *message)
		: message(message) {}

	explicit set_base_exception(std::string &message)
	{
		this->message = message.c_str();
	}

	explicit set_base_exception(const char *message, const char *additional_message)
		: message(message), additional_message(additional_message) {}

	explicit set_base_exception(std::string &message, std::string &additional_message)
	{
		this->message = message.c_str();
		this->additional_message = additional_message.c_str();
	}

protected:
	const char *message;
	const char *additional_message;
};

class set_memory_error : public set_base_exception
{
public:
	explicit set_memory_error()
		: set_base_exception("Allocation memory error!\n") {}

	explicit set_memory_error(const char *add_message)
		: set_base_exception("Allocation memory error!\n", add_message) {}

}; ///////////////////////////////////////////////////// не хватает ошибок, например "работа с удаленным объектом", "работа с пустым множеством"

#endif // SET_EXCEPTIONS_H_INCLUDED
