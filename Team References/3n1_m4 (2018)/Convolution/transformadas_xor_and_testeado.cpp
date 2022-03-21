/* Transformada Xor.
 * Transformada And.
 * Para transformada inversa llamar con inv=true.
 * Testeado en 458G - codeforces.
 */
const int B=17;
const int N=1<<B;
const LL M=(int)1e9+7;
const LL inv2=(int)5e8+4;
void transform_xor(LL x[],bool inv=0)
{
  for(int mid=1,i=2;i<=N;mid=i,i<<=1)
    for(int j=0,lo=0;lo<N;j+1==mid?(lo+=i,j=0):++j)
    {
      LL tw1=x[lo+j],tw2=x[lo+j+mid];
      if(inv)
      {
        x[lo+j]=(tw1+tw2)%M*inv2%M;
        x[lo+j+mid]=(tw1-tw2+M)%M*inv2%M;
      }
      else
      {
        x[lo+j]=tw1+tw2;
        if(x[lo+j]>=M)x[lo+j]-=M;
        x[lo+j+mid]=tw1-tw2;
        if(x[lo+j+mid]<0)x[lo+j+mid]+=M;
      }
    }
}
void transform_and(LL p[],bool inv=0)
{
  for(int len=1;(len<<1)<=N;len<<=1)
    for(int i=0;i<N;i+=(len<<1))
      for(int j=0;j<len;++j)
      {
        LL tw1=p[i+j];
        LL tw2=p[i+len+j];
        if(!inv)
        {
          p[i+j]=tw2;
          p[i+len+j]=tw1+tw2;
          if(p[i+len+j]>=M)p[i+len+j]-=M;
        }
        else
        {
          p[i+j]=tw2-tw1;
          if(p[i+j]<0)p[i+j]+=M;
          p[i+len+j]=tw1;
        }
      }
}
