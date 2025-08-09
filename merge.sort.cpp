#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    int inv_count=0;

    while((i<=mid)&&(j<=right)){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++,i++;
        }
        else{
            temp[k]=arr[j];
            k++,j++;
            inv_count+=(mid-i+1);
        }
    }

    while(i<=mid){
        temp[k]=arr[i];
        k++,i++;
    }
    while(j<=right){
        temp[k]=arr[j];
        k++,j++;
    }
    
    for(int idx=left;idx<=right;idx++){
        arr[idx]=temp[idx];
    }
    return inv_count;
}

int mergesort(vector<int>&arr,vector<int>&temp,int left,int right){
    int inv_count=0;
    if(left<right){
        int mid=(left+right)/2;
        inv_count+=mergesort(arr,temp,left,mid);
        inv_count+=mergesort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid,right);
    }
    return inv_count;
}

int main(){
    vector<int> arr={1,20,6,4,5};
    int n=arr.size();
    vector<int>temp(n);
    int result=mergesort(arr,temp,0,n-1);
    cout<<"result:"<<endl;
    return 0;
}