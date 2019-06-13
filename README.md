# Check when atexit callback is called

Neither MacOS nor Linux nor FreeBSD get this right. All call `atexit`
during `dlclose`.


## Build

```
mulle-make
```

or

```
(
   mkdir build &&
   cd build &&
   cmake .. &&
   make
)
```


## Run

### Linux / FreeBSD

```
./build/dlclose ./build/libbar.so
```

### MacOS

```
./build/dlclose ./build/libbar.dylib
```


## Output

```
-> dlopen
void bar(void)
-- install bar_atexit
<- dlclose
void bar_exit(void)   <<< TOO EARLY
-- install main_atexit
exit
void main_atexit(void)
```
