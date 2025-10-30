//ABDULLAH ALI KHAN, CS163, PROGRAM 1, KHANAB@PDX.EDU
//Purpose: this file defines the structs and the class
//
//
//
//
//


#include <iostream>
#include <cctype>
#include <cstring>


struct race
{
    char * race_name;
    char * location;
    char * placement;
    char * time_record;

};

struct race_node
{
	race data;
	race_node * next;
};

struct runner_detail
{	
	char * name;
	char * date_of_birth;
	char * gender;
	char * nationality;
	char * info;
	char * club;
	int age;

};

struct runner_node
{
	runner_detail data;
	race_node * head;
	runner_node * next;

};


class marathon
{
	public:			
	marathon();
	~marathon();
	int add_runner(runner_detail & new_runner);
	int display_all();
	int add_race(char name [],  race & new_race);
	int display_race(char name[]);
	int display_medal(char name[]);
	int remove_runner(char name[]);
	private:
	runner_node * head;
       
};






