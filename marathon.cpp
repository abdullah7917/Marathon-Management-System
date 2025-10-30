#include "marathon.h"
using namespace std;
#include <iostream>
#include <cstring>

marathon::marathon() {
    head = nullptr;  
}


marathon::~marathon() {
    runner_node* current = head;
    while (current != nullptr) {
        runner_node* temp = current;
        current = current->next;
        
        delete[] temp->data.name;
        delete[] temp->data.date_of_birth;
        delete[] temp->data.gender;
        delete[] temp->data.nationality;
        delete[] temp->data.info;
        delete[] temp->data.club;

        
        race_node* race_current = temp->head;
        while (race_current != nullptr) {
            race_node* race_temp = race_current;
            race_current = race_current->next;

            delete[] race_temp->data.race_name;
            delete[] race_temp->data.location;
            delete[] race_temp->data.placement;
            delete[] race_temp->data.time_record;

            delete race_temp;
        }

        delete temp; 
    }
}

int marathon::add_runner(runner_detail & new_runner)
{
	runner_node * new_node = new runner_node;
	new_node->next = NULL;
	new_node->head = NULL;

	char temp[100];

	cout<<"enter runner's name: ";
	cin.getline(temp,100);
	new_node->data.name = new char[strlen(temp)+1];
	strcpy(new_node->data.name,temp);

	cout<<"enter runner's date of birth: ";
        cin.getline(temp,100);
        new_node->data.date_of_birth = new char[strlen(temp)+1];
        strcpy(new_node->data.date_of_birth,temp);

	cout<<"enter runner's gender: ";
        cin.getline(temp,100);
        new_node->data.gender = new char[strlen(temp)+1];
        strcpy(new_node->data.gender,temp);

	cout<<"enter runner's nationality: ";
        cin.getline(temp,100);
        new_node->data.nationality = new char[strlen(temp)+1];
        strcpy(new_node->data.nationality,temp);

	cout<<"enter runner's information: ";
        cin.getline(temp,100);
        new_node->data.info = new char[strlen(temp)+1];
        strcpy(new_node->data.info,temp);

	cout<<"enter runner's club: ";
        cin.getline(temp,100);
        new_node->data.club = new char[strlen(temp)+1];
        strcpy(new_node->data.club,temp);

	cout<<"enter runner's age: ";
	cin>>new_node->data.age;
	cin.ignore(100, '\n');

	new_node->next = head;
   	head = new_node;

	return 1;
}

int marathon::display_all()
{
        if (head == NULL)
	{
	       	cout << "No runners to display.\n"; 
       	        return 0;
	}
        runner_node * current = head;

        while (current != NULL)
        {
                cout    << "\nName: "<<current->data.name
                        << "\nDOB: "<<current->data.date_of_birth
                        << "\nGender: "<<current->data.gender
                        << "\nNationality: "<<current->data.nationality
                        << "\nInformation: "<<current->data.info
                        << "\nClub: "<<current->data.club
                        << "\nAge: "<<current->data.age<<endl;
    
                current = current->next;
        }
        return 1;
}

int marathon::add_race(char name [],  race & new_race)
{
	if (head == nullptr)
	{
		return 0;
	}
	char temp[100];
	runner_node* current = head;
	while (current != nullptr)
	{
		if (strcmp(current->data.name, name)==0)
		{
			race_node * new_node = new race_node;
			new_node->next = nullptr;

			cout<<"enter the name of the race: ";
        		cin.getline(temp,100);
        		new_node->data.race_name = new char[strlen(temp)+1];
        		strcpy(new_node->data.race_name,temp);

        		cout<<"enter the locatin of the race: ";
        		cin.getline(temp,100);
        		new_node->data.location = new char[strlen(temp)+1];
        		strcpy(new_node->data.location,temp);

        		cout<<"enter the placement: ";
        		cin.getline(temp,100);
        		new_node->data.placement = new char[strlen(temp)+1];
        		strcpy(new_node->data.placement,temp);

        		cout<<"enter the time taken to finish the race: ";
        		cin.getline(temp,100);
        		new_node->data.time_record = new char[strlen(temp)+1];
        		strcpy(new_node->data.time_record,temp);
			
			new_node->next = current->head;
			current->head = new_node;

			return 1;
		}
		current = current->next;
	}
	return 0;
	
}

int marathon::display_race(char name[])
{
	if (head == nullptr)
	{
		cout<<"No runners"<<endl;
		return 0;
	}
	runner_node* current = head;
	
	while (current != nullptr)
	{
		if (strcmp(current->data.name, name) ==0)
		{
			if (current->head == nullptr)
			{
				cout<<"No previous race found of the racer"<<endl;
				 
				return 0;
			}
			race_node* race_current = current->head;
			while (race_current != nullptr)
			{
	                	cout    << "\nname of the race: "<<race_current->data.race_name
        	                	<< "\nlocation of the race: "<<race_current->data.location
                	        	<< "\nplacement: "<<race_current->data.placement
                        		<< "\ntime taken to finish race "<<race_current->data.time_record<<endl;
				 race_current = race_current->next;

				
			}
			return 1;
		}
		current = current ->next;
				
	}
	return 0;
}

int marathon::display_medal(char name[])
{
    if (head == nullptr)
    {
        cout << "No runners" << endl;
        return 0;
    }

    runner_node* current = head;
    bool participant_found = false;
    bool medal_found = false;

    while (current != nullptr)
    {
        if (strcmp(current->data.name, name) == 0)
        {
            participant_found = true;
            race_node* race_current = current->head;

            while (race_current != nullptr)
            {
                if (strcmp(race_current->data.placement, "1") == 0 ||
                    strcmp(race_current->data.placement, "2") == 0 ||
                    strcmp(race_current->data.placement, "3") == 0)
                {
                    cout << "Race: " << race_current->data.race_name
                         << "\nPlacement: " << race_current->data.placement << endl;
                    medal_found = true;
                }
                race_current = race_current->next;
            }
        }
        current = current->next;
    }

    if (!participant_found)
        return -1;
    if (!medal_found)
        return 0;  

    return 1;      
}

int marathon::remove_runner(char name[])
{
	if (head == nullptr)
    	{	
        cout << "No runners" << endl;
        return 0;
    	}

	runner_node* current = head;
    	runner_node* prev = nullptr;

    while (current != nullptr)
    {
       	if (strcmp(current->data.name, name) == 0) 
       	{
            
            if (prev == nullptr)
                head = current->next; 
            else
                prev->next = current->next;

            
            delete[] current->data.name;
            delete[] current->data.date_of_birth;
            delete[] current->data.gender;
            delete[] current->data.nationality;
            delete[] current->data.info;
            delete[] current->data.club;

           
            race_node* race_current = current->head;
            while (race_current != nullptr)
            {
                race_node* temp = race_current;
                race_current = race_current->next;

                delete[] temp->data.race_name;
                delete[] temp->data.location;
                delete[] temp->data.placement;
                delete[] temp->data.time_record;

                delete temp;
            }

            delete current; 
            return 1;       
        }

        prev = current;
        current = current->next;
    }

    return 0; 

}
