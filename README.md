# cudaRC
runs the code from cuda remotely via dynamic linker library(dll).  

# Crucial Dependencies
## [CPure](https://github.com/yuisanae2f/CPure)
Performs the dynamic allocation on managing heap memory.
## [Cuda](https://developer.nvidia.com/cuda-downloads)
The open-source library to command the GPU from NVDA.

# method
run [cudaTheatre.exe](https://github.com/yuisanae2f/cudaRC/tree/Theatre), to serve data and run the code.  
From now on, you could run the function from dll by requesting them with [cdrc](https://github.com/yuisanae2f/cudaRC/tree/cdrc).

# [header](./headers.md)
Since the custom request type [CDRC](https://github.com/yuisanae2f/cudaRC/blob/Theatre/req/cdrc.md) does not follow the regular string format,
one need to send the data directly.  
The library of [cudaRC](./C/cudaRC.md) helps generating the cdrc type request for the server.