/* BITWISE CONVOLUTIONS
 * Outline (in order of appearance):
 * >> (f*g)[s]=Sum(f[a]*f[b] : [a|b=s and a&b=0]) -> aka SUBSET
 * >> (f*g)[s]=Sum(f[a]*f[b] : [a|b=s]) -> aka OR
 * >> (f*g)[s]=Sum(f[a]*f[b] : [a&b=0])
 * >> (f*g)[s]=Sum(f[a]*f[b] : [a|b=s and a&b!=0])
 * >> (f*g)[s]=Sum(f[a]*g[b] : [a&b=s]) -> aka AND
 * >> (f*g)[s]=Sum(f[a]*g[b] : [a^b=s]) -> aka XOR
 * Testeado en 458G - codeforces (algunas)
 * */
namespace Mobius
{
  typedef long long int LL;

  const int B=17;
  const int N=1<<B;
  const LL invN=(LL)742744451;
  const LL M=(LL)1e9+7;

  int count[N];
  void init_count() // call this first
  {for(int i=0;i<N;++i)count[i]=__builtin_popcount(i);}
  void add(LL &x,LL y)
  {
    x+=y;
    if(x>=M)x-=M;
    else if(x<0)x+=M;
  }
  void mobius_transform(LL A[],LL inv=1ll)
  {
    for(int i=0;i<B;++i)
      for(int j=0;j<N;++j)
        if(j>>i&1)
          add(A[j],inv*A[j^1<<i]);
  }

  void ranked_mobius(LL A[],LL ans[][N])
  {
    for(int k=0;k<=B;++k)
    {
      LL* a=ans[k];
      for(int i=0;i<N;++i)
        if(count[i]==k)a[i]=A[i];
        else a[i]=0;
      mobius_transform(a);
    }
  }
  void inverse_ranked_mobius(LL A[][N],LL ans[])
  { // this could be improve to O(N)
    for(int k=0;k<=B;++k)
    {
      LL* a=A[k];
      mobius_transform(a,-1);
      for(int i=0;i<N;++i)
        if(count[i]==k)ans[i]=a[i];
    }
  }
  
  // BITWISE CONVOLUTIONS
  LL frm[B+1][N],grm[B+1][N],fg[B+1][N];
  // Partitioning product:
  // (f*g)[s]=Sum(f[a]*f[b] : [a|b=s and a&b=0])
  void subset_convolution(LL f[],LL g[],LL ans[])
  {// Testeado en 458G
    memset(fg,0,sizeof fg);
    ranked_mobius(f,frm);
    ranked_mobius(g,grm);
    for(int k=0;k<=B;++k)
      for(int X=0;X<N;++X)
        for(int r=0;r<=k;++r)
          add(fg[k][X],frm[r][X]*grm[k-r][X]%M);
    inverse_ranked_mobius(fg,ans);
  }
  // Covering product:
  // (f*g)[s]=Sum(f[a]*f[b] : [a|b=s])
  LL tmp1[N],tmp2[N];
  void or_convolution(LL f[],LL g[],LL ans[])
  {
    memcpy(tmp1,f,N* sizeof(LL));
    memcpy(tmp2,g,N* sizeof(LL));
    mobius_transform(tmp1);
    mobius_transform(tmp2);
    for(int i=0;i<N;++i)
      ans[i]=tmp1[i]*tmp2[i]%M;
    mobius_transform(ans,-1);
  }
  // Packing product:
  // (f*g)[s]=Sum(f[a]*f[b] : [a&b=0])
  void packing_product(LL f[],LL g[],LL ans[])
  {
    subset_convolution(f,g,ans);
    mobius_transform(ans);
  }
  // Intersecting covering product:
  // (f*g)[s]=Sum(f[a]*f[b] : [a|b=s and a&b!=0])
  void intersecting_covering_product(LL f[],LL g[],LL ans[],int l=0)
  {
    or_convolution(f,g,tmp1);
    subset_convolution(f,g,tmp2);
    for(int i=0;i<N;++i)
    {
      ans[i]=tmp1[i];
      add(ans[i],-tmp2[i]);
    }
  }
  // Intersecting product (AND):
  // (f*g)[s]=Sum(f[a]*g[b] : [a&b=s])
  void transform_and(LL A[],LL inv=1)
  {
    for(int i=0;i<B;++i)
      for(int j=0;j<N;++j)
        if(!(j>>i&1))
          add(A[j],inv*A[j^1<<i]);
  }
  void and_convolution(LL f[],LL g[],LL ans[])
  { // Testeado en 458G
    memcpy(tmp1,f,N* sizeof(LL));
    memcpy(tmp2,g,N* sizeof(LL));
    transform_and(tmp1);
    transform_and(tmp2);
    for(int i=0;i<N;++i)
      ans[i]=tmp1[i]*tmp2[i]%M;
    transform_and(ans,-1);
  }
  // Excluding product (XOR):
  // (f*g)[s]=Sum(f[a]*g[b] : [a^b=s])
  void transform_xor(LL x[],bool inv=0)
  {
    for(int mid=1,i=2;i<=N;mid=i,i<<=1)
      for(int j=0,lo=0;lo<N;j+1==mid?(lo+=i,j=0):++j)
      {
        LL tw1=x[lo+j],tw2=x[lo+j+mid];
        x[lo+j]=tw1+tw2;
        if(x[lo+j]>=M)x[lo+j]=x[lo+j]-M;
        x[lo+j+mid]=tw1-tw2;
        if(x[lo+j+mid]<0)x[lo+j+mid]=x[lo+j+mid]+M;
      }
    if(inv)for(int i=0;i<N;++i)x[i]=x[i]*invN%M;
  }
  void xor_convolution(LL f[],LL g[],LL ans[])
  { // Testeado en 458G
    memcpy(tmp1,f,N* sizeof(LL));
    memcpy(tmp2,g,N* sizeof(LL));
    transform_xor(tmp1);
    transform_xor(tmp2);
    for(int i=0;i<N;++i)
      ans[i]=tmp1[i]*tmp2[i]%M;
    transform_xor(ans,1);
  }
}
