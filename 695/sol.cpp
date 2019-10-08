#include <iostream>
#include <vector>
using namespace std;

int DFS(vector<vector<int>> &input, int i, int j);

int main()
{
	// get input 2D int array as vector<vector<int>>
	/*
	vector<vector<int>> input = 
	{{0,0,1,0,0,0,0,1,0,0,0,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,1,1,0,1,0,0,0,0,0,0,0,0},
	 {0,1,0,0,1,1,0,0,1,0,1,0,0},
	 {0,1,0,0,1,1,0,0,1,1,1,0,0},
	 {0,0,0,0,0,0,0,0,0,0,1,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,0,0,0,0,0,0,1,1,0,0,0,0}};
	*/
	vector<vector<int>> input =
	{{0, 1, 1},
	 {0, 0, 0}, 
	 {0, 1, 0}};
	int maxArea = 0;
	

	for(int i = 0; i < input.size(); i++)
	{
		for(int j = 0; j < input[0].size(); j++)
		{
			maxArea = max(maxArea, DFS(input, i, j));
		}
	}

	cout << maxArea << endl;

	return 0;
}

int DFS(vector<vector<int>> &input, int i, int j)
{
	if(i < 0 || j < 0 || i > input.size() - 1 || j > input[0].size() - 1 || input[i][j] == 0)
	{
		return 0;
	}

	input[i][j] = 0;

	return 1 + DFS(input, i - 1, j) + DFS(input, i + 1, j) + DFS(input, i, j - 1) + DFS(input, i, j + 1);
}
