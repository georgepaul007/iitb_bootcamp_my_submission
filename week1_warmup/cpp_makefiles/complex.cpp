#include <iostream>
using namespace std;
class ComplexNumbers {
	public:
	int * add(int a1, int a2, int b1, int b2) {
		static int res[2];
		res[0] = a1+b1;
		res[1] = a2+b2;
		return res;
	}
};
int main() {
	ComplexNumbers A;
	int a1,a2,b1,b2;
	cout<<"Enter the first complex number: ";
	cin>>a1>>a2;
	cout<<"Enter the second complex number: ";
	cin>>b1>>b2;
	int *ptr = A.add(a1,a2,b1,b2);
	cout<<"The result is : "<<ptr[0]<<" "<<ptr[1];
	return 0;
} 
 





