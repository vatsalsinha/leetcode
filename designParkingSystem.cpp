class ParkingSystem {
public:
//     int b = 0, m = 0, s = 0;
//     ParkingSystem(int big, int medium, int small) {
//         b = big;
//         m = medium;
//         s = small;
//     }
    
//     bool addCar(int carType) {
//         if(carType == 1){
//             if(b - 1 >= 0){
//                 b--;
//                 return true;
//             }
//             else
//                 return false;
//         }
//         else if(carType == 2){
//             if(m - 1 >= 0){
//                 m--;
//                 return true;
//             }
//             else
//                 return false;
//         }
//         else{
//             if(s - 1 >= 0){
//                 s--;
//                 return true;
//             }
//             else
//                 return false;
//         }
        vector<int> count;
        ParkingSystem(int big, int medium, int small) {
            count = {big, medium, small};
        }

        bool addCar(int carType) {
            return count[carType - 1]-- > 0;
        }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
