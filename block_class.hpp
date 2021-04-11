#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct TransactionData{
    double quantity;
    std::string sender;
    std::string receiver;
    time_t timestamp;
};

class Block {

    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();


    public:
        Block(int idx, TransactionData td, size_t prevHash);

        size_t getHash();

        size_t getPreviousHash();

        TransactionData data;

        bool isHashValid();
        
};

Block::Block(int idx, TransactionData td, size_t prevHash){

    index = idx;
    data = td;
    previousHash = prevHash;
    blockHash = generateHash();

}

size_t Block::generateHash(){
    
    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalHash;

    std::string toHash = std::to_string(data.quantity) + data.receiver + data.sender + std::to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));

};

size_t Block::getHash(){
    
    return blockHash;

}

size_t Block::getPreviousHash(){

    return previousHash;

}

bool Block::isHashValid(){

    return generateHash() == blockHash;

}

class Blockchain {

    private:
        Block createGenesisBlock();

    public:
        std::vector<Block> chain;

        Blockchain();

        void addBlock(TransactionData td);

        bool isChainValid();

        
};

Blockchain::Blockchain(){

    Block genesis = createGenesisBlock();
    chain.push_back(genesis);

}

Block Blockchain::createGenesisBlock(){

    time_t current;
    TransactionData td;
    td.quantity;
    td.receiver = "1";
    td.sender = "0";
    td.timestamp = time(&current);

    std::hash<int> hash1;
    Block genesis(0, td, hash1(0));

    return genesis;

}

void Blockchain::addBlock(TransactionData td){

    int index = (int)chain.size() - 1;
    Block newBlock(index, td, chain.back().getPreviousHash());

    chain.push_back(newBlock);

}

bool Blockchain::isChainValid(){

    std::vector<Block>::iterator it;
    int chainLength = (int)chain.size();

    for(it = chain.begin(); it != chain.end(); ++it){

        Block currentBlock = *it;
        
        if(!currentBlock.isHashValid()){

            return false;

        }

        if(chainLength > 1){

            Block previousBlock = *(it - 1);

            if(currentBlock.getPreviousHash() != previousBlock.getHash()){

                return false;

            }
        }
    }

    return true;

}