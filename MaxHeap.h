#ifndef MAX_HEAP_H
#define MAX_HEAP_H

using namespace std;
template<class DT>
class MaxHeap
{
public:
	//part1: constructor initializes array of size maxsize
	MaxHeap(int maxsize){
		arr=new DT[maxsize];
		heapSize=1;
	}

	//part2: Inserts data into its appropriate position
	//within the Heap
	bool insert(const DT data){
		int nodeIndex, parentIndex;
		DT temp;
		heapSize++;
		arr[heapSize-1]=data;
		nodeIndex=heapSize-1;
		while(nodeIndex!=1){
			parentIndex=(nodeIndex)/2;
			if(arr[nodeIndex]>arr[parentIndex]){
				temp=arr[nodeIndex];
				arr[nodeIndex]=arr[parentIndex];
				arr[parentIndex]=temp;
				nodeIndex=parentIndex;
			}
			else{
				return true;
			}
		}
		return false;
	}

	//part3: removes the element present in the the root 
	//of the Heap and readjusts it to form MaxHeap again
	DT Delete(){
		int nodeIndex=1, leftchildIndex, rightchildIndex;
		DT flag;
		DT temp=arr[1];
		arr[nodeIndex]=arr[heapSize-1];
		
		heapSize--;
		do{
			leftchildIndex=2*nodeIndex; rightchildIndex=(2*nodeIndex)+1;
			if(arr[nodeIndex]<arr[leftchildIndex] && arr[nodeIndex]<arr[rightchildIndex]){
				if(arr[leftchildIndex]>arr[rightchildIndex]){
					flag=arr[leftchildIndex];
					arr[leftchildIndex]=arr[nodeIndex];
					arr[nodeIndex]=flag;
					nodeIndex=leftchildIndex;
				}
				else{
					flag=arr[rightchildIndex];
					arr[rightchildIndex]=arr[nodeIndex];
					arr[nodeIndex]=flag;
					nodeIndex=rightchildIndex;
				}
			}
			else if(arr[nodeIndex]<arr[leftchildIndex]){
				flag=arr[leftchildIndex];
				arr[leftchildIndex]=arr[nodeIndex];
				arr[nodeIndex]=flag;
				nodeIndex=leftchildIndex;
			}
			else if(arr[nodeIndex]<arr[rightchildIndex]){
				flag=arr[rightchildIndex];
				arr[rightchildIndex]=arr[nodeIndex];
				arr[nodeIndex]=flag;
				nodeIndex=rightchildIndex;
			}
			
		} while(arr[nodeIndex]<arr[leftchildIndex] || arr[nodeIndex]<arr[rightchildIndex]);
		return temp;
	}

	//part4: prints all the data present in the Heap
	//use the appropriate traversal 
	void printContents(){
		for(int i=1; i<heapSize; i++){
			cout<<arr[i]<<"\t";
		}
		cout<<endl;
	}

	//part5: destructor, deletes the MaxHeap
	~MaxHeap();


private:
	DT *arr;
	int heapSize;
};
#endif



//