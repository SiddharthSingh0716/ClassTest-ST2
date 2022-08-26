// Name - Siddharth Singh
// Roll No.-2010991397
// Set-2
// Sort an array based  on frequency

#include <bits/stdc++.h>
using namespace std;

struct ele
{
    int count, index, val;
};

bool compo(struct ele a, struct ele b)
{
    return (a.val < b.val);
}
bool compo2(struct ele a, struct ele b)
{
    if (a.count != b.count)
        return (a.count < b.count);
    else
        return a.index > b.index;
}

void sorting(int arr[], int n)
{
    struct ele element[n];
    for (int i = 0; i < n; i++)
    {

        element[i].index = i;

        element[i].count = 0;

        element[i].val = arr[i];
    }

    stable_sort(element, element + n, compo);

    element[0].count = 1;

    for (int i = 1; i < n; i++)
    {

        if (element[i].val == element[i - 1].val)
        {
            element[i].count += element[i - 1].count + 1;

            element[i - 1].count = -1;

            element[i].index = element[i - 1].index;
        }

        
        else
            element[i].count = 1;
    }

    /* Now we have counts and first index for each element
    so now sort on the basis of count and in case of tie
    use index to sort.*/
    stable_sort(element, element + n, compo);
    for (int i = n - 1, index = 0; i >= 0; i--)
        if (element[i].count != -1)
            for (int j = 0; j < element[i].count; j++)
                arr[index++] = element[i].val;
}

int main()
{
    int arr[44];
    cout << "Enter the size of the array ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sorting(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
