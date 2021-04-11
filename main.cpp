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

void seeChain(){

    for(size_t i = 0; i < AlentCoin.chain.size(); i++){
        
        std::cout << "Block: " << i << std::endl;
        std::cout << "Quantity: " << AlentCoin.chain[i].data.quantity << std::endl;
        std::cout << "Receiver: " << AlentCoin.chain[i].data.receiver << std::endl;
        std::cout << "Sender: " << AlentCoin.chain[i].data.sender << std::endl;
        std::cout << "Timestamp: " << AlentCoin.chain[i].data.timestamp << std::endl;
        std::cout << "---------------------------------" << std::endl;

    }

}

int main(){

    // Add first block data
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
                seeChain();
                break;
            
            case 0:
                break;

            default:
                break;
        }
    }

    return 0;
}
