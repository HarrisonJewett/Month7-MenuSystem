#pragma once
template <typename Type>
class DynArray
{
private:
	Type * array = nullptr;
	unsigned int Size, Capacity;

public:
	//Default constructor
	DynArray()
	{
		Size = 0;
		Capacity = 0;
		array = nullptr;
	}
	//Default deconstructor
	~DynArray() { delete[] array; }
	//Copy constructor
	DynArray(const DynArray<Type>& that)
	{
		Size = that.Size;
		Capacity = that.Capacity;
		array = new Type[Capacity];
		for (unsigned int i = 0; i < Size; ++i)
			array[i] = that.array[i];
	}
	//Assignment operator
	DynArray<Type>& operator=(const DynArray<Type>& that)
	{
		if (this != &that)
		{
			Size = that.Size;
			Capacity = that.Capacity;
			delete[] array;
			array = new Type[Capacity];
			for (unsigned int i = 0; i < Size; ++i)
				array[i] = that.array[i];
		}
		return *this;
	}


	//Returns the array element at [index]
	Type& operator[](const unsigned int index) { return array[index]; }
	//Returns the const array element at [index]
	const Type& operator[](const unsigned int index) const { return array[index]; }

	//Returns Size
	unsigned int size() const { return Size; }
	//Returns capacity
	unsigned int capacity() const { return Capacity; }

	//Clears list and deletes dynamic memory
	void clear()
	{
		delete[] array;
		Size = 0;
		Capacity = 0;
		array = nullptr;
	}
	//Item added to next available spot
	void append(const Type& item)
	{
		if (Capacity == 0)
		{
			Capacity = 1;
			Type* temp = new Type[Capacity];
			delete[] array;
			array = temp;
		}
		else if (Capacity == Size)
		{
			Capacity *= 2;
			Type* temp = new Type[Capacity];
			// loop - copy from array into temp
			for (unsigned int i = 0; i < Size; ++i)
				temp[i] = array[i];
			delete[] array;
			array = temp;
		}

		array[Size] = item;
		Size++;
	}
	//Increases capacity
	void reserve(const unsigned int & newCap = 0)
	{
		if (newCap == 0)
		{
			if (Capacity == 0)
				Capacity = 1;
			else
				Capacity *= 2;
			Type* temp = new Type[Capacity];
			for (unsigned int i = 0; i < Size; ++i)
				temp[i] = array[i];
			delete[] array;
			array = temp;
		}
		else if (newCap > Capacity)
		{
			Capacity = newCap;
			Type* temp = new Type[Capacity];
			for (unsigned int i = 0; i < Size; ++i)
				temp[i] = array[i];
			delete[] array;
			array = temp;
		}
	}

	void insert(const Type val, const unsigned int index)
	{
		if (Size < index)
		{}
		else
		{
			while (Size + 1 > Capacity || Capacity == 0)
			{
				if (Capacity == 0)
					Capacity = 1;
				else
					Capacity *= 2;
			}
			Type* temp = new Type[Capacity];

			for (unsigned int  i = 0; i < index; i++)
				temp[i] = array[i];

			temp[index] = val;

			for (unsigned int i = index; i < Size; i++)
				temp[i + 1] = array[i];
			Size++;

			delete[] array;
			array = temp;
		}

	}

	void insert(const Type * val, const unsigned int n, const unsigned int index)
	{
		if (Size < index)
		{

		}
		else
		{
			while (Size + n > Capacity)
			{
				if (Capacity == 0)
					Capacity = 1;
				else
					Capacity *= 2;
			}

			Type* temp = new Type[Capacity];
			for (unsigned int i = 0; i < index; ++i)
				temp[i] = array[i];

			for (unsigned int i = 0; i < n; ++i)
				temp[index + i] = val[i];

			for (unsigned int i = index; i < Size + n; ++i)
				temp[i + n] = array[i];

			Size += n;
			delete[] array;
			array = temp;
		}
	}

	void remove(const unsigned int index)
	{
		if (Size == 0 || index > Size)
		{ }
		else
		{
			Type* temp = new Type[Capacity];
			for (unsigned int i = 0; i < index; ++i)
				temp[i] = array[i];
			for (unsigned int i = index; i < Size - 1; ++i)
				temp[i] = array[i + 1];
			Size--;
			delete[] array;
			array = temp;
		}
	}

	void remove(const unsigned int index, const unsigned int n)
	{
		if (Size < n || index + n > Size)
		{}
		else
		{
			Type* temp = new Type[Capacity];
			for (unsigned int i = 0; i < index; ++i)
				temp[i] = array[i];
			for (unsigned int i = index; i < Size - n; ++i)
				temp[i] = array[i + n];

			Size -= n;
			delete[] array;
			array = temp;
		}
	}
};