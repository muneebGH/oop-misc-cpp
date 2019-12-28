using namespace std;
struct Set
{
	int * data;
	int capacity;
	int noOfElements=0;
};

void createSet(Set &, int n);
bool addElement(Set &, int element);
bool isFull(Set);
bool searchElement(Set,int element);
int searchElementPosition(Set, int element);
bool isEmpty(Set);
void displaySet(Set);
Set setIntersection(Set, Set);
Set calcUnion(Set, Set);
void swap(Set & setA, int index1, int index2);
int isSubset(Set, Set);
void reSize(Set &, int newSize);
Set createClone(Set & source);
Set setDifference(Set, Set);
void deAllocateSet(Set & setA);