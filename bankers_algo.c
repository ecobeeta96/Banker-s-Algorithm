


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


_Bool isSafe(int A[], int max[100][100], int Alloc[100][100], int need[100][100], int n, int m);
void checkRequest_1(int need[250][250], int resourceRqst[250], int A[250], int Alloc[250][250], int m, int inP);

int main(int argc, char const *argv[])
{
	int n = 100,   /*Number of processord*/
		m = 100;   /* Number of resources*/

	

	//_Bool finish[100];     /*finish array*/

	int Max[100][100],     /*matrix defines the maximum demand*/
		Alloc[100][100],       /*matrix deines the # resources*/
		need[100][100];     /*matrix for needed instances*/

	int A[250];
	//vector_init(&A); /*vector for available resources*/


	printf("Enter the Number of processors and Resources : \n");
	scanf("%d%d", &n, &m);


	printf("\nNumber of processors : %d", n);
	printf("\nNumber of Resources : %d", m);

	printf("\n\nEnter the Availability of instances of each resources in order: ");
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &A[j]);
	}

	printf("\nEnter Max Matrix elements : \n");
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d row elements : ", i + 1);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &Max[i][j]);

		}
		
	}


	printf("\nEnter Allocation Matrix elements : \n");
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d row elements : ", i + 1);
		for (int j = 0; j < m; j++)
			scanf("%d", &Alloc[i][j]);
	}

	// calculating the NEED matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			need[i][j] = Max[i][j] - Alloc[i][j];

	//print availabilty array 
	printf("Availability : ");
	for (int i = 0; i < m; i++)
		printf("%d ", A[i]);

	//print MAX matrix 
	printf("\nMAX matrix \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", Max[i][j]);
		printf("\n");
	}

	//print Allcation matrix 
	printf("\nAllocation matrix \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", Alloc[i][j]);
		printf("\n");
	}

	//print need matrix   
	printf("\n need = max - allocation \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", need[i][j]);

		printf("\n");
	}


	isSafe(A, Max, Alloc, need, n,m);

	_Bool goAhead = isSafe(A, Max, Alloc, need, n, m);

	int inP;
	int resourceRqst[250];
	if (goAhead == false)
		return 0;
	else if (goAhead == true)
	{
		/*printf("\nEnter the process number : ");
		scanf("%d ", &inP);*/

		inP = 0;

		printf("\n m  = %d  ", m);

		printf("\nEnter requests: ");		
		

		
		for (int i = 0; i < m; i++)
		{
			printf("enter");
			scanf("%d", &resourceRqst[i]);
		}

		printf("\nResource Request : ");
		for (int i = 0; i < m; i++)
		{
			printf("%d ", resourceRqst[i]);
		}
		
		checkRequest_1(need, resourceRqst, A, Alloc, m, inP);

		printf("\n new matrixes : ");

		//print availabilty array 
		printf("Availability : ");
		for (int i = 0; i < m; i++)
			printf("%d ", A[i]);

		//print MAX matrix 
		printf("\nMAX matrix \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%d ", Max[i][j]);
			printf("\n");
		}

		//print Allcation matrix 
		printf("\nAllocation matrix \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%d ", Alloc[i][j]);
			printf("\n");
		}

		//print need matrix   
		printf("\n need = max - allocation \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%d ", need[i][j]);

			printf("\n");
		}


		isSafe(A, Max, Alloc, need, n, m);
	}

	system("PAUSE");
	return 0;

}

_Bool isSafe(int A[], int max[100][100], int Alloc[100][100], int need[100][100], int n, int m)
{
	int finish[250] ;
	int safeSeq[250];
	int count = 0;
	int work[250];

	for (int i = 0; i < n; i++)
	{
		finish[i] = 0;
	}

	for (int  i = 0; i < m; i++)
	{
		work[i] = A[i];
	}
	
	while (count < n) {
		_Bool found = false;
		for (int p = 0; p < n; p++)
		{
			if (finish[p] == 0)
			{
				int j;
				for (j = 0; j < m; j++)
				{
					if (need[p][j] > work[j])
						break;
				}
				if (j == m)
				{
					for (int k = 0; k < m; k++)
					{
						work[k] += Alloc[p][k];
					}
					safeSeq[count++] = p;

					finish[p] = 1;

					found = true;

				}
			}
		}

		if (found == false)
		{
			printf("\nSystem is not in safe state.\n ");
			return false;
		}
	}

	printf("\nSystem is in safe state.\nSafe\nSequence is : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", safeSeq[i]);
	}

	return true;

}

void checkRequest_1(int need[250][250], int resourceRqst[250], int A[250],int Alloc[250][250] ,int m, int inP)
{
	int tempA[250];

	for (int i = 0; i < m ; i++)
	{
		tempA[i] = A[i];
	}
	int count = 1;
	int count_2 = 1;
	for (int i = 0; i < m; i++)
	{
		

		if (resourceRqst[i] <= need[inP][i])
		{
			count++;
			if (count == m)
			{
				for (int j = 0; j < m; j++)
				{
					//printf("\nrsourceRqst : %d availbale  %d : ", resourceRqst[j], tempA[j]);
					if (resourceRqst[j] <= tempA[j])
					 {
						for (int k = 0; k < m; k++)
						{
							A[k] -= resourceRqst[k];
							Alloc[inP][k] += resourceRqst[k];
							need[inP][k] -= resourceRqst[k];

						}
						break;
					}
					else
					{
						printf("\nCannot grant.. EXIT!!! \n resource Request greater than Available\n");
						exit(2);
					}
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			printf("\nCannot grant.. EXIT!!! \nResource Request greater than need\n");
			exit(1);
		}
	}
 
	
}