#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include <cstdlib>
//注意 这个需要设置为点阵字体
int points{ 0 };
bool isGameOver = false;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int block[2][8];
char block_basic = 219;
int background[36][32]
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void printmap();                                                     // 打印地图
void printfallingblock();                                            // 创造方块
void copy_block_to_map();                                            // 把方块复制到地图里面
void running_block();                                                // 运行方块
void blockmovingcheck();                                             // 控制方块左右移动
void points_get_function();                                          // 消行和得分
void printpoints();                                                  // 得分控制
void gameover();                                                      // 游戏失败机制

int main() {
	printmap();
	std::cout << "Do you want to start the game?";
	std::string anwser{};
	std::cin >> anwser;
	if (anwser == "yes") {
		printfallingblock();
		copy_block_to_map();
		printmap();
		running_block();
	}

}

void printmap() {
	for (int i = 0; i < 36; i++) {
		std::cout << "                            ";
		for (int a = 0; a < 32; a++) {
			switch (background[i][a]) {
			case 1:                                       //墙壁显示
				std::cout << block_basic;
				break;
			case 0:                                       //空格显示
				std::cout << " ";
				break;
			case 2:                                       //正在下落的方块
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << block_basic;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << block_basic;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;                                    //已经掉落的方块
			}
		}
		std::cout << std::endl;
	}
}

void clean_block() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 8; ++j) {
			block[i][j] = 0;
		}
	}
} 
int randomnumber;
void printfallingblock() {
	srand((unsigned int)time(0));                                       //设定random 的基本要求
	randomnumber = rand() % 7;
	clean_block();
	switch (randomnumber) {
	case 0://正方形块
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 2; block[0][3] = 2; block[0][4] = 2; block[0][5] = 2; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 0; block[1][1] = 0; block[1][2] = 2; block[1][3] = 2; block[1][4] = 2; block[1][5] = 2; block[1][6] = 0; block[1][7] = 0;
		break;
	case 1://直线
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 0; block[0][3] = 0; block[0][4] = 0; block[0][5] = 0; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 2; block[1][1] = 2; block[1][2] = 2; block[1][3] = 2; block[1][4] = 2; block[1][5] = 2; block[1][6] = 2; block[1][7] = 2;
		break;
	case 2://1-2-1-0 1-3图形 （1-2-1-0， 竖着数，1-3，横着数）
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 2; block[0][3] = 2; block[0][4] = 0; block[0][5] = 0; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 2; block[1][1] = 2; block[1][2] = 2; block[1][3] = 2; block[1][4] = 2; block[1][5] = 2; block[1][6] = 0; block[1][7] = 0;
		break;
	case 3://1-2-1-0 2-2图形
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 2; block[0][3] = 2; block[0][4] = 2; block[0][5] = 2; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 2; block[1][1] = 2; block[1][2] = 2; block[1][3] = 2; block[1][4] = 0; block[1][5] = 0; block[1][6] = 0; block[1][7] = 0;
		break;
	case 4://两个小方块
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 2; block[0][3] = 2; block[0][4] = 0; block[0][5] = 0; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 0; block[1][1] = 0; block[1][2] = 2; block[1][3] = 2; block[1][4] = 0; block[1][5] = 0; block[1][6] = 0; block[1][7] = 0;
		break;
	case 5:
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 0; block[0][3] = 0; block[0][4] = 0; block[0][5] = 0; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 0; block[1][1] = 0; block[1][2] = 2; block[1][3] = 2; block[1][4] = 0; block[1][5] = 0; block[1][6] = 0; block[1][7] = 0;
		break;
	case 6://1-1/2-0 1-3图形
		block[0][0] = 0; block[0][1] = 0; block[0][2] = 0; block[0][3] = 0; block[0][4] = 2; block[0][5] = 2; block[0][6] = 0; block[0][7] = 0;
		block[1][0] = 2; block[1][1] = 2; block[1][2] = 2; block[1][3] = 2; block[1][4] = 2; block[1][5] = 2; block[1][6] = 0; block[1][7] = 0;
		break;
	}
}

void copy_block_to_map() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 8; ++j) {
			background[i + 1][j + 12] = block[i][j];
		}
	}
}

void running_block() {
	bool isFalling = true;
	while (isFalling) {                                                           // 检查方块下一步是否会触碰到底部或其他方块
		for (int i = 34; i >= 0; --i) {
			for (int j = 0; j < 32; ++j) {
				if (background[i][j] == 2) {
					if (background[i + 1][j] == 1 || background[i + 1][j] == 3) {
						isFalling = false;                                    // 标记为已固定
					}
				}
			}
		}
		if (!isFalling) {
			for (int i = 0; i < 36; ++i) {
				for (int j = 0; j < 32; ++j) {
					if (background[i][j] == 2) {
						background[i][j] = 3;
						points_get_function();
					}
				}
			}
		}
		blockmovingcheck();
		if (isFalling) {                                                      // 如果方块还可以掉下去
			for (int i = 34; i >= 0; --i) {
				for (int j = 0; j < 32; ++j) {
					if (background[i][j] == 2) {
						background[i + 1][j] = 2;
						background[i][j] = 0;
					}
				}
			}
			system("CLS");
			printmap();
			Sleep(100);
		}
		else {
			gameover();
			printfallingblock();
			copy_block_to_map();
			running_block();
		}
	}
}

