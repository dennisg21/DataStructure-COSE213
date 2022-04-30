#include "polynomial.h"
#include <iostream>
#include <math.h>


//
// Implementation
//


// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	// ToDo
	int i;
	capacity = source.capacity;
	terms = source.terms;
	termArray = new Term[capacity];
	for (i = 0; i < terms; i++)
	{
		termArray[i] = source.termArray[i];
	}

}

// Destructor
Polynomial::~Polynomial()
{
	// ToDo
	if (termArray != NULL) //To prevent accidental deletion, judge first before deleting
	{
		delete[] termArray;
	}
}


Polynomial& Polynomial::operator = (const Polynomial& source)
{
	// ToDo
	int i;
		if (this != &source)
		{
			delete[] termArray;
			Term* temp = new Term[source.capacity];
			int i;
			for (i = 0; i < capacity; i++)
			{
				temp[i] = source.termArray[i];
			}
			termArray = temp;
			terms = source.terms;
		}
	return *this;
}



// Sum of *this and source polynomials

/*Refer to the addition function above ppt*/
Polynomial Polynomial::operator +(const Polynomial& source)
{
	Polynomial c;

	// ToDo

	int a = 0;
	int b = 0;
	int aterm = terms; 
	int bterm = source.terms;
	while ((a <= aterm) && (b <= bterm)) // the following compare exponet
	{
		if (termArray[a].exp == source.termArray[b].exp)
		{
			float term = termArray[a].coef + source.termArray[b].coef;
			if (term) // if sum is non-zero
			{
				c.CreateTerm(source.termArray[b].coef, source.termArray[b].exp);
			}
			a++;
			b++;
		}
		else if(termArray[a].exp < source.termArray[b].exp)
		{
			c.CreateTerm(source.termArray[b].coef, source.termArray[b].exp);
			b++;
		}
		else 
		{
			c.CreateTerm(termArray[a].coef, termArray[a].exp);
			a++;
		}
	}

	for (; a <= aterm; a++) {
		c.CreateTerm(termArray[a].coef, termArray[a].exp);
	}
	for (; b <= bterm; b++) {
		c.CreateTerm(source.termArray[b].coef, source.termArray[b].exp);
	}
	return c;
}

/*Refer to the addition function above ppt*/
Polynomial Polynomial::operator - (const Polynomial& source)
{
	Polynomial c;

	// ToDo
	int a = 0;
	int b = 0;
	int aterm = terms; 
	int bterm = source.terms;
	while ((a <= aterm) && (b <= bterm))// the following compare exponet
	{
		if (termArray[a].exp == source.termArray[b].exp)
		{
			float term = termArray[a].coef - source.termArray[b].coef;
			if (term)// if sum is non-zero
			{
				c.CreateTerm(source.termArray[b].coef, source.termArray[b].exp);
			}
			a++;
			b++;
		}
		else if (termArray[a].exp < source.termArray[b].exp)
		{
			c.CreateTerm(-source.termArray[b].coef, source.termArray[b].exp);
			b++;
		}
		else
		{
			c.CreateTerm(termArray[a].coef, termArray[a].exp);
			a++;
		}
	}

	for (; a <= aterm; a++) {
		c.CreateTerm(termArray[a].coef, termArray[a].exp);
	}
	for (; b <= bterm; b++) {
		c.CreateTerm(-source.termArray[b].coef, source.termArray[b].exp);
	}
	return c;

}


Polynomial Polynomial::operator * (const Polynomial& source)
{
	Polynomial c;

	// ToDo
	int aterm = terms; int bterm = source.terms;
	int i;
	for (i = 0; i < aterm; i++) {
		for (int j = 0; j < bterm; j++) {
			float k = termArray[i].coef * source.termArray[j].coef;  //According to the rules of mathematics, the coefficients are multiplied
			int combine = termArray[i].exp + source.termArray[j].exp; //According to the rules of mathematics, the exp are added
			Polynomial temp;
			temp.CreateTerm(k, combine);
			c = c + temp;
		}
	}
	return c;
}


float Polynomial::Eval(float x)
{
	float ret = 0;

	// ToDo
	float temp = 1;
	int i, j;
	for (i = 0; i < terms; i++)
	{
		for (j = 0; j < termArray[i].exp; j++)
		{
			temp = temp * x;
		}
		ret += (temp * termArray[i].coef);
	}
	return ret;
}




// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;

	// ToDo
	int i;
	for (i = 0; i < terms; i++)
	{
		if (termArray[i].exp != 0)
		{
			c.CreateTerm(termArray[i].exp * termArray[i].coef, termArray[i].exp - 1);
		}
	}
	return c;

}

/*create term function*/
void Polynomial::CreateTerm(const float coef, const int exp)
{
	// ToDo
	if (terms == capacity) //Exceeding storage capacity
	{
		capacity *= 2;
		Term* temp = new Term[capacity]; //Temporary storage
		std::copy(termArray, termArray + terms, temp); //Copy to a term with a larger capacity
		delete[] termArray;
		termArray = temp;
	}
	//When the normal capacity is sufficient
	termArray[terms].coef = coef;
	termArray[terms].exp = exp;
	terms++;

	int i;
	for (i = 1; i < terms; i++) {
		Term current = termArray[i];
		int j = i - 1;
		while ((j >= 0) && (termArray[j].exp < exp))
		{
			termArray[j + 1] = termArray[j];
			j--;
		}
		termArray[j + 1] = current;
	}
}

