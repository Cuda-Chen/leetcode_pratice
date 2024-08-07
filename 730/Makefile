CC = gcc
NVCC = nvcc
#CFLAGS = -std=c99
CFLAGS = -g

# OpenCL settings
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS += -lOpenCL
endif

ifeq ($(UNAME), Darwin)
LIBS += -framework OpenCL
endif

.PHONY: all p_thread p_thread_barrier cuda opencl opencl_me clean

all:
	$(CC) -std=c99 -o 730.out main.c $(CFLAGS)

p_thread:
	$(CC) -D_POSIX_C_SOURCE=199309L -std=c99 -pthread $(CFLAGS) main_pthread.c -o 730_pthread.out

p_thread_barrier:
	$(CC) -pthread $(CFLAGS) main_pthread_barrier.c -o 730_pthread_barrier.out

cuda:
	$(NVCC) -o 730_cuda.out 730_solution.cu

opencl:
	$(CC) -o 730_cl.out main_cl.c $(LIBS) -I/opt/intel/oneapi/compiler/latest/linux/include/sycl/ -L/opt/intel/oneapi/compiler/latest/linux/lib/

opencl_debug:
	$(CC) -o queryocl queryocl.c $(LIBS) -I/opt/intel/oneapi/compiler/latest/linux/include/sycl/ -L/opt/intel/oneapi/compiler/latest/linux/lib/

opencl_me:
	$(CC) -g -o 730_cl.out main_cl.c $(LIBS) -L/usr/local/cuda-9.0/lib64

clean:
	rm -rf *.o
	rm -rf *.out
