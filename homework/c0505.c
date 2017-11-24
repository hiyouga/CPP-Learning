#include <stdio.h>
#include <string.h>

int main()
{
    char s[55], t[55], m[55], p[55];
    int i, j, b, c, k, max_p = 0;
    gets(s);
    gets(t);
    for(i = 0; s[i] != '\0'; i++){
        for(j = 0; t[j] != '\0'; j++){
            k = 0;//!init k
            b = i, c = j;//!backup of i, j
            while(s[b] == t[c] && s[b] != '\0' && t[c] != '\0'){
                m[k] = s[b];//!backup of now string
                k++;//!now length
                b++, c++;
            }
            m[k] = '\0';//!add a blank
            if(k > max_p){
                max_p = k;//!update answer
                strcpy(p, m);//!copy to answer
            }
        }
    }
    if(max_p>0){
        puts(p);
    }else{
        printf("No Answer");
    }
    return 0;
}
