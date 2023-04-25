#include "./Serializer.hpp"

void	printData(Data *data) {
	std::cout << "email:		" << data->email << std::endl;
	std::cout << "password:	" << data->password << std::endl << std::endl;
}

int main ()
{
	std::cout << "\033[32m--------------- Construct ---------------\033[0m" << std::endl;
	Data		*data;

	data = new Data;
	data->email = "michael.jackson@gmail.com";
	data->password = "hehe!";

	std::cout << "\033[32m--------------- Not serialized yet ---------------\033[0m" << std::endl;
	printData(data);


	uintptr_t	dataSerialized;
	Data		*dataDeserialized;

	std::cout << "\033[32m--------------- Serialized and deserialized! ---------------\033[0m" << std::endl;
	dataSerialized = Serializer::serialize(data);
	dataDeserialized = Serializer::deserialize(dataSerialized);
	printData(dataDeserialized);

	std::cout << "\033[32m--------------- Destruct ---------------\033[0m" << std::endl;

	return (0);
}
