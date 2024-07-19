#include <iostream>
#include <vector>

// 快速排序
std::vector<int> quick_sort(const std::vector<int>& arr) //使用引用防止重复调用
{
    int len = arr.size();
    if (len <= 1) 
    {
        return arr;
    }
    int mid = arr[0];

    std::vector<int> left;
    std::vector<int> right;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= mid) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }

    left = quick_sort(left);
    right = quick_sort(right);

    std::vector<int> res;
    res.reserve(left.size() + right.size() + 1);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(mid);
    res.insert(res.end(), right.begin(), right.end());

    return res;
}

int main() 
{
    std::vector<int> input_arr;
    int tmp;

    std::cout << "输入5个整数" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> tmp;
        input_arr.push_back(tmp);
    }

    std::vector<int> res_arr = quick_sort(input_arr);

    for (int i = 5; i < 5;i++)
    {
        std::cout << "排好序的数组是" << res_arr[i];
    }
    std::cout << std::endl;

    return 0;
}