void blockmovingcheck() {
	std::vector<std::pair<int, int>> tempPositions;                       //旋转临时位置储存区
	bool block_can_move_Left = false;
	bool block_can_move_Right = false;
	bool canRotate{};
	if (_kbhit()) {
		char ch = _getch();                                               //获得用户输入的东西
		if (ch == 'a' || ch == 'A') {                                     //整体往左移动一格      
			for (int i = 0; i < 36; i++) {
				for (int j = 0; j < 32; j++) {
					if (background[i][j] == 2) {
						if (j == 2 || j == 3 || background[i][j - 2] == 1 || background[i][j - 2] == 3) {
							return;
						}
						else {
							block_can_move_Left = true;
						}
					}
				}
			}
		}
		else if (ch == 'd' || ch == 'D') {                               //整体往右边移动一格      
			for (int i = 0; i < 36; i++) {
				for (int j = 0; j < 32; j++) {
					if (background[i][j] == 2) {
						if (j == 29 || j == 28 || background[i][j + 2] == 1 || background[i][j + 2] == 3) {
							return;
						}
						else {
							block_can_move_Right = true;
						}
					}
				}
			}
		}
		else if (ch == 'e' || ch == 'E') {                             //顺时针旋转90°   检查机制+实行机制  检查机制分对象 这个先做2.3.6；
			int x_max = -1, y_max = -1, x_smalleast = 100, y_smalleast = 100;
			canRotate = true;
			tempPositions.clear();
			if (randomnumber == 2 || randomnumber == 3 || randomnumber == 6) {
				for (int i = 0; i < 36; i++) {                                                                   //      0，5 不用做
					for (int j = 0; j < 32; j++) {                                                               //      1，4 单独做
						if (background[i][j] == 2) {
							if (x_max < j) {
								x_max = j;
							}
							if (y_max < i) {
								y_max = i;
							}
							if (x_smalleast > j) {
								x_smalleast = j;
							}
							if (y_smalleast > i) {
								y_smalleast = i;
							}
						}
					}

				}
			}
			int central_block_y = ((y_max - y_smalleast) + 1) / 2 + y_smalleast;
			int central_block_x = ((x_max - x_smalleast) + 1) / 2 + x_smalleast;
			for (int i = 0; i < 36; i++) {
				for (int j = 0; j < 32; j++) {
					if (background[i][j] == 2) {
						int dx = j - central_block_x;
						int dy = i - central_block_y;
						int newX = central_block_x - dy;
						int newY = central_block_y + dx;
						if (!(newX >= 0 && newX < 32 && newY >= 0 && newY < 36 && background[newY][newX] == 0)) {
							canRotate = false;
							return;
						}
						else {
							tempPositions.push_back({ newY, newX });
						}
					}
				}
			}
		}
	}
	if (canRotate) {
		for (int i = 0; i < 36; i++) {
			for (int j = 0; j < 32; j++) {
				if (background[i][j] == 2) {
					background[i][j] = 0;
				}
			}
		}
		for (auto pos : tempPositions) {
			background[pos.first][pos.second] = 2;
		}
	}
	if (block_can_move_Left) {
		for (int i = 0; i < 36; i++) {
			for (int j = 0; j < 32; j++) {
				if (background[i][j] == 2) {
					background[i][j] = 0;                           // 将当前位置设置为0
					background[i][j - 2] = 2;                       // 将左侧位置设置为2
				}
			}
		}
		block_can_move_Left = false;
	}
	if (block_can_move_Right) {
		for (int i = 0; i < 36; i++) {
			for (int j = 32; j > 0; j--) {
				if (background[i][j] == 2) {
					background[i][j] = 0;
					background[i][j + 2] = 2;
				}
			}
		}
		block_can_move_Right = false;
	}
};

void points_get_function() {
	for (int i = 2; i <= 34; i++) {
		bool full_line_checking = true;
		for (int j = 2; j <= 29; j++) {
			if (background[i][j] != 3) {
				full_line_checking = false;
			}
		}
		if (full_line_checking) {
			for (int a = 2; a <= 29; a++) {
				background[i][a] = 0;
			}
			for (int k = i; k > 2; k--) {
				for (int j = 2; j <= 29; j++) {
					background[k][j] = background[k - 1][j];            // 整个图形往下移动一行
					background[k - 1][j] = 0;                           // 清除被下移行的原位置
				}
			}
			points += 100;
		}

	}
};

void printpoints() {
	std::cout << "scores=" << std::endl;
}

void gameover() {
	for (int j = 0; j < 32; j++) {
		if (background[1][j] == 3) {
			isGameOver = true;
			break;
		}
	}
	if (isGameOver) {

		std::cout << "Game Over!" << std::endl;
		std::cout << "Your final score is: " << points << std::endl;
		Sleep(10000);
		exit(0);
	}
}




// 双重缓冲区
// 旋转                                                   尝试解决这个  nm, 解决不了，在设计结构上有问题，除非使用笨办法中的笨办法来做
// 重复申请栈空间区域过大                                 
// 交互界面（分数）                                       
// 算法循环重复问题                                       
// 失败机制                                               这个可以尝试解决，用if 遍历就可以了


//总结：这个是俄罗斯方块的第一代产品，但是有几个问题。第一：因为底层的原因，虽然可以设计出转向功能但是太麻烦没必要。
//                                                    第二：界面一直在闪烁。
//                                                    第三：有很多的空间浪费了，需要用指针来做
//                                                    这两个问题将要在第二代完美解决