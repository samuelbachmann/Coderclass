// std::string print(int length, int width){
//     for(int i = 0; i < length; i++){
//         for(int c = 0; c < width; c++){
//             std::cout << "+---";
//             if(c +1 == width){
//                 std::cout << "+\n";
//             }
//         }
//         for(int c = 0; c < width; c++){
//             std::cout << "|   ";
//             if(c +1 == width){
//                 std::cout << "|\n";
//             }
//         }
//     }

//     for(int c = 0; c < width; c++){
//         std::cout << "+---";
//         if(c +1 == width){
//             std::cout << "+\n";
//         }
//     }
//     return "\ncompleted\n";
// }

// class Cell{
//     public:
//         std::string filledwall(){    
//             return "|   ";
//         }
//         std::string emptyWall(){    
//             return "|   ";
//         }
//         std::string filledRoof(){
//             return "+---+";
//         }
//         std::string emptyRoof(){
//             return "+   +";
//         }
//     private:
// };

// for(int i = 0; i < height; i++){
//     for(int c = 0; c < width; c++){
//         currentMase.at(i) += "+---";
//         if(c +1 == width){
//             currentMase.at(i) += "+\n";
//         }
//     }
//     for(int c = 0; c < width; c++){
//         currentMase.at(i) += "|   ";
//         if(c +1 == width){
//             currentMase.at(i) += "|\n";
//         }
//     }
// }

// for(int c = 0; c < height; c++){
//     currentMase.at(height) += "+---";
//     if(c +1 == width){
//         currentMase.at(height) += "+\n";
//     }
// }