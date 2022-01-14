#include <iostream>
#include <limits>
#include <vector>

class Stack {
    public:
        Stack();
        bool isEmpty() const;
        int top() const;
        int pop();
        void push(int i);
        std::string toString() const;
    private:
        std::vector<int> elements;
};

Stack::Stack(){}

bool Stack::isEmpty() const{
    if(elements.empty()){
        return true;
    }else{return false;}
}

int Stack::top() const{
    if(isEmpty()){
        throw std::runtime_error("stack is empty");
    }else{
        return elements[0];
    }
}
int Stack::pop(){
    if(isEmpty()){
        throw std::runtime_error("stack is empty");
    }else{
        int firstInVector = elements[0];
        elements.erase(elements.begin());
        return firstInVector;
    }
}

void Stack::push(int i){
    elements.push_back(i);
}

std::string Stack::toString() const{
    std::string vectorString;
    for(int c = 0;  c < elements.size(); c++){
        vectorString.append(2, elements[c]);
        std::cout << elements[c];
    }
    std::cout << vectorString;
    return vectorString;
}

int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> ";
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){
                break;
            } else if (command.compare("top") == 0) {
                std::cout << stack.top() << std::endl;
            } else if (command.compare("pop") == 0) {
                std::cout << stack.pop() << std::endl;
            } else if (command == "push") {
                if ( std::cin.eof() ) break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if ( failed ){
                  throw std::runtime_error("not a number");
                }
                stack.push(i);
            } else if ( command.compare("list") == 0){
                std::cout << stack.toString() << std::endl;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}