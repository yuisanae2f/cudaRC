# POST
to manage the value [via your browser](./get.md).

## [realloc](./get.md#malloc)
sets the input buffer size as bytes.  
Warning: do not set this as too small value. it may not be able to receive the request.

## [dll](./get.md#dll)
### save
```
dllsave
```
saves the all linked dll path in the given path.

### load
```
dllload
```
links all dll path written on the given path.

### on
```
dllon
```
links the dll to this server by requesting with its path.
### off
```
dlloff
```
frees the dll from this server.  
by freeing it you will not able to run a code from certain dll no more.

## [del](./get.md#heap)
frees the memory from heap which match its key name.