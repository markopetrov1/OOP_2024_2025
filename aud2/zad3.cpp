//
// Created by Marko on 2.3.25.
//
#include <iostream>
#include <cstring>

using namespace std;

class Email{
private:
    char sender[50], recipient[50], subject[50], body[500];
public:
    Email(
            char * _sender = "sender@gmail.com",
            char * _recipient = "recipient@gmail.com",
            char * _subject = "Example subject",
            char * _body = "---------------------------------------"
                    ){
        strcpy(sender, _sender);
        strcpy(recipient, _recipient);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }

    ~Email(){}

    void print(){
        cout<<"Sender: "<<sender<<endl;
        cout<<"Recipient: "<<recipient<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"===================================================="<<endl;
        cout<<"Body: "<<body<<endl;
    }

    char * getSender(){
        return sender;
    }

    char * getRecipient(){
        return recipient;
    }

    char * getSubject(){
        return subject;
    }

    char * getBody(){
        return body;
    }

    void setSender(char * _sender){
        strcpy(sender, _sender);
    }

    void setRecipient(char * _recipient){
        strcpy(recipient, _recipient);
    }

    void setSubject( char * _subject){
        strcpy(subject, _subject);
    }

    void setBody( char * _body){
        strcpy(body, _body);
    }
};

bool isValidEmail(char * email){
    char * secondPart = strstr(email, "@");

    cout<<secondPart<<endl;

    if(secondPart == nullptr)
        return false;

    if(strstr(secondPart, ".") != nullptr)
        return true;

    return false;
}

int main(){
    char sender[50], recipient[50], subject[50], body[500];

    cin.getline(sender, 50);
    cin.getline(recipient, 50);
    cin.getline(subject, 50);
    cin.getline(body, 500);

    if(!isValidEmail(sender) || !isValidEmail(recipient)){
        cout<<"Invalid email address!"<<endl;
        return 0;
    }

    Email email(sender, recipient, subject, body);
    email.print();


    return 0;
}
