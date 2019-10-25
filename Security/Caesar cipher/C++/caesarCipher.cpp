//caesar cipher
#include <bits/stdc++.h>
using namespace std;

void encryption(){
    int key;
    cout<<"Enter the key : ";
    cin>>key;
    string msg;
    cout<<"Enter the message for encryption : ";
    cin.ignore();
    getline(cin,msg);

    //encryption
    string cipher;
    for(int i=0;i<msg.length();i++){
        char ch=msg[i];
        if(ch==' ') {
             cipher.push_back(ch);
        }
        else {
                int val=msg[i]-'a'+key;
                if(val<0) val+=26;
                ch=val%26+'a';
                cipher.push_back(ch);
        }
    }
    cout<<"The encrypted message is : "<<cipher<<"\n";
}

void decryption(){
    int key;
    cout<<"Enter the key : ";
    cin>>key;
    string cipher;
    cout<<"Enter the message for decryption : ";
    cin.ignore();
    getline(cin,cipher);

    //decryption
    string decipher;
    for(int i=0;i<cipher.length();i++){
        char ch=cipher[i];
        if(ch==' ') {
                decipher.push_back(ch);
        }
        else {
                int val=cipher[i]-'a'-key;
                if(val<0) val+=26;
                ch=val%26+'a';
                decipher.push_back(ch);
        }
    }
    cout<<"The decrypted message is : "<<decipher<<"\n";
}

int main(){
    int ch;
    while(1){
        cout<<"Enter your choice: \n";
        cout<<"1.Encryption\n";
        cout<<"2.Decryption\n";
        cout<<"3.Exit\n";
        cin>>ch;
        if(ch==1) encryption();
        else if(ch==2) decryption();
        else break;
    }
    return 0;
}
