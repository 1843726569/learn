#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
//������Ϸ���棬�׵ĸ�����
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

//������Ϸ���棨showmap�����ʾ���棬minemap�׵ķֲ����棩
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL]){
	memset(showmap, '*', MAX_ROW * MAX_COL);
	memset(minemap, '0', MAX_ROW * MAX_COL);
	//memset�������ǰ��ڴ��ÿһ���ֽڶ����ó�һ����
	srand((unsigned int)time(0));//�������10����
	int minecount = 0;
	while (minecount < MINE_COUNT){
		int	row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == '1'){
			continue;
		}
		minemap[row][col] = '1';
		minecount++;//�ж��׵ĸ�����ֱ��ʮ����
	}
}
//��ӡ��Ϸ������һ��������ӡ�������档
void print(char themap[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf("%c ", themap[row][col]);
		}
		printf("\n");
	}
}
//��������֮��Ľ��棬��ʾ��Χ�׵ĸ���
void date(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL], int row ,int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			//ͨ��ɨ��������Χ�˸������Ƿ�Ϊ1��ȷ���׵ĸ�����
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL){
				//�޶��жϱ߽�
				continue;//Խ��ֱ��������
			}
			if (r == row && c == col){
				continue;//�������ж�
			}
			if (minemap[r][c] == '1'){
				count++;//������ʾ����һ
			}
		}
	}
	showmap[row][col] = '0' + count;
}
//��д������
int main(){
	char showmap[MAX_ROW][MAX_COL] = { 0 };
	char minemap[MAX_ROW][MAX_COL] = { 0 };
	init(showmap, minemap);//��ʼ�����档
	int opencount = 0;
	while (1){
		system("cls");//����
		print(showmap);//��ӡ�������
		//�������
		int row = 0;
		int col = 0;
		printf("�����뷭��������(row col):");
		scanf("%d %d", &row, &col);
		//�жϺϷ��ԣ��Ƿ�Խ�硣
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("�������������������룡\n");
			continue;
		}
		//�ж��Ƿ��ѷ�����
		if (showmap[row][col] != '*'){
			printf("�������λ���Ѿ����������������룺\n");
			continue;
		}
        //�ж��Ƿ���ס�
		if (minemap[row][col] == '1'){
			printf("�������ˣ���Ϸ������\n");
			print(minemap);
			break;
		}
		date(showmap, minemap, row, col);//������Χ�׵ĸ�����
		opencount++;//ͳ���Ѿ������ġ�
		if (opencount == MAX_ROW * MAX_COL - MINE_COUNT){
			printf("���ѻ�ʤ��\n");
			break;
		}
	}
	system("pause");
	return 0;
}