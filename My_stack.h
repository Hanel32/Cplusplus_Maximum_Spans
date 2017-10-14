/*
Implementation of the Stack ADT by Carson Hanel
*/
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

class My_stack{
	int cap, top;
	int *ptr;    //Meant to take arrays, so [] usage should work.
	
public:
	My_stack(){
		cap = 10;
		top = -1;
		ptr = new int[10];
	};
	My_stack(int size){
		cap = size;
		top = -1;
		ptr = new int[size];
	};
	~My_stack(){
		cout << "Destructor called" << endl;
		delete [] ptr;
		return;
	};
	void push(const int& obj){
		if(top < (cap - 1)){
			top++;
			ptr[top] = obj;
			return;
		}
		else{
			throw runtime_error("Pushing into a full stack.");
		}
	};
	int pop(){
		if(top > -1){       //Checks if the stack is populated.
			top--;          //Decrements the top accesible member (Doesn't delete data, makes it unable to be reached.)
			return ptr[top + 1];
		}else{              //In this case, there are no elements within the stack.
			throw runtime_error("Attempting to pop from an empty stack.");
		}
	};
	int peek(){
		if(top > -1){
			return ptr[top];
		}else{
			throw runtime_error("Attempting to check top from an empty stack.");
		}
	};
	bool empty(){return (top < 0);};	
};
/*
Start spanning algorithms
*/
vector<int> spans1(const vector<int>& vec) {//Vector operations
	vector<int> spans(vec.size(), 0);        //Makes a vector of size of vec
	int j;                                   //Keeps track of consecutive days increasing.
	for (int i = 0; i < vec.size(); i++) {   //O(n) runtime
		j = 1;
		while (j <= i && vec[i - j] <= vec[i]) { //O(n) runtime at the worst, more like n(n+1)/2 when coupled with above
			j++;
		}
		spans[i] = j;
	}

	return spans;
}
/*vector<int> spans2(const vector<int>& vec) {//Stack operations (incorrect implementation)
	vector<int> spans;                        //Vector holding the spanning values.
	My_stack* temp = new My_stack();          //Stack to hold i
	int num_comps = 0;

	for(int i = 0; i < vec.size(); i++){
		int j = i + 1;
		spans.push_back(j - i);
		while(num_comps++, vec[i] < vec[j]){
			spans.push_back(j);
			j++;
		}
		temp->push(j - 1);
		i = j - 1;
	}
	cout << "The local maximums are found at: " << endl;
	while(!temp->empty()){
		int a = temp->pop();
	}
	cout << endl << "It took : " << num_comps << " operations." << endl;
	return spans;	
}*/
vector<int> spans2(const vector<int>& vec){   //Stack operations (correct implementation)
	vector<int> spans(vec.size(), 0);         //Holds the spans with 0 dummy variables
	My_stack* temp = new My_stack(vec.size());//Stack to hold local maximums. It is sizeOf vec because in the worst case, that is the number of peaks.
	int curr = 0;

	for (int i = 0; i < vec.size() - 1; i++) {//Each iteration is a span.
		curr = i;                             //Sets your comparison variable to the value directly next to i
		while (curr + 1 < vec.size() && vec.at(curr) < vec.at(curr + 1)){		
			curr++;                           //Adds the next day to the length of the span.
			spans.at(curr - 1) = (curr) - i;  //Sets the spanning value for the current day within the span.
		}
		spans.at(curr) = (curr + 1) - i;      //A maximum has been found, set the preliminary span
		if(temp->empty()){                    //If the stack of maximums is empty,
			temp->push(curr);                 //Simply push back the current index
		}else{                                //But, if it is not empty, and the current max's value is greater than the previous max
			while(!temp->empty() && vec.at(curr) > vec.at(temp->peek())){ 
				spans.at(curr) += spans.at(temp->pop());
			}                                 //The above loop discards any lower peaks, and adds their span to the current peak's span.
			temp->push(curr);                 //Sets the current peak into its rightful place on the stack.
		}
		i = temp->peek();                     //Sets the start of the next span to the position of the peak.
	}
	return spans;                             //Returns the calculated spans to main
/*
Note: The above commented spans2 is the original before I realized the reverse comparison of peaks.
	  After seeing an iteration-wise algorithm rather than span-wise (like mine), I realized that
	  the implementation I was using was actually not true const but constant amortized because I
	  was pushing back into an array of undefined size as I was going, so there were several
	  internal vector resizes that happened but can't see at this level. I took that extra runtime
	  away, and initialized it as a vector of the size of the original vector. Likewise, I've done
	  the same thing for the Stack. I set it as a stack with the maximal number of elements being
	  equivalent to 'n' in all cases, because the worst case is a completely decreasing set of values
	  wherein ever value is a technical local peak.	
*/
}
