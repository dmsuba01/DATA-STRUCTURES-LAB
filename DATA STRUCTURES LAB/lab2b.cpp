//Find the area of a square,cube,rectangle and cuboid
#include<iostream>
using namespace std;

//Class for square
class Square{
    private:
        double len;
    public:
        Square (double l) : len(l) {}
    double calArea(){
        return len*len;
    }    
};

//Class for cube
class Cube{
    private:
        double len;
    public:
        Cube(double l) : len(l) {}
    double calSurfArea(){
        return 6*len*len;
    }      
};

//Class for rectangle
class Rectangle{
    private:
        double len,bre;
    public:
        Rectangle (double l, double b) : len(l) , bre(b) {}
    double calArea(){
        return len*bre;
    }    
};

//Class for cuboid
class Cuboid{
    private:
        double len,bre,hei;
    public:
        Cuboid (double l,double b,double h) : len(l) , bre(b) , hei(h) {}
    double calSurfArea(){
        return 2*(len*bre + bre*hei + hei*len);
    }      
};

//Function for the menu
int getmenu(){
    int choice;
    cout<<"MENU FOR CALCULATING AREA OF \n";
    cout<<"1.Square\n";
    cout<<"2.Cube\n";
    cout<<"3.Rectangle\n";
    cout<<"4.Cuboid\n";
    cout<<"5.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    do{
    choice = getmenu();
    if(choice == 5){
        return 0;
    }
    switch(choice){
        case 1:{
        double len;
        cout<<" The length is : ";
        cin>>len;
        Square square(len);
        cout<<"The area of the square is "<< square.calArea() << " square units\n" << endl;
        break;
        }
        case 2:{
        double len;
        cout<<" The length is : ";
        cin>>len;
        Cube cube(len);
        cout<<"The surface area of the cube is "<< cube.calSurfArea() << " cubic units\n" << endl;
        break;
        } 

        case 3:{
        double len,bre;
        cout<<" The length is : ";
        cin>>len;
        cout<<" The breadth is : ";
        cin>>bre;
        Rectangle rectangle(len,bre);
        cout<<"The area of the rectangle is "<< rectangle.calArea() << " square units\n" << endl;
        break;
        }

        case 4:
        {
        double len,bre,hei;
        cout<<" The length is : ";
        cin>>len;
        cout<<" The breadth is : ";
        cin>>bre;
        cout<<" The height is : ";
        cin>>hei;
        Cuboid cuboid(len,bre,hei);
        cout<<"The surface area of the cuboid is "<< cuboid.calSurfArea() << " cubic units\n" << endl;
        break;
        }
        
        default:
            cout<<"Invalid choice.Please try again.\n";     
    }     
    }while (choice!=5);

    return 0;
}