#include<bits/stdc++.h>
#include"CountFreq.cpp"
using namespace std;
struct pq
{
public:
    vector<pair<char,int>>v;
    int parent(int i)

    {
        return (i-1)/2; // returns the parent of ith index
    }
    int leftchild(int i)
    {return (2*i+1); } //return the left child of the ith index;

    int rightchild(int i)
   {
       return (2*i+2) ;
   }  // return the right cjhild of the ith index;

    //recursive heapify down algo in case left or right child violate the heap property
    void heapifydown(int i)
    {
        //getting the left and right child node
        int left = leftchild(i);
        int right = rightchild(i);

        int smallest =i;

        if(left<size()&&v[left].second<v[i].second)
            smallest = left;

        if (right < size() && v[right].second < v[smallest].second) {
            smallest = right;
        }
        if(smallest!=i)
        {
            swap(v[smallest],v[i]);
            heapifydown(smallest);
        }
    }

    void heapify_up(int i)
    {
        // check if the node at index `i` and its parent violate the heap property
        if (i && v[parent(i)].second > v[i].second)
        {
            // swap the two if heap property is violated
            swap(v[i], v[parent(i)]);

            // call heapify-up on the parent
            heapify_up(parent(i));
        }
    }
public:
    //return size of the heap
    unsigned int size()
    {
        return v.size();
    }
    bool empty()
    {

        return size()==0;
    }
   void push(pair<char,int>p)
    {
        v.push_back(p);
        heapify_up(size()-1);
    }
     void pop()
    {
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : " "index is out of range(Heap underflow)");
            }

            // replace the root of the heap with the last element
            // of the vector
            v[0] = v.back();
            v.pop_back();

            // call heapify-down on the root node
            heapifydown(0);
        }
        // catch and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
    pair<char,int> top()
    {
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }

            // otherwise, return the top (first) element
            return v.at(0);        // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
};

    //int main()
pq minheap()
         {

            unordered_map<char,int>m=countfreq();
             pq pq1;
             for(auto it=m.begin();it!=m.end();it++)
             {
                 pair<char,int>p1;
                 p1.first=it->first;
                 p1.second=it->second;
                 pq1.push(p1);
             }
            /*while(pq1.size()!=0)
            {
              cout<<pq1.top().first<<"->->"<<pq1.top().second<<endl;
              cout<<"............................"<<endl;
                pq1.pop();
            }*/
             return pq1;
             //return 0;
         }
