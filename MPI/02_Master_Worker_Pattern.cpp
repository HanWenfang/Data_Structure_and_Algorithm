/// Master-Worker Pattern in MPI
/// Reference: http://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiexmpl/src2/io/C/main.html
///

#include <iostream>
#include <mpi.h>
#include <string.h>

using namespace std;

int master_io(MPI_Comm master_comm, MPI_Comm comm)
{
	int size;
	char buf[256];
	MPI_Status status;

	MPI_Comm_size(master_comm, &size);
	for(int j=1; j<=2; ++j) // commnicate times: 2*(size-1)
	{
		for(int i=1; i<size; ++i)
		{
			// will block
			MPI_Recv(buf, 256, MPI_CHAR, i, 0, master_comm, &status); // the same communicator
			cout << status.MPI_SOURCE << " : "<< buf << endl;
		}
	}
	return 0;
}

int worker_io(MPI_Comm master_comm, MPI_Comm comm)
{
	char buf[256];
	int rank;

	MPI_Comm_rank(comm, &rank); // new communicator--workers: 0 1 2
	//MPI_Comm_rank(master_comm, &rank); // worker: 1 2 3
	sprintf(buf, "Hello from worker %d", rank);
	MPI_Send(buf, strlen(buf)+1, MPI_CHAR, 0, 0, master_comm);

	sprintf(buf, "Goodbye from worker %d", rank);
	MPI_Send(buf, strlen(buf)+1, MPI_CHAR, 0, 0, master_comm);
}


int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Comm new_comm;

	MPI_Init( &argc, &argv );
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_split(MPI_COMM_WORLD, rank==0, 0, &new_comm);

	if(rank == 0)
	{
		master_io(MPI_COMM_WORLD, new_comm);
	}
	else
	{
		worker_io(MPI_COMM_WORLD, new_comm);
	}

	MPI_Finalize();
	return 0;
}

