#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName, password, Email;
    string searchName, searchPassword, searchEmail;
    fstream file;

    public:
        void login();
        void signUp();
        void forgetPassword();
}obj;

int main(){
    char choice;
    cout<<"1. Login "<<endl;
    cout<<"2. Signup "<<endl;
    cout<<"3. Forget Password"<<endl;
    cout<<"4. Exit "<<endl;

    cout<<"Enter the choice ";
    cin>>choice;
    cout<<endl;

    switch(choice){
        case '1':
            obj.login();
        break;

        case '2':
            obj.signUp();
        break;

        case '3':
            obj.forgetPassword();
        break;

        case '4':
            cout<<"You are exited";
            return 0;
        break;

        default :
            cout<<"Invalid input....!"<<endl;
    }
    return 0;
}

void temp :: signUp(){
    cout<<"Set the username: ";
    cin>>userName;
    cout<<"Set the email: ";
    cin>>Email;
    cout<<"Set the password: ";
    cin>>password;

    file.open("loginData.txt",  ios::out | ios::app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp :: login(){

    cout<<"-------------------LOGIN PAGE--------------------"<<endl;
    cout<<"Enter your userName: ";
    cin>>searchName;

    cout<<"Enter the password: ";
    cin>>searchPassword;

    file.open("loginData.txt", ios::in);
    getline(cin, userName, '*');
    getline(cin, password, '*');

    while(!file.eof()){
        if(!file.is_open()){
            cout<<"The file is not present.....";
            return;
        }

        string line;
        while(getline(file, line)){
            if((line.find(searchName) != string::npos) && (line.find(searchPassword) != string::npos)){
                cout<<"The user is successfully loggedIn"<<endl;
                cout<<"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
                cout<<"----------------LOGIN COMPLETED----------------";
                return;
            }
            else{
                cout<<"Invalid credentials";
                login();
            }
        }
    }
    file.close();
}

void temp :: forgetPassword(){
    cout<<"Enter your username: ";
    cin>>searchName;
    cout<<"Enter your email: ";
    cin>>searchEmail;

    file.open("loginData.txt", ios::in);
    getline(cin, userName, '*');
    getline(cin, Email, '*');

    while(!file.eof()){
        if(userName == searchName && Email == searchEmail){
            cout<<"Account is found....."<<endl;
            cout<<"Enter your new password: "<<password<<endl;
        }
        else{
            cout<<"Your account is not found......"<<endl;
        }
    }
    file.close();
}

