# Thetre
cudaTheatre performes as a server which could run cuda code remotely by receiving requests.

# Crucial Dependencies
## [CPure](https://github.com/yuisanae2f/CPure)
Performs the dynamic allocation on managing heap memory.
## [Cuda](https://developer.nvidia.com/cuda-downloads)
The open-source library to command the GPU from NVDA.

# Download
## x64 Windows

# Main Params
This programme has three params of launchng.  
Basically arguments follow this format.

```c
cudaTheatre ip-address(=127.0.0.1) port(=8080)
```

Basically following arguments could be omitted.  
In the round brackets are the default values in the case of not written.

# [Available Requests](./req/)
Three types of requests are available.  
Which are [GET](./req/get.md), [POST](./req/post.md), [CDRC](./req/cdrc.md).

## [GET](./req/get.md)
shows the page on your browser in order to check and manage the situation.

## [POST](./req/post.md)
to manage the value via your browser.

## [CDRC](./req/cdrc.md)
to manage the value directly with this [C library](https://github.com/yuisanae2f/cudaRC/tree/cdrc).

# Map
to allocate the value to calculate on GPU.  
to store them, it uses the map based on Container from [CPure](https://github.com/yuisanae2f/CPure).