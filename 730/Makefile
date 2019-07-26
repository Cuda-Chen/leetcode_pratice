CC = gcc
NVCC = nvcc
CFLAGS = -std=c99

# OpenCL settings
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS += -lOpenCL
endif

ifeq ($(UNAME), Darwin)
LIBS += -framework OpenCL
endif

.PHONY: all p_thread cuda opencl opencl_me clean

all:
	$(CC) -o 730.out main.c $(CFLAGS)

p_thread:
	$(CC) -lpthread $(CFLAGS) main_pthread.c -o 730_pthread.out

cuda:
	$(NVCC) -o 730_cuda.out 730_solution.cu

opencl:
	$(CC) -o 730_cl.out main_cl.c $(LIBS)

opencl_me:
	$(CC) -o 730_cl.out main_cl.c $(LIBS) -L/usr/local/cuda-9.0/lib64

clean:
	rm -rf *.o
	rm -rf *.out
