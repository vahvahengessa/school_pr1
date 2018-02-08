#include <iostream>
using namespace std;
 
 
void ZapolnenieMassiva(int **a,const int m, const int n)
{
    for (int i=0;i<m;i++)
     for (int j=0;j<n;j++)
       a[m][n] = j*j-i*j-2;
}
 
void VivodMassive(int **a, const int m,const int n)
{
    for (int i=0;i<m;i++)
     {
     for (int j=0;j<n;j++)
       cout<<a[i][j]<<"\t";
    cout<<endl;
     }
}
 
 
int MaksimalniyElement(int **a, const int m,const int n)
{
int max_1=0,max=0,max_time=0;
 
 
 
    for (int j=0;j<n;j++)
       for (int i=0;i<m;i++)
         max+=a[i][j];
         
   
   
    for (int j=1;j<n;j++)
      {
       for (int i=0;i<m;i++)
         max_1+=a[i][j];
        if (max_1>max) max=max_1;
        max_1=0;
      }
  return max;
}
 
 
main()
{
int m=0,n=0;
   
    cout<<"Vvedite kol-vo strok (Bolee>=2)\t";
      cin>>m;
    if (m<2) cout<<"m <2 - eror"<<endl;
   
    cout<<"Vvedite kol-vo stolbikov (Bolee>=2)\t";
      cin>>n;
    if (n<2) cout<<"n <2 - eror"<<endl;
   
   
    int **a = new int*[m];
      for (int i=0;i<m;i++) a[i] = new int [n];
 
ZapolnenieMassiva  (a,m,n);
VivodMassive  (a,m,n); 
   
cout<<"Maksimalnay summa elementov = "  << MaksimalniyElement (a,m,n);
   
for (int i = 0; i < m; ++i)
delete [] a[i];
}
