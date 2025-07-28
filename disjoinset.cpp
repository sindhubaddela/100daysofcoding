#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Disjointset{
    vector<int> rank , parent , size;
    public:
        void Disjoinset(int n){
            rank.resize(n+1 ,0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }

        int findparent (int u)
        {
            if(parent[u]==u)return u;
            return parent[u] = findparent(parent[u]);
        }

        void unionbyrank(int u ,int v)
        {
            int ulp_u = findparent(u);
            int ulp_v = findparent(v);

            if(ulp_u == ulp_v)return;

            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v]= ulp_u;
            }
            else
            {
                parent[ulp_v]= ulp_u;
                rank[ulp_v]++;
            }
        }
        void unionbysize(int u ,int v)
        {
            int ulp_u = findparent(u);
            int ulp_v = findparent(v);

            if(ulp_u == ulp_v)return;
            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v]+= size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+= size[ulp_v];
            }
        }


};

int main()
{
    Disjointset ds;
    ds.Disjoinset(7);

    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);

    // check if 5 and 6 are in the same set
    if(ds.findparent(5)==ds.findparent(6))
    {
        cout<< " sameset"<<endl;
    }
    else{
        cout<<"not the same set"<<endl;
    }

    ds.unionbysize(6, 7);
    ds.unionbysize(5, 6);   
    ds.unionbysize(3, 4);

    // check if 5 and 6 are in the same set
    if(ds.findparent(5)==ds.findparent(6))
    {
        cout<< " sameset"<<endl;
    }
    else{
        cout<<"not the same set"<<endl;
    }

}
