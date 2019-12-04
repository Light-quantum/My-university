//
// Created by LinSihan on 2019/11/23.
//
/**************************************************************************
    题目描述
    Description
    网上流传一句话:"常在网上飘啊，哪能不挨刀啊～"。
    其实要想能安安心心地上网其实也不难，学点安全知识就可以。
    首先，我们就要设置一个安全的密码。那什么样的密码才叫安全的呢？
    一般来说一个比较安全的密码至少应该满足下面两个条件：
    (1).密码长度大于等于8，且不要超过16。
    (2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。
    这四个字符类别分别为：
    1.大写字母：A,B,C...Z;
    2.小写字母：a,b,c...z;
    3.数字：0,1,2...9;
    4.特殊符号：~,!,@,#,$,%,^;
    给你一个密码，你的任务就是判断它是不是一个安全的密码。
    输入描述
    Input
    输入数据第一行包含一个数M，接下有M行，
    每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
    输出描述
    Output
    对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。
***************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int n, len, kind, i;
    char password[51] = "\0", different[4] = "\0";

    scanf("%d", &n);
    while(n--){
        kind = 0;
        different[0] = '\0';
        different[1] = '\0';
        different[2] = '\0';
        different[3] = '\0';

        scanf("%s", password);
        len = strlen(password);
        if(len >= 8 && len <= 16){
            for(i = 0; i < len; i++){
                if((password[i] >= 'A') && (password[i] <= 'Z')){
                    if(different[0] != 'A'){
                        kind++;
                        different[0] = 'A';
                    }
                }
                else if((password[i] >= 'a') && (password[i] <= 'z')){
                    if(different[1] != 'a'){
                        kind++;
                        different[1] = 'a';
                    }
                }
                else if((password[i] >= '0') && (password[i] <= '9')){
                    if(different[2] != '0'){
                        kind++;
                        different[2] = '0';
                    }
                }
                else if((password[i] == '~') || (password[i] <= '!') || (password[i] <= '@') || (password[i] <= '#')
                        || (password[i] <= '$') || (password[i] <= '%') || (password[i] <= '^')){
                    if(different[3] != '~'){
                        kind++;
                        different[3] = '~';
                    }
                }
                if(kind == 3){
                    printf("YES\n");
                    break;
                }
            }
            if(kind < 3){
                printf("NO\n");
            }
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}