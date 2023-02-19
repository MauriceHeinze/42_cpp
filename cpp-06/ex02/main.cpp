#include "./Base.hpp"

// void	print_data(Data *data) {
// 	std::cout << "email:		" << data->email << std::endl;
// 	std::cout << "password:	" << data->password << std::endl << std::endl;
// }

// int main ()
// {
// 	std::cout << "\033[32m--------------- Construct ---------------\033[0m" << std::endl;
// 	Serializer	serializer;
// 	Data		*data;

// 	data = new Data;
// 	data->email = "michal.jackson@live.com";
// 	data->password = "hehe!";

// 	std::cout << "\033[32m--------------- Not serialized yet ---------------\033[0m" << std::endl;
// 	print_data(data);


// 	uintptr_t	dataSerialized;
// 	Data		*dataDeserialized;

// 	std::cout << "\033[32m--------------- Serialized and deserialized! ---------------\033[0m" << std::endl;
// 	dataSerialized = serializer.serialize(data);
// 	dataDeserialized = serializer.deserialize(dataSerialized);
// 	print_data(dataDeserialized);

// 	std::cout << "\033[32m--------------- Destruct ---------------\033[0m" << std::endl;

// 	return (0);
// }

int main ()
{
	std::cout << "\033[32m--------------- Construct ---------------\033[0m" << std::endl;
	Base	*base = generate();

	std::cout << "\033[32m--------------- Not serialized yet ---------------\033[0m" << std::endl;
	base->~Base();

	std::cout << "\033[32m--------------- Serialized and deserialized! ---------------\033[0m" << std::endl;

	std::cout << "\033[32m--------------- Destruct ---------------\033[0m" << std::endl;

	return (0);
}