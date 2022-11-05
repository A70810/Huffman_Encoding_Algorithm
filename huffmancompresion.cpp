#include"minheap.cpp"
using namespace std;
int main()
{
   // priority_queue<pair<char>>
    // pq pq3;
 //countfreq();
   pq pq1=minheap();
   int i = pq1.size()-1;
   int k =0;
   pq pq2;
   pq1.pop();
   //vector<char,int>v1;
    while (pq1.size() != 1)
        {

        // Extract the two minimum freq items from min heap
        pair<char,int>pl  = pq1.top();
        int leftfreq = pl.second;
        pq1.pop();
        pq2.push(pl);
        pair<char,int>pr = pq1.top();
        int rightfreq = pr.second;
        pq1.pop();
       pq2.push(pr);
        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the two extracted node as left and right children
        // of this new node. Add this node to the min heap '$' is a special value for internal nodes, not used
        //top = new MinHeapNode('$', left->freq + right->freq);
        pair<char,int>pt;
        pt.second = leftfreq+rightfreq;
        pt.first = '$';
        int left = pq1.leftchild(i);
        //cout<<left<<" "<<right<<" "<<endl;
        int right = pq1.rightchild(i);
        pq1.v[left]=pl;
        pq1.v[right]=pr;
        pq2.push(pt);
        pq1.push(pt);
        i++;
       // while()
       // cout<<pq1.top().first<<"->->"<<pq1.top().second<<endl;
    }
        while(pq2.size()!=0)
            {
              cout<<pq2.top().first<<"->->"<<pq2.top().second<<endl;
                pq2.pop();
            }
                return 0;
    }


//}
