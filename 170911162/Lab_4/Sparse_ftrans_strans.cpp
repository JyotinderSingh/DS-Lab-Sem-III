#include <iostream>
using namespace std;
class sparse
{
    int r,c,v;
public:
    void read(sparse *);
    void ftrans(sparse *,sparse *);
    void display(sparse *);
    void stranspose(sparse *, sparse *);
    sparse()
    {
        r=0;
        c=0;
        v=0;
    }

};
void sparse::read(sparse a[])
{
    int m,n,i,j,k=1,val;

    cout<<"Enter the size of matrix:\n";
    cin>>m>>n;
    a[0].r=m;
    a[0].c=n;
    cout<<"Enter the elements:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>val;
            if(val!=0)
            {
                a[k].r=i;
                a[k].c=j;
                a[k].v=val;
                k++;
            }
        }
    }
    a[0].v=k-1;
}
void sparse::display(sparse x[])
{
    int i;
    cout<<"\nRow\tColumn\tValue\n";
    for(i=0;i<=x[0].v;i++)
        cout<<x[i].r<<"\t"<<x[i].c<<"\t"<<x[i].v<<"\n";
}
void sparse::ftrans(sparse a[],sparse b[])
{
    int i,j,k=1;
    int rT[100],sp[100];
    sp[0]=1;
    b[0].c=a[0].r;
    b[0].r=a[0].c;
    for(i=0;i<=a[0].c;i++)
        rT[i]=0;    //initializing the counter
    for(i=1;i<=a[0].v;i++)
        rT[a[i].c]++;   // increasing the values according to number of occurances
    for(i=1;i<=a[0].c;i++)
       sp[i]=sp[i-1]+rT[i-1];
   for(i=1;i<=a[0].v;i++)
    {
        j=sp[a[i].c]++;
        b[j].r=a[i].c;
        b[j].c=a[i].r;
        b[j].v=a[i].v;
        k++;
        }
    b[0].v=k-1;
}

void sparse::stranspose(sparse a[], sparse b[])
{
    int n = a[0].v;
    b[0].r = a[0].c;
    b[0].c = a[0].r;
    b[0].v = n;

    if(n>0)
    {
        int currentb = 1;
        for(int i = 0; i < a[0].c; ++i)
        {
            for(int j = 1; j<=n; ++j)
            {
                if(a[j].c == i)
                {
                    b[currentb].r = a[j].c;
                    b[currentb].c = a[j].r;
                    b[currentb].v = a[j].v;
                    currentb++;
                }
            }
        }
    }
}

int main()
{
    sparse s,s1[10],s2[10];
    s.read(s1);
    cout<<"Before transpose:\n";
    s.display(s1);
    cout<<"After transpose (fast):\n";
    s.ftrans(s1,s2);
    s.display(s2);
    sparse s3[100];
    cout<<"\nAfter transpose (slow) :\n";
    s.ftrans(s2,s3);
    s.display(s3);

    return 0;
}
