#include <iostream>

int main()
{
    int length, width, height;
    
    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    std::cout << "Enter height: ";
    std::cin >> height;

    std::cout << "Volume = " << length * width * height << std::endl;

	return 0;
}
