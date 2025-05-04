//Check whether a number is a palindrome,armstrong and perfect number
#include<iostream>
using namespace std;

//Function to check a number is palindrome or not
bool ispalindrome(int *num){
    int reversed=0,original=*num,n=original;
    while(n>0){
        reversed=reversed*10 + n%10;
        n/=10;
    }
    return reversed == original;
}

//Function to check a number is armstrong or not
bool isarmstrong(int *num){
       int original=*num,n=original,digits=0,sum=0;

       while(n>0){
          digits++;
          n/=10;
       }
       n = original;
       while(n>0){
       int digit = n%10;
       int pow=1; 
       for(int i=0;i<digits;i++){
            pow*=digit;
        }
        sum+=pow;
        n/=10;
       }
        return original == sum;
}

//Function to check a number is perfect or not
bool isperfect(int *num){
      int original=*num,sum=0;
      for(int i=1;i<original;i++){
        if(original%i == 0){
           sum+=i;
        }   
      }
    return sum == original ;  
}

//Function for the menu
int getmenu(){
    int choice;
    cout<<"MENU\n";
    cout<<"1.Palindrome\n";
    cout<<"2.Armstrong\n";
    cout<<"3.Perfect\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

int main(){
    int choice = getmenu();
    
    int *num = new int;
   

    while(choice!= 4){
      cout<<"Enter your number:\n";
      cin>>*num;    
      switch(choice){
        case 1:
             if (ispalindrome(num)){
                cout << " The number " << *num << " is a palindrome.\n" << endl;
             }
            else {
                cout << " The number " << *num << " is not a palindrome.\n" << endl;
             }
            break;

        case 2:    
        if (isarmstrong(num)){
                cout << " The number " << *num << " is a armstrong number.\n" << endl;
             }
            else {
                cout << " The number " << *num << " is not a armstrong number.\n" << endl;
             }
            break;
        case 3:
        if (isperfect(num)){
                cout << " The number " << *num << " is a perfect number.\n" << endl;
             }
            else {
                cout << " The number " << *num << " is not a perfect number.\n" << endl;
             }
            break;
        default:
            cout << " Invalid choice.Please try again.\n ";     
    }     
        choice = getmenu();
    }


    delete num;
    return 0;
}

