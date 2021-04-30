#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
//定义游戏界面，雷的个数。
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

//创建游戏界面（showmap最初显示界面，minemap雷的分布界面）
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL]){
	memset(showmap, '*', MAX_ROW * MAX_COL);
	memset(minemap, '0', MAX_ROW * MAX_COL);
	//memset的作用是把内存的每一个字节都设置成一个数
	srand((unsigned int)time(0));//随机生成10个雷
	int minecount = 0;
	while (minecount < MINE_COUNT){
		int	row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == '1'){
			continue;
		}
		minemap[row][col] = '1';
		minecount++;//判断雷的个数，直到十个。
	}
}
//打印游戏界面用一个函数打印两个界面。
void print(char themap[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf("%c ", themap[row][col]);
		}
		printf("\n");
	}
}
//创建翻开之后的界面，显示周围雷的个数
void date(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL], int row ,int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			//通过扫描坐标周围八个坐标是否为1来确定雷的个数。
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL){
				//限定判断边界
				continue;//越界直接跳过。
			}
			if (r == row && c == col){
				continue;//自身不用判断
			}
			if (minemap[r][c] == '1'){
				count++;//有雷显示数加一
			}
		}
	}
	showmap[row][col] = '0' + count;
}
//编写主函数
int main(){
	char showmap[MAX_ROW][MAX_COL] = { 0 };
	char minemap[MAX_ROW][MAX_COL] = { 0 };
	init(showmap, minemap);//初始化界面。
	int opencount = 0;
	while (1){
		system("cls");//清屏
		print(showmap);//打印最初界面
		//玩家落子
		int row = 0;
		int col = 0;
		printf("请输入翻开的坐标(row col):");
		scanf("%d %d", &row, &col);
		//判断合法性，是否越界。
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您输入有误，请重新输入！\n");
			continue;
		}
		//判断是否已翻开。
		if (showmap[row][col] != '*'){
			printf("您输入的位置已经翻开，请重新输入：\n");
			continue;
		}
        //判断是否踩雷。
		if (minemap[row][col] == '1'){
			printf("您踩雷了，游戏结束！\n");
			print(minemap);
			break;
		}
		date(showmap, minemap, row, col);//更新周围雷的个数。
		opencount++;//统计已经翻开的。
		if (opencount == MAX_ROW * MAX_COL - MINE_COUNT){
			printf("您已获胜！\n");
			break;
		}
	}
	system("pause");
	return 0;
}