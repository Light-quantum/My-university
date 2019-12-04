//
// Created by LinSihan on 2019/11/15.
//
/********************************************************************************************
    题目描述
    Description
    小应同学迷上了化学，最近他成为一个典型的实验男，他几乎天天都在学校化学实验室做实验。
    有一天他在实验室感觉很无聊，所以他就做了很多奇怪的实验，但是他困惑于这么多实验生成物的相对分子质量，
    他希望能有个很便捷的程序能使他知道他实验产生的各种物质的相对分子质量。
    现在正是2010年浙江师范大学程序设计竞赛的时刻，他希望参赛的各位精英能帮助他。
    通过一个所给的分子式，返回该物质的相对分子质量。

    输入描述
    Input
    在输入数据的第一行将给一个整数n，表示有n个分子式需要你给出他的相对分子质量。
    从第2行到第n+1行，每行会给一种物质的分子式。
    输入数据只包含8种元素，而这八种元素的相对原子质量单位给出如下：
    H (1), C (12), N (14), O (16), F (19), P (31), S (32), K (39).

    输出描述
    Output
    对于每个所给出的分子式，返回一行输出数据，即该物质的相对分子质量，没有多余的空格和空行。
*********************************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int n, i, j, len;
    char element[8] = {'H', 'C', 'N', 'O', 'F', 'P', 'S', 'K'};
    int atomicMass[8] = {1, 12, 14, 16, 19, 31, 32, 39};
    char molecularFormula[100] = "\0";
    int molecularMass = 0, temp = 0, num;

    scanf("%d", &n);
    while(n--) {
        molecularMass = 0;
        scanf("%s", molecularFormula);
        len = strlen(molecularFormula);
        for (i = 0; i < len; i++) {
            if(molecularFormula[i] >= 'A' && molecularFormula[i] <= 'Z'){
                for(j = 0; j < 8; j++){
                    if(element[j] == molecularFormula[i]){
                        temp = atomicMass[j];
                        break;
                    }
                }
                if(molecularFormula[i + 1] <= '9' && molecularFormula[i + 1] >= '0'){
                    num = molecularFormula[i + 1] - '0';
                    molecularMass = molecularMass + temp * num;
                    temp = 0;
                }
                else{
                    molecularMass += temp;
                    temp = 0;
                }
            }
            else{
                continue;
            }
        }
        printf("%d\n", molecularMass);
    }
    return 0;
}