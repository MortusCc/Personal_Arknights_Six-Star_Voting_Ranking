#include "Arknights.h"
void PrintSort(char* name[MAX], WinRate winRate[MAX])
{
	printf("����ͶƱ���Ϊ��\n");
	printf("%s %15s      %s\n", "����", "��Ա��", "ʤ��");
	for (int i = MAX - 1; i >= 0; i--)
	{
		printf(" %2d  %15s     %.2lf%%\n", MAX - i, name[winRate[i].index], winRate[i].winRate * 100);
	}
}
void Voke(char* name[MAX], int mark[MAX], int count[MAX])
{
	srand(time(NULL));
	int i, j, s;
	char c;
	for (int k = 0; k < MAX * MAX; k++)
	{
		system("cls");
		do
		{
			i = rand() % MAX;
			j = rand() % MAX;
		} while (i == j);
		count[i]++;
		count[j]++;
		printf("ѡ������Ϊ��ǿ�ĸ�Ա��\n\n");
		printf("%15s%15s\n\n", name[i], name[j]);
		printf("������a��ʾѡ��������d��ʾѡ���ң�\n");
	START:
		s = scanf(" %c", &c);
		if (s == EOF)
		{
			exit(1);
		}
		if (c == 'a')
		{
			mark[i]++;
			printf("��Ͷ���ˣ�%s\n", name[i]);
			printf("��ǰ���ȣ�%d/%d\n", k + 1, MAX * MAX);
 			system("pause");
		}
		else if (c == 'd')
		{
			mark[j]++;
			printf("��Ͷ���ˣ�%s\n", name[j]);
			printf("��ǰ���ȣ�%d/%d\n", k + 1, MAX * MAX);
			system("pause");
		}
		else
		{
			printf("��������ٴ����룺\n");
			goto START;
		}
	}
}
void Rank(char* name[MAX], int mark[MAX], int count[MAX], WinRate* winRate)
{
	for (int i = 0; i < MAX; i++)
	{
		if (count[i] == 0)
		{
			winRate[i].winRate = -1;
		}
		else
		{
			winRate[i].winRate = (double)mark[i] / count[i];
		}
	}
	BubbleSort(name, winRate);
}
void Swap(WinRate* winRate, int i, int j)
{

	WinRate temp;
	temp = winRate[i];
	winRate[i] = winRate[j];
	winRate[j] = temp;
}
void BubbleSort(char* name[MAX], WinRate* winRate)
{
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 0; j < MAX - 1 - i; j++)
		{
			if (winRate[j].winRate > winRate[j + 1].winRate)
			{
				Swap(winRate, j, j + 1);
			}
		}
	}
}