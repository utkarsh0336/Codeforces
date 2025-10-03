#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n;
		cin >> n; // Read the number of buildings excluding the headquarters
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) // Read the number of visits for each building
			cin >> a[i];

		// Create a vector of pairs to map visits to their original indices
		vector<pair<long long, long long>> building_map;
		for (int i = 0; i < n; i++)
			building_map.push_back({a[i], i});

		// Sort the buildings by the number of visits in descending order
		sort(building_map.rbegin(), building_map.rend());

		// Initialize the answer vector with size n+1 (including headquarters)
		vector<long long> ans(n + 1, 0);

		// Headquarters is at coordinate 0
		ans[0] = 0;

		long long minutes = 0; // Total time spent walking
		long long coordinate = 1; // Start placing buildings at coordinate 1
		for (int i = 0; i < n; i++)
		{
			// Assign coordinates to buildings based on sorted visits
			ans[building_map[i].second + 1] = coordinate;
			// Calculate the time spent walking to this building
			minutes += (2 * abs(coordinate) * building_map[i].first);
			// Alternate the coordinate placement between positive and negative
			if (coordinate < 0)
				coordinate = abs(coordinate) + 1;
			else
				coordinate = -coordinate;
		}

		// Output the total minutes spent walking
		cout << minutes << endl;
		// Output the coordinates of the buildings
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
	}
}

// Time Complexity (TC): O(nlogn) = O(2*10^5 * log(2*10^5)) = O(10^6)
// Space Complexity (SC): O(n) = O(2*10^5) = O(10^6)
