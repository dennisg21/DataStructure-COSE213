/** 
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */

// destructor
template <class HashMapElemType>
HashMap<HashMapElemType>::~HashMap() 
{
	int i = 0;
	for(i = 0; i < capacity; i++)
	{
		if(ht[i] != NULL)
		{
			HashMapElemType* previous = NULL;
			HashMapElemType* current = ht[i];
			while(current != NULL)
			{
				previous = current;
				current = current -> link;
				delete previous;
			}
		}
	}
	delete[] ht;
}
	
template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	unsigned int hvalue = hashfunction(k);
	HashMapElemType* current = ht[hvalue];
	while(current != NULL)
	{
		if(current -> key != k)
		{
			current = current -> link;
		}
		else
		{
			break;
		}
	}
	return current;
}
	
template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	unsigned int hvalue = hashfunction(k);
	HashMapElemType* tmp = new HashMapElemType;
	tmp -> key = k;
	tmp -> val = v;
	tmp -> link = NULL;
	if(ht[hvalue] != NULL)
	{
		if(ht[hvalue] -> key == k)
		{
			tmp ->link = ht[hvalue] -> link;
			ht[hvalue] = tmp;
		}
		else
		{
			HashMapElemType* current = ht[hvalue];
			while(current -> link != NULL)
			{
				if(current -> key == k)
				{
					ht[hvalue] = current;
					break;
			}
			current = current -> link;
			}
			if(current -> key != k)
			{
				current -> link = tmp;
				mapsize = mapsize + 1;
			}
		}	
		
	}
	else
	{
		ht[hvalue] = tmp;
		mapsize = mapsize + 1;
	}

}
		
template <class HashMapElemType>
bool 
HashMap<HashMapElemType>::remove(const KeyType k) 
{
	unsigned int hvalue = hashfunction(k);
	if(ht[hvalue] != NULL)
	{
		HashMapElemType* current = ht[hvalue];
		HashMapElemType* previous;
		while(current -> key != k)
		{
			previous = current;
			current = current -> link;
		}
		previous -> link = current -> link;
		delete [] current;
		mapsize = mapsize -1;
		return true;
	}
	else
	{
		return false;	
	}
}
	
template <class HashMapElemType>
unsigned int 
HashMap<HashMapElemType>::hashfunction(const KeyType k)
{
	unsigned int hkey = 0;
	unsigned int hvalue = 0;
	for(int i = 0; k[i] != '\0'; ++i)
	{
		hkey = hkey + (unsigned int)k[i];
	}
		return hkey % divisor;
		
}

template <class HashMapElemType>
void 
HashMap<HashMapElemType>::print()
{
	HashMapElemType* printlist[mapsize];
	int i;
	int location = 0;
	for(i = 0; i < capacity; i++)
	{
		HashMapElemType* current = ht[i];
		while(current != NULL)
		{
			printlist[location] = current;
			location++;
			current = current -> link;
		}
	}
	
	//decreasing order of value
	int j;
	for(i = 0; i < mapsize - 1; i++)
	{
		for(j = i + 1; j < mapsize; j++)
		{
			if(printlist[i] -> val < printlist[j] -> val)
			{
				HashMapElemType* tmp = printlist[i];
				printlist[i] = printlist[j];
				printlist[j] = tmp;
			}
		}
	}
	
	for(i = 0; i < mapsize; i++)
	{
		std::cout << printlist[i] ->key <<":"<<printlist[i]->val<<std::endl;
	}
}
