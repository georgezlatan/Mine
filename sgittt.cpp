#include <bits/stdc++.h>
using namespace std;
int max_sum=0,p,q,n;

void func(vector<int> arr1,vector<int> arr2,int chance,int gold){
    int amar=0,i;
    for(i=0;i<n;i++){
        if(arr1[i]>0){
            amar=i;
            break;
        }
    }
    if(i==n){
        if(gold>max_sum){
            max_sum = gold;
        }
        return;
    }
    if(chance==1){
        chance=0;
        func(arr1,arr2,chance,gold);
        for(int i=0;i<n;i++){
            if(arr1[i]>0){
                arr1[i] -= p;
                if(arr1[i] <= 0){
                    gold += arr2[i];
                }
                func(arr1,arr2,chance,gold);
                if(arr1[i] <= 0){
                    gold -= arr2[i];
                }
                arr1[i]+=p;
            }
        }
    }
    else if(chance==0){
        chance = 1;
        arr1[amar] -=q;
        if(arr1[amar] < 0){
            arr1[amar] = 0;
        }
        func(arr1,arr2,chance,gold);
    }
}

int main()
{
  cin>>p>>q>>n;
  vector<int> arr1(n);
  vector<int> arr2(n);
  for(int i=0;i<n;i++){
    cin>>arr1[i]>>arr2[i];
  }
  func(arr1,arr2,1,0);
  cout<<max_sum<<endl;

  // print output
  //cout << input;

  return 0;
}