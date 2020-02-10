#include <iostream>

using namespace std;

int n, res = 0;
int visited[9];
int sel[9];
int map[50][9];
int score_stat[3];

void play()
{
	int num = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int out_count = 0;

		//score_stat init
		for (int k = 0; k < 3; k++)
		{
			score_stat[k] = 0;
		}

		while(true)
		{
			int player = map[i][sel[num]];

			if (player == 0) out_count++;

			else if (player == 1)
			{
				for (int r = 2; r >= 0; r--)
				{
					if (score_stat[r] > 0)
					{
						if (r == 2)
						{
							score_stat[r] = 0;
							ans++;
						}
						else
						{
							score_stat[r + 1] = score_stat[r];
							score_stat[r] = 0;
						}
					}
				}
				score_stat[0] = 1;
			}
			else if (player == 2)
			{
				for (int r = 2; r >= 0; r--)
				{
					if (score_stat[r] > 0)
					{
						if (r == 2 || r == 1)
						{
							score_stat[r] = 0;
							ans++;
						}
						else
						{
							score_stat[r + 2] = score_stat[r];
							score_stat[r] = 0;
						}
					}
				}
				score_stat[1] = 1;
			}
			else if (player == 3)
			{
				for (int r = 2; r >= 0; r--)
				{
					if (score_stat[r] > 0)
					{
						score_stat[r] = 0;
						ans++;
					}
				}
				score_stat[2] = 1;
			}
			else if (player == 4)
			{
				for (int r = 2; r >= 0; r--)
				{
					if (score_stat[r] > 0)
					{
						score_stat[r] = 0;
						ans++;
					}
				}
				ans++;
			}

			if (out_count == 3)
			{
				num++;
				if (num == 9) num = 0;
				break;
			}

			num++;
			if (num == 9) num = 0;

		}
	}

	// 최고 점수 찾기
	if (ans > res)
		res = ans;

}

void dfs(int cnt)
{
	if (cnt == 9)
	{
		play();

		// 경우의 수 확인용
		/*for (int i = 0; i < 9; i++)
		{
			cout << sel[i] << " ";
		}
		cout << endl;*/

		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (visited[i] == 1) continue;

		visited[i] = 1;
		sel[i] = cnt;
		dfs(cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			cin >> map[i][k];
		}
	}

	visited[3] = 1;
	sel[3] = 0;

	dfs(1);

	cout << res << endl;
}


