# [CDRC](https://github.com/yuisanae2f/cudaRC/tree/cdrc)
to manage the value directly with this [C library](https://github.com/yuisanae2f/cudaRC/tree/cdrc).  

## get
gets the value from the key.
## set
sets the value which matches the key.
## run
runs the function from certain dll path.  
the function must match the following format.

```c
typedef cudaError_t(*ae2f_cdRCFun)(ptr_ae2f_Map);
```