//~ 458G - codeforces.
/* You are given an array S of n non-negative integers.
 * A 5-tuple of integers (a, b, c, d, e) is said
 * to be valid if it satisfies the following conditions:
 *  -> 1 <= a, b, c, d, e <= n
 *  -> (Sa | Sb) & Sc & (Sd ^ Se) = 2^i for some integer i
 *  -> Sa & Sb = 0
 * Find the sum of f(Sa|Sb) * f(Sc) * f(Sd^Se) over all
 * valid 5-tuples (a, b, c, d, e), where f(i) is the i-th
 * Fibonnaci number (f(0) = 0, f(1) = 1, f(i) = f(i-1) + f(i-2))
 * 
 * 1. se almacena en 'cnt' las frecuencias para cada indice de
 *  fibonnaci en la entrada.
 * 2. se calcula la subset_convolution de 'cnt' con el mismo
 *  y se almacena en 'ab'.
 * 3. se caclula la xor_convolution y se almacena en 'Xor'.
 * >> En cnt[i] se tiene la frecuencia del indice i de los fibonnaci.
 * >> En ab[i] se tiene la frecuencia del con que se obtiene el
 *  incide i como union de dos indices a,b (i.e. a|b=i y a&b=0).
 * >> En Xor[i] se tiene la frecuencia del con que se obtiene el
 *  incide i como xor de dos indices a,b (i.e. a^b=i).
 * 4. se multiplican esas frecuencias por los respectivos fibonnaci
 *  (i.e.
 *  for(int i=0;i<N;++i):
 *    Xor[i]=Xor[i]*fib[i]
 *    ab[i]=ab[i]*fib[i]
 *    cnt[i]=cnt[i]*fib[i] ).
 * 5. se calcula la and_convolution de 'Xor', 'ab' y 'cnt' y se
 *  almacena en 'And'.
 * 6. para dar respuesta se suman los indices con potencia de dos.
 */
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC \
target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
#define endl '\n'

const int B=17;
const int N=1<<B;
const int M=(int)1e9+7;
const LL invN=(LL)742744451;
typedef int I;
namespace Mobius
{
  int count[N];
  void init_count()
  {for(int i=0;i<N;++i)count[i]=__builtin_popcount(i);}
  void add(I &x,I y)
  {
    x+=y;
    if(1ll*x>=M)x-=M;
    else if(x<0)x+=M;
  }
  void mobius_transform(I A[],I inv=1ll)
  {
    for(int i=0;i<B;++i)
      for(int j=0;j<N;++j)
        if(j>>i&1)
          add(A[j],inv*A[j^1<<i]);
  }

  void ranked_mobius(I A[],I ans[][N])
  {
    for(int k=0;k<=B;++k)
    {
      I* a=ans[k];
      for(int i=0;i<N;++i)
        if(count[i]==k)a[i]=A[i];
        else a[i]=0;
      mobius_transform(a);
    }
  }
  void inverse_ranked_mobius(I A[][N],I ans[])
  {
    for(int k=0;k<=B;++k)
    {
      I* a=A[k];
      mobius_transform(a,-1);
      for(int i=0;i<N;++i)
        if(count[i]==k)ans[i]=a[i];
    }
  }
  I frm[B+1][N],grm[B+1][N],fg[B+1][N];
  void subset_convolution(I f[],I g[],I ans[])
  {
    // Partitioning product:
    // (f*g)[s]=Sum(f[a]*f[b] : [a|b=s and a&b=0])
    memset(fg,0,sizeof fg);
    ranked_mobius(f,frm);
    ranked_mobius(g,grm);
    for(int k=0;k<=B;++k)
      for(int X=0;X<N;++X)
        for(int r=0;r<=k;++r)
          add(fg[k][X],1ll*frm[r][X]*grm[k-r][X]%M);
    inverse_ranked_mobius(fg,ans);
  }
  I tmp1[N],tmp2[N],tmp3[N];

  void transform_and(I A[],I inv=1)
  {
    for(int i=0;i<B;++i)
      for(int j=0;j<N;++j)
        if(!(j>>i&1))
          add(A[j],inv*A[j|1<<i]);
  }
  void and_convolution(I f[],I g[],I h[],I ans[])
  {
    // Intersection product:
    // (f*g)[s]=Sum(f[a]*f[b] : [a&b=s])
    transform_and(f);
    transform_and(g);
    transform_and(h);
    for(int i=0;i<N;++i)
      ans[i]=1ll*f[i]*g[i]%M*h[i]%M;
    transform_and(ans,-1);
  }
};
using namespace Mobius;
I cnt[N],fib[N],ab[N],Xor[N],And[N];
void transform_xor(I x[],bool inv=0)
{
  for(int mid=1,i=2;i<=N;mid=i,i<<=1)
    for(int j=0,lo=0;lo<N;j+1==mid?(lo+=i,j=0):++j)
    {
      I tw1=x[lo+j],tw2=x[lo+j+mid];
      x[lo+j]=tw1+tw2;
      if(1ll*x[lo+j]>=M)x[lo+j]-=M;
      x[lo+j+mid]=tw1-tw2;
      if(x[lo+j+mid]<0)x[lo+j+mid]+=M;
    }
  if(inv)
    for(int i=0;i<N;++i)
    {
      x[i]=(1ll*x[i]*invN)%M;
    }
}
void solve()
{
  fib[0]=0,fib[1]=1;
  for(int i=2;i<N;++i)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
    if(1ll*fib[i]>=M)fib[i]=1ll*fib[i]-M;
  }

  int n;scanf("%d", &n);
  for(int i=1;i<=n;++i)
  {
    int x;scanf("%d", &x);
    ++cnt[x];
  }

  // Subset Convolution (fast O((2^B)*B^2))
  init_count();
  subset_convolution(cnt,cnt,ab);
  /*for(int i=0;i<16;++i)
    out<<ab[i]<<" \n"[i==15];*/

  // Xor Convolution
  memcpy(Xor,cnt,sizeof cnt);
  transform_xor(Xor);
  for(int i=0;i<N;++i)
    Xor[i]=1ll*Xor[i]*Xor[i]%M;
  transform_xor(Xor,1);

  for(int i=0;i<N;++i)
    Xor[i]=1ll*Xor[i]*fib[i]%M,
    ab[i]=1ll*ab[i]*fib[i]%M,
    cnt[i]=1ll*cnt[i]*fib[i]%M;

  // And Convolution
  and_convolution(Xor,ab,cnt,And);
  I ans=0;
  for(int i=1;i<N;i<<=1)ans=(ans+And[i])%M;
  printf("%d\n", ans);
}

int main()
{return solve(),0;}
