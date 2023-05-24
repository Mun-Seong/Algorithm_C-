#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

void	merge(int *arr, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = 0;

	int *tmp = new int[N];
	while (i <= q && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			tmp[k++] = arr[i];
			v.push_back(arr[i++]);
		}
		else
		{
			tmp[k++] = arr[j];
			v.push_back(arr[j++]);
		}
	}
	while (i <= q)
	{
		tmp[k++] = arr[i];
		v.push_back(arr[i++]);
	}
	while (j <= r)
	{
		tmp[k++] = arr[j];
		v.push_back(arr[j++]);
	}
	i = p;
	k = 0;
	while (i <= r)
		arr[i++] = tmp[k++];
	delete tmp;
}

void	merge_sort(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main()
{
	cin >> N >> K;
	int *a = new int[N];
	for (int i=0;i<N;++i)
		cin >> a[i];
	merge_sort(a, 0, N-1);
	if (v.size() >= K)
		cout << v[K-1] << endl;
	else
		cout << -1 << endl;
	delete a;
}