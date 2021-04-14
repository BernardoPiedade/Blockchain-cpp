#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "block_class.hpp"

// Start Blockchain
Blockchain AlentCoin;

void sendAlentCoin(){

    double quantity;
    std::string receiver;
    std::string sender;

    std::cout << "\n\nQuantity: ";
    std::cin >> quantity;

    std::cout << "\n\nSender: ";
    std::cin >> sender;

    std::cout << "\n\nReceiver: ";
    std::cin >> receiver;

    TransactionData td;
    time_t tdTime;
    td.quantity = quantity;
    td.receiver = receiver;
    td.sender = sender;
    td.timestamp = time(&tdTime);

    AlentCoin.addBlock(td);

}

void see_Chain(){

    AlentCoin.seeChain();

}

int main(){

    for(size_t i = 0; i < 50; i++){
        std::cout << "\n" << std::endl;
    }

    // Add block data
    TransactionData td;
    time_t tdTime;
    td.quantity = 1;
    td.receiver = "Sandra";
    td.sender = "Sara";
    td.timestamp = time(&tdTime);

    AlentCoin.addBlock(td);

    int n = -1;

    while(n != 0){

        std::cout << "1 - Send" << std::endl;
        std::cout << "2 - See Chain" << std::endl;
        std::cout << "0 - Exit" << std::endl << std::endl;

        std::cin >> n;

        switch(n){
            case 1:
                sendAlentCoin();
                break;

            case 2:
                see_Chain();
                break;
            
            case 0:
                break;

            default:
                break;
        }
    }

    return 0;
}
