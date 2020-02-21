#include "util.h"

int main(){
	int i;
	gotoxy(50, 5);
	printf("俄罗斯方块！！！");
	gotoxy(50, 6);
	printf("607内测版本2.0\n");
	gotoxy(50, 7);
	printf("版本描述：可以旋转，下落超慢，没有旋转限制，bug一堆, 还写少了一种T.T");
	gotoxy(50, 9);
	printf("先将输入法切换到英文，并按F11全屏食用！！！");
	gotoxy(50, 10);
	printf("A: 左 D:右 W: 旋转");
	gotoxy(50, 11);
	printf("游戏将在15s后开始: ");
	for(i = 1; i > 0; i--){
		gotoxy(50, 12);
		Sleep(1000);
		printf("%2d", i);
	}
	system("cls");
	
	SetConsoleOutputCP(437); // 使用拓展的ASCII码
	char map[30][20] = {{'\0'}}; // 定义地图二维数组
	MOD modList[6];  // 定义6种模块的坐标数组
	int kind;  //定义模块类型
	MOD currentMod; //定义当前操作模块
	int status;
	int score = 0;


	
	initmod(modList); //初始化模块
	initmap(map); //初始化地图

	kind = getkindofmod();
	getcurrentmod(kind, modList, &currentMod); // 初始化当前模块
	loadmod(map, kind, modList); //加载模块到地图中
	printmap(map);

	int had_do;
	while(1){
		had_do = 0;
		while(_kbhit()){
            status = getch();
			if(status == 'a' || status == 'A' ||
				status == 'd' || status == 'B'){
				move(map, kind, &currentMod, status);
				printmap(map);
				had_do = 1;
			}
			else if(status == 'w' || status == 'W'){
				rotate(map, kind, &currentMod);
				printmap(map);
				had_do = 1;
			}
			else if(status == 's' || status == 'S'){
				speedfall(map, kind, &currentMod);
				printmap(map);
				had_do = 1;
			}
		}
		freefall(map, kind, &currentMod);
		if(!cankeepfall(map, kind, &currentMod)){
			clean(map, &score);
			printmap(map);
			kind = getkindofmod();
			getcurrentmod(kind, modList, &currentMod); // 初始化当前模块
			loadmod(map, kind, modList); //加载模块到地图中
		}
		if(had_do == 0){
			printmap(map);
		}
		printf("your score: %d", score);
		Sleep(300);
		
	}
	return 0;

}