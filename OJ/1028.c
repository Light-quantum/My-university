//
// Created by LinSihan on 2019/12/12.
//
/* *****************************************************************************************************************
    题目描述
    Description
    Jam是个喜欢标新立异的科学怪人。他不使用阿拉伯数字计数，而是使用小写英文字母计数，
    他觉得这样做，会使世界更加丰富多彩。在他的计数法中，每个数字的位数都是相同的
    （使用相同个数的字母），英文字母按原先的顺序，排在前面的字母小于排在它后面的字母。
    我们把这样的“数字”称为Jam数字。在Jam数字中，每个字母互不相同，而且从左到右是严格递增的。
    每次，Jam还指定使用字母的范围，例如，从2到10，表示只能使用{b,c,d,e,f,g,h,i,j}这些字母。
    如果再规定位数为5，那么，紧接在Jam数字“bdfij”之后的数字应该是“bdghi”。
    （如果我们用U、V依次表示Jam数字“bdfij”与“bdghi”，则U<V< span>，且不存在Jam数字P，使U<P<V< span>）。
    你的任务是：对于从文件读入的一个Jam数字，按顺序输出紧接在后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。
******************************************************************************************************************/
// 思路： 模拟进位, 逆序操作(低位存在0)， 从高位打印；
// 不会处理进位

#include <stdio.h>
#include <string.h>

int main(){
    int jam_list_star, jam_list_end, len;
    char jam_list[27] = "\0";
    char jam[27] = "\0";
    int i, j;

    scanf("%d %d %d", &jam_list_star, &jam_list_end, &len);
    getchar();
    for(j = 0, i = jam_list_star; i <= jam_list_end; i++, j++){
        jam_list[j] = ('a' + i - 1);
    }

    for(i = len - 1; i >= 0; i--){
        scanf("%c", &jam[i]);
    }
    int n = 5, carry = 0;
    while(n --){
        jam[0]++;
        if(jam[0] > jam_list[jam_list_end - jam_list_star]){
            carry = 1;
            for(i = 1; i < len - 1; i++){

            }
        }
        if(jam[len - 1] > jam_list[jam_list_end - jam_list_star]){
            break;
        }
    }
}
