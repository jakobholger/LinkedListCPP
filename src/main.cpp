#include <iostream>
#include "linkedList.h"

void checkInputType() {
    std::cin.clear(); // clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    std::cout << "\n[-]Please enter an integer!\n" << std::endl;
}

int main() {

    std::cout << "LinkedList program\n" << "==================\n" << std::endl;
    
    LinkedList list;
    list.append(2);
    list.append(4);
    list.append(6);
    list.append(1);
    list.append(5);

	bool running = true;
	int choice;


	while (running) {
		std::cout << "Choose\n (1) Print list\n (2) Length of list\n (3) Append node\n (4) Pop last node\n (5) Remove first node\n (6) Append node to front\n (7) Insert node\n (8) Splice node\n (9) Split on index\n (10) Exit program\n";
        std::cout << std::endl;
		std::cin >> choice;
        std::cout << std::endl;

		// Check if the input is an integer
		if (std::cin.fail()) {
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "\n[-]Please enter an integer!\n" << std::endl;
			continue; // restart the loop
		}

        switch (choice) {
        case 1:
            list.printList();
            std::cout << std::endl;
            break;

        case 2: 
            list.length();
            std::cout << std::endl;
            break;

        case 3:
            std::cout << "Enter an integer to append..." << std::endl;
            int inputData;
            std::cin >> inputData;
            // Check if the input is an integer
            if (std::cin.fail()) {
                checkInputType();
                break;
            }
            list.append(inputData);
            break;

        case 4:
            list.pop();
            std::cout << std::endl;
            break;

        case 5:
            list.shift();
            std::cout << std::endl;
            break;


        case 6:
            std::cout << "Enter an integer to insert..." << std::endl;
            int input;
            std::cin >> input;
            // Check if the input is an integer
            if (std::cin.fail()) {
                checkInputType();
                break;
            }
            list.unshift(input);
            break;

        case 7:
            std::cout << "Enter an integer to insert..." << std::endl;
            int data;
            std::cin >> data;
            // Check if the input is an integer
            if (std::cin.fail()) {
                checkInputType();
                break;
            }

            std::cout << "Enter an index to insert at..." << std::endl;
            int index;
            std::cin >> index;
            // Check if the input is an integer
            if (std::cin.fail()) {
                checkInputType();
                break;
            }
            list.insert(data, index);
            break;

        case 8:
            std::cout << "Enter an index to insert at..." << std::endl;
            int spliceIndex;
            std::cin >> spliceIndex;
            if (std::cin.fail()) {
                checkInputType();
                break;
            }
            list.splice(spliceIndex);
            break;

        case 9:
            std::cout << "Enter an index to insert at..." << std::endl;
            int splitIndex;
            std::cin >> splitIndex;
            if (std::cin.fail()) {
                checkInputType();
                break;
            }
            list.split(splitIndex);
            break;
           

        case 10:
            running = false;
            std::cout << "\nExiting..." << std::endl;
            break;
        default:
            std::cout << "\nPlease enter a valid number" << std::endl;
            break;
        }
    }

    return 0;
}