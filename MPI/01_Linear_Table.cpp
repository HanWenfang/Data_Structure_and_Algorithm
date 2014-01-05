// Find Algorithm ~O(n) --> O(n/k)

// As long as you find it , stop all the processor, and return

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int dataTable[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

	int rank_id;
	int p_num; // processes number
	int key = 15;
	int index = -1;
	int stop = 0;
	int global_stop=0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank_id);
	MPI_Comm_size(MPI_COMM_WORLD, &p_num);

	// load balance , data seperation
	for(int i=rank_id; i<30; i+=p_num)
	{
		cout << rank_id  << " : " << i  << " : " << dataTable[i] << endl;

		//http://stackoverflow.com/questions/11303135/broadcast-message-for-all-processes-to-exitmpi
		MPI_Allreduce(&stop, &global_stop, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
		cout << "After AllReduce," << rank_id << " stop is " << stop << endl;

		if(global_stop) { cout << "Got message" << endl; break; }

		if(dataTable[i] == key){
			cout << "Processor: " << rank_id << " got index: " << i << endl;
			stop = 1;
			//break;
		}
	}
	

	//MPI_Reduce(&rank_solutions, &global_solutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	//MPI_Bcast(&stop,1, MPI_INT, rank_id,MPI_COMM_WORLD);

	MPI_Finalize();
	return 0;
}


