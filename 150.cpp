#include<conio.h>
#include<fstream>
#include<string.h>
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int ch;
	Main:
	system("cls");
	cout<<"\n---------------------------------------\n";
	cout<<"     Health Club Record Management\n";
	cout<<"---------------------------------------\n\n";
	cout<<"    1) Info about Equipment/Exercise\n";
	cout<<"    2) Display Members/Trainers\n";
	cout<<"    3) Add/Delete Members\n";
	cout<<"    4) Add/Delete Trainers\n";
	cout<<"    5) Info about Joining/Training\n";
	cout<<"    6) Exit from program\n\n";
	cout<<"      Enter your Choice = ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			Info:
			system("cls");	
		    cout<<"\n---------------------------------------\n";
	        cout<<"     Info about Equipment/Exercise\n";
			cout<<"---------------------------------------\n\n";
			cout<<"        Get the Fee detail of -\n\n";
		    cout<<"           1) Eqipment\n";
		    cout<<"           2) Exercise\n";
		    cout<<"           3) Back\n\n";
		    cout<<"      Enter your Choice = ";
		    cin>>ch;
		    switch(ch)
		    {
		    	case 1:
		    	{
					system("cls");
					cout<<"\n---------------------------------------\n";
					cout<<"         Info about Equipment\n";
					cout<<"---------------------------------------\n\n";
					cout<<"              Trademill -\n";
					cout<<"         It Costs around 16,800.\n\n";
					cout<<"               Dumble -\n";
					cout<<"It Costs around 999 for pack of 2KG each.\n\n";
					cout<<"            Exercise Cycle -\n";
					cout<<"        It Costs around 10,800.";
		    		getch();
		    		goto Info;
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n---------------------------------------\n";
					cout<<"          Info about Exercise\n";
					cout<<"---------------------------------------\n\n";
					cout<<"              Chest Day -\n";
					cout<<"           3 sets of 10 ...\n\n";
					cout<<"              Back Day -\n";
					cout<<"    Seated Cable Row, 3 sets of 10 ...\n\n";
					cout<<"            Shoulder Day -\n";
					cout<<" Seated Dumble Press, 3 sets of 10 ...";
					getch();
					goto Info;
				}
				break;
				case 3:
				{
					goto Main;
				}
				break;
				default:
				{
					printf("\n        Wrong Choice ...!!");
			        getch();
			        goto Info;
				}	
		    }
		}
		break;
		case 2:
		{
			int ch;
			Disp:
		    system("cls");	
		    cout<<"\n---------------------------------------\n";
	        cout<<"       Display Members/Trainers\n";
			cout<<"---------------------------------------\n\n";
		    cout<<"     1) Display record of Member\n";
		    cout<<"     2) Display record of Trainer\n";
		    cout<<"     3) Back to previous mode\n\n";
		    cout<<"      Enter your Choice = ";
		    cin>>ch;
		    switch(ch)
		    {
		    	case 1:
		    	{
		    		system("cls");
		    		fstream M;
		    		string temp;
		    		cout<<"\n---------------------------------------\n";
	                cout<<"                Members\n";
		        	cout<<"---------------------------------------\n\n"; 
		    		cout<<"         Total Members are :-\n\n";
                    M.open("Member.txt",ios::in);
                    int i=1;
                    while(!M.eof())
                    {
   	                    fflush(stdin);
						M>>temp;
						cout<<"         "<<i<<") "<<temp<<"\n";
						i++;
					}
					M.close();
		    		getch();
		    		goto Disp;
				}
				break;
				case 2:
				{
					system("cls");
					fstream T;
					string temp;
					cout<<"\n---------------------------------------\n";
	                cout<<"               Trainers\n";
		        	cout<<"---------------------------------------\n\n"; 
					cout<<"         Total Trainers are :-\n\n";
                    T.open("Trainer.txt",ios::in);
                    int i=1;
                    while(!T.eof())
                    {
   	                    fflush(stdin);
						T>>temp;
						cout<<"         "<<i<<") "<<temp<<"\n";
						i++;
					}
					T.close();
					getch();
					goto Disp;
				}	
				break;
				case 3:
				{
					goto Main;
				}	
				break;
				default:
				{
					printf("\n        Wrong Choice ...!!");
			        getch();
			        goto Disp;
				}	
			}
	    }
		break;
		case 3:
		{
			Addmember:
		    system("cls");	
		    cout<<"\n---------------------------------------\n";
	        cout<<"          Add/Delete Members\n";
			cout<<"---------------------------------------\n\n";
			cout<<"         1) Add Member\n";
		    cout<<"         2) Delete Member\n";
		    cout<<"         3) Back\n\n";
		    cout<<"       Enter your Choice = ";
		    cin>>ch;
		    switch(ch)
		    {
		    	case 1:
		    	{
		    		system("cls");
		    		int id;
		    		string name;
		    		fstream M;
		    		cout<<"\n---------------------------------------\n";
	                cout<<"              Add Members\n";
					cout<<"---------------------------------------\n\n";
					cout<<"   Enter Member Name = ";
					cin>>name;
					cout<<"\n     Enter Member Id = ";
					cin>>id;
					M.open("Member.txt",ios::app);
					M<<name<<endl;
					cout<<"\n\nCongrats.. Member added Successfully...";
					getch();
					goto Addmember;
				}
				break;
				case 2:
				{
					system("cls");
		    		string name,temp1,temp_name,var;
		    		fstream M,temp;
		    		cout<<"\n---------------------------------------\n";
	                cout<<"            Delete Members\n";
					cout<<"---------------------------------------\n\n";
					cout<<"         Total Members are :-\n\n";
                    M.open("Member.txt",ios::in);
                    int i=1;
                    while(!M.eof())
					{
					 fflush(stdin);
					 M>>temp1;
					 cout<<"         "<<i<<") "<<temp1<<"\n";
					 i++;
					}
					M.close();
					M.open("Member.txt",ios::in);
					temp.open("temp.txt",ios::app);
					cout<<"\nEnter Member Name = ";
					fflush(stdin);
					cin>>temp_name;
					int c=0;
					while(getline(M,var))
					{
					    if(var!=temp_name)
                        {
   	                        temp<<var<<endl;		
	                    }
	                    else
                   	    {
	                        c++;	
                	    } 
                    }
                    if(c==0)
                    {
					    cout<<"\nSorry.. "<<temp_name<<" is not present in List.";
                  	    M.close();
   	                    temp.close();
   	                    remove("Member.txt");
   	                    rename("temp.txt","Member.txt");
   	                    getch();
					    goto Addmember;
				    }
					else
                    {
					    cout<<"\nCongrats.. "<<temp_name<<" is deleted from List.";
                  	    M.close();
   	                    temp.close();
   	                    remove("Member.txt");
   	                    rename("temp.txt","Member.txt");
   	                    getch();
					    goto Addmember;
				    }	
			    }
			    case 3:
				{
					goto Main;
				}	
				break;
				default:
				{
					printf("\n        Wrong Choice ...!!");
			        getch();
			        goto Addmember;
				}	
			}	
		}
		break;
		case 4:
		{
			Addtrainer:
		    system("cls");	
		    cout<<"\n---------------------------------------\n";
	        cout<<"           Add/Delete Trainers\n";
			cout<<"---------------------------------------\n\n";
			cout<<"         1) Add Member\n";
		    cout<<"         2) Delete Member\n";
		    cout<<"         3) Back\n\n";
		    cout<<"       Enter your Choice = ";
		    cin>>ch;
		    switch(ch)
		    {
		    	case 1:
		    	{
		    		system("cls");
		    		int id;
		    		string name;
		    		fstream T;
		    		cout<<"\n---------------------------------------\n";
	                cout<<"             Add Trainers\n";
					cout<<"---------------------------------------\n\n";
					cout<<"  Enter Trainer Name = ";
					cin>>name;
					cout<<"\n     Enter Member Id = ";
					cin>>id;
					T.open("Trainer.txt",ios::app);
					T<<name<<endl;
					cout<<"\n\nCongrats.. Trainer added Successfully...";
					getch();
					goto Addtrainer;
				}
				break;
				case 2:
				{
					system("cls");
		    		string name,temp1,temp_name,var;
		    		fstream T,temp;
		    		cout<<"\n---------------------------------------\n";
	                cout<<"           Delete Trainers\n";
					cout<<"---------------------------------------\n\n";
					cout<<"         Total trainers are :-\n\n";
                    T.open("Trainer.txt",ios::in);
                    int i=1;
                    while(!T.eof())
					{
					 fflush(stdin);
					 T>>temp1;
					 cout<<"         "<<i<<") "<<temp1<<"\n";
					 i++;
					}
					T.close();
					T.open("Trainer.txt",ios::in);
					temp.open("temp.txt",ios::app);
					cout<<"\nEnter Trainer Name = ";
					fflush(stdin);
					cin>>temp_name;
					int c=0;
					while(getline(T,var))
					{
					    if(var!=temp_name)
                        {
   	                        temp<<var<<endl;		
	                    }
	                    else
                   	    {
	                        c++;	
                	    } 
                    }
                    if(c==0)
                    {
					    cout<<"\nSorry.. "<<temp_name<<" is not present in List.";
                  	    T.close();
   	                    temp.close();
   	                    remove("Trainer.txt");
   	                    rename("temp.txt","Trainer.txt");
   	                    getch();
					    goto Addtrainer;
				    }
					else
                    {
					    cout<<"\nCongrats.. "<<temp_name<<" is deleted from List.";
                  	    T.close();
   	                    temp.close();
   	                    remove("Trainer.txt");
   	                    rename("temp.txt","Trainer.txt");
   	                    getch();
					    goto Addtrainer;
				    }	
			    }
			    case 3:
				{
					goto Main;
				}	
				break;
				default:
				{
					printf("\n        Wrong Choice ...!!");
			        getch();
			        goto Addtrainer;
				}	
			}
		}
		break;
		case 5:
		{
			Fee:
			system("cls");	
		    cout<<"\n---------------------------------------\n";
	        cout<<"      Info about Joining/Training\n";
			cout<<"---------------------------------------\n\n";
			cout<<"        Get the Fee detail of -\n\n";
		    cout<<"         1) Member Joining\n";
		    cout<<"         2) Training Schedule\n";
		    cout<<"         3) Back\n\n";
		    cout<<"      Enter your Choice = ";
		    cin>>ch;
		    switch(ch)
		    {
		    	case 1:
		    	{
					system("cls");
					cout<<"\n---------------------------------------\n";
					cout<<"       Fee about Member Joining\n";
					cout<<"---------------------------------------\n\n";
					cout<<"             For 1 Month -\n";
					cout<<"          It Cost around 800.\n\n";
					cout<<"             For 3 Month -\n";
					cout<<"         It Costs around 2,000.\n\n";
					cout<<"             For 1 Year -\n";
					cout<<"         It Costs around 7,500.";
		    		getch();
		    		goto Fee;
				}
				break;
				case 2:
				{
					system("cls");
					cout<<"\n---------------------------------------\n";
					cout<<"      Fee about Training Schedule\n";
					cout<<"---------------------------------------\n\n";
					cout<<"             For 1 Month -\n";
					cout<<"          It Cost around 500.\n\n";
					cout<<"             For 3 Month -\n";
					cout<<"         It Costs around 1,200.\n\n";
					cout<<"             For 1 Year -\n";
					cout<<"         It Costs around 5,000.";
					getch();
					goto Fee;
				}
				break;
				case 3:
				{
					goto Main;
				}
				break;
				default:
				{
					printf("\n        Wrong Choice ...!!");
			        getch();
			        goto Fee;
				}	
		    }
		}	
		case 6:
		{
			exit(0);
		}	
		break;
		default:
		{
			printf("\n        Wrong Choice ...!!");
			getch();
			goto Main;
		}		
	}
	getch();
	return 0;
}
