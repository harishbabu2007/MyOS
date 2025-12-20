#include"sutils.h"

size_t strlen(const char* str){
    size_t rv = 0;

    while(str[rv]){
        rv++;
    }
    
    return rv;
}

void reverse_str(char *str, int length){
    int start = 0;
    int end = length - 1;

    while (start < end){
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;

        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base){
    int i = 0;
    int isNeg = 0;

    if (num == 0){
        str[i++] = '0';
        str[i] = '\0';

        return str;
    }

    if (num < 0 && base == 10){
        isNeg = 1;
        num = -num;
    }

    while(num != 0){
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';

        num = num/base;
    }

    if (isNeg){
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse_str(str, i);

    return str;
}

void *memset(void *dest, int val, size_t len){
    unsigned char *ptr = dest;
    while (len--) *ptr++ = val;
    return dest;
}

char*strcpy(char*dest , const char*src){
    size_t i = 0 ;
    while((dest[i] = src[i]) != '\0'){
        i++;
        return dest ;

    }

}

int strcmp(const char*str1 , const char*str2){
    while(*str1  && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *(const unsigned char *)

}