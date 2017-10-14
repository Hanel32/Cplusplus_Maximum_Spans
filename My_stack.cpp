#include "My_stack.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int main() {
	My_stack* v = new My_stack;
	bool isEmpty = true;
	for(int i = 5; i > 0; i--){
		v->push(i);
	}
	isEmpty = v->empty();
	cout << "It is " << isEmpty << " the the stack is full." << endl;
	for(int i = 5; i > 0; i--){
		v->pop();
	}
	try{
		cout << "Forcing pop error: " << endl;
		v->pop();
	}
	catch(const runtime_error& e){
		cout << "Error: " << e.what() << endl;
	}
	try{
		cout << "Forcing push error: " << endl;
		for(int i = 0; i < 11; i++){
			v->push(i);
		}
	}
	catch(const runtime_error& e){
		cout << "Error: " << e.what() << endl;
	}
	cout << "Deleting v" << endl;
	delete v;
	cout << "No deletion error!" << endl;
	cout << "This ends the ADT test sequence. Starting spanning." << endl;
	cout << "Using spans2 algorithm" << endl << endl;
	int tmp[] = {6, 3, 4, 5, 2};
	vector<int> nums(tmp, tmp+5);
	vector<int> spans = spans2(nums);
	cout << "The nums  are: ";
	for(int i = 0; i < nums.size(); i++){
		cout << nums.at(i) << " ";
	}
	cout << endl;
	cout << "The spans are: ";
	for(int i = 0; i < spans.size(); i++){
		cout << spans.at(i) << " ";
	}
	cout << endl << endl;
	int tmp_2[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 5, 4, 7, 4, 3, 2, 3};
	vector<int> nums_2(tmp_2, tmp_2+18);
	vector<int> spans_2 = spans2(nums_2);
	cout << "The nums  are: ";
	for(int i = 0; i < nums_2.size(); i++){
		cout << nums_2.at(i) << " ";
		if(i == 9 || i == 13 || i == 10){
			cout << " ";
		}
	}
	cout << endl;
	cout << "The spans are: ";
	for(int i = 0; i < spans_2.size(); i++){
		cout << spans_2.at(i) << " ";
	}
	cout << endl << endl;
///////////////////	
	int tmp_3[] = {10, 8, 9, 6, 7, 4, 5, 3, 2, 1, 4, 6, 8, 11, 12, 17, 12, 13};
	vector<int> nums_3(tmp_3, tmp_3+18);
	vector<int> spans_3 = spans2(nums_3);
	cout << "The nums  are: ";
	for(int i = 0; i < nums_3.size(); i++){
		cout << nums_3.at(i) << " ";
		if(i == 12){
			cout << " ";
		}
	}
	cout << endl;
	cout << "The spans are: ";
	for(int i = 0; i < spans_3.size(); i++){
		cout << spans_3.at(i) << " ";
		if(i == 0 || i == 16){
			cout << " ";
		}
	}
	cout << endl;

}
