//
// Created by LinSihan on 2019/11/20.
//
/***************************************************************************
    题目描述
    Description
    给定一段文章，请输出每个字母出现的次数
    输入描述
    Input
    只有一组输入数据，该数据大小<10KB。在文章中除最后一个字符外，
    只有小写字母、空格和换行符，没有另外的标点、数字和大写字母等。该文章以’#’结尾。
    输出描述
    Output
    输出格式为“C A”，C为’a’..’z’中的字母，A为出现次数，C和A之间空一格
**************************************************************************/

#include <stdio.h>
#include <string.h>
int main(){
    char article[11000] = "\0";
    int count[26] = {0};
    int i, len;

    for(i = 0; scanf("%c", &article[i]), article[i] != '#'; i++);
    article[i] = '\0';
    len = strlen(article);

    for(i = 0; i < len; i++){
        if(article[i] >= 'a' && article[i] <= 'z'){
            count[article[i] - 97]++;
        }
    }
    
    for(i = 0; i < 26; i++){
        printf("%c %d\n",i + 97, count[i]);
    }
    return 0;
}