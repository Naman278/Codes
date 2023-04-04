/*
Given a set ‘S’ of ‘n’ activities, implement the recursive greedy algorithm to select a subset of activities from S by selecting the task that starts last. Build a priority queue (max heap) based on start time and then select the activities

Input Format

First line contains the number of activities, n

Next 'n' line contains the details of the activities such as name of activity, start time and finish time

Output Format

Print the name of the activities that are selected separated by a space
*/

#include<iostream>
using namespace std;
#include<queue>
#include<set>
class activity
{
    public:
    string name;
    int start;
    int finish;
    friend istream& operator>>(istream&,activity&);
    friend ostream& operator<<(ostream&,const activity&);
    bool operator<(const activity&) const;
};
istream& operator>>(istream& in, activity& a)
{
    in>>a.name>>a.start>>a.finish;
}
ostream& operator<<(ostream& out, const activity& a)
{
    out<<a.name<<" ";
}
bool activity::operator<(const activity& a) const
{
    return a.start>start;
}
void recursive_activity_selector(priority_queue<activity> &pq,vector<activity> &v)
{
    activity a;
    a = pq.top();
    pq.pop();
    v.push_back(a);
    while(!pq.empty()&&pq.top().finish>a.start)
    {
        pq.pop();
    }
    if(!pq.empty())
    {
        recursive_activity_selector(pq,v);
    }
    else
        return;
}
int main()
{
    priority_queue<activity> pq;
    int n,i;
    activity a;
    vector<activity> v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        pq.push(a);
    }
    recursive_activity_selector(pq,v);
    for (auto first = v.begin(),last=v.end()-1; first<last; first++,last--) {
        swap(*first, *last);
    }
    for(auto a:v)
        cout<<a;
    
}
