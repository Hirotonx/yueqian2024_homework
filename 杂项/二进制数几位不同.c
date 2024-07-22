#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Swap Swap;
// 定义结构体
typedef struct
{
    char *name;
    int age;
    void (*display)(struct Person *self); // 函数指针，用于模拟成员函数
} Person;

// 声明成员函数
void display(struct Person *self)
{
    printf("Name: %s, Age: %d\n", self->name, self->age);
}

// 构造函数，初始化Person结构体
Person *create_person(const char *name, int age)
{
    Person *p = (Person *)malloc(sizeof(Person));
    if (p != NULL)
    {
        p->name = strdup(name); // 分配并复制字符串
        p->age = age;
        p->display = display; // 设置函数指针
    }
    return p;
}

// 析构函数，释放分配的内存
void destroy_person(Person *p)
{
    if (p != NULL)
    {
        free(p->name);
        free(p);
    }
}

int main()
{
    // 创建结构体对象
    Person *person = create_person("Alice", 30);

    // 调用成员函数
    person->display(person);

    // 访问成员变量
    printf("Accessing directly: Name: %s, Age: %d\n", person->name, person->age);

    // 释放内存
    destroy_person(person);

    return 0;
}
