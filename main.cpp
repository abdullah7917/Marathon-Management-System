#include "marathon.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	marathon my_marathon;
	runner_detail new_runner;

	int list_number = 0;

	while (list_number != 7)
	{
		cout    <<"\nlist of actions"
                	<<"\n1. add a ruuner."
			<<"\n2. display all runner"
                	<<"\n3. add a race "
                	<<"\n4. display races"
			<<"\n5. display medals"
			<<"\n6. remove runner"
			<<"\n7. quit"<<endl;
	        cin >> list_number;
		cin.ignore(100, '\n');

		if (list_number == 1)
		{
			int result = my_marathon.add_runner(new_runner);

			if (result == 1)
				cout<<"Runner added successfully"<<endl;
			else
				cout<<"Failed to add runner"<<endl;
		}	
		else if (list_number == 2)
		{
			int result = my_marathon.display_all();

			if (result == 1)
                                cout<<"Displayed  successfully"<<endl;
                        else
                                cout<<"Failed to display"<<endl;
		}
		else if (list_number == 3 )
		{
			race new_race;

			char name[100];
			cout << "Enter participant name: ";
        		cin.getline(name, 100);

			int result = my_marathon.add_race(name, new_race);
			if (result ==  1)
				cout<<"Race added "<<endl;
			else 
				cout << "Participant not found" <<endl;
		}
		else if (list_number == 4)
		{
			char name[100];
			cout << "Enter participant name: ";
			cin.getline(name, 100);
			
			int result = my_marathon.display_race(name);

			if (result == 1)
				cout<<"displayed successfully"<<endl;
			else
				cout<<"Failed to display"<<endl;
		}
		else if (list_number ==5)
		{
			char name[100];
                        cout << "Enter participant name: ";
                        cin.getline(name, 100);
			              
			int result = my_marathon.display_medal(name);	
			
			if (result == -1)
				cout<<"participant not found"<<endl;
			else if (result == 0)
                                cout<<"participant has no medals"<<endl;
			else if (result == 1)
				cout<<"displayed successfully"<<endl;
		}

		else if (list_number ==6)	
		{
			char name[100];
                        cout << "Enter participant name: ";
                        cin.getline(name, 100);

			int result = my_marathon.remove_runner(name);

			if (result == 1)
                                cout<<"removed successfully"<<endl;
                        else
                                cout<<"runner not found"<<endl;
		}
		else if (list_number == 7)
		{
			cout<<"Thank you"<<endl;
		}
		else 
			cout<<"invalid, try again"<<endl;
	}

	
	return 0;
}

