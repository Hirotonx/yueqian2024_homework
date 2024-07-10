#include <iostream>
#include <vector>
#include <string>

int main() {
    unsigned int input_number, count = 0;
    std::cout << "输入一个整数: ";
    std::cin >> input_number;

    if (input_number < 0) {
        std::cout << "输入的整数数据溢出" << std::endl;
        return 0;
    }

    int tmp = input_number;  // 保存整数部分
    std::vector<std::string> number_name = {"个", "十", "百", "千", "万", "十万", "百万", "千万", "亿", "十亿"};
    int remainder;

    while (tmp != 0) {
        remainder = tmp % 10;
        std::cout << number_name[count] << "位为" << remainder << std::endl;
        tmp /= 10;
        count++;
    }

    std::cout << "一共有" << count << "位" << std::endl;
    return 0;
}
