#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cstdlib>

typedef struct Student
{
	char first_letter_name;
	char first_letter_surname;
	int grade;
	

}Student;

typedef struct StudentsArray
{
	Student **element;

}StudentsArray;

typedef struct Iterator
{
	Student *start;
	Student *object;
	Student *stop;
	Student **current;
	Student **temp;
	
}Iterator;

void set_student(const char name, const char surname,const int note,Student  *pupil)
{
	
	pupil->first_letter_name = name;
	pupil->first_letter_surname = surname;
	pupil->grade = note;
	
}
 void print(Student pupil)
 {
 	std::cout<<"Initials: "<<pupil.first_letter_name<<". "<<pupil.first_letter_surname<<".   grade:"<<pupil.grade<<"\n";
 }
 void  init_array(StudentsArray *array,const int number )
 {
 	array->element = (Student **) malloc (number * sizeof(Student*));
 	if(array->element == NULL)
 	{
 		std::cout<<"Can't alloc memory!";
 		exit(-1);
 	}
 }
void init_iter (StudentsArray *array, Iterator *iter)
 {
 	iter->start = array->element[0];
 	iter->current = array->element;
 	iter->temp = array->element;
 	iter->stop = array->element[2];
 	iter->object = iter->start;

 }


void move_forward(Iterator *iter)
 {
 	if(*iter->temp == iter->stop)
 	{
 		iter->object = NULL;
 		iter->temp = iter-> current;
 		
 	}
 	else
 	{
 	(iter->temp)++;
 	iter->object = *iter->temp;
 	}
 }
void select_element(Iterator *iter, const int number)
{
	
	iter->object = iter->current[number];
	iter->temp = &(iter->current[number]);
}
void delete_array (StudentsArray *simpsons)
{
	/*for(int count=0; count<3; count++)
	{
		free(simpsons->element[count]);
	}*/
	free(simpsons->element);
}



#endif