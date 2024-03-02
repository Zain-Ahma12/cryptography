/*
code and decode the given string with a key
*/

#include <iostream>
#include <string>
using namespace std;

string code_pt(string str, int key){
    int l=str.length();
    for (int i=0; i<l; i++){
        // if (str[i]==' '){
        //     continue;    
        // } 
        int newLetterIndex=(str[i]+key-'a')%26;
        if (newLetterIndex<0){
           newLetterIndex+=26; 
        }
        str[i]=char(newLetterIndex + 97);
    }
    return str;
}

string decode_ct(string str, int key){
    int l=str.length();
    for (int i=0; i<l; i++){
        if (str[i]==' ') continue;
        int newLetterIndex=(str[i]-key-'a')%26;
        if (newLetterIndex<0){
           newLetterIndex+=26; 
        }
        str[i]=char(newLetterIndex + 97);
    }
    return str;
}

int main(){
    string plainText;
    string cipherText;
    cout<<"Do you want to enter:"<<endl;
    cout<<"1. PLAINTEXT"<<endl;
    cout<<"2. CIPHERTEXT"<<endl;

    int a;
    cin>>a;

    if (a==1){
        cout<<"Enter plain text(in small case without spaces)"<<endl;
        cin>>plainText;

        cout<<"Enter KEY(number greater than 0): ";
        int key;
        cin>>key;

        string ct=code_pt(plainText, key);

        cout<<ct;
    }
    else{
        cout<<"Enter cipher text(in small case)"<<endl;
        cin>>(cipherText);

        cout<<"Enter KEY: ";
        int key;
        cin>>key;

        string pt=decode_ct(cipherText, key);
        cout<<pt;
    }

    return 0;
}