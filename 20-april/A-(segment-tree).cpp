#include <cstdio>
#include <algorithm>
#define MAX 100010
#define INF 2100000000
using namespace std;

struct node
{
  long long sum, sumSq, add, set;
} SegTree[4*MAX];

long long mas[MAX];

void build(long long *a, int Vertex, int Left, int Right)
{
  if (Left == Right)
  {
    SegTree[Vertex].sum = a[Left];
    SegTree[Vertex].sumSq = 1LL * a[Left] * a[Left];
    SegTree[Vertex].add = 0;
    SegTree[Vertex].set = INF;
  }
  else 
  {
    int Middle = (Left + Right) / 2;

    build (a, 2*Vertex, Left, Middle);
    build (a, 2*Vertex+1, Middle+1, Right);

    SegTree[Vertex].sum = SegTree[2*Vertex].sum + SegTree[2*Vertex+1].sum;
    SegTree[Vertex].sumSq = 
      SegTree[2*Vertex].sumSq + SegTree[2*Vertex+1].sumSq;
    SegTree[Vertex].add = 0;
    SegTree[Vertex].set = INF;
  }
}

void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
  if (SegTree[Vertex].set != INF)
  {
    SegTree[2*Vertex].set = SegTree[Vertex].set;
    SegTree[2*Vertex].add = 0;
    SegTree[2*Vertex].sum = (Middle - LeftPos + 1) * SegTree[Vertex].set;
    SegTree[2*Vertex].sumSq = 
      (Middle - LeftPos + 1) * SegTree[Vertex].set * SegTree[Vertex].set;

    SegTree[2*Vertex+1].set = SegTree[Vertex].set;
    SegTree[2*Vertex+1].add = 0;
    SegTree[2*Vertex+1].sum = (RightPos - Middle) * SegTree[Vertex].set;
    SegTree[2*Vertex+1].sumSq = (RightPos - Middle) * 
                                SegTree[Vertex].set * SegTree[Vertex].set;
    SegTree[Vertex].set = INF;
  }

  if (SegTree[Vertex].add != 0)
  {
    SegTree[2*Vertex].add += SegTree[Vertex].add;
    SegTree[2*Vertex].sumSq += (Middle - LeftPos + 1) * SegTree[Vertex].add 
                               * SegTree[Vertex].add + 
                         2LL * SegTree[Vertex].add * SegTree[2*Vertex].sum;
    SegTree[2*Vertex].sum += (Middle - LeftPos + 1) * SegTree[Vertex].add;

    SegTree[2*Vertex+1].add += SegTree[Vertex].add;
    SegTree[2*Vertex+1].sumSq += (RightPos - Middle) * SegTree[Vertex].add  * 
                                 SegTree[Vertex].add + 
                       2LL * SegTree[Vertex].add * SegTree[2*Vertex+1].sum;
    SegTree[2*Vertex+1].sum += (RightPos - Middle) * SegTree[Vertex].add;
    SegTree[Vertex].add = 0;
  }
}

void SetValue(int Vertex, int LeftPos, int RightPos, 
              int Left, int Right, int Value)
{
  if (Left > Right) return;
  if ((LeftPos == Left) && (RightPos == Right))
  {
    SegTree[Vertex].add = 0;
    SegTree[Vertex].set = Value;
    SegTree[Vertex].sum = (long long)(Right - Left + 1) * Value;
    SegTree[Vertex].sumSq = (long long)(Right - Left + 1) * Value * Value;
    return;
  }

  int Middle = (LeftPos + RightPos) / 2;
  Push(Vertex,LeftPos,Middle,RightPos);

  SetValue(2*Vertex, LeftPos, Middle, Left, min(Middle,Right), Value);
  SetValue(2*Vertex+1, Middle+1, RightPos, max(Left,Middle+1), Right, Value);
  
  SegTree[Vertex].sum = SegTree[2*Vertex].sum + SegTree[2*Vertex+1].sum;
  SegTree[Vertex].sumSq = 
    SegTree[2*Vertex].sumSq + SegTree[2*Vertex+1].sumSq;
}

void AddValue(int Vertex, int LeftPos, int RightPos, 
              int Left, int Right, int Value)
{
  if (Left > Right) return;
  if ((LeftPos == Left) && (RightPos == Right))
  {
    SegTree[Vertex].add += Value;
    SegTree[Vertex].sumSq += (long long)(Right - Left + 1) * Value * Value + 
                             2LL * Value * SegTree[Vertex].sum;
    SegTree[Vertex].sum += (long long)(Right - Left + 1) * Value;
    return;
  }

  int Middle = (LeftPos + RightPos) / 2;
  Push(Vertex,LeftPos,Middle,RightPos);

  AddValue(2*Vertex, LeftPos, Middle, Left, min(Middle,Right), Value);
  AddValue(2*Vertex+1, Middle+1, RightPos, max(Left,Middle+1), Right, Value);
  
  SegTree[Vertex].sum = SegTree[2*Vertex].sum + SegTree[2*Vertex+1].sum;
  SegTree[Vertex].sumSq = 
    SegTree[2*Vertex].sumSq + SegTree[2*Vertex+1].sumSq;
}

long long SumSq(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
  if (Left > Right) return 0;
  if ((LeftPos == Left) && (RightPos == Right)) return SegTree[Vertex].sumSq;

  int Middle = (LeftPos + RightPos) / 2;
  Push(Vertex,LeftPos,Middle,RightPos);

  return SumSq(2*Vertex, LeftPos, Middle, Left, min(Middle,Right)) + 
         SumSq(2*Vertex+1, Middle+1, RightPos, max(Left,Middle+1), Right);
}

int i, n, q, cs, tests, type, l, r, x;

int main(void)
{
  scanf("%d",&tests);
  for(cs = 1; cs <= tests; cs++)
  {
    scanf("%d %d",&n,&q);
    for(i = 1; i <= n; i++)
      scanf("%lld",&mas[i]);

    build(mas,1,1,n);
    printf("Case %d:\n",cs);

    while(q--)
    {
      scanf("%d",&type);
      if (type == 0) 
      {
        scanf("%d %d %d",&l,&r,&x);
        SetValue(1,1,n,l,r,x);
      } else 
      if (type == 1)	
      {
        scanf("%d %d %d",&l,&r,&x);
        AddValue(1,1,n,l,r,x);
      } else
      {
        scanf("%d %d",&l,&r);
        printf("%lld\n",SumSq(1,1,n,l,r));
      }
    }
  }
  return 0;
}