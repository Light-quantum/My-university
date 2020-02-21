//
// Created by LinSihan on 2019/12/18.
//
/************************************************************************
    题目描述
    Description
    Jam是个喜欢标新立异的科学怪人。
    他不使用阿拉伯数字计数，而是使用小 写英文字母计数，
    他觉得这样做，会使世界更加丰富多彩。
    在他的计数法中，每个数字的位数都是相同的（使用相同个数的字母），
    英文字母按原先的顺序，排在前 面的字母小于排在它后面的字母。
    我们把这样的“数字”称为Jam数字。
    在Jam数字中，每个字母互不相同，而且从左到右是严格递增的。
    每次，Jam还指定 使用字母的范围，
    例如，从2到10，表示只能使用{b,c,d,e,f,g,h,i,j}这些字母。
    如果再规定位数为5，那么，紧接在Jam数字 “bdfij”之后的数字应该是“bdghi”。
    （如果我们用U、V依次表示Jam数字“bdfij”与“bdghi”，
    则U〈V，且不存在Jam数字 P，使U〈P〈V）。
    你的任务是：对于从文件读入的一个Jam数字，
    按顺序输出紧接在后面的5个Jam数字，
    如果后面没有那么多Jam数字，那么有几个就 输出几个。
    输入描述
    Input
    有2行，第1行为3个正整数，用一个空格隔开：
    s t w
    （其中s为所使用的最小的字母的序号，
    t为所使用的最大的字母的序号。
    w为数字的位数，这3个数满足：1≤s〈t≤26, 2≤w≤t-s ）
    第2行为具有w个小写字母的字符串，为一个符合要求的Jam数字。
    所给的数据都是正确的，不必验证。
    输出描述
    Output
    最多为5行，为紧接在输入的Jam数字后面的5个Jam数字，
    如果后面没有那么多Jam数字，那么有几个就输出几个。
    每行只输出一个Jam数字，是由w个小写字母组成的字符串，
    不要有多余的空格。
************************************************************************/

#include <stdio.h>
int main(){
    int s, t, w;
    char startJam[26] = "\0";
    char endJam[26] = "\0";
    int i, j, k;

    scanf("%d %d %d\n", &s, &t, &w);
    scanf("%s", startJam);

    for(j = 0, i = t-w; i < t; i++, j++){
        endJam[j] = 'a' + i;
    }

    j = w - 1;
    int times = 5;
    while(times--){
        if(startJam[j] != endJam[j]){
            startJam[j]++;
        }
        else{
            while(startJam[j] == endJam[j]){
                j--;
            }
            startJam[j]++;
            for(k = j + 1; k < w; k++){
                startJam[k] = startJam[k - 1] + 1;
                if(startJam[k] != endJam[k]){
                    j++;
                }
            }
        }
        printf("%s\n", startJam);
        if(startJam[0] == endJam[0]){
            break;
        }
    }
    return 0;
}