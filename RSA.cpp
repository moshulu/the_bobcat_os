/*
 * C++ Program to Implement the RSA Algorithm
 */
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;
 
//instantiate
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

//prime method
//checks to see if a number is prime
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

//main method
int main()
{
    //print message
    cout << "\nENTER FIRST PRIME NUMBER\n";
    //store in p
    cin >> p;
    //check to see if p is a prime
    flag = prime(p);
    
    //if p is not prime...
    if (flag == 0)
    {
        //print message
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    //print message
    cout << "\nENTER ANOTHER PRIME NUMBER\n";
    //store input in q
    cin >> q;
    //check to see if q is a prime
    flag = prime(q);
    
    //if q is not prime or p is q
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    //print message
    cout << "\nENTER MESSAGE\n";
    
    //flush standardin
    fflush(stdin);
    //store the next in msg
    cin >> msg;
    
    for (i = 0; msg[i] != '\0'; i++)
        //store all individual characters from msg in m sub i
        m[i] = msg[i];
    
    //multiplication of both prime numbers
    n = p * q;
    //multiplication of both prime numbers minus 1
    t = (p - 1) * (q - 1);
    //invoke ce(). See comments for this method for description of what this does.
    ce();
    cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";
    encrypt();
    decrypt();
    return 0;
}


void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}
long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}
void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
}
