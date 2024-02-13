#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
struct book{
    int id;
    string name;
    int quantity;
    int borrowed=0;
    string pplborrow[10]{};

};
book books[100];
int added=0;
//*****************************

struct user{
    int id_user;
    string name_user;
    int idbooks[10]={0};
};
user users[100];
int added_u=0;
//**************************

void add_book(){
    cout<<"Enter book info id & name & quantity\n";
    cin>>books[added].id>>books[added].name>>books[added].quantity;
    added++;

}
//*************************

void search_books_by_prefix(){
    cout<<"Enter book name prefix\n";
    string bookprefix;
    cin>>bookprefix;
    int cnt=0;
    for(int i=0;i<added;i++){
        int flag=0;
        for(int j=0;j<bookprefix.size();j++){
            if(bookprefix[j]==books[i].name[j])
                flag=1;
            else {
                flag = 0;
                break;
            }
        }
        if(flag==1) {
            cout << books[i].name << endl;
            cnt=1;
        }
    }
    if(cnt==0)
        cout<<"No book with that name\n";
}
//*************************

void print_who_borrowed_book_by_name(){
    int flag=0;
    string bookname;
    cout<<"Enter book name \n";
    cin>>bookname;
    for(int i=0;i<added;i++){
        if(bookname==books[i].name){
            flag=1;
            for(int j=0;j<10;j++){
                if(books[i].pplborrow[j]!="")
                    cout<<books[i].pplborrow[j]<<endl;

            }
            break;
        }
    }
    if(flag==0)
        cout<<"Invalid  \n";
}
//****************************

void print_library_by_id(){
    book min;
    for(int i=0;i<added;i++){
        for(int j=i+1; j<added; j++) {
            if(books[i].id>books[j].id)
            {
                min =books[i];
                books[i] = books[j];
                books[j] = min;
            }
        }
    }

    for(int j=0;j<added;j++){
        cout<<"id = "<<books[j].id<<" name = "<<books[j].name
        <<" Tatal quantity = "<<books[j].quantity
        <<" Total borrowed = "<<books[j].borrowed<<endl;
    }

}
//*******************************

void print_library_by_name(){
    book min;
    for(int i=0;i<added;i++){
        for(int j=i+1; j<added; j++) {
            if(books[i].name>books[j].name)
            {
                min =books[i];
                books[i] = books[j];
                books[j] = min;
            }
        }
    }
    for(int j=0;j<added;j++){
        cout<<" id = "<<books[j].id<<" name = "<<books[j].name
            <<" Tatal quantity = "<<books[j].quantity
            <<" Total borrowed = "<<books[j].borrowed<<endl;
    }

}
//******************************

void add_user(){
    cout<<"Enter user name & id\n";
    cin>>users[added_u].name_user>>users[added_u].id_user;
    added_u++;

}
//***************************

void user_borrow_book(){
    int bookid,bookidx;
    cout<<"Enter user name and book name \n";
    string user_borrow,bookborrow;
    cin>>user_borrow>>bookborrow;
    for(int i=0;i<added;i++){
        if(bookborrow==books[i].name){
            bookidx=i;
            if(books[i].quantity){
            books[i].quantity--;
            bookid=books[i].id;
            books[i].borrowed++;
            for(int j=0;j<10;j++) {
                if(books[i].pplborrow[j]==""){
                books[i].pplborrow[j] = user_borrow;
                break;}
            }

        break;}
            else
                cout<<"There is no copies of that book \n";
        }
        else
        cout<<"We don't have that book\n";

    }
    if(books[bookidx].quantity+1){
    for(int j=0;j<added_u;j++){
        if(user_borrow==users[j].name_user){
            for(int k=0;k<10;k++) {
                if(users[j].idbooks[k]==0){
                users[j].idbooks[k] = bookid;
                break;
                }
            }
            break;
        }
    }
    }
}
//************************************

void user_return_book(){
    int bookid;
    cout<<"Enter user name and book name\n";
    string user_return,bookreturn;
    cin>>user_return>>bookreturn;
    for(int i=0;i<added;i++){
        if(bookreturn==books[i].name){
            bookid=books[i].id;
            books[i].quantity++;
            books[i].borrowed--;
            break;
        }

    }
    for(int j=0;j<added_u;j++){
        if(user_return==users[j].name_user){
            for(int k=0;k<10;k++){
                if(bookid==users[j].idbooks[k]){
                    users[j].idbooks[k]=0;
                break;
                }

            }
            break;

        }
    }
}
//****************************

void print_users(){
    for(int i=0;i<added_u;i++){
        cout<<"user "<<users[i].name_user<<
        "  id "<<users[i].id_user<<
        "  borowed books ";
        for(int j=0;j<10;j++){
            if(users[i].idbooks[j]!=0)
                cout<<users[i].idbooks[j]<<" ";
        }
        cout<<endl;
    }
}


void menu(){
    cout<<"Library menu :\n "
          "1)add book\n"
          "2)search books by prefix\n"
          "3)print who borrowed book by name \n"
          "4)print library by id\n"
          "5)print library by name \n"
          "6)add user\n"
          "7)user borrow book\n"
          "8)user return book\n"
          "9)print users\n"
          "10)Exit\n";
    int n;
    cin>>n;
    if(n==10)
        return;
    else if(n==1)
        add_book();
    else if(n==2)
        search_books_by_prefix();
    else if(n==3)
        print_who_borrowed_book_by_name();
    else if(n==4)
        print_library_by_id();

    else if(n==5)
        print_library_by_name();
    else if(n==6)
        add_user();
    else if(n==7)
        user_borrow_book();
    else if(n==8)
        user_return_book();
    else if(n==9)
        print_users();

    return menu();


}

int main()
{
    menu();

    return 0;
}
