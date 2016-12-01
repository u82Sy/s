/*
#include <stdio.>
*/
//extern void test();

namespace vigenere
{


char* encryption(char* plaintext,int count,char* key,int length)    
{   /*函数不负责释放分配的内存*/
    char* ciphertext;
    int station=0;
    ciphertext=new char[count];
    for(int i=0;i<count;i++)
    {
        station=i%length;
        ciphertext[i]=plaintext[i]+key[station]+1;
    }
//test();

    return ciphertext;
}
char* decryption(char *ciphertext,int count,char *key,int length)    
{
     char* plaintext;
    int station=0;
    plaintext=new char[count];
    for(int i=0;i<count;i++)
    {
        station=i%length;
        plaintext[i]=ciphertext[i]-key[station]-1;
    }
    
    return plaintext;
}

}//namespace vigenere

