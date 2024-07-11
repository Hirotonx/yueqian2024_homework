#include<iostream>

class Change_5{
private:
    int five_1;
    int five_0;
    int input_number;
public:
    Change_5(){
        five_1 = 1<<4;
        five_0 = ~five_1;
        std::cout << "输入一个整数"; 
        std::cin >> input_number;
    }
    int and_or(int sign){
            if(sign){return five_1 | input_number;}
            else{return five_0 & input_number; }
    }
    int xor_(int sign){
            if(sign){return five_1 ^ input_number;}
            else{return five_0 ^ input_number; }
    }
};
int main(){
    Change_5 change;

    //第五位强制转换1
    int res = change.and_or(1);
        
    //第五位强制转换0
    int res1 = change.and_or(0);
        
    //第五位强制反转
    int res2 = change.xor_(1);
    
    std::cout << "强制第五位转换为1为" << res << std::endl;
    std::cout << "强制第五位转换为0为" << res1 << std::endl;
    std::cout << "强制第五位反转为" << res2 << std::endl;

    return 0;
}

