//                                PHONEBOOK MANAGEMENT SYSTEM
								//		UZAIR AHMAD MIRZA 
                //   NOW DOING IT AGAIN , AND GETTING OUT OF THIS SHIT BECAUSE IT GOT DELETED FIRST TIME

#include<iostream>
#include<stdlib.h>
#include <string>
#include<fstream>
using namespace std;
class Pms{
	private:
		string name,number;
	public:
		void Display();
		void Search_data(string naam);
		void Delete_data(string naam);
		void Modify_data(string naam);

		Pms(){
			name= "";
			number= "";
		}	
		Pms(string na, string no){
			this->name=na;
			this->number=no;
		}
		void setname(string na){
			this->name=na;
		}
		void setnumber(string no){
			this->number=no;
		}
		string getname(){
			return name;
		}
		string getnumber(){
			return number;
		}
		
		~Pms()
		{

		}
};


void Choice()
{
	cout<<"								  PHONEBOOK MANAGEMENT SYSTEM"<<endl;
	cout<<"				---------------------Press 1 to ADD record---------------------------			"<<endl;
	cout<<"				---------------------Press 2 to SEARCH from record------------------- 			"<<endl;
	cout<<"				---------------------Press 3 to SHOW record stored------------------- 			"<<endl;
	cout<<"				---------------------Press 4 to MODIFY record------------------------ 			"<<endl;
	cout<<"				---------------------Press 5 to DELETE record------------------------ 			"<<endl;
	cout<<"				---------------------Press 6 to ADD SPEED DIAL numbers---------------			"<<endl;
	cout<<"				---------------------Press 7 to EXIT from Program--------------------			"<<endl;
		cout<<"enter your choice for operation to perform "<<endl;
	
}
 
void Pms::Display(){
			
			cout<<"The name stored is "<<getname()<<endl;
			cout<<"The number stored is "<<getnumber()<<endl;
			cout<<"Your  data is saved "<<endl;
			
		}

void Pms::Search_data(string naam){
	if(naam[0]==name[0])
	{
		cout<<"The name found is  "<<getname()<<endl;
		cout<<"The number is "<<getnumber()<<endl;
	}
	else{	
		cout<<"not found..."<<endl;
	}
}
void SearchData(Pms obj[],string naam)
{
	for(int i=0;i<2;i++)
	{ 
		obj[i].Search_data(naam);
	//	cout<<obj[i].getname();
		
	}
}


void Pms::Delete_data(string naam){
	if(naam[0]==name[0])
	{
		name="NULL";
		number="NULL";
		cout<<"The name found is deleted"<<endl;
		cout<<"The number found is deleted"<<endl;
	}
	else{	
		cout<<"not found..."<<endl;
	}
}
void Delete(Pms obj[],string naam)
{
	for(int i=0;i<2;i++)
	{ 
		cout<<obj[i].getname();
		obj[i].Delete_data(naam);
	}
}
			

void Pms::Modify_data(string naam){
	if(naam[0]==name[0])
	{
		cout<<"The name found is"<<getname()<<endl;
		cout<<"The number found is "<<getnumber()<<endl;
		cout<<"The modification of name is "<<endl;
		cin.ignore();
		getline(cin,name);
		cout<<"The modification of number is "<<endl;
		cin.ignore();
		getline(cin,number);

		setname(name);
		setnumber(number);
			
	}
	else{	
		cout<<"not found..."<<endl;
	}
}
void Modify(Pms obj[],string naam)
{
	for(int i=0;i<2;i++)
	{ 
		obj[i].Modify_data(naam);
		cout<<obj[i].getname();
	}
}

void Speed_dial()
{
	int* a = NULL;  
	int numbers;        
	cout<<"Enter Size needed for array"<<endl;  
	cin >> numbers;      	
	a = new int[numbers];  
	for (int i=0; i<numbers; i++) {
    a[i] = 0; 
    cout<<"input numbers you want to save in speed dial"<<endl;
	cin>>a[i];
	
	}

	delete [] a;
  	a = NULL;     	
}

int main()
{
	cout<<"******** WELCOME ********"<<endl;
	cout<<"  ******** TO *******"<<endl;
	cout<<"		***** MY *****	"<<endl;
	cout<<"*** PHONE DIRECTORY ***"<<endl;
	cout<<endl<<endl<<endl;

	string name,number;
	string naam,namber,del_name,mod_name;
	int i=0,n;

	system("color 8E");
	//system("color OA"); 						For Colour Menu foreground and background
	
	Pms obj[10];
	int c1=0;	
	while(n!=7){
	Choice();
	cin>>n;
	
	
	cout<<"Its Iteration "<<i+1<<endl;
	switch(n){
	
		case 1:
			{
				system("cls");
				cout<<"*********************ADD DATA*************************"<<endl; 
				//cin.ignore();
				cout<<"enter the name you want to save :"<<endl;
				getline(cin,name);
				cin.ignore();
				cout<<"enter the phone number you want to save :"<<endl;
				getline(cin,number);
				
				obj[i].setname(name);
				obj[i].setnumber(number);
				obj[i].getname();
				obj[i].getnumber();
				c1+=1;
				break;			
			}
			case 2:
			{
				system("cls");
				cout<<"*******************SEARCH FOR DATA************************"<<endl;
				
				cout<<"enter the name you want to search"<<endl;
				cin.ignore();
				getline(cin,naam);
				SearchData(obj,naam);
				break;
			}
			case 3:
			{
				system("cls");
				cout<<"*****************SHOW RECORD STORED**********************"<<endl;
				for(int  i=0;i<c1;i++)
				obj[i].Display();										//function to Display DAta
				break;
			}
			case 4:
			{
				system("cls");
				cout<<"*****************MODIFY RECORD STORED********************"<<endl;
				cout<<"Enter the name you want to change"<<endl;
				cin.ignore();
				getline(cin,mod_name);
				c1+=1;
				Modify(obj,mod_name);
				break;
			}
			case 5:
			{				
				system("cls");
				cout<<"*****************DELETE RECORD STORED************************"<<endl;
				cout<<"Enter the name you want to delete "<<endl;
				cin.ignore();
				getline(cin,del_name);	
				Delete(obj,del_name);
				break;
			}	
			case 6:
			{
				system("cls");
				cout<<"*********************ADD SPEED DIAL NUMBEERS******************"<<endl;
				Speed_dial();
				break;
			}
			case 7:
			{
				cout<<"**********************Exit THE PROGRAM*************************"<<endl;
				return 0;
			}
	}
	i++;
}
}
