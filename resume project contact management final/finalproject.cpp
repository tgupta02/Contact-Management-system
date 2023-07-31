#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<cstdlib>
#include<process.h>

using namespace std;

typedef struct contact
{
    long long ph;
    char name[20], add[50], email[30];
}lst;

char query[20], name[20];

fstream fp, ft;

int i, n, l, found, ch;

class ContactManager
{
    public:
        void addContact()
        {
            lst list;
            fp.open("contact.dll", ios::out | ios::app);
            for(;;)
            {
                fflush(stdin);
                cout << "To exit enter blank space in the name input\nName (Use identical):";
                cin.getline(list.name,20);
                
                if(strcmp(list.name, "")==0 || strcmp(list.name," ")==0)
                    break;
                    
                fflush(stdin);
                cout << "Phone:";
                cin >> list.ph;
                
                fflush(stdin);
                cout << "address:";
                cin.getline(list.add, 50);
                
                fflush(stdin);
                cout << "email address:";
                cin.getline(list.email, 30);
                
                cout << endl;
                fp.write((char*)&list,sizeof(list));
            }
            fp.close();
        }
        
        void listContacts()
        {
            lst list;
            system("cls");
            cout << "\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n";
    


             for(i=97;i<=122;i=i+1)
		    {
		        fp.open("contact.dll", ios::in);
		        fflush(stdin);  
		        found = 0;
		        while(fp.read((char*)&list, sizeof(list)))
		        {
		            if(list.name[0]==i || list.name[0]==i-32)
		            {
		                cout << "\nName\t: " << list.name << "\nPhone\t: " << list.ph << "\nAddress\t: " << list.add << "\nEmail\t: " << list.email << endl;
		                found++;
		            }
		        }
		        if(found!=0)
		        {
		            cout << "=========================================================== [" << (char)(i-32) << "]-(" << found << ")" << endl;
		            cin.get();
		        }
		        fp.close();
		    }
		    cin.get();
        }
        
    void search_contact()
    {
	lst list;
	char c;
    system("cls");
        do
        {
            found=0;
            cout<<"\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ";
            fflush(stdin);
            cin>>query;
            l=strlen(query);
            fp.open("contact.dll", ios::in);
            system("cls");
            cout<<"\n\n..::Search result for "<<query<<" \n===================================================\n";
            while(fp.read((char*)&list, sizeof(list)))
            {
                for(int i=0; i<=l; i++)
                    name[i]=list.name[i];

                name[l]='\0';
                if(strcmp(name,query)==0)
                {
                    cout<<"\n..::Name\t: "<<list.name<<"\n..::Phone\t: "<<list.ph<<"\n..::Address\t: "<<list.add<<"\n..::Email\t: "<<list.email<<"\n";
                    found++;
                    if (found%4==0)
                    {
                        cout<<"..::Press any key to continue...";
                        cin>>c;
                    }
                }
            }
            if(found==0)
                cout<<"\n..::No match found!";
            else
                cout<<"\n..::"<<found<<" match(s) found!";

            fp.close();
            cout<<"\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t";
            cin>>ch;
        }
        while(ch==1);
        /* *********************edit contacts************************/
    }
    

};

int main()
{
    ContactManager contactManager;
    while(1)
    {
        system("cls");
        cout << "\n\t **** Welcome to Contact Management System ****";
	    cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
	    cout << "Enter the choice:";
	    cin >> ch;
        switch(ch)
        {
        	case 0:
                exit(0);
                break;
            case 1:
                contactManager.addContact();
                break;
            case 2:
                contactManager.listContacts();
                break;
            case 3:
                contactManager.search_contact();
                break;

            default:
                cout << "\nEnter valid option";
                break;    
        }
    }
  
}

