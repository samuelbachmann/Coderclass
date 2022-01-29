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

// std::string maseGen::mase(int height, int width){

//     for(int i = 0; i < coordinates.size(); i++){
//         for(int c = 0; c < coordinates.at(i).size(); c++){

//             if(coordinates.at(i).at(c) == 1){ // opening to the right
//                 if (c + 2 > width){
//                     std::cout << "not possible";
//                 }else{    
//                     std::cout << i << c;
//                 }
                
//             }else if(coordinates.at(i).at(c) == 2){ // opening to the left
//                 if (c < 0){
//                     std::cout << "not possible";
//                 }else{

//                 }

//             }else if(coordinates.at(i).at(c) == 3){ // opening to the bottom
//                 if (i + 2 > height){
//                     std::cout << "not possible";
//                 }else{
                    
//                 }

//             }else if(coordinates.at(i).at(c) == 4){ // opening to the top
//                 if (i < 0){
//                     std::cout << "not possible";
//                 }else{
                    
//                 }
//             }
//         }
//     }
//     return "0";
// }

    // if(cords.second + 1 <= width){ //Opening to the right
    //     std::cout << "1 \n";
    //     if(checkIfvisited(std::make_pair(cords.first, cords.second + 1)) == false){
    //         cells.removeWallsCeilling(cords, 0, height, width, currentmaze);
    //     }
    // }else if(cords.second - 1 >= 0){ //Opening to the left
    //     std::cout << "2 \n";
    //     if(checkIfvisited(std::make_pair(cords.first, cords.second - 1)) == false){
    //         cells.removeWallsCeilling(cords, 1, height, width, currentmaze);
    //     }
    // }else if(cords.first + 1 <= height){ //Opening to the bottom
    //     std::cout << "3 \n";
    //     if(checkIfvisited(std::make_pair(cords.first + 1, cords.second)) == false){
    //         cells.removeWallsCeilling(cords, 2, height, width, currentmaze);
    //     }
    // }else if(cords.first - 1 >= 0){ //Opening to the top
    //     std::cout << "4 \n";
    //     if(checkIfvisited(std::make_pair(cords.first - 1, cords.second)) == false){
    //         cells.removeWallsCeilling(cords, 3, height, width, currentmaze);
    //     }
    // }