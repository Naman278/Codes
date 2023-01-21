/*
Merge by Inserting is a variation of merge sort in which we make change in the merge part of merge sort. The right part of the array is inserted into 
the left part of the array. That is the elements in the right part of the array has to be insered into the sorted array which is  the left part of the 
array

For example, consider an array of elements with first four elements as left part and second four elements as right part. Left part and right part are 
sorted by themselves. In the merge step, insert the elements one by one in the right part into the left part. The left part will keep on increasing in 
length and will become whole array at the end. Consider the elements 1, 4, 7, 12, 2, 5, 8, 14.

Left part consist of 1, 4, 7, 12

Right part consist of 2, 5, 8, 14

Insert 2 into sorted left part, then 5, 8 and 14
*/

#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
void merge(vector<int> &elements, int left, int mid, int right)
{	
	//insert the elements in the right part into the left part
	int key;
	for(int i = mid+1;i <=right ; i++){
		key = elements[i];
		int j = i-1;
		while(j>=left && elements[j]>key)
		{
			elements[j+1] = elements[j];
			j--;
		}
		elements[j+1] = key; 
	}
}	
void mergesort(vector<int> &elements, int left, int right)
{
	int mid;
	// When there is only one element in the array
	if(left==right)
		return;
	// Find mid of the array
	mid = (left+right)/2;
	// call mergesort for left subarray
	mergesort(elements,left,mid);
	// call mergesort for right subarray
	mergesort(elements,mid+1,right);
	// merge the sorted left and right subarray
	merge(elements,left,mid,right);
}
int main()
{
	int n,i,ele;
	vector<int> elements;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}
	clock_t tStart = clock();
	mergesort(elements, 0, n-1);
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	//cout<<"Time taken is "<<time1<<endl;
	for(i=0;i<n;i++)
	{
		cout<<elements[i]<<" ";
	}
}
