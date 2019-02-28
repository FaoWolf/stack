#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct s_stack
{
	void	*data;
	Stack	*next;
};

Stack*	create(void *data)
{
	Stack *s;		// garde en mémoire la valeur
	s = (Stack*)malloc(sizeof(Stack));
	if (!s)			// s == NULL
		return NULL; 	// ou s (car s = NULL)
	s->data = data;		// s.data mais pour pointeur
	s->next = NULL;		// initialise
	return s;
}

Stack*	push(Stack *s, void *data)
{
	Stack *new;
	
	new = create(data);
	if(! new)
		return s;
	new->next = s;
	return new;
}

Stack*	pop(Stack *s, void(*f)(void *))
{
	if(!s)
		return NULL;

	Stack *old;

	old = s->next;
	if (f)
		f(s->data);	
	free(s);
	return old;
}

void*	peek(Stack *s)
{
	// (condition) ? si vrai : sinon;
	return (s) ? s->data : NULL;
}

void	foreach(Stack *s, void(*f)(void *))
{
	if(!f)
		return;
	while(s)
	{
		f(s->data);
		s = s->next;
	}
}
