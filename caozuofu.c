#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main(){
//	int m = 0;
//	int n = 0;
//	int count = 0;
//	printf("������Ƚϵ�����\n");
//	scanf("%d %d", &m,&n);
//	for (int i = 31; i >= 0; i--){
//		if ((((m >> i) & 1) ^ ((n >> i) & 1)) == 1){
//			count++;
//		}
//	}
//	printf("��ͬλ��Ϊ:%d\n",count);
//	system("pause");
//	return 0;
//}

//int main(){
//	int m = 0;
//	int i = 0;
//	printf("�����룺\n");
//	scanf("%d", &m);
//	printf("ż��λΪ��");
//	for (i = 31; i >= 1; i = i - 2){
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//	printf("����λΪ��");
//	for (i = 30; i >= 0; i = i - 2){
//		printf("%d ", (m >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//int main(){
//	int m = 0; 
//	int count = 0;
//	printf("�����룺\n");
//	scanf("%d", &m);
//	for (int i = 31; i >= 0; i--){
//		if ((((m >> i) & 1)^1)==0){
//			count++;
//		}
//	}
//	printf("��������1�ĸ���Ϊ��%d\n", count);
//	system("pause");
//	return 0;
//}

int main(){
	int m = 0;
	int n = 0;
	printf("������Ҫ����������\n");
	scanf("%d %d", &m, &n);
	m = m ^ n;
	n = m ^ n;
	m = m ^ n;
	printf("������Ϊm=%d,n=%d", m, n);
	system("pause");
	return 0;
}