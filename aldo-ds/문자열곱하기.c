#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*char:보통 1바이트=8비트, int: 보통 4바이트=32비트
문자열은 고정된크기 없음 문자열바이트+1로 메모리 크기 할당
ex)sizeof(srting)=6+1바이트 strlen(string)=6바이트
알아야 할것: 결과 문자열에 메모리가 얼마나 필요한지 두번째,세번째 문자열을 어느 위치부터 복하할 것인지
*/
char* solution(const char* my_string, int k) {
    size_t len= strlen(my_string);
    char* answer = malloc(len*k+1);
    if (answer==NULL){
        return NULL;
    }
    for (int i=0;i<k;i++){
        for (int j=0;j<len;j++){
            answer[len*i+j]=my_string[j];
        }
    }
    answer[len*k]='\0';
    return answer;
}