#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class SimpleVector
{
public:
	T* data;
	int CurrentSize = 0;
	int CurrentCapacity = 0;

	SimpleVector()
	{
		data = new T[10];
		CurrentCapacity = 10;
	}
	SimpleVector(int Capacity)
	{
		data = new T[Capacity];
		CurrentCapacity = Capacity;
	}
	~SimpleVector()
	{
		delete[] data;
	}
	void push_back(const T& value)
	{
		if (CurrentSize < CurrentCapacity)
		{
			data[CurrentSize] = value;
			CurrentSize++;
		}
		else
		{
			cout << "배열이 가득 찼습니다." << endl;
		}
	}
	void pop_back()
	{
		if (CurrentSize > 0)
		{
			CurrentSize--;
		}
		else
		{
			cout << "배열이 비어 있습니다." << endl;
		}
	}
	int size()
	{
		return CurrentSize;
	}
	int Capacity()
	{
		return CurrentCapacity;
	}
};

int main()
{
	SimpleVector<int> myvector;
	for (int i = 0; i < 11; i++)
	{
		myvector.push_back(i);
		cout << myvector.data[i] << endl;
	}

	SimpleVector<int> myvector2(11);
	for (int i = 0; i < 11; i++)
	{
		myvector2.push_back(i);
		cout << myvector2.data[i] << endl;
	}
}

