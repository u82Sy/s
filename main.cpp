/*vigenere
string 对像不能由cin>>输入

*/


#include "headerfile.h"
//void test();
using namespace myspace;

static int n=0;
void main()
{
    char temp[100];
    memset(temp,0,100);
    string strfilenamei,strfilenameo,strkey;
    strkey.c_str();
    int x;
    cout<<"**********vigenere*********"<<endl;
    cout<<"\n\n\n"<<endl;
    cout<<"select operate:encryption or decryption 1/2 ";
    cin>>x;
    cout<<endl<<"input filename:"<<endl;
    cin>>temp;
    strfilenamei=temp;
    memset(temp,0,100);

    cout<<endl<<"input key ";
    cin>>temp;
    strkey=temp; 
    memset(temp,0,100);
    cout<<endl;
    
    cout<<"output filename:"<<endl;
    cin>>temp;
    strfilenameo=temp;
    memset(temp,0,100);
    cout<<endl;
    
    dataturn object(strkey);
//test();
    if(x==2) object.setenrode(true);

    object.optfiledata(strfilenamei,strfilenameo);    
    
    cout<<"programe quit"<<endl;
}
void test()
{
    cout<<"num:"<<n++<<endl;
}

/*
*/
    


