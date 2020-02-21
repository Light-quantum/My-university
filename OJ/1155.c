//
// Created by LinSihan on 2019/12/17.
//
/***************************************************************
    题目描述
    Description
    恺撒生活在充满危险和阴谋的时代. 恺撒面对的最困难的问题是生存.
    为了生存, 他决定创造一种密码. 这种密码听起来难以置信, 如果不知
    道方法, 没有人可以破解.
    你是恺撒军队的一个上尉. 你的工作是解密消息并将之提供给将军.
    密码很简单. 对明文的每个字母右移5个位置以创建密文 (如字母'A', 密
    文是'F').
    有如下对应:
    密文
    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    明文
    V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
    只有字母需要移位, 其它字符保持不变, 所有字母均是大写.
    输入描述
    Input
    输入为至多100组数据. 每组数据有如下格式, 中间无空行.
    一组数据有3部分:
    起始行 - 单独一行: "START"
    密文 - 单独一行, 包含1到200个字符, 组成恺撒的消息.
    结束行 - 单独一行: "END"
    最后一组输入是单独一行: "ENDOFINPUT".
****************************************************************/
// 解密算法

#include <stdio.h>
#include <string.h>

void decode(char ciphertext[], int len){
    int i;

    for(i = 0; i < len; i++){
        if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'){
            if((ciphertext[i] - 5) < 'A'){
                ciphertext[i] += (21);
            }
            else{
                ciphertext[i] -= 5;
            }
        }
        else{
            continue;
        }
    }
}

int main(){
    char start[15] = "\0";
    char cipher[205] = "\0";
    char end[10] = "\0";

    while(gets(start), strcmp(start, "ENDOFINPUT") != 0){
        gets(cipher);
        if(gets(end), strcmp(end, "END") == 0){
            decode(cipher, strlen(cipher));
            puts(cipher);
        }
    }
    return 0;
}

