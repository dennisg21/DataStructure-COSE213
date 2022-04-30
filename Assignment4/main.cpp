/** 
  * Assignment 4 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 6. 1
  *
  */
#include "SearchTree.h"  
#include "LinkedBinaryTree.h"

#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#include <iostream>
 
using namespace std;

int main()
{
	typedef Entry<int, float> EntryType;
	SearchTree<EntryType> st1;
	AVLTree<EntryType> avl1;
	//
	// SearchTree random test nElem=100
	//
	std::cout << "SearchTree random test nElem=100" << std::endl;

	int nElem = 100;
	int *k1 = new int[nElem*2];
	float *v1 = new float[nElem*2];
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0; i<nElem*2; i++)
	{
		k1[i] = std::rand();
		v1[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	clock_t time;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st1.insert(k1[i], v1[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st1.find(k1[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	bool T;
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {st1.find(k1[i]);}
		else {st1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {st1.find(k1[i]);}
		else {st1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {st1.find(k1[i]);}
		else {st1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {st1.find(k1[i]);}
		else {st1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {st1.find(k1[i]);}
		else {st1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);
	


	std::cout << "------------------------------" << std::endl;
	


	//
	// AVLTree random test nElem=100
	//
	std::cout << "AVLTree random test nElem=100" << std::endl;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl1.insert(k1[i], v1[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl1.find(k1[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {avl1.find(k1[i]);}
		else {avl1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {avl1.find(k1[i]);}
		else {avl1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {avl1.find(k1[i]);}
		else {avl1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {avl1.find(k1[i]);}
		else {avl1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {avl1.find(k1[i]);}
		else {avl1.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);




	std::cout << "------------------------------" << std::endl;


	SearchTree<EntryType> st2;
	AVLTree<EntryType> avl2;

	//
	// SearchTree random test nElem=1000
	//
	std::cout << "SearchTree random test nElem=1000" << std::endl;

	nElem = 1000;
	int *k2 = new int[nElem*2];
	float *v2 = new float[nElem*2];
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0; i<nElem*2; i++)
	{
		k2[i] = std::rand();
		v2[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st2.insert(k2[i], v2[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st2.find(k2[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {st2.find(k1[i]);}
		else {st2.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {st2.find(k1[i]);}
		else {st2.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {st2.find(k1[i]);}
		else {st2.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {st2.find(k1[i]);}
		else {st2.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {st2.find(k1[i]);}
		else {st2.erase(k1[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	
	std::cout << "------------------------------" << std::endl;



	//
	// AVLTree random test nElem=1000
	//
	std::cout << "AVLTree random test nElem=1000" << std::endl;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl2.insert(k2[i], v2[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl2.find(k2[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {avl2.find(k2[i]);}
		else {avl2.erase(k2[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {avl2.find(k2[i]);}
		else {avl2.erase(k2[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {avl2.find(k2[i]);}
		else {avl2.erase(k2[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {avl2.find(k2[i]);}
		else {avl2.erase(k2[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {avl2.find(k2[i]);}
		else {avl2.erase(k2[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	std::cout << "------------------------------" << std::endl;

	//
	// SearchTree random test nElem=10000
	//
	SearchTree<EntryType> st3;
	AVLTree<EntryType> avl3;

	std::cout << "SearchTree random test nElem=10000" << std::endl;

	nElem = 10000;
	int *k3 = new int[nElem*2];
	float *v3 = new float[nElem*2];
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0; i<nElem*2; i++)
	{
		k3[i] = std::rand();
		v3[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st3.insert(k3[i], v3[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st3.find(k3[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {st3.find(k3[i]);}
		else {st3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {st3.find(k3[i]);}
		else {st3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {st3.find(k3[i]);}
		else {st3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {st3.find(k3[i]);}
		else {st3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {st3.find(k3[i]);}
		else {st3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);



	
	std::cout << "------------------------------" << std::endl;



	//
	// AVLTree random test nElem=10000
	//
	std::cout << "AVLTree random test nElem=10000" << std::endl;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl3.insert(k3[i], v3[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl3.find(k3[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {avl3.find(k3[i]);}
		else {avl3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {avl3.find(k3[i]);}
		else {avl3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {avl3.find(k3[i]);}
		else {avl3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {avl3.find(k3[i]);}
		else {avl3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {avl3.find(k3[i]);}
		else {avl3.erase(k3[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	std::cout << "------------------------------" << std::endl;
	delete [] k3;
	delete [] v3;


	//
	// SearchTree random test nElem=100000
	//
	SearchTree<EntryType> st4;
	AVLTree<EntryType> avl4;

	std::cout << "SearchTree random test nElem=100000" << std::endl;

	nElem = 100000;
	int *k4 = new int[nElem*2];
	float *v4 = new float[nElem*2];
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0; i<nElem*2; i++)
	{
		k4[i] = std::rand();
		v4[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st4.insert(k4[i], v4[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st4.find(k4[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {st4.find(k4[i]);}
		else {st4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {st4.find(k4[i]);}
		else {st4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {st4.find(k4[i]);}
		else {st4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {st4.find(k4[i]);}
		else {st4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {st4.find(k4[i]);}
		else {st4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);



	
	std::cout << "------------------------------" << std::endl;



	//
	// AVLTree random test nElem=100000
	//
	std::cout << "AVLTree random test nElem=100000" << std::endl;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl4.insert(k4[i], v4[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl4.find(k4[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {avl4.find(k4[i]);}
		else {avl4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {avl4.find(k4[i]);}
		else {avl4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {avl4.find(k4[i]);}
		else {avl4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {avl4.find(k4[i]);}
		else {avl4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {avl4.find(k4[i]);}
		else {avl4.erase(k4[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);
	
	std::cout << "------------------------------" << std::endl;
	delete [] k4;
	delete [] v4;



	//
	// SearchTree random test nElem=1000000
	//
	SearchTree<EntryType> st5;
	AVLTree<EntryType> avl5;

	std::cout << "SearchTree random test nElem=1000000" << std::endl;

	nElem = 1000000;
	int *k5 = new int[nElem*2];
	float *v5 = new float[nElem*2];
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0; i<nElem*2; i++)
	{
		k5[i] = std::rand();
		v5[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st5.insert(k5[i], v5[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		st5.find(k5[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {st5.find(k5[i]);}
		else {st5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {st5.find(k5[i]);}
		else {st5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {st5.find(k5[i]);}
		else {st5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {st5.find(k5[i]);}
		else {st5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {st5.find(k5[i]);}
		else {st5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);
	


	
	std::cout << "------------------------------" << std::endl;

	delete [] k5;
	delete [] v5;

	//
	// AVLTree random test nElem=1000000
	//
	std::cout << "AVLTree random test nElem=1000000" << std::endl;
	
	// a
	std::cout << "a" << std::endl;

    	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl5.insert(k5[i], v5[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// b
	std::cout << "b" << std::endl;

	time = clock();
	for(int i=0; i<nElem; i++)
	{
		avl5.find(k5[i]);
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// c
	std::cout << "c" << std::endl;

	// erase/find 20:80
	std::cout << "erase/find 20:80" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<20;
		if (T==true) {avl5.find(k5[i]);}
		else {avl5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 40:60
	std::cout << "erase/find 40:60" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<40;
		if (T==true) {avl5.find(k5[i]);}
		else {avl5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);


	// erase/find 50:50
	std::cout << "erase/find 50:50" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<50;
		if (T==true) {avl5.find(k5[i]);}
		else {avl5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 60:40
	std::cout << "erase/find 60:40" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<60;
		if (T==true) {avl5.find(k5[i]);}
		else {avl5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	// erase/find 80:20
	std::cout << "erase/find 80:20" << std::endl;

	time = clock();
	
	for(int i=nElem; i<nElem*2; i++)
	{
		T=(std::rand()/100)<80;
		if (T==true) {avl5.find(k5[i]);}
		else {avl5.erase(k5[i]);}
	}
	time = clock() - time;
	printf ("It took me %f seconds.\n",((float)time)/(float)CLOCKS_PER_SEC);

	std::cout << "------------------------------" << std::endl;
	return 0;

}
