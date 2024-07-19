#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> arr;
    std::cout << "输入n"<<std::endl;
    int n,sum = 0;
    std::cin >> n;
    float mean = 0;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cout << "输入数组中的元素:" << std::endl;
        std::cin >> arr[i];
        sum += arr[i];
    }
    mean =sum/ (float)n;
    int count;
    for (int i = 0; i < n;i++)
    {
        if(arr[i] >  mean){count++;}
    }
    std::cout << "大于平均数的个数是:   " << count << std::endl;
}
