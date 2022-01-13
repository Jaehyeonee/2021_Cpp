#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

// my code


class Sorting {
public:
	virtual void sort(vector<int>& nums) {  }
	static void print(vector<int>& nums) {
		for (const auto& i : nums) {
			cout << i << " ";
		}
		cout << endl;
	
	}
};

//숫자들이 나온 횟수를 셈
class Counting : public Sorting {
public:
	void sort(vector<int>& nums) {
		vector<int> c(10, 0);
		for (int i = 0; i < nums.size(); i++)
			c[nums[i]]++;
		for (int i = 1; i < 10; i++)
			c[i] += c[i - 1];

		vector<int> b(nums.size());
		for (int i = nums.size() - 1; i >= 0; i--)
			b[--c[nums[i]]] = nums[i];
		nums = b;


	}
};

class Radix : public Counting {
public:
	void sort(vector<int>& nums) {
		int d = 8, w = 32;
		for (int p = 0; p < w / d; p++) {
			vector<int> c(1 << d, 0);
			vector<int> b(nums.size());
			for (int i = 0; i < nums.size(); i++)
				c[(nums[i] >> d * p) & ((1 << d) - 1)]++;
			for (int i = 1; i < 1 << d; i++)
				c[i] += c[i - 1];
			for (int i = nums.size() - 1; i >= 0; i--)
				b[--c[(nums[i] >> d * p) & ((1 << d) - 1)]] = nums[i];
			nums = b;
		}


	}

};

int main() {
	int number;
	int type;
	vector<int> nums;
	string infilename, outfilename;
	Sorting* sort;
	cout << "Give an input file name:" << endl;
	cin >> infilename;
	cout << "Give an output file name:" << endl;
	cin >> outfilename;
	cout << "Select you algorithm: 1. Counting Sort, 2. Radix Sort" << endl;
	cin >> type;
	// read values from a file

	ifstream ist{ infilename };
	if (!ist.is_open()) {
		cerr << "can't open the file" << infilename << endl;
		return EXIT_FAILURE;

	}
	while (ist >> number) {
		nums.push_back(number);

	}
	ist.close();



	if (type == 1) sort = new Counting();
	else sort = new Radix();
	cout << "Initial Values" << endl;
	Sorting::print(nums);
	sort->sort(nums);
	cout << "Sorted Values" << endl;
	Sorting::print(nums);
	// write the sorted values into the file

	ofstream ofs{ outfilename };
	if (!ofs.is_open())
		cout << "can't open output file" << endl;
	
	vector<int> v;
	char buf[100];
	for (int i=0; i < nums.size(); i++)
		v.push_back(i);

	for (int i = 0; i < nums.size(); ++i) {
		//ofs.write((char*)&v[i], sizeof(int));
		ofs << nums[i]<< " ";
	}
	cout << endl;
	ofs.close();
}





//
//lecture solution code
//



#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
class Sorting {
public:
	virtual void sort(vector<int>& nums) = 0;
	static void print(vector<int>& nums);
};

void Sorting::print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
	cout << endl;
}

class Counting : public Sorting {
private:
	void countFrequency(int *count, vector<int>& nums);
	void calFirstPos(int *count, int *pos);
	void countsort(int *pos, vector<int>& nums);
protected:
	virtual int getValue(int v);
public:
	void sort(vector<int>& nums);
};

int Counting::getValue(int v) {
	return v;
}

void Counting::countFrequency(int* count, vector<int>& nums) {
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	for (int i = 0; i < nums.size(); i++)
		count[getValue(nums[i])]++;
}

void Counting::calFirstPos(int* count, int* pos) {
	for (int i = 0; i < 10; i++)
		pos[i] = 0;
	for (int i = 1; i < 10; i++)
		pos[i] = pos[i - 1] + count[i - 1];
}

void Counting::countsort(int* pos, vector<int>& nums) {
	vector<int> temp;
	for (int i = 0; i < nums.size(); i++)
		temp.push_back(0);
	for (int i = 0; i < nums.size(); i++) {
		temp[pos[getValue(nums[i])]] = nums[i];
		pos[getValue(nums[i])]++;
	}
	for (int i = 0; i < nums.size(); i++)
		nums[i] = temp[i];
}

void Counting::sort(vector<int>& nums) {
	int count[10];
	int pos[10];
	countFrequency(count, nums);
	calFirstPos(count, pos);
	countsort(pos, nums);
}

class Radix : public Counting {
	int bit;
protected:
	virtual int getValue(int v);
public:
	void sort(vector<int>& nums);
};

int Radix::getValue(int v) {
	int mask = 1;
	mask = mask << bit;
	return (v & mask);
}

void Radix::sort(vector<int>& nums) {
	for (bit = 0; bit < 4; bit++) {
		Counting::sort(nums);
		Sorting::print(nums);
	}
}


int main() {
	int type;
	vector<int> nums;
	string infilename, outfilename;
	Sorting* sort;

	cout << "Give an input file name:" << endl;
	cin >> infilename;
	cout << "Give an output file name:" << endl;
	cin >> outfilename;
	cout << "Select you algorithm: 1. Counting Sort, 2. Radix Sort" << endl;
	cin >> type;

	// read values from a file
	ifstream ist(infilename);
	int temp;
	while (ist >> temp)
		nums.push_back(temp);

	if (type == 1) sort = new Counting();
	else sort = new Radix();

	cout << "Initial Values" << endl;
	Sorting::print(nums);
	sort->sort(nums);
	cout << "Sorted Values" << endl;
	Sorting::print(nums);

	// write the sorted values into the file
	ofstream ost(outfilename);
	for (int i = 0; i < nums.size(); i++) {
		ost << nums[i] << endl;
	}

}
