#include <stdio.h>
int main()
{
	char input[100];
	int hash_map[128] = {0};
	printf("输入一个字符串");
	scanf("%99s", input);
	printf("输入的字符串是::%s\n", input);
	char res[100];
	int res_index = 0;
	
	//遍历子串或者遍历char ASCII字符
	for (int i = 'A'; i <= 'Z'; i++)
	{
		hash_map[i] = 1;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		hash_map[i] = 1;
	}

	//
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (hash_map[input[i]] != 1)
		{
			continue;
		}
		else
		{
			res[res_index++] = input[i];
			hash_map[input[i]]--;
		}
	}
	res[res_index] = '\0';
	printf("%s", res);
}