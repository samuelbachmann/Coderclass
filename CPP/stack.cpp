#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <iterator>

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
    return elements.empty();
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
    elements.insert(elements.begin(), i);
}

std::string Stack::toString() const{
    std::ostringstream oss;

    if (!elements.empty())
    {
        std::copy(elements.begin(), elements.end()-1,
            std::ostream_iterator<int>(oss, ","));

        oss << elements.back();
    }
    return oss.str();
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
                std::cout << "[" << stack.toString() << "]" << std::endl;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}