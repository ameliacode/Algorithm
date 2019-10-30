#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//O(n^2)
typedef struct Job {	//Jobs structure
	int Si, Ei, Wi;
}Job;

//Jobs �켱���� �ο� custom-compare �Լ�
bool cmp(Job job1, Job job2)
{
	if (job1.Si < job2.Si)
		return true;
	else if (job1.Si == job2.Si)
		return job1.Ei < job2.Ei;
	else
		return false;
}

bool working(Job *jobs, int N)
{
	int shift, lastday;

	sort(jobs, jobs + N, cmp);
	lastday = jobs[N - 1].Ei;

	for (int day = 1; day <= lastday; day++) //day count
	{
		sort(jobs, jobs + N, cmp);
		shift = 8;	//�κ��� �Ϸ翡 ���� �� �ִ� �ð� = 8�ð�
		for (int i = 0; i < N; i++)
		{
			if (jobs[i].Si == day) //���� ���� �����ϴ� ��� jobs ������
			{
				if (shift != 0)  //�۾��� ������ �ʾҴٸ�,
				{
					if (jobs[i].Wi <= 8)
					{
						shift = 8 - jobs[i].Wi;
						jobs[i].Wi = 0;
					}
					else if (jobs[i].Wi > 8)
					{
						jobs[i].Wi -= shift;
						jobs[i].Si++;	//���� �۾����� �������� �Ѱ��ֵ��� ��ȹ
						shift = 0;
					}
				}
				else //�۾��� �����ٸ�, "���ϳ�" �ܿ� �۾� ���� ���� �ϵ��� ��ȹ
				{
					if (jobs[i].Wi != 0) jobs[i].Si++;
				}
			}
		}
	}
	if (jobs[N - 1].Wi == 0) return true;	//���� ��� ���� �����ٸ� true ��ȯ
	else return false;
}

int main() {

	int N, T;
	int start, end, work;
	Job *jobs;
	cin >> T;

	while (T--)
	{
		cin >> N;
		jobs = new Job[N];
		for (int i = 0; i < N; i++)
		{
			cin >> start;
			jobs[i].Si = start;
			cin >> end;
			jobs[i].Ei = end;
			cin >> work;
			jobs[i].Wi = work;
		}
		if (working(jobs, N)) cout << "Yes" << endl;
		else cout << "No" << endl;
		delete jobs;
	}
}//copyright 2019 github @ameliacode