#include "util.h"

int main(){
	int i;
	gotoxy(50, 5);
	printf("����˹���飡����");
	gotoxy(50, 6);
	printf("607�ڲ�汾2.0\n");
	gotoxy(50, 7);
	printf("�汾������������ת�����䳬����û����ת���ƣ�bugһ��, ��д����һ��T.T");
	gotoxy(50, 9);
	printf("�Ƚ����뷨�л���Ӣ�ģ�����F11ȫ��ʳ�ã�����");
	gotoxy(50, 10);
	printf("A: �� D:�� W: ��ת");
	gotoxy(50, 11);
	printf("��Ϸ����15s��ʼ: ");
	for(i = 1; i > 0; i--){
		gotoxy(50, 12);
		Sleep(1000);
		printf("%2d", i);
	}
	system("cls");
	
	SetConsoleOutputCP(437); // ʹ����չ��ASCII��
	char map[30][20] = {{'\0'}}; // �����ͼ��ά����
	MOD modList[6];  // ����6��ģ�����������
	int kind;  //����ģ������
	MOD currentMod; //���嵱ǰ����ģ��
	int status;
	int score = 0;


	
	initmod(modList); //��ʼ��ģ��
	initmap(map); //��ʼ����ͼ

	kind = getkindofmod();
	getcurrentmod(kind, modList, &currentMod); // ��ʼ����ǰģ��
	loadmod(map, kind, modList); //����ģ�鵽��ͼ��
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
			getcurrentmod(kind, modList, &currentMod); // ��ʼ����ǰģ��
			loadmod(map, kind, modList); //����ģ�鵽��ͼ��
		}
		if(had_do == 0){
			printmap(map);
		}
		printf("your score: %d", score);
		Sleep(300);
		
	}
	return 0;

}