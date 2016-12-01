/*

*/

#include "headerfile.h"
/*
extern char* encryption(char* plaintext,int count,char* key,int length);    
extern char* decryption(char* ciphertext,int count,char* key,int length);    
*/
//extern void test();
using namespace vigenere;

namespace myspace
{


void dataturn::activekey(int &station,int datalength,char *actkey)
{   
    int len=0;
    len=keylen;
    //char *actkey=new char[len];
    if(datalength<station)
    station=(station+datalength)%len;
    else if(datalength>station)
    station=(datalength-station)%len;
    else ;
    for(int i=0;i<keylen;i++)
    {
        actkey[i]=key[len];
        len=(len++)%keylen;
    }
    //return actkey;
}

void dataturn::optfiledata(string strfilenamei,string strfilenameo)
{/**/ 
    const char *filename;
    //filename=new char [strfilenamei.size()];
    //如果这个常量非常大会有什么问题 如果释放了这个常量会有什么问题
    //delete [] (char *)filename;没有编译出错
    filename=strfilenamei.c_str();
    fpin=fopen(filename,"rb");
    if(NULL==fpin)return;
    
    filename=strfilenameo.c_str();
    fpout=fopen(filename,"wb");
    if(NULL==fpout)return;
    
    filename=NULL;
//test();

    station=0;
    char *actkey;
    actkey=new char[keylen];
    for(int i=0;i<keylen;i++)
        actkey[i]=key[i];
    data=new char[256];
    for(;!feof(fpin);)
    {
        int temp=0;
        dcount=fread(data,1,256,fpin);
        if(!enrode)
        data=encryption(data, dcount, actkey, keylen);
        else
        data=decryption(data, dcount, actkey, keylen);
        temp=fwrite(data,1,dcount,fpout);
        if(temp!=dcount) return;    
        activekey(station,dcount,actkey);
    }
    
    delete []actkey;

}

void dataturn::keyturn(string &strkey)
{
    keylen=strkey.length();//strkey.size()
    key=new char [keylen];
    for(int i=0;i<keylen;i++)
        key[i]=strkey[i];//strkey.at(i)
}

}//namespace myspace

/*void strturn(string &str,char *cha)
{
        
    for(int i=0;i<str.size();i++)
        cha[i]=str[i];}*/