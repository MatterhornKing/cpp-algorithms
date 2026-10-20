#include <cstdio>
int MergeSort(int s[], int left, int middle, int right)
{
   int i = left, j = middle;
   int b[right - left + 1];
   int index = 0;
   int sum = 0;
   int t = 0;
   //----------------------------------------------
   //核心代码
   while (i < middle && j <= right)
   {
       if (s[i] > s[j])
       {
           b[index++] = s[j++];
           t++;
       }
       if (s[i] <= s[j] || j == right + 1)
       {// j == right + 1是防止j已经到达最右边啦，i却没有
       //因此我们需要进入if条件语句中而不是直接跳出
           sum += t * (middle - i);
           b[index++] = s[i++];
           t = 0;
       }
   }
   //----------------------------------------------------------------
   while (i < middle)
       b[index++] = s[i++];
   while (j <= right)
       b[index++] = s[j++];

   index = 0;
   for (int m = left; m <= right; m++)
       s[m] = b[index++];
   return sum ;//最后返回给k值
}
int k = 0;
void Merge(int s[], int low, int high)
{
   if (low < high)
   {
       int mid = (low + high) / 2;
       Merge(s, low, mid);
       Merge(s, mid + 1, high);
       k += MergeSort(s, low, mid + 1, high);
   }
}
int main()
{
    int a[30005];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
   Merge(a, 0, n - 1);
   printf("%d\n", k);
   return 0;
}

