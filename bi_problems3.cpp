#include <iostream>
#include <vector> 
using namespace std;
// Book Allocation Problem
bool isPossible(vector<int>arr,int n,int m,int mid){
	int studentCount =1;
	int pageSum =0;
	for(int i=0; i<n; i++){
		if(pageSum + arr[i]<=mid){
			pageSum=pageSum+ arr[i];
		}
			
		else{
			studentCount++;
			if(studentCount>m || arr[i]>mid){
				return false;
			}
			pageSum=0;
			pageSum= pageSum +arr[i];
		}  
	}
	return true;
}
int ayushGivesNinjatest(int n, int m, vector<int> arr) 
{	
	int s=0;
	int sum =0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int e=sum;
	int mid= s+(e-s)/2;
	int ans=-1;
	while(s<=e){
		if(isPossible(arr,n,m,mid)){
			ans=mid;
			e=mid-1;
		}else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}

int main(){
    vector<int> arr = {1, 2, 2, 3, 1};
    int n = arr.size();
    int m = 3;
    cout<<ayushGivesNinjatest(n,m,arr);
    return 0;
}

