#include<stdio.h>  
#include<stdlib.h>  

/* �������� */
int long_n(int n);
int shuru(char *arr, int k, char *wei, int is_first);
void jiami(char *arr, int k, int e, int n);

/* ���뺯������¼�Ӽ������������*/
int shuru(char *arr, int k, char *wei, int is_first)
{
	int i;
	char ch;
	/*�ж��Ƿ�Ϊ��һ��������룬��������ȡ������ַ�������ͽ���һ��������ȡ���ַ���Ϊ��һ����ĵ�һ���ַ�*/
	if (is_first == 1)
		ch = getchar();
	else
		ch = *wei;
	for (i = 0; (i < k) && (ch != '\n'); i++)  //��ȡ�ַ�ֱ����ȡ���س���Ϊֹ  
	{
		arr[i] = ch;
		ch = getchar();
	}
	*wei = ch;  //����ȡ�����ַ�׼����Ϊ��һ����ĵ�һ���ַ�  
	for (i = i; i < k; i++)
		arr[i] = 'a';  //���벻��һ���������������'a'(��Ϊ����)  
	if (ch == '\n')  //���յ��س�������0������Ϊ1  
		return 0;
	else
		return 1;
}

/*���ܺ���*/
void jiami(char *arr, int k, int e, int n)
{
	int m = 0, c = 1, i, j, t = 0, shu, temp, num = 0;
	int *array;
	/*Mi��ֵ����*/
	for (i = 0; i < k; i++)
	{
		temp = 1;
		for (j = 0; j < (k - i - 1) * 2; j++)
			temp = temp * 10;
		shu = (int)arr[i] - 97;
		m = m + temp * shu;
	}
	temp = e;
	/*��ȡe�Ķ����Ʊ����ʽ��λ��*/
	do {
		temp = temp / 2;
		num++;
	} while (temp != 0);
	array = (int *)malloc(sizeof(int)*k);   //���붯̬����  
	temp = e;
	/*��̬����洢e�Ķ����Ʊ����ʽ*/
	for (i = 0; i < num; i++)
	{
		array[i] = temp % 2;
		temp = temp / 2;
	}
	/*��������������ֵ��㷨���������������˵��*/
	for (i = num - 1; i >= 0; i--)
	{
		t = t * 2;
		temp = c*c;
		if (temp > n)
		{
			for (j = 0; temp - n*j >= 0; j++);
			j--;
			c = temp - n*j;
		}
		else
			c = temp;
		if (array[i] == 1)
		{
			t = t + 1;
			temp = c*m;
			if (temp > n)
			{
				for (j = 0; temp - n*j >= 0; j++);
				j--;
				c = temp - n*j;
			}
			else
				c = temp;
		}

		e = e / 2;
	}
	temp = c;
	i = 0;
	/*c��λ��С�ڷ��鳤������ǰ����*/
	do {
		temp = temp / 10;
		i++;
	} while (temp != 0);
	for (i; i < num; i++)
		printf("0");
	printf("%d", c);
}

/*��ȡ����ĳ���*/ 

int long_n(int n)
{
	int temp, i, j, k, shi, comp = 0;
	temp = n;
	/*��ȡn��λ��*/
	for (i = 1; temp / 10 != 0; i++)
	{
		temp = temp / 10;
	}
	temp = i;
	/*��n��λ��Ϊ����*/
	if (i % 2 != 0)
	{
		i = i - 1;
		return i;
	}
	/*��λ��Ϊż��*/
	else
	{
		for (j = 0; j < i / 2; j++)
		{
			shi = 1;
			for (k = 0; k < temp - 2; k++)
				shi = shi * 10;
			comp = comp + shi * 25;
			temp = temp - 2;
		}
		if (comp <= n)
			return i;
		else
		{
			i = i - 2;
			return i;
		}
	}
}

/*������*/
int main()
{
	int p, q, e, d, n, fai_n, k, i, is_first = 1;
	char ch, *arr, wei = 'a';
	printf("������p��q��eֵ(�ÿո�����)\n");
	scanf("%d%d%d", &p, &q, &e);  //�Ӽ��̻�ȡp��q��eֵ  
	n = p*q;
	fai_n = (p - 1)*(q - 1);   //��(n)  
	for (k = 0; (k*n + 1) % e != 0; k++);
	if ((k*n + 1) % e == 0)
		d = (k*n + 1) / e;  //d * e �� 1 (mod ��(n))  
	k = long_n(n);
	k = k / 2;  //����ĳ���  
	ch = getchar(); //����س���  
	arr = (char *)malloc(sizeof(char)*k);  //���붯̬����  
	printf("����������\n");
	while (1)
	{
		i = shuru(arr, k, &wei, is_first);  //���������ַ��ĺ��������յ��س�������0������Ϊ1  
		is_first = 0;  //��һ����¼�������Ϊ0  
		jiami(arr, k, e, n);  //���ü��ܺ���  
		if (i == 0)  //���յ�����ֵΪ0����ѭ��  
			break;
	}
	printf("\n");
	return 0;
}
