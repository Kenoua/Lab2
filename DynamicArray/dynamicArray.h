#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

using namespace std;

class DynamicArray
{

public:

	DynamicArray(unsigned int _capacite = 100);
	DynamicArray(const DynamicArray& _copie);
	//~DynamicArray();

	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int _index);
	void setCapacite(unsigned int _capacite);
	int getCapacite();

	DynamicArray& DynamicArray::operator=(const DynamicArray& _rhs) ;
	bool DynamicArray::operator==(const DynamicArray& _rhs) const;
	DynamicArray& DynamicArray::operator+=(const DynamicArray& _rhs);

private:

	int* tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_