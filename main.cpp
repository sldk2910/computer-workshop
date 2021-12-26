#include <stdio.h.>
#include <string.h>
#include <stdlib.h>

void EX_1(const char* str)
{
	int first1 = 0;
	int first2 = 0;
	int last1 = 0;
	int last2 = 0;
	int i = 0;

	while (str[i] == ' ')
	{
		++first1;
		++i;
	}

	while (str[i] != ' ')
	{
		++last1;
		++i;
	}

	--last1;

	while (str[i] != '\0')
	{
		++i;
		++last2;
	}

	++last2;

	while (str[i] != ' ')
		--i;

	first2 = i + 1;

	int first_word = last1 - first1 + 1 ;
	int last_word = last2 - first2;

	char Fw[64];

	for (int i = 0; i < first_word; ++i)
		Fw[i] = str[i];

	Fw[i - 3] = '\0';

	char Lw[64];

	for (int i = 0; i < last_word; ++i)
		Lw[i] = str[ strlen(str) - last_word + 1];

	Lw[i] = '\0';

	int len = strlen(str) + 1;

	char* New_string = (char*)malloc(len * sizeof(char));

	for (int i = 0; i < len; ++i)
		New_string[i] = str[i];
	
	for (int i = 0; i < first_word; ++i)
		New_string[i] = Lw[i];

	for (int i = len - 1 - last_word; i < len - 1; ++i)
		New_string[i] = Fw[i - len + 1 + last_word];

	printf("%s", New_string);

	return;
}

struct Human {
	char Surname[25];
	char Name[25];
	char Patronymic[25];

	char Sex;// "f" or "m"

	char Post[50];

	char Date[11];
};



void EX_3()
{
	FILE* F;
	errno_t err = fopen_s(&F, "f.txt", "r");

	if (err)
	{
		perror("file F");
		return;
	}

	FILE* G;
	errno_t err_ = fopen_s(&G, "g.txt", "w+");

	if (err_)
	{
		perror("file G");
		return;
	}
	int count = 0;

	for (char tmp = 0; fscanf_s(F, "%d", &tmp) != EOF;)
	{
		if (tmp == ' ')
		{
			++count;
		}

		if((count +1)%4 != 0)
			fscanf_s(F, "%c", G);
	}
	return;
}

int main()
{
	struct Human arr[4];

	arr[1] = {
		"Huzin",
		"Marat",
		"Rustemovich",

		'm',
		"student",
		"12.09.2003",
	};



	arr[3] = {
		"1",
		" ",
		" ",

		'm',
		"engineer",
		"12.03.1955",
	};


	EX_3();

	return 0;
}