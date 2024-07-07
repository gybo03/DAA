#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int b;
} Tuple;

int
compareTupleAsc (const void *a, const void *b)
{
    const Tuple *ta = a;
    const Tuple *tb = b;
    if (ta->a > tb->a)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int
compareTupleDesc (const void *a, const void *b)
{
    const Tuple *ta = a;
    const Tuple *tb = b;
    if (ta->a > tb->a)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int
zad1 ()
{
    int x = 100;                      // liters of milk needed
    int l[] = { 20, 40, 10, 80, 30 }; // milk in liter per store
    int c[] = { 5, 9, 3, 8, 6 };      // cost of milk per one liter
    int res = 0;
    Tuple tuples[5];
    for (int i = 0; i < 5; i++)
    {
        tuples[i].a = c[i];
        tuples[i].b = l[i];
    }

    qsort (tuples, 5, sizeof (Tuple), compareTupleAsc);
    int i = 0;
    while (x != 0 && i < 5)
    {
        if (x - tuples[i].b < 0)
        {
            res += x * tuples[i].a;
            break;
        }
        res += tuples[i].b * tuples[i].a;
        x -= tuples[i].b;
        i++;
    }

    return res;
}

int
colides (Tuple t1, Tuple t2)
{
    if (t1.a > t2.b && t1.a < t2.a)
    {
        return 0;
    }
    return 1;
}
int
zad2 ()
{
    int a[] = { 1, 9, 7, 2, 5 };   // begin of interval
    int b[] = { 3, 11, 10, 7, 7 }; // end
    int res = 0;
    Tuple tuples[5];
    for (int i = 0; i < 5; i++)
    {
        tuples[i].b = a[i]; // sort acording to the end of the interval
        tuples[i].a = b[i];
    }
    qsort (tuples, 5, sizeof (Tuple), compareTupleAsc);
    int i = 1;
    res++;
    while (i < 5)
    {
        if (colides (tuples[i - 1], tuples[i]))
        {
            res++;
        }
        i++;
    }
    return res;
}
// try to maximize cost
int
zad3 ()
{
    int W = 50;                 // max weight
    int w[] = { 10, 30, 20 };   // weight of an object
    int c[] = { 60, 120, 100 }; // cost of an object
    Tuple tuplesW[3];
    Tuple tuplesC[3];
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        tuplesW[i].a = (double)c[i] / w[i];
        tuplesW[i].b = w[i];
        tuplesC[i].a = (double)c[i] / w[i];
        tuplesC[i].b = c[i];
    }
    qsort (tuplesW, 3, sizeof (Tuple), compareTupleDesc);
    qsort (tuplesC, 3, sizeof (Tuple), compareTupleDesc);
    for (int i = 0; i < 3; i++)
    {
        printf ("%2d", tuplesC[i].a);
    }
    printf ("\n");
    for (int i = 0; i < 3; i++)
    {
        printf ("%2d", tuplesC[i].b);
    }
    printf ("\n");
    for (int i = 0; i < 3; i++)
    {
        printf ("%2d", tuplesW[i].a);
    }
    printf ("\n");
    for (int i = 0; i < 3; i++)
    {
        printf ("%2d", tuplesW[i].b);
    }
    printf ("\n");
    int i = 0;
    while (W != 0 && i < 3)
    {
        if (W - tuplesW[i].b < 0)
        {
            res += (double)W / tuplesW[i].b * tuplesC[i].b;
            break;
        }
        res += tuplesC[i].b;
        W -= tuplesW[i].b;
        i++;
    }
    return res;
}
// 4th is just stupid

int
maxNum (int i, int j, int k)
{
    if (i > j && i > k)
    {
        return 1;
    }
    if (j > i && j > k)
    {
        return 2;
    }
    if (k > i && k > j)
    {
        return 3;
    }
    return 0;
}

int
zad5 ()
{
    int s1[] = { 1, 1, 1, 2, 3 };
    int s2[] = { 2, 3, 4 };
    int s3[] = { 1, 4, 5, 2 };
    int sp1 = 0, sp2 = 0, sp3 = 0;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < 5; i++)
    {
        sum1 += s1[i];
        if (i < 3)
        {
            sum2 += s2[i];
        }
        if (i < 4)
        {
            sum3 += s3[i];
        }
    }
    int m;
    while ((m = maxNum (sum1, sum2, sum3)))
    {
        switch (m)
        {
        case 1:
            sum1 -= s1[sp1++];
            break;
        case 2:
            sum2 -= s2[sp2++];
            break;
        case 3:
            sum3 -= s3[sp3++];
            break;
        }
    }
    return sp1 + sp2 + sp3;
}

int 
zad6()
{
    int n=12;
    int a[]={1,3,5};
    int i=0;
    int res=0;
    int max=0;
    while (max<n) {
        if (i<3&&a[i]<=max+1) {
            max+=a[i++];
        }else {
            max+=max+1;
            res++;
        }
    }
    return res;
}

int
main ()
{
    // printf ("%d", zad1 ());
    // printf ("%d", zad2 ());
    //printf ("%d", zad3 ());
    //printf ("%d", zad5 ());
    printf ("%d", zad6 ());
    return 0;
}