#include "dynamicArray.h"

DynamicArray::DynamicArray(unsigned int _capacite){
	tabElements = new int[_capacite];
	capacite = _capacite;

	for (size_t i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray& _copie)
	:capacite(_copie.capacite),
	tabElements(new int[_copie.capacite])
{
	for (size_t i = 0; i < capacite; i++)
	{
		tabElements[i] = _copie.tabElements[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& _rhs) {

	if (&_rhs != this){
		delete[] tabElements;
		capacite = _rhs.capacite;
		tabElements = new int[_rhs.capacite];

		for (size_t i = 0; i < capacite; i++)
		{
			tabElements[i] = _rhs.tabElements[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& _rhs) const{
	bool isSame = true;

	if (capacite != _rhs.capacite){
		isSame = false;
	}
	else{
		int counter = 0;
		while (isSame && counter < capacite)
		{
			if (tabElements[counter] != _rhs.tabElements[counter]){
				isSame = false;
			}
			counter++;
		}
	}
	return isSame;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _rhs){
	//if (this != &_rhs){

		int oldCapacite = capacite;
		setCapacite(capacite + _rhs.capacite);
		for (size_t i = 0; i < _rhs.capacite; i++)
		{
			tabElements[i + oldCapacite] = _rhs.tabElements[i];
		}
		
	//}
	return *this;
}


int DynamicArray::getCapacite(){
	return capacite;
}

int DynamicArray::getElement(unsigned int _index){
	return tabElements[_index];
}

void DynamicArray::setElement(unsigned int _index, int _valeur){

	if (_index >= capacite){
		setCapacite(_index+1);
	}
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(unsigned int _capacite){

	if (_capacite < 1){
		throw;
	}
	

	int* newTab = new int[_capacite];

	for (size_t i = 0; i < _capacite; i++)
	{
		newTab[i] = 0;
	}

	for (size_t i = 0; i < capacite; i++)
	{
		if (i <= _capacite){
			newTab[i] = tabElements[i];
		}
	}

	capacite = _capacite;
	delete tabElements;
	tabElements = newTab;
}