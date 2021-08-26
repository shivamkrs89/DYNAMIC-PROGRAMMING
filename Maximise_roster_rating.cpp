You are given two lists of integers ratings and ages, both of them the same length. A person i has a skill rating of ratings[i] and is ages[i] old. A team's rating is defined to be the sum of each individual ratings.

Return the maximum team rating you can achieve given that you can pick anyone to be in your team as long as there aren't any two people i and j such that ratings[i] > ratings[j] and ages[i] < ages[j].

Constraints

    n ≤ 1,000 where n is the length of ratings and ages

Example 1
Input

ratings = [5, 4, 8]

ages = [25, 24, 18]

Output

9

//code
int LCSsum(vector<int>& ages,vector<int>& ratings) {
    int n=ages.size();
   int arr[n],i,j,arr2[n];
       for(i=0;i<n;i++){
       arr[i]=1;arr2[i]=ratings[i];
       }
       //arr2 for storing the max sum rating till ith index
       int maxlen=1;
       int sumrating=0,maxrating=0;
       arr2[0]=ratings[0];
       //here we are basically finding various ages LIS and calculating sum of those involved in terms of ratings 
       for(i=1;i<n;i++)
       {
           sumrating=ratings[i];
           for(j=i-1;j>=0;j--)
           {
               if(ages[j]<=ages[i]){
               arr[i]=max(arr[j]+1,arr[i]);
               arr2[i]=max(arr2[j]+ratings[i],arr2[i]);
               
               }
               
               
           }
           maxrating=max(maxrating,arr2[i]);
           maxlen=max(arr[i],maxlen);//not necessary here though
       }
    
    return maxrating; 
}

bool mycmp(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first==p2.first)
    return p1.second<p2.second; //if same then return ia order of ages
    return p1.first<p2.first;
}


int solve(vector<int>& ratings, vector<int>& ages) {

   vector<pair<int,int>> v1;

   int n=ages.size();
   int i,j;
   for(i=0;i<n;i++)
   {
       v1.push_back(make_pair(ratings[i],ages[i]));
   }

sort(v1.begin(),v1.end(),mycmp);//sorting 2nd according to first
 for(i=0;i<n;i++)
   {
      ratings[i]=v1[i].first;
      ages[i]=v1[i].second;

     // cout<<ratings[i]<<' '<<ages[i]<<'\n';
   }
   
return LCSsum(ages,ratings);  //finding LCS of ages and finding sum 

}
